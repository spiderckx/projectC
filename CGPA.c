#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#pragma warning(disable:4996)
#define TOTALCHOURS1 7
#define TOTALCHOURS2 8
#define TOTALCHOURS3 6
#define TOTALCSUB1 3
#define TOTALCSUB2 4
#define TOTALCSUB3 5
#define TOTALCSUB4 3
#define TOTALCSUB5 4
#define TOTALCSUB6 2

//Global declaration for ranking
char studIdstored[13][13] = { "KPKL23601","KPKL23602","KPKL23603","KPKL23604","KPKL23701","KPKL23702","KPKL23703","KPKL22201","KPKL24101","KPKL24102","KPKL24103","KPKL24104" };

double cgpa3[13] = { 3.07, 3.39, 4.00, 4.00, 2.95, 4.00, 2.48, 3.45, 3.94, 4.00, 4.00, 1.61 };

char namestud[13][25] = { "Alvin Tan", "Ros", "Albert Einstein", "Cheong Hong Heng", "Joel Zhu", "Eric Chou", "Joeny Lee", "Max Chan", "Boss", "Boum", "Prem", "Ivan Chua" };

//1. Function declaration
//(a)For staff mode (written by Virgin Cheong Kai Xin)
void staff();
float subcodes1();
int chours1();
float subcodes2();
int chours2();
float subcodes3();
int chours3();
float subcodes4();
int chours4();
float subcodes5();
int chours5();
float subcodes6();
int chours6();

//(b)For student mode (written by Tang Boa Yee)
void student();
void KPKL23601();
void KPKL23602();
void KPKL23603();
void KPKL23604();
void KPKL23701();
void KPKL23702();
void KPKL23703();
void KPKL22201();
void KPKL22202();
void KPKL22203();
void KPKL24101();
void KPKL24102();
void KPKL24103();
void KPKL24104();
void ranking();

//2. Selection
void main(){
	int choice;
	printf("\n			W    W  EEEEE  L       CCCCC   OOOO   M     M  EEEEE\n");
	printf("			W    W  E      L      C       O    O  MM   MM  E\n");
	printf("			W WW W  EEEE   L      C       O    O  M M M M  EEEE\n");
	printf("			WW  WW  E      L      C       O    O  M  M  M  E\n");
	printf("			W    W  EEEEE  LLLLL   CCCCC   OOOO   M     M  EEEEE\n");

	printf("\n\n					TTTTTT    OOO\n");
	printf("					  TT     O   O\n");
	printf("					  TT     O   O\n");
	printf("					  TT     O   O\n");
	printf("					  TT      OOO\n");

	printf("\n\n				K   K    OOO    L       EEEEE    JJJJJ\n");
	printf("				K  K    O   O   L       E          J\n");
	printf("				KK      O   O   L       EEEEE      J\n");
	printf("				K  K    O   O   L       E          J\n");
	printf("				K   K    OOO    LLLLL   EEEEE   JJJ\n");

	printf("\n\n				PPPP     AAA    SSSS     AAA    RRRR\n");
	printf("				P   P   A   A  S        A   A   R   R\n");
	printf("				PPPP    AAAAA   SSSS    AAAAA   RRRR\n");
	printf("				P       A   A       S   A   A   R   R\n");
	printf("				P       A   A   SSSS    A   A   R    R\n");
	printf("\n..............................................................................................");
	printf("\n  Do you wanna continue as a staff administrator, 1 or a student, 2? (Key in 0 to exit) > ");
	scanf("%d", &choice);
	rewind(stdin);
		while (choice > 2 || choice<0) {
			printf("\nInvalid code!\n");
			printf("\nDo you wanna continue as a staff administrator, 1 or a student, 2? (Key in 0 to exit) >");
			scanf("%d", &choice);
		}
		if (choice == 1)
			staff(); //Call 1st Function
		else if (choice == 2)
			student();
		else if (choice == 0)
			printf("\nPlease double press enter to exit!\n");
		

	system("pause");
}

