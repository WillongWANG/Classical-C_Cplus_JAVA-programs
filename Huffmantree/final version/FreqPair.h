#pragma once
#ifndef P
#define P

#include<iostream>
using namespace std;

template<class Elem>
class FreqPair {
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