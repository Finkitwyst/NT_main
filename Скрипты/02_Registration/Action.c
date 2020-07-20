Action()
{
	lr_start_transaction("02_Registration");
	
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
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		LAST);
	
	lr_end_transaction("Open_Home_Page", LR_AUTO);

	lr_think_time(5);

	lr_start_transaction("Click_SignUp_Button");

	web_reg_find("Fail=NotFound",
		"Text/IC=User Information",
		LAST);

	
	web_url("sign up now", 
		"URL=http://localhost:1080/cgi-bin/login.pl?username=&password=&getInfo=true", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/WebTours/home.html", 
		"Snapshot=t6.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("Click_SignUp_Button",LR_AUTO);

	lr_think_time(5);

	lr_start_transaction("Insert_Registration_Info");

	web_reg_find("Fail=NotFound",
		"Text/IC=Welcome to Web Tours",
		LAST);

	web_submit_data("login.pl", 
		"Action=http://localhost:1080/cgi-bin/login.pl", 
		"Method=POST", 
		"TargetFrame=info", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/login.pl?username=&password=&getInfo=true", 
		"Snapshot=t7.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=username", "Value={username}", ENDITEM, 
		"Name=password", "Value={password}", ENDITEM, 
		"Name=passwordConfirm", "Value={password}", ENDITEM, 
		"Name=firstName", "Value={firstName}", ENDITEM, 
		"Name=lastName", "Value={lastName}", ENDITEM, 
		"Name=address1", "Value={adress1}", ENDITEM, 
		"Name=address2", "Value={adress2}", ENDITEM, 
		"Name=register.x", "Value=53", ENDITEM, 
		"Name=register.y", "Value=7", ENDITEM, 
		LAST);

	lr_end_transaction("Insert_Registration_Info",LR_AUTO);

	lr_think_time(5);

	lr_start_transaction("Login");

	web_reg_find("Fail=NotFound",
		"Text/IC=User has returned to the home page",
		LAST);

	web_url("button_next.gif", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?page=menus", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/login.pl", 
		"Snapshot=t8.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("Login",LR_AUTO);

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
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t9.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("Sign_Off",LR_AUTO);
	
	lr_end_transaction("02_Registration", LR_AUTO);

	return 0;
}