#include <stdio.h>
#include <windows.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS 1

#define NUM 3
#define FLUSH while(getchar()!='\n')

typedef struct {
	int nID;
	char name[20];
	int nscore[3];
}STUDENT;


STUDENT InputStuInfo();
void PrintAllInfo(STUDENT stu[],int nlen);
void PrintSingleInfo(STUDENT stu);

void SortStuInfobyID(STUDENT stu[],int size);
void SortStuInfobyName(STUDENT stu[],int size);

int SearchbyID(STUDENT stu[],int nlen);
int SearchbyName(STUDENT stu[],int nlen);

void Insert(STUDENT stu[],int maxlen,int *pcnt);
void DelbyID(STUDENT stu[],int *pcnt);

int WritetoFile(const STUDENT stu[], int cnt);
int ReadfromFile(STUDENT stu[], int* pcnt);


void main()
{
	STUDENT stu[NUM];//= { {1000,{'c'},{30,30,30}},{800,'b',90,90,90},{1100,'a',100,100,100} };
	
	//memset(stu,0,NUM*sizeof(STUDENT));
	int count=0;//学生人数
	int i = 0;
	int choice;

	ReadfromFile(stu, &count);

	while(1)
	{
		puts("------------Welcome to student information management system--------------.\n\n");
		puts("1.Insert\n2.SortByID\n3.SortByName\n4.SearchByID\n5.SearchByName\n6.DeleteByID\n7.PrintAll\n8.Write&Exit\n");
		puts("Please select a service: ");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:
				Insert(stu,NUM,&count);
				system("Pause");
				break;
			case 2:
				SortStuInfobyID(stu,count);
				system("Pause");
				break;
			case 3:
				SortStuInfobyName(stu,count);
				system("Pause");
				break;
			case 4:
				SearchbyID(stu,count);
				system("Pause");
				break;
			case 5:
				SearchbyName(stu,count);
				system("Pause");
				break;
			case 6:
				DelbyID(stu,&count);
				system("Pause");
				break;
			case 7:
				PrintAllInfo(stu,count);
				system("Pause");
				break;
			case 8:
				WritetoFile(stu, count);
				return;
		}
		system("CLS");
	 } 
}

void Insert(STUDENT stu[],int maxlen,int *pcnt)
{
	if(*pcnt>=maxlen)
	{
		puts("Reach the max length of the student array!\n");
		return;
	}
	stu[*pcnt]=InputStuInfo();
	(*pcnt)++;
}

STUDENT InputStuInfo()
{
	STUDENT stutemp;
	printf("input a student id(<= 5 bits):");
	do
	{
		scanf("%5d",&stutemp.nID);
	}while(stutemp.nID<=0);
	FLUSH;
	printf("\ninput a student name contain no more than 19 characters:");
	gets(stutemp.name);
	FLUSH;
	printf("\ninput 3 scores:");
	do
	{
		scanf("%d%d%d",&stutemp.nscore[0],&stutemp.nscore[1],&stutemp.nscore[2]);
	}while(stutemp.nscore[0]<0 || stutemp.nscore[1]<0 ||stutemp.nscore[2]<0);
	getchar();
	printf("\n");
	return stutemp;
}

void PrintAllInfo(STUDENT stu[],int nlen)
{
	int i = 0;
	int nstunum = 0;
	for(; i < nlen; i++)
	{
		nstunum++;
		PrintSingleInfo(stu[i]);
	}
	printf("Totoally %d students information printed!\n",nstunum);
}

//为了打印单条记录修改原来程序结构
void PrintSingleInfo(STUDENT stu)
{

//if(stu.nID != 0)//防止非正常记录被打印
	{
		printf("student ID=%5d,name=%19s,score={%3d,%3d,%3d}\n",stu.nID,\
		stu.name,stu.nscore[0],stu.nscore[1],stu.nscore[2]);
	}
}

void SortStuInfobyName(STUDENT stu[],int size)
{
		STUDENT temp;
	   unsigned int pass;
	   unsigned int i;
	   for (pass = 1; pass < size; ++pass) {                                      
	        for (i = 0; i < size - pass; ++i) {  
				if (strcmp(stu[i].name,stu[i + 1].name)>0) {                        
	            temp = stu[i];                                   
	            stu[i] = stu[i + 1];                             
	            stu[i + 1] = temp;                               
	         }                                       
	      }                                   
	   }

}

void SortStuInfobyID(STUDENT stu[],int size)
{
		STUDENT temp;
	   unsigned int pass;
	   unsigned int i;
	   for (pass = 1; pass < size; ++pass) {                                      
	        for (i = 0; i < size - pass; ++i) { 
				
				if (stu[i].nID > stu[i + 1].nID) {                        
	            temp = stu[i];                                   
	            stu[i] = stu[i + 1];                             
	            stu[i + 1] = temp;                               
	         }                                       
	      }                                   
	   }

}

int SearchbyID(STUDENT stu[],int nlen)
{
	int i = 0;
	int id;
	puts("Please input the ID you want search: ");
	scanf("%d",&id);
	for(; i < nlen; i++)
	{
		if(stu[i].nID == id)
		{
			puts("Find one record.\n");
			PrintSingleInfo(stu[i]);
			return i;			
		}
	}
	
	puts("ID not Found!\n");
	return -1;
}

int SearchbyName(STUDENT stu[],int nlen)
{
	int i = 0;
	char nm[20];
	puts("Please input the name you want search: ");
	scanf("%s",nm);
	for(; i < nlen; i++)
	{
		if(strcmp(stu[i].name,nm) == 0)
		{
			puts("Find one record.\n");
			PrintSingleInfo(stu[i]);
			return i;			
		}
	}
	
	puts("ID not Found!\n");
	return -1;
}

void DelbyID(STUDENT stu[],int *pcnt)
{
	int index;
	index = SearchbyID(stu,*pcnt);
	if (index == -1) return;
	
	int ans;
	do{
		puts("Delete or not? 1 for yes ,0 for no:");
		scanf("%d",&ans);
	}while(ans !=0 && ans != 1);

	if(ans)
	{
		stu[index]=stu[*pcnt-1];
		(*pcnt)--;
	}
	
}

int WritetoFile(const STUDENT stu[], int cnt)
{
	FILE* fp;
	fp = fopen("stu.txt", "wb");
	if (!fp)
	{
		puts("Write to file failed!\n");
		return -1;
	}
	fwrite(stu, sizeof(STUDENT), cnt, fp);

	fclose(fp);
	return 0;
}

int ReadfromFile(STUDENT stu[], int* pcnt)
{
	FILE* fp;
	fp = fopen("stu.txt", "rb");
	if (!fp)
	{
		puts("Read from file failed!\n");
		return -1;
	}
	//arr应该足够大以容纳文件的所有数据
	int i = 0;
	while (fread(&stu[i], sizeof(STUDENT), 1, fp) == 1)//必须掌握
		i++;

	fclose(fp);

	*pcnt = i;
	return 0;
}