#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

void vote();
void homedisplay();
void admin();

struct vd
{
char name[20];
char age[20];
char address[20];
char contact[20];
char ano[20];
char gender[20];
char voteno[20];
};

void main()
{
	int choice;
	for(;;)
	{
		clrscr();
		homedisplay();
		printf("\n\nEnter your choice - ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: vote();
					break;
			case 2: admin();
					break;
			case 3: printf("\n\n*****THANK YOU*****");
					break;
			default: printf("\nInvalid choice...\n");
		}
		if (choice==3)
			break;
	}
	getch();
}

void admin()
{
	FILE *fp1=NULL;
	char filedata[1000];
	char word[105][20];
	int i,j,k,m,ad=0,kk=0,rr=0;
	long age;
	int count[13];
	char code[7];
	int choice1=0;
	memset(filedata,'\0',sizeof(filedata));
	memset(word,'\0',sizeof(word));
	fp1 = fopen("data.txt","r");
	clrscr();
	printf("\n*****RAJAHMUNDRY SARPANCH ELECTIONS 2021*****\n");
	printf("\n*****ADMIN SETTINGS*****\n\n");
	printf("Enter 'exit' to return to Home Screen...\n\n");
	printf("Enter admin code: ");
	scanf("%s",code);
	if (strcmp(code,"*******")==0)
	{
		printf("\n\n***CODE MATCHED***");
		getch();
		for(;;)
		{
		clrscr();
		printf("\n*****RAJAHMUNDRY SARPANCH ELECTIONS 2021*****\n");
		printf("\n*****ADMIN SETTINGS*****\n\n");
		printf("Enter your choice from menu : ");
		printf("\n");
		printf(" \n Enter 1 -> Display voter details");
		printf("\n----------------------------------");
		printf(" \n Enter 2 -> Candidate Vote Statistics");
		printf("\n----------------------------------");
		printf(" \n Enter 3 -> Exit to Home Screen");
		printf("\n\nEnter your choice - ");
		scanf("%d",&choice1);
		fgets(filedata,1000,fp1);
		i=0;
		for (j=0; j<105; j++)
		{
			for (k=0; k<20; k++)
			{
				if(filedata[i]!='_')
				{
					word[j][k] = filedata[i];
					i++;
				}
				else
				{
					age = atol(word[j]);
					if(age<=99 && age>=19 && age/10!=0)
					{
						word[j][k] = ' ';
						word[j][k+1] = ' ';
						word[j][k+2] = ' ';
						word[j][k+3] = '\0';
						i++;
						break;
					}
					age = word[j][9] - '0';
					if (age<=9 && age>=0)
					{
						word[j][k] = ' ';
						word[j][k+1] = ' ';
						word[j][k+2] = ' ';
						word[j][k+3] = '\0';
						i++;
						break;
					}
					else if(strlen(word[j])==1)
					{
						word[j][k] = '\0';
						i++;
						break;
					}
					else
					{
						if(k==19)
						{
							word[j][k]='\0';
							i++;
							break;
						}
						else
							word[j][k]=' ';
					}
				}
			}
			if (filedata[i]=='\0')
				break;
		}
		switch(choice1)
		{
			case 1: clrscr();
					printf("NAME               ");
					printf("AGE  ");
					printf("ADDRESS            ");
					printf("CONTACT NO.  ");
					printf("AADHAAR NO.    ");
					printf("GENDER  ");
					printf("\n--------------------------------------------------------------------------------\n");
					for (j=0; j<105; j++)
					{
						if (strcmp(word[j],"M")==0 || strcmp(word[j],"F")==0)
						{
							printf("%s",word[j]);
							printf("\n\n");
						}
						else if (strcmp(word[j],"1")==0 || strcmp(word[j],"2")==0 || strcmp(word[j],"3")==0)
							continue;
						else if (word[j]==NULL)
							break;
						else
							printf("%s",word[j]);
					}
					getch();
					break;
			case 2: m=6; i=0;
					clrscr();
					while (i<15)
					{
						count[i] = word[m][0] - '0';
						i++;
						m = m + 7;
					}
					for (i=0; i<15; i++)
					{
						if (count[i]==1)
							ad++;
						else if (count[i]==2)
							kk++;
						else if (count[i]==3)
							rr++;
						else
							continue;
					 }
					printf("\n*****RAJAHMUNDRY SARPANCH ELECTIONS 2021*****\n\n");
					printf("CANDIDATE NAME     ");
					printf("VOTE COUNT\n\n");
					printf("--------------------------------------\n");
					printf("Arjun Dhara         %d\n\n",ad);
					printf("Krishna Kumar       %d\n\n",kk);
					printf("Rambabu Reddy       %d\n\n",rr);
					printf("\n\nLeading candidate = ");
					m = (ad>kk)?((ad>rr)?ad:rr):((kk>rr)?kk:rr);
					if (m==ad)
						printf("Arjun Dhara");
					else if (m==kk)
						printf("Krishna Kumar");
					else
						printf("Rambabu Reddy");
					getch();
					break;
			case 3: printf("\n\nExiting admin settings...");
					break;
			default: printf("\nInvalid choice...\n");
				     getch();
					 break;
		}
		if(choice1==3)
			break;
		}
	}
	else if (strcmp(code,"exit")==0)
	{
		printf("\n\nExiting admin settings...");
	}
	else
	{
		printf("\n\n***INVALID CODE***");
		printf("\n\n***TRY AGAIN***");
		getch();
	}
	fclose(fp1);
}

