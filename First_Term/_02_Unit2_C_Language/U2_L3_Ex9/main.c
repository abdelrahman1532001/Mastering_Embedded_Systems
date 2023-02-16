/*
 * main.c
 *
 *  Created on: Oct 25, 2022
 *      Author: User
 */
#include <stdio.h>

void main()
{
	char ch; //variable
	printf("Enter an alphabet : "); //print
	fflush(stdin); fflush(stdout); //clear buffers
	scanf("%c", &ch); //take alphabet from user
	//check vowel or constant
	if(((ch >= 'a') && (ch <= 'z')) || ((ch >= 'A') && (ch <= 'Z')))
	{
		switch( ch )
		{
		case 'a' :
		case 'A' :
		case 'e' :
		case 'E' :
		case 'o' :
		case 'O' :
		case 'i' :
		case 'I' :
		case 'u' :
		case 'U' :
			printf("%c is vowel\n", ch); //print
			break;
		default  :
			printf("%c is constant\n", ch); //print
			break;
		}
	}
}//end main
