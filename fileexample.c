#include <stdio.h>
#include <windows.h>

//示例读写操作程序，可能部分编程风格不合要求

//1.只读方式打开一个不存在的文件，fp无效
/*#include <stdio.h>
void main()
{
	char str[512];
	FILE  *fp;
		fp = fopen("test.txt","r");
	if(!fp)
		return;
	fscanf(fp, "%s", str);
	printf("%s\n", str);

	fclose(fp);
}*/

//2.写文件方式创建一个不存在的文件，写入成功，text.txt文件在当前c文件所在文件夹
/*#include <stdio.h>
void main()
{
	char str[] = "this is a test!";
	FILE  *fp;
		fp = fopen("test1.txt","wb");
	if(!fp)
		return;
	fprintf(fp,"%s",str);
	fclose(fp);
}
*/

//3.写文件方式打开一个有数据的文件，写入新数据成功，text.txt文件原有数据被清空
/*
#include <stdio.h>
void main()
{
	char str[] = "new write!";
	FILE  *fp;
		//fp = fopen("test.txt","w");//清空原有数据
		fp = fopen("test.txt","a");//保留原有数据
	if(!fp)
		return;
	fprintf(fp,"%s",str);
	fclose(fp);
}
*/

/*
//3.1写结构体变量,"%d"和"%d "对读入造成的影响不同 
#include <stdio.h>
void main()
{
	FILE* fp;               //定义一个文件
	fp = fopen("p5.txt", "wb+");

	int arr[5] = { 1,2,3,4,5 };
	for (int i = 0; i < 5; i++)
		fprintf(fp,"%d", arr[i]);//对读出造成影响 
		//fprintf(fp,"%d ", arr[i]);//%d加上空格后，才可以正确读出 

	fclose(fp);
	fp = fopen("p5.txt", "rb+");

	int x[5] = { 0 };
	int i = 0;
	while (fscanf(fp, "%d", &x[i])==1)//!feof(fp)
	{
		i++;
	}
	fclose(fp);

	for ( i = 0; i < 5; i++)
		printf("%d\t", x[i]);

} */


/*
//4.写文件后不关闭文件，直接读
#define N 512
#include <stdio.h>

void main()
{
	char str1[N]="this is example 4!";
	char str2[N];
	int actlen=0;
	//1.首先观察以wb方式是否可以写完就读
	FILE  *fp;
		fp = fopen("test.txt","wb");//错误方式
		//fp = fopen("test.txt","wb+");//正确方式
	if(!fp)
		return;
		
	fputs(str1,fp);

	//2.随后在wb+模式下，注释掉rewind观察影响，数据无法正常读出
	rewind(fp);
	fgets(str2,N,fp);
	printf("Now print ...\n");
	puts(str2);
	fclose(fp);

	system("Pause!");
}
*/

//5.
/*
#include <stdio.h>
#define N 10
void main()
{
	int narr[N] ={11,22,3,4,5,6,7,8,9,10};
	int narrout[N]={0};
	FILE  *fp;
	int n,i;
	fp = fopen("try.txt","wb+");//清空原有数据
	if(!fp)
		return;

	//写入
	n = fwrite(narr,sizeof(int),N,fp);

	//读出
	rewind(fp);
	n = fread(&narrout[0],sizeof(int),N*2,fp);//尝试读出2倍长度的数据
	
	//屏幕输出
	printf("Now print ...\n");
	for(i = 0; i < N; i++)
	{
		printf("%d\t",narrout[i]);
	}
	fclose(fp);
	system("Pause");
}

*/

/*
//6.
#include <stdio.h>
#define N 10
BOOL filew(char *filename);
void main()
{
	int narr[N] ={11,22,3,4,5,6,7,8,9,10};
	int narrout[N]={0};
	FILE  *fp;
	int n,i;
	BOOL bwok = FALSE;//默认写失败 
    bwok = filew("try.txt");
	if(!bwok)//写失败
		return;

	//读操作
	fp = fopen("try.txt","rb");
	if(!fp)
		return;
		
	printf("Now print ...\n");
	//在不知道知道长度N时可以这样读取
	i=0;
	while(fread(&narrout[i],sizeof(int),1,fp)==1)
	{
		printf("%d\t",narrout[i]);
		i++;
	}
	//*************************///
	/*///在已经知道长度N时可以这样读取
	for(i = 0; i < N; i++)
	{
		fread(&narrout[i],sizeof(int),1,fp);//示例循环读
		printf("%d\t",narrout[i]);
	}*/
	//*************************
//	fclose(fp);
//}
/*
BOOL filew(char *filename)
{
	FILE  *fp;
	int n,i;
	int narr[N] ={11,22,3,4,5,6,7,8,9,10};
	fp = fopen(filename,"wb");//保留原有数据
	if(!fp)
		return FALSE;
	n = fwrite(narr,sizeof(int),N,fp);
	fclose(fp);
	return TRUE;
}
*/




