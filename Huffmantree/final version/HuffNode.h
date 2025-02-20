#pragma once
#ifndef H
#define H

#include"FreqPair.h"

template<class Elem>
class HuffNode {
public:
	virtual int weight() = 0;
	virtual bool isLeaf() = 0;
};

template <class Elem>
class LeafNode : public HuffNode<Elem> {
private:
	FreqPair<Elem>* it;
public:
	LeafNode(Elem val, int freq)
	{
		it = new FreqPair<Elem>(val, freq);
	}
	int weight() {
		return it->weight();
	}
	bool isLeaf() {
		return true;
	}
	Elem val() {
		return it->val();
	}
};

template <class Elem>
class IntlNode : public HuffNode<Elem> {
private:
	HuffNode<Elem>* lc;
	HuffNode<Elem>* rc;
	int wgt;
public:
	IntlNode(HuffNode<Elem>* l, HuffNode<Elem>* r) {
		wgt = l->weight() + r->weight();
		lc = l;
		rc = r;
	}
	int weight() {
		return wgt;
	}
	bool isLeaf() {
		return false;
	}
	HuffNode<Elem>* left() {
		return lc;
	}
	HuffNode<Elem>* right() {
		return rc;
	}
	void setLeft(HuffNode<Elem>* r) {
		lc = (HuffNode*)r;
	}
	void setRight(HuffNode<Elem>* r) {
		rc = (HuffNode*)r;
	}
};

#endif