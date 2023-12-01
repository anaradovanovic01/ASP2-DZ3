#include "Tree.h"

Tree::Tree() {
	root = nullptr;
	numOfNodes = 0;
	numOfWords = 0;
}

Tree::~Tree() {
	if (root) delete root;
}

void Tree::insertNode (const char* word) {
	char* p = new char[strlen(word) + 1]; int i;
	for (i = 0; i < strlen(word); i++) {
		if (isupper(word[i])) p[i] = word[i] + 32;
		else p[i] = word[i];
	}
	p[i] = '\0';
	const char* w = p;
	if (!root){
		root = new Node;
		numOfNodes++;
	}
	Node* curr = root;
	for (int i = 0; i < strlen(w); i++) {
		curr = curr->addChild(w[i], numOfWords, numOfNodes, w);
	}
	curr->addChild(EOK, numOfWords, numOfNodes, w);
}

void Tree::readFromTextFiles() {
	ifstream file;
	const char* p; char* word; string s;
	bool f;
	Node* curr;
	string path = "text";
	for (const auto & entry : fs::directory_iterator(path)) {
		file.open(entry.path());
		if (!file.is_open()) return;
		while (file >> s) {
			f = true;
			for (char& c : s) {
				if (!isalpha(c))
					f = false;
			}
			if (f) {
				p = s.c_str();
				word = const_cast <char *>(p);
				this->insertNode(word);

			}
		}
		file.close();
	}
}

bool Tree::findWord(const char * word) {
	Node *p = root, *pom = nullptr; int i = 0; bool log = true;
	for (int i = 0; i < strlen(word); i++) {
		if (p->findLetter(word[i], pom)) {
			if (pom) p = pom;
			else {
				log = false;
				break;
			}
		}
		else {
			log = false;
			break;
		}
	}
	if (log) {
		if (p->findLetter(EOK, pom)) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

void Tree::suggestWords(const char * word) {
	const char* w[3]; int f[3], d[3];
	for (int i = 0; i < 3; i++) w[i] = nullptr;
	Node *p = root, *pom = nullptr; int i = 0; bool log = true;
	for(int i = 0; i < strlen(word); i++) {
		if (p->findLetter(word[i], pom)) {
			if (pom) p = pom;
			else {
				log = false;
				break;
			}
		}
		else {
			log = false;
			break;
		}
	}
	if (log) {
		if (p->findLetter(EOK, pom)) {
			obidji(p, word, w, f, d);
		}
		else {
			obidji(p, word, w, f, d);
		}
	}
	else {
		obidji(root, word, w, f, d);
	}
	for (int i = 0; i < 3; i++) {
		if (i == 0 && !w[i]) {cout << "Nema slicnih reci."; return; }
		if (w[i]) cout << w[i] << ' ';
	}
}

void Tree::obidji(Node* curr, const char* word, const char** w, int* f, int* d) {
	if (curr) curr->poseti(word, w, f, d);
}