void homedisplay()
{
	clrscr();
	printf("\n*****RAJAHMUNDRY SARPANCH ELECTIONS 2021*****\n");
	printf("Enter your choice from menu : ");
	printf("\n");
	printf(" \n Enter 1 -> Cast a vote");
	printf("\n---------------------------");
	printf(" \n Enter 2 -> Admin Settings");
	printf("\n---------------------------");
	printf(" \n Enter 3 -> Exit");
}

void vote()
{
	FILE *fp = NULL;
	char temp;
	long convert;
	struct vd input;
	fp = fopen("data.txt","a");
	clrscr();
	printf("\n*****RAJAHMUNDRY SARPANCH ELECTIONS 2021*****\n\n");
	printf("\n*****CAST A VOTE*****\n\n");
	printf("Nominated Candidates are : ");
	printf("\n");
	printf(" \n Enter 1 -> Arjun Dhara");
	printf("\n---------------------------");
	printf(" \n Enter 2 -> Krishna Kumar");
	printf("\n---------------------------");
	printf(" \n Enter 3 -> Rambabu Reddy");
	printf("\n\n\n");
	printf("*****Voter Details*****\n\n");
	printf("Enter Name: ");
	scanf("%c",&temp);
	gets(input.name);
	printf("Enter Age: ");
	scanf("%s",input.age);
	convert = atol(input.age);
	if(convert<=18)
	{
		printf("Sorry..You aren't eligible to vote...");
		printf("\n****THANK YOU****");
		getch();
		exit(0);
	}
	if(convert>999)
	{
		printf("Invalid Age...");
		printf("\n\nEnter Age: ");
		scanf("%s",input.age);
	}
	printf("Enter Address: ");
	scanf("%c",&temp);
	gets(input.address);
	printf("Enter Contact No.: ");
	scanf("%s",input.contact);
	if(input.contact[10]!='\0'|| input.contact[9]=='\0' || input.contact[8]=='\0')
	{
		printf("Invalid Contact Number...");
		printf("\n\nEnter Contact No.: ");
		scanf("%s",input.contact);
	}
	printf("Enter Aadhaar number: ");
	scanf("%s",input.ano);
	if(input.ano[12]!='\0')
	{
		printf("Invalid Aadhaar number...");
		printf("\n\nEnter Aadhaar number: ");
		scanf("%s",input.ano);
	}
	printf("Enter gender (M or F): ");
	scanf("%s",input.gender);
	if(input.gender[1]!='\0')
	{
		printf("Invalid Gender...");
		printf("\n\nEnter Gender: ");
		scanf("%s",input.gender);
	}
	printf("Enter candidate number to cast your vote: ");
	scanf("%s",input.voteno);
	convert = atol(input.voteno);
	if(convert>3 || convert<1)
	{
		printf("Invalid Candidate number...");
		printf("\n\nEnter candidate number to cast your vote: ");
		scanf("%s",input.voteno);
	}
	printf("\n\n****YOUR VOTE HAS BEEN RECORDED****");
	printf("\n****THANK YOU****");
	fputs(input.name,fp);
	fputs("_",fp);
	fputs(input.age,fp);
	fputs("_",fp);
	fputs(input.address,fp);
	fputs("_",fp);
	fputs(input.contact,fp);
	fputs("_",fp);
	fputs(input.ano,fp);
	fputs("_",fp);
	fputs(input.gender,fp);
	fputs("_",fp);
	fputs(input.voteno,fp);
	fputs("_",fp);
	fclose(fp);
	printf("\n\nEnter 1 -> Home Screen\n\n");
	scanf("%ld",&convert);
}
