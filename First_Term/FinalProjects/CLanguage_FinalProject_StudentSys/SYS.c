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

//initiate my system
SSYS_t MySYS = {NULL, //initiate first node address as NULL
				NULL, //initiate last node address as NULL
				   0, //initiate the student number as 0
				  20};//initiate the max student number as 20

/*
 * @describe: function to print user's available options screen
 * @input   : void
 * @output  : void
 */
void SYS_PrintOptionsScreen(void)
{

	printf("========================================================================\n");
	printf("                   ! Welcome To My Student System !\n");
	printf("                           Reserved : %.3d  \n", MySYS.StudentsNum);
	printf("                           Free     : %.3d  \n", MySYS.MaxStudentNum - MySYS.StudentsNum);
	printf("========================================================================\n");

	printf("1- Add a new student\n");
	printf("2- List all students\n");
	printf("3- Delete a student by ID \n");
	printf("4- Search a student by ID\n\n");
	printf("0- Clear Screen  \n");
	printf("=========================\n");

}
/*
 * @describe: function to check if the name is available or not.
 * @input   : pointer to the name.
 * @output  : state of type Error_et.
 */
Error_et SYS_CheckName(char *Cpy_pName)
{
	Error_et ERR = NO_ERROR;
	int Counter = 0;

	//check letters of the name
	while( Cpy_pName[Counter] != '\0' ) //loop until end of name
	{
		//check letters
		if((Cpy_pName[Counter] >= 'a' && Cpy_pName[Counter] <= 'z') || //allow from (a:z)
		   (Cpy_pName[Counter] >= 'A' && Cpy_pName[Counter] <= 'Z') || //allow from (A:Z)
		   (Cpy_pName[Counter] == ' ')) //allow spaces
		{
			//nothing
		}
		else //if the name doesn't follow the rules
		{
			ERR = ERROR;
		}
		Counter++; //increase a counter in each iteration to know the length of the name and check it later
	} /* end while( Cpy_pName[Counter] != '\0' ) */

	//check length and return error if not between (4:50) letters
	if(Counter > 50 || Counter < 4)
	{
		ERR = ERROR;
	}

	return ERR;
}
/*
 * @describe: function to search for an id
 * @input   : take the desired id
 * @output  : address of the searched student, return NULL if system empty
 */
SSNode_t* SYS_SearchID(const unsigned long long Cpy_ID)
{
	SSNode_t* pCurrentSNode = MySYS.gpFirstSNode; //start from the first node

	while(pCurrentSNode != NULL) //loop until end of the students
	{
		if( Cpy_ID == pCurrentSNode->SData.ID ) //if find the id
		{
			break; //get out of search
		}
		pCurrentSNode = pCurrentSNode->pNxtStudentNode; //move to next student to search
	} //end while loop
	return pCurrentSNode; //return address of the student if id be found or NULL if not
}
/*
 * @describe: function to check  an id
 * @input   : take the desired id
 * @output  : ERROR or NO_ERROR
 */
Error_et SYS_CheckID(const unsigned long long Cpy_ID)
{
	Error_et ERR = NO_ERROR;
	int digits  = 0, //counter to count number of digits
		counter = 1; //counter to divide by

	while( Cpy_ID / counter ) //count number of digits
	{
		digits++; //increase number of digits every iteration
		counter *= 10; //multiply the counter by 10.
	}
	if( (SYS_SearchID(Cpy_ID) != NULL) || (digits != 9) ) //check if id is exist or not and if it has 9 digits
	{
		ERR = ERROR;
	}
	return ERR;
}
/*
 * @describe: function to check a valid day
 * @input   : take the day
 * @output  : ERROR or NO_ERROR
 */
Error_et SYS_CheckDay(const unsigned int Cpy_Day)
{
	Error_et ERR = NO_ERROR;

	if( Cpy_Day > 30 || Cpy_Day < 1 ) //check if the day is valid
	{
		ERR = ERROR;
	}
	return ERR;
}
/*
 * @describe: function to check a valid day
 * @input   : take the day
 * @output  : ERROR or NO_ERROR
 */
Error_et SYS_CheckMonth(const unsigned int Cpy_Month)
{
	Error_et ERR = NO_ERROR;

	if( Cpy_Month > 12 || Cpy_Month < 1 ) //check if the day is valid
	{
		ERR = ERROR;
	}
	return ERR;
}
/*
 * @describe: function to check a valid day
 * @input   : take the day
 * @output  : ERROR or NO_ERROR
 */
