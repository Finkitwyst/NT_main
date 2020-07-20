Action()
{
	lr_start_transaction("05_Check_Flights");

/*Correlation comment - Do not change!  Original value='129194.541190765zztftttpcVcfDQiHcpzzfcHf' Name ='userSession' Type ='ResponseBased'*/
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
		"Snapshot=t8.inf", 
		"Mode=HTML", 
		LAST);
	
	lr_end_transaction("Open_Home_Page", LR_AUTO);

	lr_think_time(5);

	lr_start_transaction("Login");

	web_reg_find("Fail=NotFound",
		"Text/IC=User password was correct",
		LAST);
	
	web_submit_data("login.pl",
		"Action=http://localhost:1080/cgi-bin/login.pl",
		"Method=POST",
		"TargetFrame=body",
		"RecContentType=text/html",
		"Referer=http://localhost:1080/cgi-bin/nav.pl?in=home",
		"Snapshot=t9.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=userSession", "Value={userSession}", ENDITEM,
		"Name=username", "Value={login}", ENDITEM,
		"Name=password", "Value={password}", ENDITEM,
		"Name=JSFormSubmit", "Value=off", ENDITEM,
		"Name=login.x", "Value=79", ENDITEM,
		"Name=login.y", "Value=4", ENDITEM,
		LAST);

	lr_end_transaction("Login",LR_AUTO);

	lr_start_transaction("Click_Itinerary_Button");

	web_reg_find("Fail=NotFound",
		"Text/IC=User wants the intineraries",
		LAST);
	
	web_url("Itinerary Button", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?page=itinerary", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t10.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("Click_Itinerary_Button",LR_AUTO);

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
		"Snapshot=t11.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("Sign_Off",LR_AUTO);
	
	lr_end_transaction("05_Check_Flights", LR_AUTO);

	return 0;
}