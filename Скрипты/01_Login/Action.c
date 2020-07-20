Action()
{
	lr_start_transaction("01_Login");

/*Correlation comment - Do not change!  Original value='129194.535520454zztfttDpQcAiDDDDDQiHcpzzDfcf' Name ='userSession' Type ='ResponseBased'*/
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
		"Snapshot=t3.inf", 
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
		"Snapshot=t4.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=userSession", "Value={userSession}", ENDITEM,
		"Name=username", "Value={login}", ENDITEM,
		"Name=password", "Value={password}", ENDITEM,
		"Name=JSFormSubmit", "Value=off", ENDITEM,
		"Name=login.x", "Value=29", ENDITEM,
		"Name=login.y", "Value=1", ENDITEM,
		LAST);

	lr_end_transaction("Login",LR_AUTO);

	lr_start_transaction("Sign_Off");

	web_reg_find("Fail=NotFound",
		"Text/IC=A Session ID has been created",
		LAST);

	
	web_url("SignOff Button", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?signOff=1", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("Sign_Off",LR_AUTO);
	lr_end_transaction("01_Login", LR_AUTO);


	return 0;
}