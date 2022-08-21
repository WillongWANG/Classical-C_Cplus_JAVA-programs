#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//����һ��4λ����ÿ�����ֲ�ͬ0~9
void generatemagicabcd(int *,int *,int *, int *);
//��ȡǧλ����
int getthousand(int);
//��ȡ��λ����
int gethundred(int);
//��ȡʮλ����
int getten(int);
//��ȡ��λ����
int getone(int);
void main()
{
	int imaga,imagb,imagc,imagd;//magic number abcd
	int i = 0;
	int iuserdata = 0;
	int iuserth=0,iuserh=0,iusert=0,iusero=0;//�û���ǧ�ٸ�ʮλ
	int A=0;//λ����ȷ��������ȷ�ĸ���
	int B=0;//������ȷ��λ�ò���ȷ�ĸ���
	int th=0,h=0,t=0,o=0;//��¼��λ���Ƿ�A������ǣ��򲻽���B�ķ���
	//�������µ������
	generatemagicabcd(&imaga,&imagb,&imagc,&imagd);
	while(i<80)
    {
		i++;
		A=0;
		B=0;
		//�����û������4λ��
		printf("Please input an integer containing 4 different digits:");
		scanf_s("%d",&iuserdata);

		//����ǧ��ʮ��λ
		iuserth=getthousand(iuserdata);
		iuserh = gethundred(iuserdata);
		iusert = getten(iuserdata);
		iusero = getone(iuserdata);

		while (iuserth == iuserh || iuserth == iusert || iuserth == iusero || iuserh == iusert || iuserh == iusero || iusert == iusero)
		{
			printf("illegal,please input again:");
			scanf_s("%d", &iuserdata);

			iuserth = getthousand(iuserdata);
			iuserh = gethundred(iuserdata);
			iusert = getten(iuserdata);
			iusero = getone(iuserdata);
		}
		
		//�ֱ�Ƚ��ĸ�λ�õ���������¼
		//Ѱ��A
		if (iuserth == imaga)
			A++;
		if (iuserh == imagb)
			A++;
		if (iusert == imagc)
			A++;
		if (iusero == imagd)
			A++;
		//Ѱ��B
		if (iuserth == imagb)
			B++;
		if (iuserth == imagc)
			B++;
		if (iuserth == imagd)
			B++;
		if (iuserh == imaga)
			B++;
		if (iuserh == imagc)
			B++;
		if (iuserh == imagd)
			B++;
		if (iusert == imaga)
			B++;
		if (iusert == imagb)
			B++;
		if (iusert == imagd)
			B++;
		if (iusero == imaga)
			B++;
		if (iusero == imagb)
			B++;
		if (iusero == imagc)
			B++;
		//��ӡ���
		printf("%dA%dB\n",A,B);
		if(A==4)
		{
			printf("You win! You are a genius!\n");
			return;
		}
	}
    
}


/*
��������0~9����������������2������Ԫ�ص��±꣬��Χ��0~9�䣬Ȼ�󽻻�������Ԫ�أ�����Ľ������κ�ԭ���������
������Ϊ���������Ȼ�������ǰ4��Ԫ�أ����±�0~3��Ԫ������������ħ������ǧ��ʮ��λ��tͨ������ָ��ķ�ʽ���ظ�����
������ 
*/ 
void generatemagicabcd(int *pmaga,int *pmagb,int *pmagc, int *pmagd)
{
	int arr[10]={0,1,2,3,4,5,6,7,8,9};//���飬ȷ��ÿ������ֻ��һ�� 
	int i=0,j=0;//���ڽ���������Ԫ�ص��±� 
	int m=0;
	int itemp=0;
	srand( (unsigned)time( NULL ) );
	while(m<10)
	{
		i=rand()%10;//����2������±�
		j=rand()%10;
		itemp = arr[i];//����������
		arr[i]=arr[j];
		arr[j]=itemp;
		m++;
	}

	*pmaga = arr[0];//��ǰ4��Ԫ�أ�����ǧ��ʮ��λ
	*pmagb = arr[1];
	*pmagc = arr[2];
	*pmagd = arr[3];
}

//��ȡǧλ����
int getthousand(int inum)
{
	return (inum / 1000) % 10;
}
//��ȡ��λ����
int gethundred(int inum)
{
	return (inum / 100) % 10;
}
//��ȡʮλ����
int getten(int inum)
{
	return (inum / 10) % 10;
}
//��ȡ��λ����
int getone(int inum)
{
	return inum % 10;
}