//3.STAFF MODE
void staff() {
	char nameStudent[50], studentID[10], studcompare1[5] = "KPKL", studcompare2[5] = "ABCD";
	int currentSem = 0, csub1, csub2, csub3, csub4, csub5, csub6, totalcsub,yesNo=3;
	float grade1, grade2, grade3, grade4, grade5, grade6,totalQualityPs1 = 0, totalQualityPs2 = 0, totalQualityPs3 = 0, totalQualityPs4 = 0, totalQualityPs5 = 0, totalQualityPs6 = 0, gpaS1, gpaS2, gpaS3,cgpa1;

	system("cls");
	printf("\n===============================================================");
	printf("\nGood day, Sir / Miss.\n"); //Greetings

	do {
		//1. Asking student's name
		rewind(stdin);
		printf("\n\nKindly please key in student's name > ");
		scanf("%[^\n]", &nameStudent);
		rewind(stdin);

		//2. Asking student's ID
		//MAKE A LOOPING
		do {
			printf("\nPlease key in student's ID (format: KPKLXXXXX)> ");
			scanf("%s", &studentID);
			rewind(stdin);
			for (int i = 0; i < 4; i++) {
				studentID[i] = toupper(studentID[i]);
			}

			for (int i = 0; i < 4; i++) {
				studcompare2[i] = studentID[i];
			}

			if (strcmp(studcompare1, studcompare2) == 0)
				break;
			else
				printf("Invalid student ID.\n");
		} while (1);
		
		//3. Asking student's current semester
		printf("\nKindly please key in his/her current semester > ");
		scanf("%d", &currentSem);
		rewind(stdin);

		//4. Asking for Subject codes(subcodes=sub), credit hour(csub=chours)
		do {
			if (currentSem == 1)
			{//Asking 1st Subject, credit hour and grade
				grade1 = subcodes1();
				csub1 = chours1();

				//Asking 2nd Subject, credit hour and grade
				grade2 = subcodes2();
				csub2 = chours2();

				//Calculate GPA Semester 1
				totalQualityPs1 = grade1 * TOTALCSUB1;
				totalQualityPs2 = grade2 * TOTALCSUB2;
				gpaS1 = (totalQualityPs1 + totalQualityPs2) / TOTALCHOURS1;

				//Start to display for Semester 1
				system("cls");
				printf("\n	===============================================================\n\n");
				printf("		Student Name             : %s\n", nameStudent);
				printf("		Student ID               : %s\n", studentID);
				printf("\n	----------------------------------------------------------------\n");
				printf("	===========================RESULTS===============================\n");
				printf("\n		Introduction to Information Technology(AAA2000):\n");
				printf("		Grade point              : %.2f\n", grade1);
				printf("		Credit hour              : %d\n", csub1);
				printf("\n		English(ABA1099)                               :\n");
				printf("		Grade point              : %.2f\n", grade2);
				printf("		Credit hour              : %d\n", csub2);
				printf("\n		Total Quality Point    : %.2f\n", totalQualityPs1 + totalQualityPs2);
				printf("		Grade Point Average(GPA) : %.2f\n", gpaS1);
				printf("\n	===============================================================\n");
				break;
			}

			else if (currentSem == 2)
			{
				//Asking 1st Subject, credit hour and grade
				grade1 = subcodes1();
				csub1 = chours1();

				//Asking 2nd Subject, credit hour and grade
				grade2 = subcodes2();
				csub2 = chours2();

				//Asking 3rd Subject, credit hour and grade
				grade3 = subcodes3();
				csub3 = chours3();

				//Asking 4th Subject, credit hour and grade
				grade4 = subcodes4();
				csub4 = chours4();

				//Calculate GPA Semester 1
				totalQualityPs1 = grade1 * TOTALCSUB1;
				totalQualityPs2 = grade2 * TOTALCSUB2;
				gpaS1 = (totalQualityPs1 + totalQualityPs2) / TOTALCHOURS1;

				//Calculate GPA Semester 2
				totalQualityPs3 = grade3 * TOTALCSUB3;
				totalQualityPs4 = grade4 * TOTALCSUB4;
				gpaS2 = (totalQualityPs3 + totalQualityPs4) / TOTALCHOURS2;

				//Start to display for Semester 1 and Semester 2
				system("cls");
				printf("\n	===============================================================\n\n");
				printf("		Student Name             : %s\n", nameStudent);
				printf("		Student ID               : %s\n", studentID);
				printf("\n	----------------------------------------------------------------\n");
				printf("	===========================RESULTS===============================\n");
				printf("\n		Introduction to Information Technology(AAA2000):\n");
				printf("		Grade point              : %.2f\n", grade1);
				printf("		Credit hour              : %d\n", csub1);
				printf("\n		English(ABA1099)                               :\n");
				printf("		Grade point              : %.2f\n", grade2);
				printf("		Credit hour              : %d\n", csub2);
				printf("\n		Total Quality Point    : %.2f\n", totalQualityPs1 + totalQualityPs2);
				printf("		Grade Point Average(GPA) : %.2f\n", gpaS1);
				printf("\n	----------------------------------------------------------------\n");
				printf("\n		Web Design and Development(ACC3001)           :\n");
				printf("		Grade point              : %.2f\n", grade3);
				printf("		Credit hour              : %d\n", csub3);
				printf("\n		Calculus and Algebra(AXE3219)                 :\n");
				printf("		Grade point for          : %.2f\n", grade4);
				printf("		Credit hour for          : %d\n", csub4);
				printf("\n		Total Quality Point    : %.2f\n", totalQualityPs3 + totalQualityPs4);
				printf("		Grade Point Average(GPA) : %.2f\n", gpaS2);
				printf("\n	===============================================================\n");
				break;
			}

			else if (currentSem == 3)
			{
				//Asking 1st Subject, credit hour and grade
				grade1 = subcodes1();
				csub1 = chours1();

				//Asking 2nd Subject, credit hour and grade
				grade2 = subcodes2();
				csub2 = chours2();

				//Asking 3rd Subject, credit hour and grade
				grade3 = subcodes3();
				csub3 = chours3();

				//Asking 4th Subject, credit hour and grade
				grade4 = subcodes4();
				csub4 = chours4();

				//Asking 5th Subject, credit hour and grade
				grade5 = subcodes5();
				csub5 = chours5();

				//Asking 6th Subject, credit hour and grade
				grade6 = subcodes6();
				csub6 = chours6();

				//Calculate GPA Semester 1
				totalQualityPs1 = grade1 * TOTALCSUB1;
				totalQualityPs2 = grade2 * TOTALCSUB2;
				gpaS1 = (totalQualityPs1 + totalQualityPs2) / TOTALCHOURS1;

				//Calculate GPA Semester 2
				totalQualityPs3 = grade3 * TOTALCSUB3;
				totalQualityPs4 = grade4 * TOTALCSUB4;
				gpaS2 = (totalQualityPs3 + totalQualityPs4) / TOTALCHOURS2;

				//Calculate GPA Semester 3
				totalQualityPs5 = grade5 * TOTALCSUB5;
				totalQualityPs6 = grade6 * TOTALCSUB6;
				gpaS3 = (totalQualityPs5 + totalQualityPs6) / TOTALCHOURS3;

				//Calculate credit hour for a student
				totalcsub = csub1 + csub2 + csub3 + csub4 + csub5 + csub6;

				//Calculate CGPA
				cgpa1 = (totalQualityPs1 + totalQualityPs2 + totalQualityPs3 + totalQualityPs4 + totalQualityPs5 + totalQualityPs6) / (TOTALCHOURS1 + TOTALCHOURS2 + TOTALCHOURS3);



				//Start to display for Semester 1 and Semester 2
				system("cls");
				printf("\n	===============================================================\n\n");
				printf("		Student Name             : %s\n", nameStudent);
				printf("		Student ID               : %s\n", studentID);
				printf("\n	----------------------------------------------------------------\n");
				printf("	===========================RESULTS===============================\n");
				printf("\n		Introduction to Information Technology(AAA2000):\n");
				printf("		Grade point              : %.2f\n", grade1);
				printf("		Credit hour              : %d\n", csub1);
				printf("\n		English(ABA1099)                               :\n");
				printf("		Grade point              : %.2f\n", grade2);
				printf("		Credit hour              : %d\n", csub2);
				printf("\n		Total Quality Point    : %.2f\n", totalQualityPs1 + totalQualityPs2);
				printf("		Grade Point Average(GPA) : %.2f\n", gpaS1);
				printf("\n	----------------------------------------------------------------\n");
				printf("\n		Web Design and Development(ACC3001)           :\n");
				printf("		Grade point              : %.2f\n", grade3);
				printf("		Credit hour              : %d\n", csub3);
				printf("\n		Calculus and Algebra(AXE3219)                 :\n");
				printf("		Grade point for          : %.2f\n", grade4);
				printf("		Credit hour for          : %d\n", csub4);
				printf("\n		Total Quality Point    : %.2f\n", totalQualityPs3 + totalQualityPs4);
				printf("		Grade Point Average(GPA) : %.2f\n", gpaS2);
				printf("\n	----------------------------------------------------------------\n");
				printf("\n		Penghayatan Etika(XHS1066)                   :\n");
				printf("		Grade point for          : %.2f\n", grade5);
				printf("		Credit hour for          : %d\n", csub5);
				printf("\n		Programming Concept and Design(XSD1314)      :\n");
				printf("		Grade point for          : %.2f\n", grade6);
				printf("		Credit hour for          : %d\n", csub6);
				printf("\n		Total Quality Point    : %.2f\n", totalQualityPs5 + totalQualityPs6);
				printf("		Grade Point Average(GPA) : %.2f\n", gpaS3);
				printf("\n	----------------------------------------------------------------\n");
				printf("	Cumulative Grade Point Average = %.2f\n", cgpa1);
				printf("	Total Credit Hour              = %d\n", totalcsub);
				printf("\n	===============================================================\n");
				if (totalcsub == 21 && cgpa1 >= 2.0)
					printf("Congratulation! He / She is fulfilled the requirement to graduate!\n");
				else
					printf("Unforunately, He / She may have to retake this course to graduate!\n");
				break;
			}
			else {//If receive invalid number of semester
				printf("\nInvalid number of semester.\n");
				printf("\nKindly please key in his/her current semester > ");
				scanf("%d", &currentSem);
				rewind(stdin);
				do {
					if (currentSem <= 3 && currentSem >= 1)
						break;
					else
						printf("Invalid number of semester.\n");
					printf("\nKindly please key in his/her current semester > ");
					scanf("%d", &currentSem);
					rewind(stdin);

				} while (1);//While true
				
}
		} while (currentSem <= 3 && currentSem >= 1);

		
		do {
					printf("Do you want to continue to key in other student's result?(Yes = 1; No = 0)");
					scanf("%d", &yesNo);
					rewind(stdin);
					if (yesNo == 1) {
						system("cls");
						break;
					}
					else if (yesNo == 0)
						break;
					else
						printf("\nInvalid decision.");
				} while (1);
		
		if (yesNo == 0)
			break;
	}while (1);
	
}

float subcodes1() {
		char grade[5];
		float grade1 = 0;

		printf("\n\nSubject 1: Introduction to Information Technology, AAA2000\n");
		printf("A  = 4.00\n");
		printf("A- = 3.75\n");
		printf("B+ = 3.50\n");
		printf("B  = 3.00\n");
		printf("B- = 2.75\n");
		printf("C+ = 2.50\n");
		printf("C  = 2.00\n");
		printf("F  = 0.00\n");


		
		do {
			printf("\nPlease enter the grade by the format > ");
		scanf("%s", grade);
		grade[0] = toupper(grade[0]);
			if (strcmp("A", grade) == 0) {
				grade1 = 4.00;
				break;
			}
			else if (strcmp("A-", grade) == 0) {
				grade1 = 3.75;
				break;
			}

			else if (strcmp("B+", grade) == 0) {
				grade1 = 3.50;
				break;
			}

			else if (strcmp("B", grade) == 0) {
				grade1 = 3.00;
				break;
			}

			else if (strcmp("B-", grade) == 0) {
				grade1 = 2.75;
				break;
			}

			else if (strcmp("C+", grade) == 0) {
				grade1 = 2.50;
				break;
			}

			else if (strcmp("C", grade) == 0) {
				grade1 = 2.00;
				break;
			}

			else if (strcmp("F", grade) == 0) {
				grade1 = 0;
				break;
			}

			else {
				printf("\nInvalid input.\n");
				
			}
		} while (1);

		return grade1;
	}

int chours1() {
		int csub1;
		printf("\n\nKindly please key in the credit hour (Maximum value=3) > ");
		scanf("%d", &csub1);
		rewind(stdin);
		while (csub1 < 0 || csub1 >3)
		{
			printf("\nInvalid value.\n");
			printf("Kindly please key in the credit hour (Maximum value=3) > ");
			scanf("%d", &csub1);
			rewind(stdin);
		}
		if (csub1 >= 0) {
			return csub1;
		}

	}

