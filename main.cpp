#include <iostream>
using namespace std;
#include "Node.h"
#include "Tree.h"

int main() {
	int flag = 1, u;
	string s; const char* word;
	Tree *t = nullptr;
	cout << "Meni:" << endl << "1. Stvaranje recnika iz datoteke" << endl << "2. Pretrezivanje reci" << endl;
	cout << "3. Umetanje reci" << endl;
	cout << "4. Predvidjanje reci na osnovu zadatog stringa" << endl;
	cout << "0. Kraj programa" << endl;
	while (flag) {
		printf("\nOdaberite stavku iz menija: ");
		scanf("%d", &u);
		switch (u) {
		case 1: { //Stvori stablo
			t = new Tree;
			t->readFromTextFiles();
			cout << "Stablo je formirano i ima " << t->getNumOfWords() << " reci." << endl;
			break;
		}
		case 2: { // Pretrazivanje reci
			cout << "Unesite rec: ";
			cin >> s;
			word = s.c_str();
			if (t->findWord(word)) cout << "Rec je pronadjena." << endl;
			else cout << "Rec nije pronadjena." << endl;
			break;
		}
		case 3: { //Umetanje reci
			cout << "Unesite rec: ";
			cin >> s;
			word = s.c_str();
			t->insertNode(word);
			cout << "Rec je umetnuta." << endl;
			break;
		}
		case 4: { //Predvidjanje reci
			cout << "Unesite rec: ";
			cin >> s;
			word = s.c_str();
			t->suggestWords(word);
			cout << endl;
			break;
		}
		case 0: { //kraj
			flag = 0;
			if (t != nullptr) delete t;
			break;
		}
		default: {
			cout << "Uneta opcija ne postoji u meniju, pokusajte ponovo." << endl;
		}
		}
	}
	return 0;
}