//Admission Management System

#include"stdio.h"
#include"string.h"
#include"stdlib.h"
#include"conio.h"
#include"func13.c"

int main()
{
int i,j,c=0,dist,tns,n,bld,ent,sib;
char ch,bg[3],pe[10];
printf("\tEnter the number of Entries you want to Insert:: ");
scanf("%d",&ent);
clear();

printf("\n\t\tENTER DATABASE\n");
printf("\t\t--------------\n");
for(i=1;i<=ent;i++)	//for scanning
{
	printf("\n\t\t\tAdmission Entry No: %d",i);
	printf("\n______________________________________________________________________________________\n");
	name:
	printf("\tEnter student's name\t\t: ");
	scanf(" %[^\n]%*c",&ob[i].student_name);
	for(j=0;j<strlen(ob[i].student_name);j++)
	{
		if(ob[i].student_name[j]>=65 && ob[i].student_name[j]<=90 || ob[i].student_name[j]>=97 && ob[i].student_name[j]<=122 || ob[i].student_name[j]==32)
		{
			c+=1;
		}
		else
		{
			printf("\t\t-------Invalid Input!-------\n");
			goto name;
		}
	}c=0;
	if(c==strlen(ob[i].student_name))
		goto father;
	
	father:
	printf("\tEnter father's name\t\t: ");
	scanf(" %[^\n]%*c",&ob[i].father_name);
	for(j=0;j<strlen(ob[i].father_name);j++)
	{
		if(ob[i].father_name[j]>=65 && ob[i].father_name[j]<=90 || ob[i].father_name[j]>=97 && ob[i].father_name[j]<=122 || ob[i].father_name[j]==32)
		{
			c+=1;
		}
		else
		{
			printf("\t\t-------Invalid Input!-------\n");
			goto father;
		}
	}c=0;
	if(c==strlen(ob[i].student_name))
		goto address;
	
	address:
	printf("\tEnter Address\t\t\t: ");
	scanf(" %[^\n]*c",&ob[i].address);
	
	blood:
	printf("\n\t1.A+\n\t2.A-\n\t3.B+\n\t4.B-\n\t5.AB+\n\t6.AB-\n\t7.O+\n\t8.O-\n");
	printf("\tSelect you Blood Group\t: ");
	scanf("%d",&bld);
	if(bld==1)
		stpcpy(ob[i].bld_grp,"A+");
	else if(bld==2)
		stpcpy(ob[i].bld_grp,"A-");
	else if(bld==3)
		stpcpy(ob[i].bld_grp,"B+");
	else if(bld==4)
		stpcpy(ob[i].bld_grp,"B-");
	else if(bld==5)
		stpcpy(ob[i].bld_grp,"AB+");
	else if(bld==6)
		stpcpy(ob[i].bld_grp,"AB-");
	else if(bld==7)
		stpcpy(ob[i].bld_grp,"O+");
	else if(bld==8)
		stpcpy(ob[i].bld_grp,"O-");
	else
	{
		printf("\t\t-------Invalid Input!-------\n");
		goto blood;
	}
	
	sib:
	printf("\tEnter Sibling Status(y/n): ");
	sib=getche();
		if(sib=='y' || sib=='Y')
		{
			strcpy(ob[i].sibling,"yes");
			c+=1;
		}
		else if(sib=='N' || sib=='n')
		{
			strcpy(ob[i].sibling,"no");
			c+=1;
		}
		else
		{
			printf("\t\t-------Invalid Input!-------\n");
			goto sib;
		}c=0;
	//if(c==strlen(ob[i].sibling))
		//goto distance;
	
	distance:
	printf("\n\tEnter Distance between Home & School(in kms): ");
	//fgets(ob[i].schl_dist,100,stdin);
	scanf("%d",&ob[i].schl_dist);
	
	transport:
	printf("\n\tTRANSPORT Needed:--\t1.BUS\n\t\t\t\t2.VAN\n\t\t\t\t3.SELF\n\t\t\t\tEnter Transport Choice: ");
	scanf("%d",&tns);
	if(tns==1)
		stpcpy(ob[i].transport,"bus");
	else if(tns==2)
		stpcpy(ob[i].transport,"van");
	else if(tns==3)
		stpcpy(ob[i].transport,"self");
	else
	{
		printf("\t\t\n-------Invalid Input!-------\n");
			goto transport;
	}
	
	printf("\tEnter Parent Employment : ");
	scanf("%s",ob[i].prnt_employment);
	fflush(stdin);
	
	cont:
	printf("\tEnter Contact number(10 digit): +91 ");
	scanf("%s",&ob[i].contact);
	if(strlen(ob[i].contact)!=10)
	{
		printf("\t\t-------Please Enter 10 digits-------\n");
		goto cont;
	}
	printf("\n");
}
clear();
//===============================================================================================================
//-----------------------------------------DATABASE--------------------------------------------------------------
printf("\n\t\tDatabase\n");
printf("\t\t--------\n");
for(i=1;i<=ent;i++)
{
	display(i);
}
filter:
printf("\n--------------------Filtration Menu--------------------\n");
printf("1.Sibling Status\n2.Transport\n3.Blood Group\n4.Parent Employment\n5.Distance(Home-School)\n6.Display List");
printf("\nEnter type of filtration: ");
scanf("%d",&n);

	if(n==1)	//Sibling
	{
	p:	printf("\nEnter Sibling Status for search:-  1.Yes\t2.No\nEnter your choice: ");
		scanf("%d",&sib);
		if(sib==1)
		{
			for(i=1;i<=ent;i++)
			{
				if(strcmp(ob[i].sibling,"yes")==0)
					display(i);
				//else
					//printf("\t---NO Records!---");
			}
		}
		else if(sib==2)
		{
			for(i=1;i<=ent;i++)
			{
				if(strcmp(ob[i].sibling,"no")==0)
					display(i);
				//else
					//printf("\t---NO Records!---");
			}
		}

		else
		{
			printf("-------------Invalid Choice!--------------\n");
			goto p;
		}
	}
	
	else if(n==2)	//transport
	{
		trans:
		printf("\nEnter type of Transport for search(bus/van/self): ");
		printf("\n1.Bus\n2.Van\n3.Self\n\nEnter Your Choice: ");
		scanf("%d",&tns);
		if(tns>0 && tns<4)
		{
			for(i=1;i<=ent;i++)
			{
				if(tns==1 && strcmp(ob[i].transport,"bus")==0)
				{
					display(i);
				}
				else if(tns==2 && strcmp(ob[i].transport,"van")==0)
				{
					display(i);
				}
				else if(tns==3 && strcmp(ob[i].transport,"self")==0)
				{
					display(i);
				}
			}
		}
		else
		{
			printf("-------------Invalid Choice!--------------\n");
			goto trans;
		}
	}
	else if(n==3)	//Blood Group
	{
		printf("\nEnter Blood Group for search(A+/A-/B+/B-/O+/O-): ");
		scanf("%s",&bg);
		for(i=1;i<=ent;i++)
		{
			if(strcmp(ob[i].bld_grp,bg)==0)
			{
				display(i);
			}
		}
	}
	else if(n==4)	//Parent Employment
	{
		printf("\nEnter Parent Employment for search: ");
		scanf("%s",&pe);
		for(i=1;i<=ent;i++)
		{
			if(strcmp(ob[i].prnt_employment,pe)==0)
			{
				display(i);
			}
		}
	}
	else if(n==5)	//Distance
	{
		printf("\nEnter Maximum Distance (in kms): ");
		scanf("%d",&dist);
		for(i=1;i<=ent;i++)
		{
			if(ob[i].schl_dist < dist)
			{
				display(i);
			}
		}
	}
	else if(n==6)
	{
		for(i=1;i<=ent;i++)
		{
			display(i);
		}
	}
	else
	{
		printf("\t----------Invalid Choice!-------\n\n");
		goto filter;
	}
	
printf("\nDo you want to search again? (Y/N):");
ch=getche();
if(ch=='Y' ||  ch=='y')
{
	fflush(stdin);
	goto filter;
}
else
	exit(0); 
}