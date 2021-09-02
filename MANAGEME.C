#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>


void main()
{
    FILE *fp, *ft;
    char another, choice;
    char s[20],s2[30];
    int pass;


    struct emp
    {
	char name[40];
	int age;
	float bs;
	char mob[20];
    };

    struct emp e;

    char empname[40];

    long int recsize;


    fp = fopen("EMP.txt","rb+");
    if(fp == NULL)
    {
	fp = fopen("EMP.txt","wb+");
	if(fp == NULL)
	{
	    printf("Can't open file");
	    exit(1);
	}
    }


    recsize = sizeof(e);
    clrscr();
    l:
    fflush(stdin);
     printf("\nEnter UserName:");
     scanf("%s",s);
     fflush(stdin);
      printf("\nEnter PassWord:");
      scanf("%d",&pass);
      if((strcmp(s,"Admin")==0) && pass==1234)
      {
    clrscr();
   textcolor(LIGHTGREEN);
   printf("\n");
   cprintf("       **    **   *******  **       ******  ******  ****  ****  ******* ");
   printf("\n");
   cprintf("       **    **   **       **       **      **  **  **  *** **  **      ");
   printf("\n");
   cprintf("       ** ** **   ****     **       **      **  **  **  *** **  *****   ");
   printf("\n");
   cprintf("       ** ** **   **       **       **      **  **  **      **  **      ");
   printf("\n");
   cprintf("       ********   *******  *******  ******  ******  **      **  ******* ");

   printf("\n");
   textcolor(BROWN);
   printf("\n");
   cprintf("                              ********  ******                         ");
   printf("\n");
   cprintf("                                 **     *    *                         ");
   printf("\n");
   cprintf("                                 **     ******                         ");

   printf("\n");
   textcolor(LIGHTBLUE);
   printf("\n");
   cprintf("                   *************************************    ");
   textcolor(LIGHTRED);
   printf("\n");
   cprintf("                          EMPLOYEE MANAGMENT SYSTEM              ");
   textcolor(LIGHTBLUE);
   printf("\n");
   cprintf("                   *************************************    ");

   printf("\n\n");
   textcolor(WHITE);
   cprintf("                                   MADE BY                                    ");
   printf("\n\n");
   textcolor(YELLOW);
   cprintf("                            # # # # # # # # # # # # # # # #                   ");
   cprintf("                           #                             #                    ");
   textcolor(YELLOW+BLINK);
   cprintf("                           #         RAJPUT MO.SABBIR    #                     ");
   textcolor(YELLOW);
   cprintf("                           #                             #                      ");
   textcolor(YELLOW+BLINK);
   cprintf("                           #          SHAIKH MO.HANIF     #                       ");
   textcolor(YELLOW);
   cprintf("                           #                             #                        ");
   cprintf("                           # # # # # # # # # # # # # # # #                        ");

   textcolor(LIGHTGREEN);
   textcolor(LIGHTGREEN);
   cprintf(" Press Key ");
   getch();

   }
   else
   {
   printf("\nInvalid try Again!!...");
   getch();
   goto l;
   }
    while(1)
    {
	system("cls");
	gotoxy(30,10);
	printf("1. Add Record");
	gotoxy(30,12);
	printf("2. List Records");
	gotoxy(30,14);
	printf("3. Modify Records");
	gotoxy(30,16);
	printf("4. Delete Records");
	gotoxy(30,18);
	printf("5. Exit");
	gotoxy(30,20);
	printf("Your Choice: ");
	fflush(stdin);
	choice  = getche();
	switch(choice)
	{
	case '1':
	    clrscr();
	    fseek(fp,0,SEEK_END);


	    another = 'y';
	    while(another == 'y')
	    {
		printf("\nEnter name: ");
		scanf("%s",e.name);
		printf("\nEnter age: ");
		scanf("%d", &e.age);
		printf("\nEnter salary: ");
		scanf("%f", &e.bs);

		ab:
		printf("\nEnter mobile number: ");
		scanf("%s", &e.mob);

		if(strlen(e.mob)>10 || strlen(e.mob)<10)
		{
		printf("enter valid number !");
		goto ab;
		}

		fwrite(&e,recsize,1,fp);

		printf("\nAdd another record(y/n) ");
		fflush(stdin);
		another = getche();
	    }
	    break;
	case '2':
	    system("cls");
	    rewind(fp);
	    while(fread(&e,recsize,1,fp)==1)
	    {
		printf("\n%s \n%d \n%.2f \n%s",e.name,e.age,e.bs,e.mob);
	    }
	    getch();
	    break;

	case '3':
	    system("cls");
	    another = 'y';
	    while(another == 'y')
	    {
		printf("Enter the employee name to modify: ");
		scanf("%s", empname);
		rewind(fp);
		while(fread(&e,recsize,1,fp)==1)
		{
		    if(strcmp(e.name,empname) == 0)
		    {
			printf("\nEnter New Name: ");
			scanf("%s",e.name);
			printf("\nEnter New Age: ");
			scanf("%d", &e.age);
			printf("\nEnter New Salary: ");
			scanf("%f", &e.bs);

			b:
			printf("\nEnter Mobile Number: ");
			scanf("%s", &e.mob);

			if(strlen(e.mob)>10 || strlen(e.mob)<10)
			{
			printf("enter valid number !");
			goto b;
			}

			fseek(fp,-recsize,SEEK_CUR);
			fwrite(&e,recsize,1,fp);
			break;
		    }
		}
		printf("\nModify another record(y/n)");
		fflush(stdin);
		another = getche();
	    }
	    break;
	case '4':
	    system("cls");
	    another = 'y';
	    while(another == 'y')
	    {
		printf("\nEnter name of employee to delete: ");
		scanf("%s",empname);
		ft = fopen("Temp.dat","wb");
		rewind(fp);
		while(fread(&e,recsize,1,fp) == 1)
		{
		    if(strcmp(e.name,empname) != 0)
		    {
			fwrite(&e,recsize,1,ft);
		    }
		}
		fclose(fp);
		fclose(ft);
		remove("EMP.txt");
		rename("Temp.dat","EMP.txt");
		fp = fopen("EMP.Txt", "rb+");
		printf("Delete another record(y/n)");
		fflush(stdin);
		another = getche();
	    }
	    break;
	case '5':
	    fclose(fp);
	    exit(0);
	}
    }



}
