#include"function.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include<string.h>
#include<stdlib.h>
using namespace std;
#pragma warning(disable:4996)
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


//����Ҫ��
void char_code() {
	cout << "�������ļ�����" << endl;
	string s_temp;
	cin >> s_temp;
	if (s_temp.empty()) {
		return;
	}
	my = readSoure(s_temp);
	int num = 0;  char* Code;
	char s[NUMBER];   int  w[NUMBER] = { 0 }; //�������ͳ�ƺõ��ַ����͸��ַ�Ƶ�ȼ�
	Stat(my, w, num);  //  ͳ���ַ�Ƶ�ȶԼ����ַ�������Ϊnum
	int* w_new = new int[num];
	deletezero(s, w, w_new);
	tt = HuffmanBuild(s, w_new, num);    // ��huffman��
	tt->print();
	Code = new char[num];        //����������Ŀռ�
	for (int temp = 0; temp < num; temp++)
		Code[temp] = '\0';//��ʼ��Code
	cout << "�����뱣���ַ���������ļ�����";
	string shuchu;
	cin >> shuchu;
	char* p = (char*)shuchu.data();
	fpencoder = fopen(p, "w");
	if (fpencoder == NULL) {
		cout << "���ļ�ʧ��" << endl;
		return;
	}
	cout << endl << " the coding result is:" << endl;
	Encoder(tt->root(), Code, -1);//�ӹ����õ�huffman���ĸ���ʼ�Ը���Ҷ�ӽ����벢���������
	cout << endl;
	getCodeMap(tt->root(), "");
	cout << "�ɹ��õ����������Ͷ�Ӧ�ַ�����" << endl;
	fclose(fpencoder);
}

string readSoure(string filename) {
	char* p = (char*)filename.data();
	FILE* fp = fopen(p, "r");
	if (fp == NULL)
	{
		cout << "Դ�ļ������ڣ����������!" << endl;
		return "";
	}
	char ch;
	string str = "";
	while ((ch = fgetc(fp)) != EOF) //!feof(fp)���У�str�������EOF
	{
		str+=ch;
	}
	fclose(fp);
	return str;
}

void  Stat(string s, int statis[], int& num) //  ͳ���ַ�Ƶ�ȶԼ�
{
	unsigned int i = 0, j = 0;
	for (i = 0; i < s.length(); i++)
		for (j = 0; j < 128; j++)    //ascii
			if (s[i] == j)
			{
				statis[j]++;
				break;
			}
	for (i = 0; i < NUMBER; i++)
		num = num + (statis[i] > 0);
}

void deletezero(char s[], int w[], int w_new[]) {
	int j = 0;
	for (int i = 0; i <= 128; i++) {
		if (w[i] != 0) {
			w_new[j] = w[i];
			s[j] = (char)i;
			j++;
		}
	}

}

HuffTree<char>* HuffmanBuild(char s[], int w[], int num)
{
	HuffTree<char>* ttree[NUMBER];//���ַ���s��Ȩֵ��w������num��������ttree��Ԫ��ָ������
	HuffTree<char>* tempTree;
	for (int i = 0; i < num; i++) {
		ttree[i] = new HuffTree<char>(s[i], w[i]);//tree leaf
	}
	int j = num;
	while (j != 1)
	{
		int s1, s2;

		for (int i = 0; i < j; i++)
		{
			//������ֱ��ѡ������
			tempTree = ttree[i];
			int tempW = ttree[i]->weight();
			int tempK = i;
			for (int k = i; k < j; k++) {
				if (tempW > (ttree[k]->weight()))
				{
					tempTree = ttree[k];
					tempW = (ttree[k]->weight());
					tempK = k;
				}//Сѭ��������tempWΪ��С��weight
			}
			ttree[tempK] = ttree[i];
			ttree[i] = tempTree;
		}
		s1 = 0; s2 = 1;
		HuffTree<char>* temptree = new HuffTree<char>(ttree[s1], ttree[s2]);
		*ttree[s1] = *temptree;
		for (int p = s2; p < j - 1; p++) {
			ttree[p] = ttree[p + 1];
		}
		ttree[j - 1] = 0;
		j--;//jΪĿǰHufftree�ĸ���

	}
	return ttree[0];
}

void Encoder(HuffNode<char>* tt, char* Code, int length)
{
	if (tt == NULL) {
		return;
	}
	if (tt->isLeaf()) {
		cout << "������һ���ַ���Ƶ�ʣ�";
		cout << ((LeafNode<char>*)tt)->weight() << endl;
		cout << ((LeafNode<char>*)tt)->val() << endl;
		cout << "���Ǵ��ַ��ı��룺";
		cout << Code << endl;

		fputc(((LeafNode<char>*)tt)->val(), fpencoder);
		fputc(' ', fpencoder);
		char str[LEN_STR];
		itoa(((LeafNode<char>*)tt)->weight(), str, 10);//��Ȩֵ����ַ���������ļ�
		fputs(str, fpencoder);
		fputc(' ', fpencoder);
		fputs(Code, fpencoder);
		fputc('\n', fpencoder);
		return;

	}
	else if (((IntlNode<char>*)tt)->left() != NULL) {
		char tempC[LEN_CHAR] = { 0 };//LEN_CHAR����ѡ��һ��С�ڵ���ǰ��ʼ��Codeʱ��num
		strcpy(tempC, Code);
		int len = length;
		len++;
		tempC[len] = '0';
		Encoder(((IntlNode<char>*)tt)->left(), tempC, len);
	}
	if (((IntlNode<char>*)tt)->right() != NULL) {
		char tempC[LEN_CHAR] = { 0 };
		strcpy(tempC, Code);
		int len = length;
		len++;
		tempC[len] = '1';
		Encoder(((IntlNode<char>*)tt)->right(), tempC, len);
	}
}

