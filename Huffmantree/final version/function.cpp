#include"function.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include<string.h>
#include<stdlib.h>
using namespace std;
#pragma warning(disable:4996)
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


//初级要求
void char_code() {
	cout << "请输入文件名称" << endl;
	string s_temp;
	cin >> s_temp;
	if (s_temp.empty()) {
		return;
	}
	my = readSoure(s_temp);
	int num = 0;  char* Code;
	char s[NUMBER];   int  w[NUMBER] = { 0 }; //用来存放统计好的字符集和各字符频度集
	Stat(my, w, num);  //  统计字符频度对集，字符种类数为num
	int* w_new = new int[num];
	deletezero(s, w, w_new);
	tt = HuffmanBuild(s, w_new, num);    // 建huffman树
	tt->print();
	Code = new char[num];        //分配编码结果的空间
	for (int temp = 0; temp < num; temp++)
		Code[temp] = '\0';//初始化Code
	cout << "请输入保存字符集编码的文件名：";
	string shuchu;
	cin >> shuchu;
	char* p = (char*)shuchu.data();
	fpencoder = fopen(p, "w");
	if (fpencoder == NULL) {
		cout << "打开文件失败" << endl;
		return;
	}
	cout << endl << " the coding result is:" << endl;
	Encoder(tt->root(), Code, -1);//从构建好的huffman树的根开始对各个叶子结点编码并输出编码结果
	cout << endl;
	getCodeMap(tt->root(), "");
	cout << "成功得到哈夫曼树和对应字符编码" << endl;
	fclose(fpencoder);
}

string readSoure(string filename) {
	char* p = (char*)filename.data();
	FILE* fp = fopen(p, "r");
	if (fp == NULL)
	{
		cout << "源文件不存在，请检查后重试!" << endl;
		return "";
	}
	char ch;
	string str = "";
	while ((ch = fgetc(fp)) != EOF) //!feof(fp)不行，str最后会包含EOF
	{
		str+=ch;
	}
	fclose(fp);
	return str;
}

void  Stat(string s, int statis[], int& num) //  统计字符频度对集
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
	HuffTree<char>* ttree[NUMBER];//用字符集s和权值集w新申请num棵树，令ttree的元素指向他们
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
			//在这里直接选择排序
			tempTree = ttree[i];
			int tempW = ttree[i]->weight();
			int tempK = i;
			for (int k = i; k < j; k++) {
				if (tempW > (ttree[k]->weight()))
				{
					tempTree = ttree[k];
					tempW = (ttree[k]->weight());
					tempK = k;
				}//小循环出来后tempW为最小的weight
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
		j--;//j为目前Hufftree的个数

	}
	return ttree[0];
}