float subcodes2() {
		char grade[5];
		float grade2 = 0;

		printf("\n\nSubject 2: English, ABA1099\n");
		printf("A  = 4.00\n");
		printf("A- = 3.75\n");
		printf("B+ = 3.50\n");
		printf("B  = 3.00\n");
		printf("B- = 2.75\n");
		printf("C+ = 2.50\n");
		printf("C  = 2.00\n");
		printf("F  = 0.00\n");


		
		do {
			printf("\nPlease enter the grade by the format > ");
		scanf("%s", grade);
		grade[0] = toupper(grade[0]);
			if (strcmp("A", grade) == 0) {
				grade2 = 4.00;
				break;
			}
			else if (strcmp("A-", grade) == 0) {
				grade2 = 3.75;
				break;
			}

			else if (strcmp("B+", grade) == 0) {
				grade2 = 3.50;
				break;
			}

			else if (strcmp("B", grade) == 0) {
				grade2 = 3.00;
				break;
			}

			else if (strcmp("B-", grade) == 0) {
				grade2 = 2.75;
				break;
			}

			else if (strcmp("C+", grade) == 0) {
				grade2 = 2.50;
				break;
			}

			else if (strcmp("C", grade) == 0) {
				grade2 = 2.00;
				break;
			}

			else if (strcmp("F", grade) == 0) {
				grade2 = 0;
				break;
			}

			else {
				printf("\nInvalid input.\n");

			}
		} while (1);

		return grade2;
	}

int chours2() {
		int csub2;
		
		printf("\n\nKindly please key in the credit hour (Maximum value=4) > ");
		scanf("%d", &csub2);
		rewind(stdin);

		while (csub2 < 0 || csub2 >4)
		{
			printf("\nInvalid value.\n");
			printf("Kindly please key in the credit hour > ");
			scanf("%d", &csub2);
			rewind(stdin);
		}
		if (csub2 >= 0) {
			return csub2;
		}
	}

float subcodes3() {
		char grade[5];
		float grade3 = 0;

		printf("\n\nSubject 3: Web Design and Development, ACC3001\n");
		printf("A  = 4.00\n");
		printf("A- = 3.75\n");
		printf("B+ = 3.50\n");
		printf("B  = 3.00\n");
		printf("B- = 2.75\n");
		printf("C+ = 2.50\n");
		printf("C  = 2.00\n");
		printf("F  = 0.00\n");

		do {
			printf("\nPlease enter the grade by the format > ");
		scanf("%s", grade);
		grade[0] = toupper(grade[0]);
			if (strcmp("A", grade) == 0) {
				grade3 = 4.00;
				break;
			}
			else if (strcmp("A-", grade) == 0) {
				grade3 = 3.75;
				break;
			}

			else if (strcmp("B+", grade) == 0) {
				grade3 = 3.50;
				break;
			}

			else if (strcmp("B", grade) == 0) {
				grade3 = 3.00;
				break;
			}

			else if (strcmp("B-", grade) == 0) {
				grade3 = 2.75;
				break;
			}

			else if (strcmp("C+", grade) == 0) {
				grade3 = 2.50;
				break;
			}

			else if (strcmp("C", grade) == 0) {
				grade3 = 2.00;
				break;
			}

			else if (strcmp("F", grade) == 0) {
				grade3 = 0;
				break;
			}

			else {
				printf("\nInvalid input.\n");

			}
		} while (1);
		return grade3;
	}	

int chours3() {
		int csub3;
		
		printf("\n\nKindly please key in the credit hour (Maximum value=5) > ");
		scanf("%d", &csub3);
		rewind(stdin);

		while (csub3 < 0 || csub3 >5)
		{
			printf("\nInvalid value.\n");
			printf("Kindly please key in the credit hour (Maximum value=5) > ");
			scanf("%d", &csub3);
			rewind(stdin);
		}
		if (csub3 >= 0) {
			return csub3;
		}
	}

float subcodes4() {
		char grade[5];
		float grade4 = 0;

		printf("\n\nSubject 4: Calculus and Algebra, AXE3219\n");
		printf("A  = 4.00\n");
		printf("A- = 3.75\n");
		printf("B+ = 3.50\n");
		printf("B  = 3.00\n");
		printf("B- = 2.75\n");
		printf("C+ = 2.50\n");
		printf("C  = 2.00\n");
		printf("F  = 0.00\n");

		do {
			printf("\nPlease enter the grade by the format > ");
		scanf("%s", grade);
		grade[0] = toupper(grade[0]);
			if (strcmp("A", grade) == 0) {
				grade4 = 4.00;
				break;
			}
			else if (strcmp("A-", grade) == 0) {
				grade4 = 3.75;
				break;
			}

			else if (strcmp("B+", grade) == 0) {
				grade4 = 3.50;
				break;
			}

			else if (strcmp("B", grade) == 0) {
				grade4 = 3.00;
				break;
			}

			else if (strcmp("B-", grade) == 0) {
				grade4 = 2.75;
				break;
			}

			else if (strcmp("C+", grade) == 0) {
				grade4 = 2.50;
				break;
			}

			else if (strcmp("C", grade) == 0) {
				grade4 = 2.00;
				break;
			}

			else if (strcmp("F", grade) == 0) {
				grade4 = 0;
				break;
			}

			else {
				printf("\nInvalid input.\n");

			}
		} while (1);

		return grade4;
	}

int chours4() {
		int csub4;

		printf("\n\nKindly please key in the credit hour (Maximum value=3) > ");
		scanf("%d", &csub4);
		rewind(stdin);

		while (csub4 < 0 || csub4 >3)
		{
			printf("\nInvalid value.\n");
			printf("Kindly please key in the credit hour (Maximum value=3) > ");
			scanf("%d", &csub4);
			rewind(stdin);
		}
		if (csub4 >= 0) {
			return csub4;
		}
	}

float subcodes5() {
		char grade[5];
		float grade5 = 0;

		printf("\n\nSubject 5: Penghayatan Etika, XHS1066\n");
		printf("A  = 4.00\n");
		printf("A- = 3.75\n");
		printf("B+ = 3.50\n");
		printf("B  = 3.00\n");
		printf("B- = 2.75\n");
		printf("C+ = 2.50\n");
		printf("C  = 2.00\n");
		printf("F  = 0.00\n");

		do {
			printf("\nPlease enter the grade by the format > ");
		scanf("%s", grade);
		grade[0] = toupper(grade[0]);
			if (strcmp("A", grade) == 0) {
				grade5 = 4.00;
				break;
			}
			else if (strcmp("A-", grade) == 0) {
				grade5 = 3.75;
				break;
			}

			else if (strcmp("B+", grade) == 0) {
				grade5 = 3.50;
				break;
			}

			else if (strcmp("B", grade) == 0) {
				grade5 = 3.00;
				break;
			}

			else if (strcmp("B-", grade) == 0) {
				grade5 = 2.75;
				break;
			}

			else if (strcmp("C+", grade) == 0) {
				grade5 = 2.50;
				break;
			}

			else if (strcmp("C", grade) == 0) {
				grade5 = 2.00;
				break;
			}

			else if (strcmp("F", grade) == 0) {
				grade5 = 0;
				break;
			}

			else {
				printf("\nInvalid input.\n");

			}
		} while (1);

		return grade5;
	}

int chours5() {
		int csub5;

		printf("\n\nKindly please key in the credit hour (Maximum value=4) > ");
		scanf("%d", &csub5);
		rewind(stdin);

		while (csub5 < 0 || csub5 >4)
		{
			printf("\nInvalid value.\n");
			printf("Kindly please key in the credit hour (Maximum value=4) > ");
			scanf("%d", &csub5);
			rewind(stdin);
		}
		if (csub5 >= 0) {
			return csub5;
		}
	}

float subcodes6() {
		char grade[5];
		float grade6 = 0;

		printf("\n\nSubject 6: Programming Concept and Design\n");
		printf("A  = 4.00\n");
		printf("A- = 3.75\n");
		printf("B+ = 3.50\n");
		printf("B  = 3.00\n");
		printf("B- = 2.75\n");
		printf("C+ = 2.50\n");
		printf("C  = 2.00\n");
		printf("F  = 0.00\n");

		do {
		printf("\nPlease enter the grade by the format > ");
		scanf("%s", grade);
		grade[0] = toupper(grade[0]);

			if (strcmp("A", grade) == 0) {
				grade6 = 4.00;
				break;
			}
			else if (strcmp("A-", grade) == 0) {
				grade6 = 3.75;
				break;
			}

			else if (strcmp("B+", grade) == 0) {
				grade6 = 3.50;
				break;
			}

			else if (strcmp("B", grade) == 0) {
				grade6 = 3.00;
				break;
			}

			else if (strcmp("B-", grade) == 0) {
				grade6 = 2.75;
				break;
			}

			else if (strcmp("C+", grade) == 0) {
				grade6 = 2.50;
				break;
			}

			else if (strcmp("C", grade) == 0) {
				grade6 = 2.00;
				break;
			}

			else if (strcmp("F", grade) == 0) {
				grade6 = 0;
				break;
			}

			else {
				printf("\nInvalid input.\n");

			}
		} while (1);

		return grade6;
	}

