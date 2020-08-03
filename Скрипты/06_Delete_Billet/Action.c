Action()
{
	int FlightsIDCount = 0;
	lr_start_transaction("06_Delete_Billet");

	//Random rnd = new Random();
/*Correlation comment - Do not change!  Original value='129215.633373836zztzfcQpVtVzzzzHDQiHQpVHtif' Name ='userSession' Type ='ResponseBased'*/
	web_reg_save_param_attrib(
		"ParamName=userSession",
		"TagName=input",
		"Extract=value",
		"Name=userSession",
		"Type=hidden",
		SEARCH_FILTERS,
		"IgnoreRedirections=No",
		"RequestUrl=*/nav.pl*",
		LAST);
		
	lr_start_transaction("Open_Home_Page");

	web_reg_find("Fail=NotFound",
		"Text/IC=Web Tours",
		LAST);
		
	web_url("WebTours", 
		"URL=http://localhost:1080/WebTours/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);
	
	lr_end_transaction("Open_Home_Page", LR_AUTO);

	lr_think_time(5);

	lr_start_transaction("Login");
	
	web_reg_find("Fail=NotFound",
		"Text/IC=User password was correct",
		LAST);
	
	web_reg_find("Text=Welcome, <b>{login}</b>",
		LAST);
	
	web_submit_data("login.pl",
		"Action=http://localhost:1080/cgi-bin/login.pl",
		"Method=POST",
		"TargetFrame=body",
		"RecContentType=text/html",
		"Referer=http://localhost:1080/cgi-bin/nav.pl?in=home",
		"Snapshot=t2.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=userSession", "Value={userSession}", ENDITEM,
		"Name=username", "Value={login}", ENDITEM,
		"Name=password", "Value={password}", ENDITEM,
		"Name=JSFormSubmit", "Value=off", ENDITEM,
		"Name=login.x", "Value=29", ENDITEM,
		"Name=login.y", "Value=9", ENDITEM,
		LAST);

	lr_end_transaction("Login",LR_AUTO);

	lr_think_time(5);

	lr_start_transaction("Click_Itinerary_Button");
	
	web_reg_find("Fail=NotFound",
		"Text/IC=User wants the intineraries",
		LAST);
	
	web_reg_save_param_ex(
		"ParamName=FlightsID",
		"LB=name=\"flightID\" value=\"",
		"RB=\"  />",
		"Ordinal=ALL",
		SEARCH_FILTERS,
		LAST);
	
	web_reg_save_param("FlightID1",
    	"LB=name=\"flightID\" value=\"",
    	"RB=-",
    	LAST);
	
	web_url("Itinerary Button", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?page=itinerary", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		LAST);
	
	lr_end_transaction("Click_Itinerary_Button",LR_AUTO);

	lr_think_time(5);

	lr_start_transaction("Delete_Billet");

	web_reg_find("Text=Flights List",
		LAST);
	
	web_reg_save_param("FlightIDDelete",
    	"LB=name=\"flightID\" value=\"",
    	"RB=-",
    	LAST);
	
	web_submit_form("itinerary.pl", 
        "Snapshot=t1.inf", 
        ITEMDATA, 
        "Name=1", "Value=on", ENDITEM,         
        "Name=removeFlights.x", "Value=74", ENDITEM, 
        "Name=removeFlights.y", "Value=16", ENDITEM, 
        LAST);
	
	    if ((lr_eval_string("{FlightID1}")) != lr_eval_string("{FlightIDDelete}"))
    {
      	lr_output_message("OK");
    }
	else
	{
      	lr_error_message("NOPE");          
    }

	lr_end_transaction("Delete_Billet",LR_AUTO);

	lr_think_time(5);

	lr_start_transaction("Sign_Off");
	
	web_reg_find("Fail=NotFound",
		"Text/IC=A Session ID has been created",
		LAST);
	
	web_url("SignOff Button", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?signOff=1", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=itinerary", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("Sign_Off",LR_AUTO);
	
	lr_end_transaction("06_Delete_Billet", LR_AUTO);

	return 0;
}