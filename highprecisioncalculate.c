#include<stdio.h>

main()
{
	char str1[21] = "\0", str2[21] = "\0"; int plus1[21] = { '\0' }, plus2[21] = { '\0' }, result[21] = {'\0'};
	int i, j, sign;
	printf("please input the number1(<=20 bits):");
	scanf_s(" %s",str1,21);
	printf("please input the number2(<=20 bits):");
	scanf_s(" %s", str2,21);
	for (i = 20,j=0; i >= 0; i--)
	{
		if (str1[i] == '\0') continue;
		else {
			plus1[j] = str1[i]-48;
			j++;
		}
	}
	for (i = 20, j = 0; i >= 0; i--)
	{
		if (str2[i] == '\0') continue;
		else {
			plus2[j] = str2[i]-48;
			j++;
		}
	}
	for (i = 0, sign = 0;i<21;i++)
	{
		result[i] = (plus1[i] + plus2[i]+sign) % 10;
		sign = (plus1[i] + plus2[i]+sign) / 10;
	}
	for (i = 20; i >=0; i--)
	{
		if (result[i] == '\0') continue;
		printf("%d",result[i]);
	}
}