int chours6() {
		int csub6;

		printf("\n\nKindly please key in the credit hour (Maximum value=2) > ");
		scanf("%d", &csub6);
		rewind(stdin);

		while (csub6 < 0 || csub6 >2)
		{
			printf("\nInvalid value.\n");
			printf("Kindly please key in the credit hour (Maximum value=2) > ");
			scanf("%d", &csub6);
			rewind(stdin);
		}
		if (csub6 >= 0) {
			return csub6;
		}
	}

//3rd Function - STUDENT MODE
void student() {

		char studID[11];
		/*char liststud;*/
		int yesNo,yesNo1;
		system("cls");
		do {
			do {
				printf("PLEASE ENTER YOUR STUDENT ID : ");
				scanf("%s", &studID);
				rewind(stdin);
				studID[0] = toupper(studID[0]);
				studID[1] = toupper(studID[1]);
				studID[2] = toupper(studID[2]);
				studID[3] = toupper(studID[3]);
				system("cls");
				if (strcmp("KPKL23601", studID) == 0)
				{
					KPKL23601();
					break;
				}

				else if (strcmp("KPKL23602", studID) == 0)
				{
					KPKL23602();
					break;
				}

				else if (strcmp("KPKL23603", studID) == 0)
				{
					KPKL23603();
					break;
				}

				else if (strcmp("KPKL23604", studID) == 0)
				{
					KPKL23604();
					break;
				}

				else if (strcmp("KPKL23701", studID) == 0)
				{
					KPKL23701();
					break;
				}

				else if (strcmp("KPKL23702", studID) == 0)
				{
					KPKL23702();
					break;
				}

				else if (strcmp("KPKL23703", studID) == 0)
				{
					KPKL23703();
					break;
				}

				else if (strcmp("KPKL22201", studID) == 0)
				{
					KPKL22201();
					break;
				}

				else if (strcmp("KPKL22202", studID) == 0)
				{
					KPKL22202();
					break;
				}

				else if (strcmp("KPKL22203", studID) == 0)
				{
					KPKL22203();
					break;
				}

				else if (strcmp("KPKL24101", studID) == 0)
				{
					KPKL24101();
					break;
				}

				else if (strcmp("KPKL24102", studID) == 0)
				{
					KPKL24102();
					break;
				}

				else if (strcmp("KPKL24103", studID) == 0)
				{
					KPKL24103();
					break;
				}

				else if (strcmp("KPKL24104", studID) == 0)
				{
					KPKL24104();
					break;
				}

				else
					printf("INVALID STUDENT ID.\n");


			} while (1);


			do {
				printf("\nDo you want to continue checking? (1 to continue, 0 to exit)\n");
				scanf("%d", &yesNo);
				rewind(stdin);
				if (yesNo == 1)
					break;
				else if (yesNo == 0)
					break;
				else
					printf("Invalid input.");
			} while (yesNo != 1 && yesNo != 0);

			if (yesNo == 0)
				break;
			else
			{
				system("cls");
				continue;
			}
		} while (yesNo = '1');

		

		do {
			printf("\n\nWould you like to check the ranking list?(1 to continue, 0 to exit) > ");
			scanf("%d", &yesNo1);
			switch (yesNo1)
			{
			case 1:
				ranking();
				break;
			case 0:
				break;
			default:
				system("cls");
				printf("\nInvalid value.");
			}
			
		} while (yesNo1 > 1 || yesNo1< 0);
		
		printf("\n\nThank you for using Kolej Pasar Student Web. Wish you all the best!!\n\n");
	}

void KPKL23601() {
		/*grade point*/
		float grade1 = 3.50, grade2 = 3.75, grade3 = 3.00, grade4 = 0.00, grade5 = 4.00, grade6 = 3.50;
		float tqps1 = 3.64, tqps2 = 1.88, tqps3 = 3.83;
		float cgpa = 3.07;
		/*Current Semester*/
		int sem = 3;
		/*result as Grade*/
		char resultsub1[3] = "B+";
		char resultsub2[3] = "A-";
		char resultsub3 = 'B';
		char resultsub4 = 'F';
		char resultsub5 = 'A';
		char resultsub6[3] = "B+";
		/*result as Programme*/
		char programme1[4] = "DFT";
		/*Student Name*/
		char name1[16] = "Alvin Tan";
		char gender1 = 'M';
		char studentid1[10] = "KPKL23601";
		char sub1[8] = "AAA2000";
		char sub2[8] = "ABA1099";
		char sub3[8] = "ACC3001";
		char sub4[8] = "AXE3219";
		char sub5[8] = "XHS1066";
		char sub6[8] = "XSD1314";
		/*result as Tutorial Group*/
		char tutolialgroup1 = '6';
		/*Total Credit Hour*/
		double TCH1 = 21;

		printf("\n\n				Student Name          : %s\n", name1);
		printf("				Student ID            : %s\n", studentid1);
		printf("				Programme             : %s\n", programme1);
		printf("				Tutorial Group        : %c\n", tutolialgroup1);
		printf("				Gender                : %c\n", gender1);
		printf("				Current Semester      : %d\n", sem);
		printf("				Total Credit Hour     : %.2f\n\n", TCH1);

		printf("				Result of semester 1  : \n");
		printf("				Result of %s          : %.2f  / %s\n", sub1, grade1, resultsub1);
		printf("				Result of %s          : %.2f  / %s\n", sub2, grade2, resultsub2);
		printf("				Total Quality Point in Semester 1  :%.2f\n\n", tqps1);

		printf("				Result of semester 2  : \n");
		printf("				Result of %s          : %.2f  / %c\n", sub3, grade3, resultsub3);
		printf("				Result of %s          : %.2f  / %c\n", sub4, grade4, resultsub4);
		printf("				Total Quality Point in Semester 2  :%.2f\n\n", tqps2);

		printf("				Result of semester 3  : \n");
		printf("				Result of %s          : %.2f  / %c\n", sub5, grade5, resultsub5);
		printf("				Result of %s          : %.2f  / %s\n", sub6, grade6, resultsub6);
		printf("				Total Quality Point in Semester 3  :%.2f\n\n", tqps3);

		printf("				Cumulative Grade Point Average(CGPA) : %.2f\n", cgpa);

		printf("				Ranking : 9/12\n");
		printf("				Keep hardworking on study.You are closed to success. \n\n");


	}

void KPKL23602() {
		//grade point
		float grade1 = 3.00, grade2 = 3.50, grade3 = 2.75, grade4 = 3.50, grade5 = 4.00, grade6 = 4.00;
		float tqps1 = 3.29, tqps2 = 3.03, tqps3 = 4.00;
		float cgpa = 3.39;
		//Current Semester
		int sem = 3;
		/*int resultsem1 = ;*/
		//result as Grade
		char resultsub1 = 'B';
		char resultsub2[3] = "B+";
		char resultsub3[3] = "B-";
		char resultsub4[3] = "B+";
		char resultsub5 = 'A';
		char resultsub6 = 'A';
		//result as Programme
		char programme2[4] = "DFT";
		//Student Name
		char name2[4] = "Ros";
		char gender2 = 'F';
		char studentid2[10] = "KPKL23602";
		char sub1[8] = "AAA2000";
		char sub2[8] = "ABA1099";
		char sub3[8] = "ACC3001";
		char sub4[8] = "AXE3219";
		char sub5[8] = "XHS1066";
		char sub6[8] = "XSD1314";
		/*result as Tutorial Group*/
		char tutolialgroup2 = '6';
		/*Total Credit Hour*/
		double TCH2 = 21;


		printf("\n\n				Student Name          : %s\n", name2);
		printf("				Student ID            : %s\n", studentid2);
		printf("				Programme             : %s\n", programme2);
		printf("				Tutorial Group        : %c\n", tutolialgroup2);
		printf("				Gender                : %c\n", gender2);
		printf("				Current Semester      : %d\n", sem);
		printf("				Total Credit Hour     : %.2f\n\n", TCH2);

		printf("				Result of semester 1  : \n");
		printf("				Result of %s          : %.2f  / %c\n", sub1, grade1, resultsub1);
		printf("				Result of %s          : %.2f  / %s\n", sub2, grade2, resultsub2);
		printf("				Total Quality Point in Semester 1  :%.2f\n\n", tqps1);

		printf("				Result of semester 2  : \n");
		printf("				Result of %s          : %.2f  / %s\n", sub3, grade3, resultsub3);
		printf("				Result of %s          : %.2f  / %s\n", sub4, grade4, resultsub4);
		printf("				Total Quality Point in Semester 2  :%.2f\n\n", tqps2);

		printf("				Result of semester 3  : \n");
		printf("				Result of %s          : %.2f  / %c\n", sub5, grade5, resultsub5);
		printf("				Result of %s          : %.2f  / %c\n", sub6, grade6, resultsub6);
		printf("				Total Quality Point in Semester 3  :%.2f\n\n", tqps3);

		printf("				Cumulative Grade Point Average(CGPA) : %.2f\n", cgpa);
		printf("				Ranking : 8/12\n");
		printf("				Keep hardworking on study.You are closed to success. \n\n");

	}

