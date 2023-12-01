#ifndef _Tree_h
#define _Tree_h

#include <iostream>
using namespace std;
#include "Node.h"
#include <fstream>
#include <string>
#include <filesystem> //#include <experimental/filesystem>
namespace fs = std::experimental::filesystem;
#include <ctype.h>
#define EOK 0

class Tree {
	Node* root;
	int numOfNodes;
	int numOfWords;

public:
	Tree();

	~Tree();

	int getNumOfWords() { return numOfWords; }

	void insertNode(const char* word);

	void readFromTextFiles();

	void suggestWords(const char* word);

	bool findWord(const char* word);

	void obidji(Node* curr, const char* word, const char** w, int* f, int* d);

};
#endif