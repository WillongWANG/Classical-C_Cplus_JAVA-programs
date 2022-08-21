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

extern Buffer buf;//二进制读写的缓冲区
extern map<char, string>code;//字典
extern string my;//存放原文件的字符串，在高级要求中作为一个循环判断使用，在run（）中清空
extern FILE* fpencoder;//用来保存字符编码集至文本文件，用于Encoder函数中，文件在char_code关闭
extern FILE* infp;//从二进制文件解码至文本文件，在高级要求后关闭文件
extern HuffTree<char>* tt;//树作为全局变量，方便进行高级要求的解码，在run()中每做一次循环，清空一次


//初级要求
void char_code();

string readSoure(string filename);

void  Stat(string s, int statis[], int& num);

void deletezero(char s[], int w[], int num, int w_new[]);

HuffTree<char>* HuffmanBuild(char s[], int w[], int num);

void Encoder(HuffNode<char>* tt, char* Code, int length);

void getCodeMap(HuffNode<char>* root, string pastCode);



//中级要求，按2则会自动完成初级要求，再进行中级要求
void File_Code();
//char_code()

void WriteToOutfp();

string get01Text(string sourceText);

void Write(unsigned int bit, FILE* outfp);



//高级要求,按3则会自动完成前两个要求，再完成高级要求
void File_decode();
//File_code()

void decode(HuffNode<char>* tt, FILE* fname1, FILE* fname2);

void Read(unsigned int& bit, FILE* infp);



//下面两个是主函数内的函数
void display();

void run();
#endif