void KPKL23603() {
		/*grade point*/
		float grade1 = 4.00, grade2 = 4.00, grade3 = 4.00, grade4 = 4.00, grade5 = 4.00, grade6 = 4.00;
		float tqps1 = 4.00, tqps2 = 4.00, tqps3 = 4.00;
		float cgpa = 4.00;
		/*Current Semester*/
		int sem = 3;
		/*result as Grade*/
		char resultsub1 = 'A';
		char resultsub2 = 'A';
		char resultsub3 = 'A';
		char resultsub4 = 'A';
		char resultsub5 = 'A';
		char resultsub6 = 'A';
		/*result as Programme*/
		char programme3[4] = "DFT";
		/*Student Name*/
		char name3[16] = "Albert Einstein";
		char gender3 = 'M';
		char studentid3[10] = "KPKL23603";
		char sub1[8] = "AAA2000";
		char sub2[8] = "ABA1099";
		char sub3[8] = "ACC3001";
		char sub4[8] = "AXE3219";
		char sub5[8] = "XHS1066";
		char sub6[8] = "XSD1314";
		/*result as Tutorial Group*/
		char tutolialgroup3 = '6';
		/*Total Credit Hour*/
		double TCH3 = 21;

		printf("\n\n				Student Name         : %s\n", name3);
		printf("				Student ID           : %s\n", studentid3);
		printf("				Programme            : %s\n", programme3);
		printf("				Tutorial Group       : %c\n", tutolialgroup3);
		printf("				Gender               : %c\n", gender3);
		printf("				Current Semester     : %d\n", sem);
		printf("				Total Credit Hour    : %.2f\n\n", TCH3);

		printf("				Result of semester 1 : \n");
		printf("				Result of %s         : %.2f  / %c\n", sub1, grade1, resultsub1);
		printf("				Result of %s         : %.2f  / %c\n", sub2, grade2, resultsub2);
		printf("				Total Quality Point in Semester 1  :%.2f\n\n", tqps1);

		printf("				Result of semester 2 : \n");
		printf("				Result of %s         : %.2f  / %c\n", sub3, grade3, resultsub3);
		printf("				Result of %s         : %.2f  / %c\n", sub4, grade4, resultsub4);
		printf("				Total Quality Point in Semester 2  :%.2f\n\n", tqps2);

		printf("				Result of semester 3 : \n");
		printf("				Result of %s         : %.2f  / %c\n", sub5, grade5, resultsub5);
		printf("				Result of %s         : %.2f  / %c\n", sub6, grade6, resultsub6);
		printf("				Total Quality Point in Semester 3  :%.2f\n\n", tqps3);

		printf("				Cumulative Grade Point Average(CGPA) : %.2f\n", cgpa);
		printf("				Ranking : 1/12\n");
		printf("				Congratulation . Your are excellent on study!\n\n");

	}

void KPKL23604() {
		//grade point
		float grade1 = 4.00, grade2 = 4.00, grade3 = 4.00, grade4 = 4.00, grade5 = 4.00, grade6 = 4.00;
		float tqps1 = 4.00, tqps2 = 4.00, tqps3 = 4.00;
		float cgpa = 4.00;
		//Current Semester
		int sem = 3;
		//result as Grade
		char resultsub1 = 'A';
		char resultsub2 = 'A';
		char resultsub3 = 'A';
		char resultsub4 = 'A';
		char resultsub5 = 'A';
		char resultsub6 = 'A';
		//result as Programme
		char programme4[4] = "DFT";
		//Student Name
		char name4[17] = "Cheong Hong Heng";
		char gender4 = 'M';
		char studentid4[10] = "KPKL23604";
		char sub1[8] = "AAA2000";
		char sub2[8] = "ABA1099";
		char sub3[8] = "ACC3001";
		char sub4[8] = "AXE3219";
		char sub5[8] = "XHS1066";
		char sub6[8] = "XSD1314";
		//result as Tutorial Group
		char tutolialgroup4 = '6';
		/*Total Credit Hour*/
		double TCH4 = 21;


		printf("\n\n				Student Name         : %s\n", name4);
		printf("				Student ID           : %s\n", studentid4);
		printf("				Programme            : %s\n", programme4);
		printf("				Tutorial Group       : %c\n", tutolialgroup4);
		printf("				Gender               : %c\n", gender4);
		printf("				Current Semester     : %d\n", sem);
		printf("				Total Credit Hour    : %.2f\n\n", TCH4);

		printf("				Result of semester 1 : \n");
		printf("				Result of %s         : %.2f  / %c\n", sub1, grade1, resultsub1);
		printf("				Result of %s         : %.2f  / %c\n", sub2, grade2, resultsub2);
		printf("				Total Quality Point in Semester 1  :%.2f\n\n", tqps1);

		printf("				Result of semester 2 : \n");
		printf("				Result of %s         : %.2f  / %c\n", sub3, grade3, resultsub3);
		printf("				Result of %s         : %.2f  / %c\n", sub4, grade4, resultsub4);
		printf("				Total Quality Point in Semester 2  :%.2f\n\n", tqps2);

		printf("				Result of semester 3 : \n");
		printf("				Result of %s         : %.2f  / %c\n", sub5, grade5, resultsub5);
		printf("				Result of %s         : %.2f  / %c\n", sub6, grade6, resultsub6);
		printf("				Total Quality Point in Semester 1  :%.2f\n\n", tqps3);

		printf("				Cumulative Grade Point Average(CGPA) : %.2f\n", cgpa);
		printf("				Ranking : 1/12\n");
		printf("				Congratulation . Your are excellent on study!\n");
	}

void KPKL23701() {
		//grade point
		float grade1 = 4.00, grade2 = 3.00, grade3 = 3.00, grade4 = 3.00, grade5 = 3.50, grade6 = 0.00;
		float tqps1 = 3.43, tqps2 = 3.00, tqps3 = 2.33;
		float cgpa = 2.95;
		//Current Semester
		int sem = 3;
		//result as Grade
		char resultsub1 = 'A';
		char resultsub2 = 'B';
		char resultsub3 = 'B';
		char resultsub4 = 'B';
		char resultsub5[3] = "B+";
		char resultsub6 = 'F';
		//result as Programme
		char programme5[4] = "DFT";
		//Student Name
		char name5[9] = "Joel Zhu";
		char gender5 = 'F';
		char studentid5[10] = "KPKL23701";
		char sub1[8] = "AAA2000";
		char sub2[8] = "ABA1099";
		char sub3[8] = "ACC3001";
		char sub4[8] = "AXE3219";
		char sub5[8] = "XHS1066";
		char sub6[8] = "XSD1314";
		//result as Tutorial Group
		char tutolialgroup5 = '6';
		/*Total Credit Hour*/
		double TCH5 = 20;


		printf("\n\n				Student Name           : %s\n", name5);
		printf("				Student ID             : %s\n", studentid5);
		printf("				Programme              : %s\n", programme5);
		printf("				Tutorial Group         : %c\n", tutolialgroup5);
		printf("				Gender                 : %c\n", gender5);
		printf("				Current Semester       : %d\n", sem);
		printf("				Total Credit Hour      : %.2f\n\n", TCH5);

		printf("				Result of semester 1   : \n");
		printf("				Result of %s           : %.2f  / %c\n", sub1, grade1, resultsub1);
		printf("				Result of %s           : %.2f  / %c\n", sub2, grade2, resultsub2);
		printf("				Total Quality Point in Semester 1  :%.2f\n\n", tqps1);

		printf("				Result of semester 2   : \n");
		printf("				Result of %s           : %.2f  / %c\n", sub3, grade3, resultsub3);
		printf("				Result of %s           : %.2f  / %c\n", sub4, grade4, resultsub4);
		printf("				Total Quality Point in Semester 2  :%.2f\n\n", tqps2);

		printf("				Result of semester 3   : \n");
		printf("				Result of %s           : %.2f  / %s\n", sub5, grade5, resultsub5);
		printf("				Result of %s           : %.2f  / %c\n", sub6, grade6, resultsub6);
		printf("				Total Quality Point in Semester 1  :%.2f\n\n", tqps3);

		printf("				Cumulative Grade Point Average(CGPA) : %.2f\n\n", cgpa);
		printf("				Ranking : 10/12\n");
		printf("				Keep hardworking on study.You are closed to success. \n");
	}

