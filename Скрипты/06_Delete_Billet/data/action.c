Action()
{

	web_url("WebTours", 
		"URL=http://localhost:1080/WebTours/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);

	lr_think_time(9);

	lr_start_transaction("Login");

	web_submit_data("login.pl", 
		"Action=http://localhost:1080/cgi-bin/login.pl", 
		"Method=POST", 
		"TargetFrame=body", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?in=home", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=userSession", "Value=129215.633373836zztzfcQpVtVzzzzHDQiHQpVHtif", ENDITEM, 
		"Name=username", "Value=jojo", ENDITEM, 
		"Name=password", "Value=bean", ENDITEM, 
		"Name=JSFormSubmit", "Value=off", ENDITEM, 
		"Name=login.x", "Value=29", ENDITEM, 
		"Name=login.y", "Value=9", ENDITEM, 
		LAST);

	lr_end_transaction("Login",LR_AUTO);

	lr_think_time(13);

	lr_start_transaction("Click_Itinerary_Button");

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

	lr_think_time(18);

	lr_start_transaction("Delete_Billet");

	web_submit_data("itinerary.pl", 
		"Action=http://localhost:1080/cgi-bin/itinerary.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/itinerary.pl", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=1", "Value=on", ENDITEM, 
		"Name=flightID", "Value=1156667-7-JB", ENDITEM, 
		"Name=flightID", "Value=1156666-15-JB", ENDITEM, 
		"Name=flightID", "Value=1156666-23-JB", ENDITEM, 
		"Name=flightID", "Value=1156751893-30855-JB", ENDITEM, 
		"Name=flightID", "Value=45737066-3906-DI", ENDITEM, 
		"Name=flightID", "Value=45714832-4651-DI", ENDITEM, 
		"Name=flightID", "Value=45722241-5424-DI", ENDITEM, 
		"Name=flightID", "Value=45711134-6202-DI", ENDITEM, 
		"Name=flightID", "Value=45711134-6971-DI", ENDITEM, 
		"Name=flightID", "Value=45725939-7721-DI", ENDITEM, 
		"Name=flightID", "Value=45729649-8503-DI", ENDITEM, 
		"Name=.cgifields", "Value=6", ENDITEM, 
		"Name=.cgifields", "Value=11", ENDITEM, 
		"Name=.cgifields", "Value=3", ENDITEM, 
		"Name=.cgifields", "Value=7", ENDITEM, 
		"Name=.cgifields", "Value=9", ENDITEM, 
		"Name=.cgifields", "Value=2", ENDITEM, 
		"Name=.cgifields", "Value=8", ENDITEM, 
		"Name=.cgifields", "Value=1", ENDITEM, 
		"Name=.cgifields", "Value=4", ENDITEM, 
		"Name=.cgifields", "Value=10", ENDITEM, 
		"Name=.cgifields", "Value=5", ENDITEM, 
		"Name=removeFlights.x", "Value=65", ENDITEM, 
		"Name=removeFlights.y", "Value=12", ENDITEM, 
		LAST);

	lr_end_transaction("Delete_Billet",LR_AUTO);

	lr_think_time(10);

	lr_start_transaction("Sign_Off");

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

	return 0;
}