//7-0.
//正确程序
//知道确定数组长度时，可以整体读出；
//在不确定数组长度时，但该数组为文件中的最后一个数据块，也可以整体读出
#include <string.h>
#include <stdio.h>
#define N 10
#define M 20
void main()
{
	int narr[N] ={11,22,3,4,5,6,7,8,9,10};
	int narrout[N]={0};
	char str[]="this is example 8!";
	char strout[M];
	FILE  *fp;
	int n,i;
	//写数组
	fp = fopen("try.txt","wb");
	if(!fp)
		return;
	n = fwrite(narr,sizeof(int),N,fp);
	fclose(fp);

	//写字符串
	fp = fopen("try.txt","a+");//保留原有数据
	if(!fp)
		return;
	n = fwrite(str,sizeof(char),strlen(str),fp);
	fclose(fp);
	
	//读操作
	fp = fopen("try.txt","rb");
	if(!fp)
		return;
	n = fread(narrout,sizeof(int),N,fp);


	//1、调试观察n和M是否相等，n表示什么？
    //不相等，希望读出M=20个，但实际的写入是18个字符
	n = fread(strout,sizeof(char),M,fp);
	//2、下面一句注销,则不是字符串，而是字符数组，不可以用puts
	strout[n] = '\0';
	printf("Now print ...\n");
	for(i = 0; i < 10; i++)
	{
		printf("%d\t",narrout[i]);
	}
	printf("\noutput %d characters:",n);
	puts(strout);
	fclose(fp);

	system("Pause");
}

/*
//7-1
//错误程序示范
//在不确定数组长度时，且该数组不是文件中的最后一个数据块，数据无法正确读出
#include <string.h>
#include <stdio.h>
#define N 10
#define M 20
void main()
{
	int narr[N] ={11,22,3,4,5,6,7,8,9,10};
	int narrout[N]={0};
	char str[]="this is example 8!";
	char strout[M];
	FILE  *fp;
	int n,i;

	//写字符串
	fp = fopen("try.txt","a+");//保留原有数据
	if(!fp)
		return;
	n = fwrite(str,sizeof(char),strlen(str),fp);
	fclose(fp);

	//写数组
	fp = fopen("try.txt","wb");
	if(!fp)
		return;
	n = fwrite(narr,sizeof(int),N,fp);
	fclose(fp);

	
	
	//读操作：先读字符串后读数组
	fp = fopen("try.txt","rb");
	if(!fp)
		return;
	//1、调试观察n和M是否相等，n表示什么？
    //相等，实际的写入是18个字符，然后将后面的写入的整数数组中的部分数据读入了
	n = fread(strout,sizeof(char),M,fp);

	//分次读，依然不可能正确，i将>20
	//i=0;
	//while(fread(&strout[i],sizeof(char),1,fp)==1)
	//	i++;
	
	strout[19] = '\0';

	//2、由于读字符串的操作使得文件内部指针移动过数组的0号元素位置，所以无法读出10个元素
	//n< N 
	n = fread(narrout,sizeof(int),N,fp);
	
	
	printf("Now print ...\n");
	for(i = 0; i < 10; i++)
	{
		printf("%d\t",narrout[i]);
	}
	printf("\noutput %d characters:",n);
	puts(strout);
	fclose(fp);

	system("Pause");
}
*/

/*
#include <string.h>
#include <stdio.h>
void main()//work properly
{
	FILE *fa = NULL;
	fa=fopen("a.txt","a+");//"a"
	
	if(fa != NULL)
	{
		while(!(feof(fa)))//判断文件是否结束
			printf("%c",fgetc(fa));
	}
	else
		return;
	
	fclose(fa);
}
*/

/*
#include <stdio.h>
#define N 10
BOOL filew(char *filename);
void main()
{
	int narr[N] ={11,22,3,4,5,6,7,8,9,10};
	int narrout[N]={0};
	FILE  *fp;
	int n,i; 

	fp = fopen("try.txt","w+");
	if(!fwrite(narr,sizeof(int),N,fp))//写失败
		return;

	//读操作
	rewind(fp);
		
	printf("Now print ...\n");
	//在不知道知道长度N时可以这样读取
	i=0;
	//*********方法1********************/
/*	while(fread(&narrout[i],sizeof(int),1,fp)==1)
	{
		printf("%d\t",narrout[i]);
		i++;
	}
	//未知长度情况下，读数组
	//*********方法2********************/
/*	fread(&narrout[i],sizeof(int),1,fp);//这句如果注释掉则会多输出一个无用字符
	while(!feof(fp))
	{
		fread(&narrout[i],sizeof(int),1,fp);
		printf("%d\t",narrout[i]);
		i++;
	}	
	//*********方法3********************/
/*	while(!feof(fp))
	{
		n=fread(&narrout[i],sizeof(int),1,fp);
		if(n!=1)
		{
			printf("%d\t",narrout[i]);
			i++;
		}
	}


	fclose(fp);
}

*/