void KPKL23702() {
		//grade point
		float grade1 = 4.00, grade2 = 4.00, grade3 = 4.00, grade4 = 4.00, grade5 = 4.00, grade6 = 4.00;
		float tqps1 = 4.00, tqps2 = 4.00, tqps3 = 4.00;
		float cgpa = 4.00;
		//Current Semester
		int sem = 3;
		//result as Grade
		char resultsub1 = 'A';
		char resultsub2 = 'A';
		char resultsub3 = 'A';
		char resultsub4 = 'A';
		char resultsub5 = 'A';
		char resultsub6 = 'A';
		//result as Programme
		char programme6[4] = "DFT";
		//Student Name
		char name6[10] = "Eric Chou";
		char gender6 = 'M';
		char studentid6[10] = "KPKL23702";
		char sub1[8] = "AAA2000";
		char sub2[8] = "ABA1099";
		char sub3[8] = "ACC3001";
		char sub4[8] = "AXE3219";
		char sub5[8] = "XHS1066";
		char sub6[8] = "XSD1314";
		//result as Tutorial Group
		char tutolialgroup6 = '6';
		/*Total Credit Hour*/
		double TCH6 = 21;


		printf("\n\n				Student Name           : %s\n", name6);
		printf("				Student ID             : %s\n", studentid6);
		printf("				Programme              : %s\n", programme6);
		printf("				Tutorial Group         : %c\n", tutolialgroup6);
		printf("				Gender                 : %c\n", gender6);
		printf("				Current Semester       : %d\n", sem);
		printf("				Total Credit Hour      : %.2f\n\n", TCH6);

		printf("				Result of semester 1   : \n");
		printf("				Result of %s           : %.2f  / %c\n", sub1, grade1, resultsub1);
		printf("				Result of %s           : %.2f  / %c\n", sub2, grade2, resultsub2);
		printf("				Total Quality Point in Semester 1  :%.2f\n\n", tqps1);

		printf("				Result of semester 2   : \n");
		printf("				Result of %s           : %.2f  / %c\n", sub3, grade3, resultsub3);
		printf("				Result of %s           : %.2f  / %c\n", sub4, grade4, resultsub4);
		printf("				Total Quality Point in Semester 2  :%.2f\n\n", tqps2);

		printf("				Result of semester 3   : \n");
		printf("				Result of %s           : %.2f  / %c\n", sub5, grade5, resultsub5);
		printf("				Result of %s           : %.2f  / %c\n", sub6, grade6, resultsub6);
		printf("				Total Quality Point in Semester 3  :%.2f\n\n", tqps3);

		printf("				Cumulative Grade Point Average(CGPA) : %.2f\n", cgpa);
		printf("				Ranking : 1/12\n");
		printf("				Congratulation . Your are excellent on study!\n ");
	}

void KPKL23703() {
		//grade point
		float grade1 = 2.50, grade2 = 3.00, grade3 = 2.50, grade4 = 3.00, grade5 = 3.00, grade6 = 2.00;
		float tqps1 = 2.79, tqps2 = 2.75, tqps3 = 2.33;
		float cgpa = 2.48;
		//Current Semester
		int sem = 3;
		//result as Grade
		char resultsub1[3] = "C+";
		char resultsub2 = 'B';
		char resultsub3[3] = "C+";
		char resultsub4 = 'B';
		char resultsub5 = 'B';
		char resultsub6 = 'C';
		//result as Programme
		char programme7[4] = "DFT";

		//Student Name
		char name7[10] = "Joeny Lee";
		char gender7 = 'F';
		char studentid7[10] = "KPKL23703";
		char sub1[8] = "AAA2000";
		char sub2[8] = "ABA1099";
		char sub3[8] = "ACC3001";
		char sub4[8] = "AXE3219";
		char sub5[8] = "XHS1066";
		char sub6[8] = "XSD1314";
		//result as Tutorial Group
		char tutolialgroup7 = '6';

		/*Total Credit Hour*/
		double TCH7 = 19;


		printf("\n\n				Student Name           : %s\n", name7);
		printf("				Student ID             : %s\n", studentid7);
		printf("				Programme              : %s\n", programme7);
		printf("				Tutorial Group         : %c\n", tutolialgroup7);
		printf("				Gender                 : %c\n", gender7);
		printf("				Current Semester       : %d\n", sem);
		printf("				Total Credit Hour      : %.2f\n\n", TCH7);

		printf("				Result of semester 1   : \n");
		printf("				Result of %s           : %.2f  / %s\n", sub1, grade1, resultsub1);
		printf("				Result of %s           : %.2f  / %c\n", sub2, grade2, resultsub2);
		printf("				Total Quality Point in Semester 1  :%.2f\n\n", tqps1);

		printf("				Result of semester 2   : \n");
		printf("				Result of %s           : %.2f  / %s\n", sub3, grade3, resultsub3);
		printf("				Result of %s           : %.2f  / %c\n", sub4, grade4, resultsub4);
		printf("				Total Quality Point in Semester 2  :%.2f\n\n", tqps2);

		printf("				Result of semester 3   : \n");
		printf("				Result of %s           : %.2f  / %c\n", sub5, grade5, resultsub5);
		printf("				Result of %s           : %.2f  / %c\n", sub6, grade6, resultsub6);
		printf("				Total Quality Point in Semester 3  :%.2f\n\n", tqps3);

		printf("				Cumulative Grade Point Average(CGPA) : %.2f\n", cgpa);
		printf("				Ranking : 11/12\n");
		printf("				Keep hardworking on study.You are closed to success. \n");
	}

void KPKL22201() {
		/*grade point*/
		float grade1 = 3.00, grade2 = 3.50, grade3 = 3.50, grade4 = 3.00, grade5 = 3.75, grade6 = 4.00;
		float tqps1 = 3.29, tqps2 = 3.31, tqps3 = 3.83;
		float cgpa = 3.45;
		/*Current Semester*/
		int sem = 3;
		/*result as Grade*/
		char resultsub1 = 'B';
		char resultsub2[3] = "B+";
		char resultsub3[3] = "B+";
		char resultsub4 = 'B';
		char resultsub5[3] = "A-";
		char resultsub6 = 'A';
		/*result as Programme*/
		char programme8[4] = "DFT";

		/*Student Name*/
		char name8[9] = "Max Chan";
		char gender8 = 'M';
		char studentid8[10] = "KPKL22201";
		char sub1[8] = "AAA2000";
		char sub2[8] = "ABA1099";
		char sub3[8] = "ACC3001";
		char sub4[8] = "AXE3219";
		char sub5[8] = "XHS1066";
		char sub6[8] = "XSD1314";
		/*result as Tutorial Group*/
		char tutolialgroup8 = '6';

		/*Total Credit Hour*/
		double TCH8 = 21;


		printf("\n\n				Student Name           : %s\n", name8);
		printf("				Student ID             : %s\n", studentid8);
		printf("				Programme              : %s\n", programme8);
		printf("				Tutorial Group         : %c\n", tutolialgroup8);
		printf("				Gender                 : %c\n", gender8);
		printf("				Current Semester       : %d\n", sem);
		printf("				Total Credit Hour      : %.2f\n\n", TCH8);

		printf("				Result of semester 1   : \n");
		printf("				Result of %s           : %.2f  / %c\n", sub1, grade1, resultsub1);
		printf("				Result of %s           : %.2f  / %s\n", sub2, grade2, resultsub2);
		printf("				Total Quality Point in Semester 1  :%.2f\n\n", tqps1);

		printf("				Result of semester 2   : \n");
		printf("				Result of %s           : %.2f  / %s\n", sub3, grade3, resultsub3);
		printf("				Result of %s           : %.2f  / %c\n", sub4, grade4, resultsub4);
		printf("				Total Quality Point in Semester 2  :%.2f\n\n", tqps2);

		printf("				Result of semester 3   : \n");
		printf("				Result of %s           : %.2f  / %s\n", sub5, grade5, resultsub5);
		printf("				Result of %s           : %.2f  / %c\n", sub6, grade6, resultsub6);
		printf("				Total Quality Point in Semester 3  :%.2f\n\n", tqps3);

		printf("				Cumulative Grade Point Average(CGPA) : %.2f\n", cgpa);
		printf("				Ranking : 7/12\n");
		printf("				Keep hardworking on study.You are closed to success. \n");

	}