Error_et SYS_CheckYear(const unsigned int Cpy_Year)
{
	Error_et ERR = NO_ERROR;

	if( Cpy_Year > 2050 || Cpy_Year < 2000 ) //check if the day is valid
	{
		ERR = ERROR;
	}
	return ERR;
}

/*
 * @describe: function to fill data of a student
 * @input   : take pointer to student data container
 * @output  : ERROR or NO_ERROR
 */
Error_et SYS_FillSData(SSData_t* Cpy_pSData)
{
	Error_et Err = NO_ERROR;

	//check a valid name
	do
	{
		//enter name of a student
		printf("Name (4:50 letters) or 0 to exit : ");
		DGETS(Cpy_pSData->Name); //get the name from the user
		if(strcmp(Cpy_pSData->Name, "0") == 0) //check if the user press '0' to exit
		{
			Err = ERROR;
			return Err;
		}
	}while(SYS_CheckName(Cpy_pSData->Name) == ERROR); //while not valid


	//check a valid id
	do
	{
		//enter id of as student
		printf("ID   (9 digits) or 0 to exit : ");
		DSCANF("%llu",&Cpy_pSData->ID);
		if(Cpy_pSData->ID == 0)
		{
			Err = ERROR;
			return Err;
		}
	}while(SYS_CheckID(Cpy_pSData->ID) == ERROR); //while not valid

	//check a valid day
	do
	{
		printf("Day of Birth  (1:30) or 0 to exit : "); //enter day of birthday
		DSCANF("%u", &(Cpy_pSData->BirthDate.D)); //take a day from user
		if(Cpy_pSData->BirthDate.D == 0) //if user enter 0 to exit
		{
			Err = ERROR;
			return Err; //exit
		}
	}while(SYS_CheckDay(Cpy_pSData->BirthDate.D) == ERROR); //while not valid


	//check a valid month
	do
	{
		printf("Month of Birth (1:12) or 0 to exit : "); //enter month of birthday
		DSCANF("%u", &(Cpy_pSData->BirthDate.M)); //take a month from a user
		if(Cpy_pSData->BirthDate.M == 0) //if user enter 0 to exit.
		{
			Err = ERROR;
			return Err;
		}
	}while(SYS_CheckMonth(Cpy_pSData->BirthDate.M) == ERROR); //while not valid


	//check a valid Year
	do
	{
		printf("Year of Birth (2000:2050) or 0 to exit : "); //enter month of birthday
		DSCANF("%u", &(Cpy_pSData->BirthDate.Y)); //take a year from a user
		if(Cpy_pSData->BirthDate.Y == 0) //if user enter 0 to exit.
		{
			Err = ERROR;
			return Err;
		}
	}while(SYS_CheckYear(Cpy_pSData->BirthDate.Y) == ERROR); //while not valid


	return Err;
}
/*
 * @describe: function to hold a space and fill student data then link it to the system
 * @input   : nothing
 * @output  : nothing
 */
Error_et SYS_AddStudent()
{
	SSNode_t *pTempSNode;
	Error_et Err = NO_ERROR;

	//check if system is available to add a student
	if(MySYS.StudentsNum <= MySYS.MaxStudentNum) //if system available
	{
		//allocate space for the new student node.
		pTempSNode = (SSNode_t *)(malloc(sizeof(SSNode_t)));
		//check if allocation succeed
		if( pTempSNode != NULL ) //if allocate succeed
		{
			Err = SYS_FillSData(&(pTempSNode->SData)); //fill the data of the student
			//check if fill succeed or not
			if( Err == NO_ERROR ) //if filling has no error
			{
				if(MySYS.StudentsNum == 0) //if no students in the system
				{
					MySYS.gpFirstSNode = pTempSNode; //first node is the allocated node
					MySYS.gpLastSNode = MySYS.gpFirstSNode; //last and first student are same
					MySYS.gpLastSNode->pNxtStudentNode = NULL; //make last student points to null
				} /* end if(MySYS.StudentsNum == 0) */
				else //if there is at least one student in the system
				{
					MySYS.gpLastSNode->pNxtStudentNode = pTempSNode; //make last node points to the new added student
					MySYS.gpLastSNode = pTempSNode; //then make added student as last one
					MySYS.gpLastSNode->pNxtStudentNode = NULL; //finally make it points to null
				}
				//update system informations
				MySYS.StudentsNum++; //increase students number by one
				printf("Adding Done !\n");
			} /* end if( Err == NO_ERROR ) */
			else //if filling do not pass
			{
				Err = ERROR;
				printf("Adding Not Complete, You Exit From Filling Data.\n");
				free(pTempSNode); //delete the reserved space
			}
		} /* end if( pTempSNode != NULL ) */
		else //no memory to allocate a new space
		{
			Err = ERROR;
			printf("Adding Not Complete, No Enough Memory!");
		}
	} /* end if(MySYS.StudentsNum < MySYS.MaxStudentNum) */
	else //if system is not available to add a student
	{
		Err = ERROR;
		printf("Adding Not Complete, System Is Full.\n");
	}

	return Err;
} /* end function */
/*
 * @describe: function to delete a student using his id
 * @input   : void
 * @output  : void
 */
