#include "Node.h"

Node::Node() {
	head = nullptr;
}

Node::~Node() {
	while (head) {
		ListElem* p = head;
		head = head->next;;
		delete p->child;
		delete p;
	}
}

Node* Node::addChild(char c, int& numOfWords, int& numOfNodes, const char* word) {
	int flag = 0;
	if (!head) {
		head = new ListElem(c);
		if (c != EOK) { head->child = new Node; numOfNodes++; }
		else { numOfWords++; head->word = word; }
		return head->child;
	}
	ListElem* curr = head, *prev = nullptr;
	while (curr) {
		if (curr->info == c) {
			flag = 1;
			curr->n++;
			break;
		};
		prev = curr;
		curr = curr->next;
	}
	if (flag) {
		if (!curr->child) {
			if (c != EOK) { curr->child = new Node; numOfNodes++; }
		}
		Node* pom = curr->child;
		return pom;
	}
	else {
		curr = new ListElem(c);
		prev->next = curr;
		if (c != EOK) {	curr->child = new Node; numOfNodes++; }
		else { numOfWords++; curr->word = word; }
		Node* pom = curr->child;
		return pom;
	}
}

bool Node::findLetter(char c, Node*& pom) {
	ListElem* p = head;
	while (p) {
		if (p->info == c) {
			pom = p->child;
			return true;
		}
		else  p = p->next;
	}
	return false;
}

void Node::compareWords(ListElem * p, const char* word, const char ** w, int * f, int * d) {
	int numOfDif = 0;
	if (strlen(p->word) < strlen(word)) return;
	for (int i = 0; i < strlen(word); i++) {
		if (word[i] != p->word[i]) numOfDif++;
	}
	if (numOfDif > 3) return;
	for (int i = 0; i < 3; i++) {
		if (w[i] == nullptr) { w[i] = p->word; f[i] = p->n; d[i] = numOfDif; return; }
		if (numOfDif < d[i]) {
			for (int j = 2; j > i; j--) {
				w[j] = w[j - 1]; f[j] = f[j - 1]; d[j] = d[j - 1];
			}
			w[i] = p->word; f[i] = p->n; d[i] = numOfDif; return;
		}
		else if (numOfDif == d[i]) {
			if (p->n > f[i]) {
				for (int j = 2; j > i; j--) {
					w[j] = w[j - 1]; f[j] = f[j - 1]; d[j] = d[j - 1];
				}
				w[i] = p->word; f[i] = p->n; d[i] = numOfDif; return;
			}
		}
	}
}

void Node::poseti(const char* word, const char** w, int* f, int* d) {
	for (ListElem* p = head; p; p = p->next) {
		if (p->info == EOK) { compareWords(p, word, w, f, d); }
		if(p->child) 
			p->child->poseti(word, w, f, d);
	}
}