void KPKL22202() {
		//grade point
		float grade1 = 3.00, grade2 = 3.75;
		float tqps1 = 3.43;
		//Current Semester
		int sem = 1;
		//result as Grade
		char resultsub1 = 'B';
		char resultsub2[3] = "A-";
		//result as Programme
		char programme9[4] = "DFT";

		//Student Name
		char name9[12] = "Vivian Yong";
		char gender9 = 'F';
		char studentid9[10] = "KPKL22202";
		char sub1[8] = "AAA2000";
		char sub2[8] = "ABA1099";
		char sub3[8] = "ACC3001";
		char sub4[8] = "AXE3219";
		//result as Tutorial Group
		char tutolialgroup9 = '6';

		/*Total Credit Hour*/
		double TCH9 = 21;

		printf("\n\n				Student Name           : %s\n", name9);
		printf("				Student ID             : %s\n", studentid9);
		printf("				Programme              : %s\n", programme9);
		printf("				Tutorial Group         : %c\n", tutolialgroup9);
		printf("				Gender                 : %c\n", gender9);
		printf("				Current Semester       : %d\n", sem);
		printf("				Total Credit Hour      : %.2f\n\n", TCH9);

		printf("				Result of semester 1   : \n");
		printf("				Result of %s           : %.2f  / %c\n", sub1, grade1, resultsub1);
		printf("				Result of %s           : %.2f  / %s\n", sub2, grade2, resultsub2);
		printf("				Total Quality Point in Semester 1  :%.2f\n\n", tqps1);

		printf("				Work harder for your further study!\nGod bless you...\n");
	}

void KPKL22203() {
		//grade point
		float grade1 = 3.75, grade2 = 3.50, grade3 = 2.75, grade4 = 3.00;
		float tqps1 = 3.61, tqps2 = 2.84;

		//Current Semester
		int sem = 2;

		//result as Grade
		char resultsub1[3] = "A-";
		char resultsub2[3] = "B+";
		char resultsub3[3] = "B-";
		char resultsub4 = 'B';

		//result as Programme
		char programme10[4] = "DFT";

		//Student Name
		char name10[15] = "Stphen Hawking";
		char gender10 = 'M';
		char studentid10[10] = "KPKL22203";
		char sub1[8] = "AAA2000";
		char sub2[8] = "ABA1099";
		char sub3[8] = "ACC3001";
		char sub4[8] = "AXE3219";

		//result as Tutorial Group
		char tutolialgroup10 = '6';

		/*Total Credit Hour*/
		double TCH10 = 21;


		printf("\n\n				Student Name           : %s\n", name10);
		printf("				Student ID             : %s\n", studentid10);
		printf("				Programme              : %s\n", programme10);
		printf("				Tutorial Group         : %c\n", tutolialgroup10);
		printf("				Gender                 : %c\n", gender10);
		printf("				Current Semester       : %d\n", sem);
		printf("				Total Credit Hour      : %.2f\n\n", TCH10);
		printf("				Result of semester 1   : \n");
		printf("				Result of %s           : %.2f  / %s\n", sub1, grade1, resultsub1);
		printf("				Result of %s           : %.2f  / %s\n", sub2, grade2, resultsub2);
		printf("				Total Quality Point in Semester 1  :%.2f\n\n", tqps1);

		printf("				Result of semester 2   : \n");
		printf("				Result of %s           : %.2f  / %s\n", sub3, grade3, resultsub3);
		printf("				Result of %s           : %.2f  / %c\n", sub4, grade4, resultsub4);
		printf("				Total Quality Point in Semester 2  :%.2f\n\n", tqps2);

		printf("				Work harder for your further study!\nGod bless you...\n");
	}

void KPKL24101() {
		/*grade point*/
		float grade1 = 4.00, grade2 = 4.00, grade3 = 4.00, grade4 = 3.75, grade5 = 4.00, grade6 = 3.75;
		float tqps1 = 4.00, tqps2 = 3.91, tqps3 = 3.94;
		float cgpa = 3.94;
		/*Current Semester*/
		int sem = 3;
		/*result as Grade*/
		char resultsub1 = 'A';
		char resultsub2 = 'A';
		char resultsub3 = 'A';
		char resultsub4[3] = "A-";
		char resultsub5 = 'A';
		char resultsub6[3] = "A-";
		/*result as Programme*/
		char programme11[4] = "DFT";

		/*Student Name*/
		char name11[5] = "Boss";
		char gender11 = 'M';
		char studentid11[10] = "KPKL24101";
		char sub1[8] = "AAA2000";
		char sub2[8] = "ABA1099";
		char sub3[8] = "ACC3001";
		char sub4[8] = "AXE3219";
		char sub5[8] = "XHS1066";
		char sub6[8] = "XSD1314";

		/*result as Tutorial Group*/
		char tutolialgroup11 = '6';

		/*Total Credit Hour*/
		double TCH11 = 21;
		printf("\n\n				Student Name         : %s\n", name11);
		printf("				Student ID           : %s\n", studentid11);
		printf("				Programme            : %s\n", programme11);
		printf("				Tutorial Group       : %c\n", tutolialgroup11);
		printf("				Gender               : %c\n", gender11);
		printf("				Current Semester     : %d\n", sem);
		printf("				Total Credit Hour    : %.2f\n\n", TCH11);

		printf("				Result of semester 1 : \n");
		printf("				Result of %s         : %.2f  / %c\n", sub1, grade1, resultsub1);
		printf("				Result of %s         : %.2f  / %c\n", sub2, grade2, resultsub2);

		printf("				Result of semester 2 : \n");
		printf("				Result of %s         : %.2f  / %c\n", sub3, grade3, resultsub3);
		printf("				Result of %s         : %.2f  / %s\n", sub4, grade4, resultsub4);

		printf("				Result of semester 3 : \n");
		printf("				Result of %s         : %.2f  / %c\n", sub5, grade5, resultsub5);
		printf("				Result of %s         : %.2f  / %s\n", sub6, grade6, resultsub6);
		printf("				Ranking : 6/12\n");
		printf("				Keep hardworking on study.You are closed to success. \n\n");
	}

void KPKL24102() {
		/*grade point*/
		float grade1 = 4.00, grade2 = 4.00, grade3 = 4.00, grade4 = 4.00, grade5 = 4.00, grade6 = 4.00;
		float tqps1 = 4.00, tqps2 = 4.00, tqps3 = 4.00;
		float cgpa = 4.00;

		/*Current Semester*/
		int sem = 3;
		/*result as Grade*/
		char resultsub1 = 'A';
		char resultsub2 = 'A';
		char resultsub3 = 'A';
		char resultsub4 = 'A';
		char resultsub5 = 'A';
		char resultsub6 = 'A';

		/*result as Programme*/
		char programme12[4] = "DFT";

		/*Student Name*/
		char name12[5] = "Boum";
		char gender12 = 'M';
		char studentid12[10] = "KPKL24102";
		char sub1[8] = "AAA2000";
		char sub2[8] = "ABA1099";
		char sub3[8] = "ACC3001";
		char sub4[8] = "AXE3219";
		char sub5[8] = "XHS1066";
		char sub6[8] = "XSD1314";

		/*result as Tutorial Group*/
		char tutolialgroup12 = '6';

		/*Total Credit Hour*/
		double TCH12 = 21;

		printf("\n\n				Student Name         : %s\n", name12);
		printf("				Student ID           : %s\n", studentid12);
		printf("				Programme            : %s\n", programme12);
		printf("				Tutorial Group       : %c\n", tutolialgroup12);
		printf("				Gender               : %c\n", gender12);
		printf("				Current Semester     : %d\n", sem);
		printf("				Total Credit Hour    : %.2f\n\n", TCH12);

		printf("				Result of semester 1 : \n");
		printf("				Result of %s         : %.2f  / %c\n", sub1, grade1, resultsub1);
		printf("				Result of %s         : %.2f  / %c\n", sub2, grade2, resultsub2);
		printf("				Total Quality Point in Semester 1  :%.2f\n\n", tqps1);

		printf("				Result of semester 2 : \n");
		printf("				Result of %s         : %.2f  / %c\n", sub3, grade3, resultsub3);
		printf("				Result of %s         : %.2f  / %c\n", sub4, grade4, resultsub4);
		printf("				Total Quality Point in Semester 2  :%.2f\n\n", tqps2);

		printf("				Result of semester 3 : \n");
		printf("				Result of %s         : %.2f  / %c\n", sub5, grade5, resultsub5);
		printf("				Result of %s         : %.2f  / %c\n", sub6, grade6, resultsub6);
		printf("				Total Quality Point in Semester 1  :%.2f\n\n", tqps3);

		printf("				Cumulative Grade Point Average(CGPA) : %.2f\n", cgpa);
		printf("				Ranking : 1/12\n");
		printf("				Congratulation . Your are excellent on study!\n");
	}