void Encoder(HuffNode<char>* tt, char* Code, int length)
{
	if (tt == NULL) {
		return;
	}
	if (tt->isLeaf()) {
		cout << "这是下一行字符的频率：";
		cout << ((LeafNode<char>*)tt)->weight() << endl;
		cout << ((LeafNode<char>*)tt)->val() << endl;
		cout << "这是此字符的编码：";
		cout << Code << endl;

		fputc(((LeafNode<char>*)tt)->val(), fpencoder);
		fputc(' ', fpencoder);
		char str[LEN_STR];
		itoa(((LeafNode<char>*)tt)->weight(), str, 10);//将权值变成字符串输出到文件
		fputs(str, fpencoder);
		fputc(' ', fpencoder);
		fputs(Code, fpencoder);
		fputc('\n', fpencoder);
		return;

	}
	else if (((IntlNode<char>*)tt)->left() != NULL) {
		char tempC[LEN_CHAR] = { 0 };//LEN_CHAR合理选择，一定小于等于前初始化Code时的num
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

void getCodeMap(HuffNode<char>* root, string pastCode) {//这个不比Encoder简化的多？其实都没必要用Encoder
	if (root == NULL) return;
	if (!root->isLeaf())
	{
		getCodeMap(((IntlNode<char>*)root)->left(), pastCode + "0");
		getCodeMap(((IntlNode<char>*)root)->right(), pastCode + "1");
	}
	else {
		code[((LeafNode<char>*)root)->val()] = pastCode;//pastCode为((LeafNode<char>*)root)->val()字符的huffman编码
	}
}



//中级要求，按2则会自动完成初级要求，再进行中级要求
void File_Code() {
	WriteToOutfp();
}

void WriteToOutfp() {
	char_code();
	cout << "请输入压缩文件名(二进制后缀bin或huf）:" << endl;
	string filename;
	cin >> filename;
	string codeText = get01Text(my);
	char* p = (char*)filename.data();
	while (codeText.length() % 8 != 0) {
		codeText.append(1, '0');//不足8（一字节），补0；
	}
	FILE* Outfp = fopen(p, "wb");//将哈夫曼编码转换为二进制位输出至二进制文件
	if (Outfp == NULL) {
		cout << "文件打开失败" << endl;
		return;
	}
	for (unsigned int i = 0; i < codeText.length(); i++) {
		char ch = codeText[i];
		Write(unsigned int(ch - '0'), Outfp);//减'0'是为了将字符ch变成无符号整型0，1
	}
	cout << "文件压缩率为：" << (float)codeText.length() / (float)(my.length() * 8) << endl;//codeText的每个0、1视为1bit，my的每一个字符视为1字节
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

void Write(unsigned int bit, FILE* outfp) { //buf成员默认值都为0
	buf.bits++;
	buf.ch = (buf.ch << 1) + bit;
	if (buf.bits == 8) {
		fputc(buf.ch, outfp);
		buf.bits = 0;
		buf.ch = 0;
	}
}



//高级要求,按3则会自动完成前两个要求，再完成高级要求
void File_Decode() {
	File_Code();
	cout << "请输入要解码的文件(.bin/huf):" << endl;
	string decodename;
	cin >> decodename;
	char* q = (char*)decodename.data();
	infp = fopen(q, "rb");
	if (infp == NULL) {
		cout << "待解码的二进制文件打开失败" << endl;
		return;
	}
	FILE* result = fopen("f1_result.txt", "w");//解码后的新文件f1_result.txt
	if (result == NULL) {
		cout << "解码至txt文件打开失败" << endl;
		return;
	}
	unsigned int numtemp = 0;
	while (numtemp < my.length()) {  
		decode(tt->root(), infp, result);
		numtemp++;
	}
	//解码完后清空buf缓冲区
	buf.bits = 0;
	buf.ch = 0;
	cout << "解码完成" << endl;
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
		buf.ch = fgetc(infp);//每次读一个字节即八位数
		buf.bits = 8;
	}
	bit = (buf.ch & 128) >> 7;
	buf.ch = buf.ch << 1;
	buf.bits--;
}



//主函数内
void display() {
	cout << "******************************************************" << endl;
	cout << "   		欢迎使用huffman 编码器v1.0" << endl;
	cout << "******************************************************" << endl;
	cout << "操作命令说明：" << endl;
	cout << "统计输入文件字符频度并对字符集编括码并输出至文件（基本要求）： 1" << endl;
	cout << "  对整个文件编括码并保存编码结果到一个二进制文件（中级要求）： 2" << endl;
	cout << "            文件解码并将解码结果保存为一文本文件（高级要求）： 3" << endl;
	cout << "    	                                                   退出 ： 4" << endl;
}
void run() {
	char option;
	do {
		printf("\n$$");

		scanf("%c", &option);       //用户选择操作命令键入
		switch (option) {        //根据用户选择调用相关函数完成指定操作
		case '1':             //基本要求，输入文件，统计，编码字符集并输出
			char_code();
			break;
		case '2':            //中级要求，编括码整个文件并保存至一个二进制文件
			File_Code();				 	//File_Code();  
			break;
		case '3':     				//高级要求，解码并保存解码结果到一个文本文件，以便与原始的文件作对比
			File_Decode();	//File_Decode();
			break;
		}
		//清空树、my全局变量；
		tt->~HuffTree();
		my.clear();

	} while (option != '4');
}



