#pragma once

#ifndef T
#define T

#include"HuffNode.h"

template<typename Elem>
class HuffTree {
private:
	HuffNode<Elem>* myroot;
	void printhelp(HuffNode<Elem>* subroot, int level)const {
		if (subroot == NULL)
			return;
		if (subroot->isLeaf()) {
			for (int i = 0; i < level; i++) {
				cout << "*";
			}
			cout << "Leaf:";
			cout << ((LeafNode<Elem>*)subroot)->val() << " " << ((LeafNode<Elem>*)subroot)->weight() << endl;
		}
		else {
			printhelp(((IntlNode<Elem>*)subroot)->left(), level + 1);
			for (int i = 0; i < level; i++) {
				cout << "*";
			}
			cout << "Internal: ";
			cout << ((IntlNode<Elem>*)subroot)->weight() << endl;
			printhelp(((IntlNode<Elem>*)subroot)->right(), level + 1);
		}
	}

public:
	HuffNode<Elem>* root() {
		return myroot;
	}
	HuffTree(Elem val, int freq) {
		myroot = new LeafNode<Elem>(val, freq);
	}
	HuffTree(HuffTree<Elem>* l, HuffTree<Elem>* r) {
		myroot = new IntlNode<Elem>(l->root(), r->root());
	}
	~HuffTree() {}

	int weight() {
		return myroot->weight();
	}

	void print() const {
		if (myroot == NULL) {
			cout << "The HuffTree is empty.";
		}
		else printhelp(myroot, 0);
	}
}; 
#endif