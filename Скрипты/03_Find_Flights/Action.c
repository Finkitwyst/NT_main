Action()
{
	lr_start_transaction("03_Find_Flights");

/*Correlation comment - Do not change!  Original value='129195.122802754zztftHtpVcQVzzzHDQiHcpittHHf' Name ='userSession' Type ='ResponseBased'*/
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
		"Snapshot=t11.inf", 
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
		"Snapshot=t12.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=userSession", "Value={userSession}", ENDITEM,
		"Name=username", "Value={login}", ENDITEM,
		"Name=password", "Value={password}", ENDITEM,
		"Name=JSFormSubmit", "Value=off", ENDITEM,
		"Name=login.x", "Value=38", ENDITEM,
		"Name=login.y", "Value=9", ENDITEM,
		LAST);

	lr_end_transaction("Login",LR_AUTO);

	lr_start_transaction("Click_Flights_Button");

	web_reg_find("Fail=NotFound",
		"Text/IC=User has returned to the search page",
		LAST);

	web_url("Search Flights Button", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?page=search", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t13.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("Click_Flights_Button",LR_AUTO);

	lr_think_time(5);

	lr_start_transaction("Insert_Flight_Info");

	web_reg_find("Fail=NotFound",
		"TextPfx/IC=From {depart}",
		"TextSfx/IC=to {arrive}",
		LAST);

	web_submit_data("reservations.pl",
		"Action=http://localhost:1080/cgi-bin/reservations.pl",
		"Method=POST",
		"TargetFrame=",
		"RecContentType=text/html",
		"Referer=http://localhost:1080/cgi-bin/reservations.pl?page=welcome",
		"Snapshot=t14.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=advanceDiscount", "Value=0", ENDITEM,
		"Name=depart", "Value={depart}", ENDITEM,
		"Name=departDate", "Value={departDate}", ENDITEM,
		"Name=arrive", "Value={arrive}", ENDITEM,
		"Name=returnDate", "Value={returnDate}", ENDITEM,
		"Name=numPassengers", "Value={numPassengers}", ENDITEM,
		"Name=seatPref", "Value={seatPref}", ENDITEM,
		"Name=seatType", "Value={seatType}", ENDITEM,
		"Name=.cgifields", "Value=roundtrip", ENDITEM,
		"Name=.cgifields", "Value=seatType", ENDITEM,
		"Name=.cgifields", "Value=seatPref", ENDITEM,
		"Name=findFlights.x", "Value=46", ENDITEM,
		"Name=findFlights.y", "Value=7", ENDITEM,
		LAST);

	lr_end_transaction("Insert_Flight_Info",LR_AUTO);

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
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=flights", 
		"Snapshot=t15.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("Sign_Off",LR_AUTO);
	
	lr_end_transaction("03_Find_Flights", LR_AUTO);

	return 0;
}