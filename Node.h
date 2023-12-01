#ifndef _Node_h
#define _Node_h

#include <iostream>
using namespace std;
#define EOK 0

class Node {
	struct ListElem {
		char info;
		Node* child;
		ListElem* next;
		int n;
		const char* word;

		ListElem(char c) {
			info = c;
			n = 1;
			child = nullptr;
			next = nullptr;
			word = nullptr;
		}

	};
	ListElem* head;

	void compareWords(ListElem* p, const char* word, const char** w, int* f, int* d);

public:
	friend class Tree;

	Node();

	~Node();

	Node* addChild(char c, int& numOfWords, int& numOfNodes, const char* word);

	bool findLetter(char c, Node*& pom);

	void poseti(const char* word, const char** w, int* f, int* d);

};
#endif