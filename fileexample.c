#include <stdio.h>
#include <windows.h>

//ʾ����д�������򣬿��ܲ��ֱ�̷�񲻺�Ҫ��

//1.ֻ����ʽ��һ�������ڵ��ļ���fp��Ч
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

//2.д�ļ���ʽ����һ�������ڵ��ļ���д��ɹ���text.txt�ļ��ڵ�ǰc�ļ������ļ���
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

//3.д�ļ���ʽ��һ�������ݵ��ļ���д�������ݳɹ���text.txt�ļ�ԭ�����ݱ����
/*
#include <stdio.h>
void main()
{
	char str[] = "new write!";
	FILE  *fp;
		//fp = fopen("test.txt","w");//���ԭ������
		fp = fopen("test.txt","a");//����ԭ������
	if(!fp)
		return;
	fprintf(fp,"%s",str);
	fclose(fp);
}
*/

/*
//3.1д�ṹ�����,"%d"��"%d "�Զ�����ɵ�Ӱ�첻ͬ 
#include <stdio.h>
void main()
{
	FILE* fp;               //����һ���ļ�
	fp = fopen("p5.txt", "wb+");

	int arr[5] = { 1,2,3,4,5 };
	for (int i = 0; i < 5; i++)
		fprintf(fp,"%d", arr[i]);//�Զ������Ӱ�� 
		//fprintf(fp,"%d ", arr[i]);//%d���Ͽո�󣬲ſ�����ȷ���� 

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
//4.д�ļ��󲻹ر��ļ���ֱ�Ӷ�
#define N 512
#include <stdio.h>

void main()
{
	char str1[N]="this is example 4!";
	char str2[N];
	int actlen=0;
	//1.���ȹ۲���wb��ʽ�Ƿ����д��Ͷ�
	FILE  *fp;
		fp = fopen("test.txt","wb");//����ʽ
		//fp = fopen("test.txt","wb+");//��ȷ��ʽ
	if(!fp)
		return;
		
	fputs(str1,fp);

	//2.�����wb+ģʽ�£�ע�͵�rewind�۲�Ӱ�죬�����޷���������
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
	fp = fopen("try.txt","wb+");//���ԭ������
	if(!fp)
		return;

	//д��
	n = fwrite(narr,sizeof(int),N,fp);

	//����
	rewind(fp);
	n = fread(&narrout[0],sizeof(int),N*2,fp);//���Զ���2�����ȵ�����
	
	//��Ļ���
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
	BOOL bwok = FALSE;//Ĭ��дʧ�� 
    bwok = filew("try.txt");
	if(!bwok)//дʧ��
		return;

	//������
	fp = fopen("try.txt","rb");
	if(!fp)
		return;
		
	printf("Now print ...\n");
	//�ڲ�֪��֪������Nʱ����������ȡ
	i=0;
	while(fread(&narrout[i],sizeof(int),1,fp)==1)
	{
		printf("%d\t",narrout[i]);
		i++;
	}
	//*************************///
	/*///���Ѿ�֪������Nʱ����������ȡ
	for(i = 0; i < N; i++)
	{
		fread(&narrout[i],sizeof(int),1,fp);//ʾ��ѭ����
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
	fp = fopen(filename,"wb");//����ԭ������
	if(!fp)
		return FALSE;
	n = fwrite(narr,sizeof(int),N,fp);
	fclose(fp);
	return TRUE;
}
*/




//7-0.
//��ȷ����
//֪��ȷ�����鳤��ʱ���������������
//�ڲ�ȷ�����鳤��ʱ����������Ϊ�ļ��е����һ�����ݿ飬Ҳ�����������
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
	//д����
	fp = fopen("try.txt","wb");
	if(!fp)
		return;
	n = fwrite(narr,sizeof(int),N,fp);
	fclose(fp);

	//д�ַ���
	fp = fopen("try.txt","a+");//����ԭ������
	if(!fp)
		return;
	n = fwrite(str,sizeof(char),strlen(str),fp);
	fclose(fp);
	
	//������
	fp = fopen("try.txt","rb");
	if(!fp)
		return;
	n = fread(narrout,sizeof(int),N,fp);


	//1�����Թ۲�n��M�Ƿ���ȣ�n��ʾʲô��
    //����ȣ�ϣ������M=20������ʵ�ʵ�д����18���ַ�
	n = fread(strout,sizeof(char),M,fp);
	//2������һ��ע��,�����ַ����������ַ����飬��������puts
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
//�������ʾ��
//�ڲ�ȷ�����鳤��ʱ���Ҹ����鲻���ļ��е����һ�����ݿ飬�����޷���ȷ����
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

	//д�ַ���
	fp = fopen("try.txt","a+");//����ԭ������
	if(!fp)
		return;
	n = fwrite(str,sizeof(char),strlen(str),fp);
	fclose(fp);

	//д����
	fp = fopen("try.txt","wb");
	if(!fp)
		return;
	n = fwrite(narr,sizeof(int),N,fp);
	fclose(fp);

	
	
	//���������ȶ��ַ����������
	fp = fopen("try.txt","rb");
	if(!fp)
		return;
	//1�����Թ۲�n��M�Ƿ���ȣ�n��ʾʲô��
    //��ȣ�ʵ�ʵ�д����18���ַ���Ȼ�󽫺����д������������еĲ������ݶ�����
	n = fread(strout,sizeof(char),M,fp);

	//�ִζ�����Ȼ��������ȷ��i��>20
	//i=0;
	//while(fread(&strout[i],sizeof(char),1,fp)==1)
	//	i++;
	
	strout[19] = '\0';

	//2�����ڶ��ַ����Ĳ���ʹ���ļ��ڲ�ָ���ƶ��������0��Ԫ��λ�ã������޷�����10��Ԫ��
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
		while(!(feof(fa)))//�ж��ļ��Ƿ����
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
	if(!fwrite(narr,sizeof(int),N,fp))//дʧ��
		return;

	//������
	rewind(fp);
		
	printf("Now print ...\n");
	//�ڲ�֪��֪������Nʱ����������ȡ
	i=0;
	//*********����1********************/
/*	while(fread(&narrout[i],sizeof(int),1,fp)==1)
	{
		printf("%d\t",narrout[i]);
		i++;
	}
	//δ֪��������£�������
	//*********����2********************/
/*	fread(&narrout[i],sizeof(int),1,fp);//������ע�͵��������һ�������ַ�
	while(!feof(fp))
	{
		fread(&narrout[i],sizeof(int),1,fp);
		printf("%d\t",narrout[i]);
		i++;
	}	
	//*********����3********************/
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
