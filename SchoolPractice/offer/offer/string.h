#pragma once 

void Compare()
{
	// not same
	char str1[] = "hello world";
	char str2[] = "hello world";
	;
	// same
	char *str3 = "hello world";
	char *str4 = "hello world";
	if (str1 == str2)
		printf("same\n");
	else
		printf("no same\n");

	if (str3 == str4)
		printf("same\n");
	else
		printf("no same\n");

}