void getCodeMap(HuffNode<char>* root, string pastCode) {//�������Encoder�򻯵Ķࣿ��ʵ��û��Ҫ��Encoder
	if (root == NULL) return;
	if (!root->isLeaf())
	{
		getCodeMap(((IntlNode<char>*)root)->left(), pastCode + "0");
		getCodeMap(((IntlNode<char>*)root)->right(), pastCode + "1");
	}
	else {
		code[((LeafNode<char>*)root)->val()] = pastCode;//pastCodeΪ((LeafNode<char>*)root)->val()�ַ���huffman����
	}
}



//�м�Ҫ�󣬰�2����Զ���ɳ���Ҫ���ٽ����м�Ҫ��
void File_Code() {
	WriteToOutfp();
}

void WriteToOutfp() {
	char_code();
	cout << "������ѹ���ļ���(�����ƺ�׺bin��huf��:" << endl;
	string filename;
	cin >> filename;
	string codeText = get01Text(my);
	char* p = (char*)filename.data();
	while (codeText.length() % 8 != 0) {
		codeText.append(1, '0');//����8��һ�ֽڣ�����0��
	}
	FILE* Outfp = fopen(p, "wb");//������������ת��Ϊ������λ������������ļ�
	if (Outfp == NULL) {
		cout << "�ļ���ʧ��" << endl;
		return;
	}
	for (unsigned int i = 0; i < codeText.length(); i++) {
		char ch = codeText[i];
		Write(unsigned int(ch - '0'), Outfp);//��'0'��Ϊ�˽��ַ�ch����޷�������0��1
	}
	cout << "�ļ�ѹ����Ϊ��" << (float)codeText.length() / (float)(my.length() * 8) << endl;//codeText��ÿ��0��1��Ϊ1bit��my��ÿһ���ַ���Ϊ1�ֽ�
	fclose(Outfp);                                                                              //my.length()-1
}

string get01Text(string sourceText) {
	string result = "";
	for (unsigned int i = 0; i < sourceText.length(); i++) {
		char ch = sourceText[i];
		result.append(code[ch]);
	}
	return result;
}

void Write(unsigned int bit, FILE* outfp) { //buf��ԱĬ��ֵ��Ϊ0
	buf.bits++;
	buf.ch = (buf.ch << 1) + bit;
	if (buf.bits == 8) {
		fputc(buf.ch, outfp);
		buf.bits = 0;
		buf.ch = 0;
	}
}



//�߼�Ҫ��,��3����Զ����ǰ����Ҫ������ɸ߼�Ҫ��
void File_Decode() {
	File_Code();
	cout << "������Ҫ������ļ�(.bin/huf):" << endl;
	string decodename;
	cin >> decodename;
	char* q = (char*)decodename.data();
	infp = fopen(q, "rb");
	if (infp == NULL) {
		cout << "������Ķ������ļ���ʧ��" << endl;
		return;
	}
	FILE* result = fopen("f1_result.txt", "w");//���������ļ�f1_result.txt
	if (result == NULL) {
		cout << "������txt�ļ���ʧ��" << endl;
		return;
	}
	unsigned int numtemp = 0;
	while (numtemp < my.length()) {  
		decode(tt->root(), infp, result);
		numtemp++;
	}
	//����������buf������
	buf.bits = 0;
	buf.ch = 0;
	cout << "�������" << endl;
	fclose(infp);
	fclose(result);
}

void decode(HuffNode<char>* tt, FILE* fname1, FILE* fname2) {
	if (tt == NULL)
		return;
	if (tt->isLeaf()) {
		fputc(((LeafNode<char>*)tt)->val(), fname2);
		return;
	}

	unsigned int bit;
	Read(bit, fname1);
	switch (bit) {
	case 0: {
		decode(((IntlNode<char>*)tt)->left(), fname1, fname2);
		break;
	}

	case 1:decode(((IntlNode<char>*)tt)->right(), fname1, fname2);
	}
}

void Read(unsigned int& bit, FILE* infp) {
	if (buf.bits == 0) {
		buf.ch = fgetc(infp);//ÿ�ζ�һ���ֽڼ���λ��
		buf.bits = 8;
	}
	bit = (buf.ch & 128) >> 7;
	buf.ch = buf.ch << 1;
	buf.bits--;
}



//��������
void display() {
	cout << "******************************************************" << endl;
	cout << "   		��ӭʹ��huffman ������v1.0" << endl;
	cout << "******************************************************" << endl;
	cout << "��������˵����" << endl;
	cout << "ͳ�������ļ��ַ�Ƶ�Ȳ����ַ��������벢������ļ�������Ҫ�󣩣� 1" << endl;
	cout << "  �������ļ������벢�����������һ���������ļ����м�Ҫ�󣩣� 2" << endl;
	cout << "            �ļ����벢������������Ϊһ�ı��ļ����߼�Ҫ�󣩣� 3" << endl;
	cout << "    	                                                   �˳� �� 4" << endl;
}
void run() {
	char option;
	do {
		printf("\n$$");

		scanf("%c", &option);       //�û�ѡ������������
		switch (option) {        //�����û�ѡ�������غ������ָ������
		case '1':             //����Ҫ�������ļ���ͳ�ƣ������ַ��������
			char_code();
			break;
		case '2':            //�м�Ҫ�󣬱����������ļ���������һ���������ļ�
			File_Code();				 	//File_Code();  
			break;
		case '3':     				//�߼�Ҫ�󣬽��벢�����������һ���ı��ļ����Ա���ԭʼ���ļ����Ա�
			File_Decode();	//File_Decode();
			break;
		}
		//�������myȫ�ֱ�����
		tt->~HuffTree();
		my.clear();

	} while (option != '4');
}