void SYS_DelStudent(void)
{
	SSNode_t *pCurrentStudent ;
	SSNode_t *pPreStudent ;
	unsigned long long DelID; //buffer to save id

	printf("Enter ID to delete : "); //print on screen
	DSCANF("%llu", &DelID); //take id from the user

	pCurrentStudent = SYS_SearchID(DelID); //find address of the student

	if(pCurrentStudent == NULL) //id does not exist
	{
		printf("Delete failed no id found\n");
	}
	else //if id exist
	{
		//delete the node
		if( pCurrentStudent == MySYS.gpFirstSNode ) //if first node
		{
			MySYS.gpFirstSNode = MySYS.gpFirstSNode->pNxtStudentNode;
			pCurrentStudent->pNxtStudentNode = NULL;
			free(pCurrentStudent);
		}
		else //if not first node
		{
			pPreStudent = MySYS.gpFirstSNode;
			//loop until reach the previous student
			while(pPreStudent->pNxtStudentNode == pCurrentStudent)
			{
				pPreStudent = pPreStudent->pNxtStudentNode;
			}
			pPreStudent->pNxtStudentNode = pCurrentStudent->pNxtStudentNode;
			pCurrentStudent->pNxtStudentNode = NULL;
			free(pCurrentStudent);
		}
		MySYS.StudentsNum--; //decrease student number after delete
		printf("Delete Done.\n");
	}
}
/*
 * @describe: function to list one student in the system
 * @input   : void
 * @output  : void
 */
void SYS_ShowStudent(const SSNode_t *Cpy_pSNode)
{
	//make sure the number is in the range
	if(Cpy_pSNode != NULL)
	{
		printf("|%-50s|%-10llu|%.2d/%.2d/%-5d|\n",
							Cpy_pSNode->SData.Name,  //print the name of the student
							Cpy_pSNode->SData.ID,  //print the id of the student
							Cpy_pSNode->SData.BirthDate.D, //print the day of birthday
							Cpy_pSNode->SData.BirthDate.M, //print the month of birthday
							Cpy_pSNode->SData.BirthDate.Y); //print the year of birthday

	}
	else //if the address isn't exist
	{
		printf("Nothing To View. \n");
	}
}
/*
 * @describe: function to list all student in the system
 * @input   : void
 * @output  : void
 */
void SYS_ListStudents(void)
{
	SSNode_t *pTempSNode = MySYS.gpFirstSNode; //start from first student
	unsigned int Counter = 0;
	//check system if empty or not
	if(pTempSNode == NULL) //if it is empty
	{
		printf("System is empty.......\n");
	}
	else //if not empty
	{
		//print pattern on screen
		printf("=============================================================================== \n");
		printf("|%-3s|%-50s|%-10s|%-11s|\n", "N", "Name", "ID", "Birth Day");
		printf("=============================================================================== \n");
		while(pTempSNode != NULL) //loop until last student
		{
			Counter++; //counter to show order of each student.
			printf("|%.3d",	Counter); //print on screen.
			SYS_ShowStudent(pTempSNode); //call function to show each student by address.
			pTempSNode = pTempSNode->pNxtStudentNode; //move to next student to show in next iteration.
		} //end for
		printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n");
	} //end if
} //end function
/*
 * @describe: function to search a student by id
 * @input   : nothing
 * @output  : nothing
 */
void SYS_SearchStudent(void)
{
	unsigned long long ID;
	SSNode_t *pSNode; //hold address of the student after been found

	DPRINTF("Enter ID to search : "); //print on screen
	scanf("%llu", &ID); //take id from the user

	pSNode = SYS_SearchID(ID); //search the id and return address of the student

	if(pSNode == NULL) //if id is not found
	{
		printf("Student ID not found.\n"); //print on screen
	} //end if
	else //if id is found
	{
		SYS_ShowStudent(pSNode); //call function to show a student by address.
	}
} //end function


