#include "stdio.h"
int leapyear(int);
void print(int,int,int);
main()
{
	int year=0, month=0,day,days=0;
	printf("This program is designed to display a monthly calendar!\n");
	printf("please input the year:");
	scanf_s("%d", &year);
	while (year < 1)
	{
		printf("illegal,input again:");
		scanf_s("%d", &year);
	}
	printf("please input the month:");
	scanf_s("%d", &month);
	while ((month < 1) || (month>12))
	{
		printf("illegal,input again:");
		scanf_s("%d", &month);
	}

	//该年第一天是周几
	day=(((year - 1) * 365) + (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400 + 1) % 7;

	//4.累加本月前的所有月份的天数总和
	switch (month - 1)
	{
	case 11: days += 30;
	case 10: days += 31;
	case 9:  days += 30;
	case 8:  days += 31;
	case 7:  days += 31;
	case 6:  days += 30;
	case 5:  days += 31;
	case 4:  days += 30;
	case 3:  days += 31;
	case 2:  days += 28 + leapyear(year);
	case 1:  days += 31;
	default: days = 0;
	}

	//当前月份第一天是星期几
	day = day+days % 7;

	print(year, month, day);
}

//是否闰年
int leapyear(int year)
{
	if (year % 100 == 0)
		if (year % 400 == 0) return 1;
		else return 0;
	if ((year % 4 == 0) && (year % 100 != 0)) return 1;
	else return 0;
}

void print(int year, int month,int day)
{
	int i,monthday;
	switch (month)
	{
	case 12: monthday=31; break;
	case 11: monthday = 30; break;
	case 10: monthday = 31; break;
	case 9:  monthday = 30; break;
	case 8:  monthday = 31; break;
	case 7:  monthday = 31; break;
	case 6:  monthday = 30; break;
	case 5:  monthday = 31; break;
	case 4:  monthday = 30; break;
	case 3:  monthday = 31; break;
	case 2:  monthday = 28+leapyear(year); break;
	default: monthday = 31; break;
	}

	printf("\n\n\n%d    ", year);
	switch (month)
	{
	case 12: printf("December"); break;
	case 11: printf("November"); break;
	case 10: printf("October"); break;
	case 9:  printf("September"); break;
	case 8:  printf("August"); break;
	case 7:  printf("July"); break;
	case 6:  printf("June"); break;
	case 5:  printf("May"); break;
	case 4:  printf("April"); break;
	case 3:  printf("March"); break;
	case 2:  printf("February"); break;
	default: printf("January"); break;
	}

	printf("\nSun"); printf("    ");
	printf("Mon"); printf("    ");
	printf("Tue"); printf("    ");
	printf("Wed"); printf("    ");
	printf("Thu"); printf("    ");
	printf("Fri"); printf("    ");
	printf("Sat"); printf("    ");

	printf("\n");

	for (i = 1; i <= day % 7; i++)
	{
		printf("   "); printf("    ");
	}

	for (i = 1; i <= 7 - day; i++)
	{
		printf("%d  ", i); printf("    ");
	}
	printf("\n");

	for (i = 8 - day; i <= monthday; i++)
	{
		if (i < 10) printf("%d  ", i); else printf("%d ", i);
		printf("    ");
		if ((i % 7 == (7 - day) % 7)) printf("\n");
	}
}