#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//产生一个4位数，每个数字不同0~9
void generatemagicabcd(int *,int *,int *, int *);
//获取千位数字
int getthousand(int);
//获取百位数字
int gethundred(int);
//获取十位数字
int getten(int);
//获取个位数字
int getone(int);
void main()
{
	int imaga,imagb,imagc,imagd;//magic number abcd
	int i = 0;
	int iuserdata = 0;
	int iuserth=0,iuserh=0,iusert=0,iusero=0;//用户的千百个十位
	int A=0;//位置正确且数字正确的个数
	int B=0;//数字正确而位置不正确的个数
	int th=0,h=0,t=0,o=0;//记录该位置是否A，如果是，则不进行B的分析
	//参数被猜的随机数
	generatemagicabcd(&imaga,&imagb,&imagc,&imagd);
	while(i<80)
    {
		i++;
		A=0;
		B=0;
		//读入用户输入的4位数
		printf("Please input an integer containing 4 different digits:");
		scanf_s("%d",&iuserdata);

		//分离千百十个位
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
		
		//分别比较四个位置的数，并记录
		//寻找A
		if (iuserth == imaga)
			A++;
		if (iuserh == imagb)
			A++;
		if (iusert == imagc)
			A++;
		if (iusero == imagd)
			A++;
		//寻找B
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
		//打印结果
		printf("%dA%dB\n",A,B);
		if(A==4)
		{
			printf("You win! You are a genius!\n");
			return;
		}
	}
    
}


/*
数组存放了0~9，随后用随机数产生2个数组元素的下标，范围在0~9间，然后交换这两个元素，随机的交换几次后，原数组的内容
可以视为“随机”；然后将数组的前4个元素，即下标0~3的元素依次用作“魔数”的千百十个位。t通过传递指针的方式返回给主调
函数。 
*/ 
void generatemagicabcd(int *pmaga,int *pmagb,int *pmagc, int *pmagd)
{
	int arr[10]={0,1,2,3,4,5,6,7,8,9};//数组，确保每个数字只有一个 
	int i=0,j=0;//用于交换的两个元素的下标 
	int m=0;
	int itemp=0;
	srand( (unsigned)time( NULL ) );
	while(m<10)
	{
		i=rand()%10;//产生2个随机下标
		j=rand()%10;
		itemp = arr[i];//交换两个数
		arr[i]=arr[j];
		arr[j]=itemp;
		m++;
	}

	*pmaga = arr[0];//读前4个元素，用作千百十个位
	*pmagb = arr[1];
	*pmagc = arr[2];
	*pmagd = arr[3];
}

//获取千位数字
int getthousand(int inum)
{
	return (inum / 1000) % 10;
}
//获取百位数字
int gethundred(int inum)
{
	return (inum / 100) % 10;
}
//获取十位数字
int getten(int inum)
{
	return (inum / 10) % 10;
}
//获取个位数字
int getone(int inum)
{
	return inum % 10;
}
