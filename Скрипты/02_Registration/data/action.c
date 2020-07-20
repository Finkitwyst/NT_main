Action()
{

	web_url("WebTours", 
		"URL=http://localhost:1080/WebTours/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		LAST);

	lr_think_time(21);

	lr_start_transaction("01_Click_SignUp_Button");

	web_url("sign up now", 
		"URL=http://localhost:1080/cgi-bin/login.pl?username=&password=&getInfo=true", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/WebTours/home.html", 
		"Snapshot=t6.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("01_Click_SignUp_Button",LR_AUTO);

	lr_think_time(11);

	lr_start_transaction("02_Insert_Registration_Info");

	web_submit_data("login.pl", 
		"Action=http://localhost:1080/cgi-bin/login.pl", 
		"Method=POST", 
		"TargetFrame=info", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/login.pl?username=&password=&getInfo=true", 
		"Snapshot=t7.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=username", "Value=asd", ENDITEM, 
		"Name=password", "Value=asd", ENDITEM, 
		"Name=passwordConfirm", "Value=asd", ENDITEM, 
		"Name=firstName", "Value=asd", ENDITEM, 
		"Name=lastName", "Value=asd", ENDITEM, 
		"Name=address1", "Value=asd", ENDITEM, 
		"Name=address2", "Value=asd", ENDITEM, 
		"Name=register.x", "Value=53", ENDITEM, 
		"Name=register.y", "Value=7", ENDITEM, 
		LAST);

	lr_end_transaction("02_Insert_Registration_Info",LR_AUTO);

	lr_think_time(25);

	lr_start_transaction("03_Login");

	web_url("button_next.gif", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?page=menus", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/login.pl", 
		"Snapshot=t8.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("03_Login",LR_AUTO);

	lr_think_time(14);

	lr_start_transaction("04_Sign_Off");

	web_url("SignOff Button", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?signOff=1", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t9.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("04_Sign_Off",LR_AUTO);

	return 0;
}