/*
 *
 * @author: Eng.abdelrahman
 * @course: Learn-In-Depth Online Diploma
 * @date  :
 *
 */

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#include "SYS.h"

int main()
{
	unsigned int Option_e;

	while(1)
	{
		SYS_PrintOptionsScreen();

		DPRINTF("Enter Option : ");
		scanf("%u", &Option_e);

		switch(Option_e)
		{
		case    Clear        : system("cls");      break;
		case    AddStudent   : SYS_AddStudent();   break;
		case    ListStudent  : SYS_ListStudents(); break;
		case    DelStudent   : SYS_DelStudent();   break;
		case    SearchStudent: SYS_SearchStudent();break;
		default              : printf("Unavailable option\n");
		}

	}

	return 1;
}