void KPKL24103() {
		/*grade point*/
		float grade1 = 4.00, grade2 = 4.00, grade3 = 4.00, grade4 = 4.00, grade5 = 4.00, grade6 = 4.00;
		float tqps1 = 4.00, tqps2 = 4.00, tqps3 = 4.00;
		float cgpa = 4.00;

		/*Current Semester*/
		int sem = 3;

		/*result as Grade*/
		char resultsub1 = 'A';
		char resultsub2 = 'A';
		char resultsub3 = 'A';
		char resultsub4 = 'A';
		char resultsub5 = 'A';
		char resultsub6 = 'A';

		/*result as Programme*/
		char programme13[4] = "DFT";

		/*Student Name*/
		char name13[5] = "Prem";
		char gender13 = 'M';
		char studentid13[10] = "KPKL24103";
		char sub1[8] = "AAA2000";
		char sub2[8] = "ABA1099";
		char sub3[8] = "ACC3001";
		char sub4[8] = "AXE3219";
		char sub5[8] = "XHS1066";
		char sub6[8] = "XSD1314";

		/*result as Tutorial Group*/
		char tutolialgroup13 = '6';

		/*Total Credit Hour*/
		double TCH13 = 21;

		printf("\n\n				Student Name         : %s\n", name13);
		printf("				Student ID           : %s\n", studentid13);
		printf("				Programme            : %s\n", programme13);
		printf("				Tutorial Group       : %c\n", tutolialgroup13);
		printf("				Gender               : %c\n", gender13);
		printf("				Current Semester     : %d\n", sem);
		printf("				Total Credit Hour    : %.2f\n\n", TCH13);

		printf("				Result of semester 1 : \n");
		printf("				Result of %s         : %.2f  / %c\n", sub1, grade1, resultsub1);
		printf("				Result of %s         : %.2f  / %c\n", sub2, grade2, resultsub2);
		printf("				Total Quality Point in Semester 1  :%.2f\n\n", tqps1);

		printf("				Result of semester 2 : \n");
		printf("				Result of %s         : %.2f  / %c\n", sub3, grade3, resultsub3);
		printf("				Result of %s         : %.2f  / %c\n", sub4, grade4, resultsub4);
		printf("				Total Quality Point in Semester 2  :%.2f\n\n", tqps2);

		printf("				Result of semester 3 : \n");
		printf("				Result of %s         : %.2f  / %c\n", sub5, grade5, resultsub5);
		printf("				Result of %s         : %.2f  / %c\n", sub6, grade6, resultsub6);
		printf("				Total Quality Point in Semester 1  :%.2f\n\n", tqps3);

		printf("				Cumulative Grade Point Average(CGPA) : %.2f\n", cgpa);
		printf("				Ranking : 1/12\n");
		printf("				Congratulation . Your are excellent on study!\n");
	}

void KPKL24104() {
		/*grade point*/
		float grade1 = 2.00, grade2 = 2.00, grade3 = 2.50, grade4 = 0.00, grade5 = 0.00, grade6 = 2.00;
		float tqps1 = 2.00, tqps2 = 1.56, tqps3 = 0.37;
		float cgpa = 1.61;

		/*Current Semester*/
		int sem = 3;

		/*result as Grade*/
		char resultsub1 = 'C';
		char resultsub2 = 'C';
		char resultsub3[3] = "C+";
		char resultsub4 = 'F';
		char resultsub5 = 'F';
		char resultsub6 = 'C';

		/*result as Programme*/
		char programme14[4] = "DFT";

		/*Student Name*/
		char name14[10] = "Ivan Chua";
		char gender14 = 'M';
		char studentid14[10] = "KPKL24104";
		char sub1[8] = "AAA2000";
		char sub2[8] = "ABA1099";
		char sub3[8] = "ACC3001";
		char sub4[8] = "AXE3219";
		char sub5[8] = "XHS1066";
		char sub6[8] = "XSD1314";
		/*result as Tutorial Group*/
		char tutolialgroup14 = '6';

		/*Total Credit Hour*/
		double TCH14 = 19;

		printf("\n\n				Student Name         : %s\n", name14);
		printf("				Student ID           : %s\n", studentid14);
		printf("				Programme            : %s\n", programme14);
		printf("				Tuotorial Group      : %c\n", tutolialgroup14);
		printf("				Gender               : %c\n", gender14);
		printf("				Current Semester     : %d\n", sem);
		printf("				Total Credit Hour    : %.2f\n\n", TCH14);

		printf("				Result of semester 1 : \n");
		printf("				Result of %s         : %.2f  / %c\n", sub1, grade1, resultsub1);
		printf("				Result of %s         : %.2f  / %c\n", sub2, grade2, resultsub2);
		printf("				Total Quality Point in Semester 1  :%.2f\n\n", tqps1);

		printf("				Result of semester 2 : \n");
		printf("				Result of %s         : %.2f  / %s\n", sub3, grade3, resultsub3);
		printf("				Result of %s         : %.2f  / %c\n", sub4, grade4, resultsub4);
		printf("				Total Quality Point in Semester 2  :%.2f\n\n", tqps2);

		printf("				Result of semester 3 : \n");
		printf("				Result of %s         : %.2f  / %c\n", sub5, grade5, resultsub5);
		printf("				Result of %s         : %.2f  / %c\n", sub6, grade6, resultsub6);
		printf("				Total Quality Point in Semester 1  :%.2f\n\n", tqps3);

		printf("				Cumulative Grade Point Average(CGPA) : %.2f\n", cgpa);
		printf("				Ranking : 12/12\n");
		printf("				Regret to inform, you may need to retake the course to graduate.\n");
	}

void ranking() {
	system("cls");
	printf("-----------------------[RANKING]-----------------------\n");
	printf("                    1st:\n");
	for (int i = 0; i < 14; i++) {
		if (cgpa3[i] == 4.00)
		{
			printf("                    %s\n", namestud[i]);
			printf("                    %s\n", studIdstored[i]);
			printf("                    %.2f\n\n", cgpa3[i]);
		}
		else
			continue;
	}
	printf("                    6th:\n");
	for (int i = 0; i < 14; i++) {
		if (cgpa3[i] == 3.94)
		{
			printf("                    %s\n", namestud[i]);
			printf("                    %s\n", studIdstored[i]);
			printf("                    %.2f\n\n", cgpa3[i]);
		}
		else
			continue;
	}
	printf("                    7th:\n");
	for (int i = 0; i < 14; i++) {
		if (cgpa3[i] == 3.45)
		{
			printf("                    %s\n", namestud[i]);
			printf("                    %s\n", studIdstored[i]);
			printf("                    %.2f\n\n", cgpa3[i]);
		}
		else
			continue;
	}
	printf("                    8th:\n");
	for (int i = 0; i < 14; i++) {
		if (cgpa3[i] == 3.39)
		{
			printf("                    %s\n", namestud[i]);
			printf("                    %s\n", studIdstored[i]);
			printf("                    %.2f\n\n", cgpa3[i]);
		}
		else
			continue;
	}
	printf("                    9th:\n");
	for (int i = 0; i < 14; i++) {
		if (cgpa3[i] == 3.07)
		{
			printf("                    %s\n", namestud[i]);
			printf("                    %s\n", studIdstored[i]);
			printf("                    %.2f\n\n", cgpa3[i]);
		}
		else
			continue;
	}
	printf("                    10th:\n");
	for (int i = 0; i < 14; i++) {
		if (cgpa3[i] == 2.95)
		{
			printf("                    %s\n", namestud[i]);
			printf("                    %s\n", studIdstored[i]);
			printf("                    %.2f\n\n", cgpa3[i]);
		}
		else
			continue;
	}
	printf("                    11th:\n");
	for (int i = 0; i < 14; i++) {
		if (cgpa3[i] == 2.48)
		{
			printf("                    %s\n", namestud[i]);
			printf("                    %s\n", studIdstored[i]);
			printf("                    %.2f\n\n", cgpa3[i]);
		}
		else
			continue;
	}
	printf("                    12th:\n");
	for (int i = 0; i < 14; i++) {
		if (cgpa3[i] == 1.61)
		{
			printf("                    %s\n", namestud[i]);
			printf("                    %s\n", studIdstored[i]);
			printf("                    %.2f\n\n", cgpa3[i]);
		}
		else
			continue;
	}
}
