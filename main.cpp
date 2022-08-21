#include"function.h"
#include<iostream>
using namespace std;

Buffer buf;
map<char, string>code;
string my;
FILE* fpencoder;
FILE* infp;
HuffTree<char>* tt;

/*程序逻辑：
1.初级要求:打开待读文件，将文件中的字符写入数组并计频率，此阶段由char_code()函数内的readSoure、Stat、deletezero完成;
			建树、打印字符频率信息由char_code()函数内HuffmanBuild以及tt->print（）完成；
			得到哈夫曼编码并写入文件、编写字典由char_code()函数内的Encoder、getCodeMap完成。


2.中级要求：完成初级要求后，保留原文件中的字符串my，并将my全都用哈夫曼编码改写成01字符串并存入codeText中，此阶段
			由WriteToOutfp()中的get01Text函数与字典共同完成；
			让用户输入压缩得到的文件名（二进制文件），调用write函数将codeText逐个写入，并计算压缩率;


3.高级要求：需要完成中级要求，此时哈夫曼编码树以及my都存留；让用户输入待解码文件（即中级要求中的压缩文件），调用decode(),
			在其内部调用Read()逐个读入二进制bit，依据其为0或1采用递归方法解出一个字符，在decode()内部采用循环解码文件，
			循环结束的标志为my的长度-1=解码的字符个数，注意解码完成后需要清空缓冲区buf，否则下一次主函数循环解码时，其缓冲区
			存在数据则译码错误，另外在主函数循环一次后需要调用析构函数把树清空。
			*/



int main() {
	display();
	run();
	return 0;
}