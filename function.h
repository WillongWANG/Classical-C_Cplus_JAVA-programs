#pragma once
#ifndef F
#define F

#include"HuffTree.h"
#include<map>

#define NUMBER 128
#define LEN_STR 8
#define LEN_CHAR 20

typedef struct {
	char ch;
	unsigned int bits;
}Buffer;

extern Buffer buf;//�����ƶ�д�Ļ�����
extern map<char, string>code;//�ֵ�
extern string my;//���ԭ�ļ����ַ������ڸ߼�Ҫ������Ϊһ��ѭ���ж�ʹ�ã���run���������
extern FILE* fpencoder;//���������ַ����뼯���ı��ļ�������Encoder�����У��ļ���char_code�ر�
extern FILE* infp;//�Ӷ������ļ��������ı��ļ����ڸ߼�Ҫ���ر��ļ�
extern HuffTree<char>* tt;//����Ϊȫ�ֱ�����������и߼�Ҫ��Ľ��룬��run()��ÿ��һ��ѭ�������һ��


//����Ҫ��
void char_code();

string readSoure(string filename);

void  Stat(string s, int statis[], int& num);

void deletezero(char s[], int w[], int num, int w_new[]);

HuffTree<char>* HuffmanBuild(char s[], int w[], int num);

void Encoder(HuffNode<char>* tt, char* Code, int length);

void getCodeMap(HuffNode<char>* root, string pastCode);



//�м�Ҫ�󣬰�2����Զ���ɳ���Ҫ���ٽ����м�Ҫ��
void File_Code();
//char_code()

void WriteToOutfp();

string get01Text(string sourceText);

void Write(unsigned int bit, FILE* outfp);



//�߼�Ҫ��,��3����Զ����ǰ����Ҫ������ɸ߼�Ҫ��
void File_decode();
//File_code()

void decode(HuffNode<char>* tt, FILE* fname1, FILE* fname2);

void Read(unsigned int& bit, FILE* infp);



//�����������������ڵĺ���
void display();

void run();
#endif