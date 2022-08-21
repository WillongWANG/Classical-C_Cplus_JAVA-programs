#include<stdio.h>
#include<string.h>

void printcodebook(char alphalist[], char codebookmatrix[][27]);
void virginiacoder(int length, char cleantext[], char alphalist[], char ciphertext[]);
void virginiadecoder(int length, char cleantext[], char alphalist[], char ciphertext[]);

main()
{
	char alphalist[26], cleantext[25] = "\0", ciphertext[25] = "\0", codebookmatrix[27][27] = { ' ' }; int i;
	for (i = 0; i < 26; i++)
		alphalist[i] = 'a' + i;
	printcodebook(alphalist, codebookmatrix);
	printf("input the clean text(less than 25 words):");
	scanf_s(" %s", cleantext, 25);
	virginiacoder(strlen(cleantext), cleantext, alphalist, ciphertext);
	printf("\ninput the cipher text(less than 25 words):");
	scanf_s(" %s", ciphertext,25);
	virginiadecoder(strlen(ciphertext), cleantext, alphalist, ciphertext);
}

void printcodebook(char alphalist[], char codebookmatrix[][27])
{
	int i,j;
	for (j = 1; j < 27; j++)
		codebookmatrix[0][j] = 'a' + j - 1;
	for (j = 1; j < 27; j++)
		codebookmatrix[j][0] = 'a' + j - 1;
	for (i = 1; i < 27; i++)
		for (j = 1; j < 27; j++)
			codebookmatrix[i][j] = alphalist[(i + j - 2) % 26];
	for (i = 0; i < 27; i++)
		for (j = 0; j < 27; j++)
		{
			printf("%c ", codebookmatrix[i][j]);
			if (j == 26) printf("\n");
		}
}

void virginiacoder(int length,char cleantext[],char alphalist[],char ciphertext[])
{
	char espionage[25]="\0"; int a;
	for (a = 0; a < length; a++)
	{
		switch (a % 9)
		{
		case 0:espionage[a] = 'e'; break;
		case 1:espionage[a] = 's'; break;
		case 2:espionage[a] = 'p'; break;
		case 3:espionage[a] = 'i'; break;
		case 4:espionage[a] = 'o'; break;
		case 5:espionage[a] = 'n'; break;
		case 6:espionage[a] = 'a'; break;
		case 7:espionage[a] = 'g'; break;
		case 8:espionage[a] = 'e'; break;
		}
	}
	for(a=0;a<length;a++)
	ciphertext[a] = alphalist[(cleantext[a] - 'a' + espionage[a] - 'a') % 26];
	printf("\nthe cipher text is %s",ciphertext);
}

void virginiadecoder(int length, char cleantext[], char alphalist[], char ciphertext[])
{
	char espionage[25]="\0"; int a;
	for (a = 0; a < length; a++)
	{
		switch (a % 9)
		{
		case 0:espionage[a] = 'e'; break;
		case 1:espionage[a] = 's'; break;
		case 2:espionage[a] = 'p'; break;
		case 3:espionage[a] = 'i'; break;
		case 4:espionage[a] = 'o'; break;
		case 5:espionage[a] = 'n'; break;
		case 6:espionage[a] = 'a'; break;
		case 7:espionage[a] = 'g'; break;
		case 8:espionage[a] = 'e'; break;
		}
	}
	for (a = 0; a < length; a++)
	cleantext[a] = alphalist[(ciphertext[a] - 'a' + 26- espionage[a] + 'a') % 26];
	printf("\nthe clean text is %s", cleantext);
}
