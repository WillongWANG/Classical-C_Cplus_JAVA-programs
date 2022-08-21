#pragma once
#ifndef P
#define P

#include<iostream>
using namespace std;

template<class Elem>
class FreqPair {//freqpair是啥呢？很简单：一个需要编码的东西：symbol和一个频率
private:
	Elem symbol;
	int freq;
public:
	FreqPair(Elem s, int f) {
		symbol = s;
		freq = f;
	}
	int weight() {
		return freq;
	}
	Elem val() {
		return symbol;
	}
};

#endif