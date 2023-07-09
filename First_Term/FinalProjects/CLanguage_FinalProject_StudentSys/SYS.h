/*
 *
 * @author: Eng.abdelrahman
 * @course: Learn-In-Depth Online Diploma
 * @date  :
 *
 */

#ifndef SYS_H_
#define SYS_H_

#define DPRINTF(...)     {fflush(stdin)      ;\
                          fflush(stdout)     ;\
                          printf(__VA_ARGS__);\
                          fflush(stdin)      ;\
                          fflush(stdout)     ;}

#define DSCANF(...)     {fflush(stdout);             \
						 fflush(stdin);              \
						 scanf(__VA_ARGS__);         \
						 fflush(stdout);             \
						 fflush(stdin);}

#define DGETS(...)      {fflush(stdout);             \
						 fflush(stdin);              \
						 gets(__VA_ARGS__);          \
						 fflush(stdout);             \
						 fflush(stdin);}

//new data type to save dates
typedef struct {
	unsigned int D; //day
	unsigned int M; //month
	unsigned int Y; //year
}SDate_t;

//new data type to save a student data
typedef struct {
	char Name[51];  //name of a student of maximum 50 letters
	unsigned long long ID;	//ID of a student of a maximum 9 letters
	SDate_t BirthDate;	//Birth date container
}SSData_t;

//new data type to save a student in the system
typedef struct S_StudentNode{
	SSData_t SData;	//data type of node data
	struct S_StudentNode *pNxtStudentNode;	//pointer to link this node with the next one if exist
}SSNode_t;

typedef enum{
	NO_ERROR,
	ERROR
}Error_et;

typedef struct{
	SSNode_t *gpFirstSNode;	//pointer to first node in the system
	SSNode_t *gpLastSNode ;	//pointer to last  node in the system
	unsigned int StudentsNum;	//number of students in the system
	const unsigned int MaxStudentNum;	//max number of students the system can reserve
}SSYS_t;

//all available options
enum{
	Clear,
	AddStudent,
	ListStudent,
	DelStudent,
	SearchStudent,
};


//function prototype

/******************************************************************
 ******************************************************************
 ** @describe: function to print user's available options screen **
 ** @input   : void                                              **
 ** @output  : void                                              **
 ******************************************************************
 ******************************************************************/
void SYS_PrintOptionsScreen(void);

/*
 * @describe: function to check if the name is available or not.
 * @input   : pointer to the name.
 * @output  : state of type Error_et.
 */
Error_et SYS_CheckName( char *Cpy_pName);

/*
 * @describe: function to search for an id
 * @input   : take the desired id
 * @output  : address of the searched student, return NULL if system empty
 */
SSNode_t* SYS_SearchID(const unsigned long long Cpy_ID);

/*
 * @describe: function to check  an id
 * @input   : take the desired id
 * @output  : ERROR or NO_ERROR
 */
Error_et SYS_CheckID(const unsigned long long Cpy_ID);

/*
 * @describe: function to check a valid day
 * @input   : take the day
 * @output  : ERROR or NO_ERROR
 */
Error_et SYS_CheckDay(const unsigned int Cpy_Day);

/*
 * @describe: function to check a valid Month
 * @input   : take the Month
 * @output  : ERROR or NO_ERROR
 */
Error_et SYS_CheckMonth(const unsigned int Cpy_Month);

/*
 * @describe: function to check a valid Year
 * @input   : take the Year
 * @output  : ERROR or NO_ERROR
 */
Error_et SYS_CheckYear(const unsigned int Cpy_Year);

/*
 * @describe: function to fill data of a student
 * @input   : take pointer to student data container
 * @output  : ERROR or NO_ERROR
 */
Error_et SYS_FillSData(SSData_t* Cpy_pSData);

/*
 * @describe: function to hold a space and fill student data then link it to the system
 * @input   : nothing
 * @output  : nothing
 */
Error_et SYS_AddStudent(void);

/*
 * @describe: function to delete a student using his id
 * @input   : void
 * @output  : void
 */
void SYS_DelStudent(void);

/*
 * @describe: function to list one student in the system
 * @input   : the address of the student node you want to view
 * @output  : void
 */
void SYS_ShowStudent(const SSNode_t *Cpy_pSNode);

/*
 * @describe: function to list all student in the system
 * @input   : void
 * @output  : void
 */
void SYS_ListStudents(void);

/*
 * @describe: function to search a student by id
 * @input   : nothing
 * @output  : nothing
 */
void SYS_SearchStudent(void);


#endif /* SYS_H_ */
