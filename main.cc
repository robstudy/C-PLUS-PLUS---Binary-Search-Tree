#include <iostream>
#include <string>
#include "BinaryTree.h"
using namespace std;

void upperCase(string &input) {
	for(unsigned int i = 0; i < input.size(); i++) 
		input[i] = toupper(input[i]);
};

int main() {

	BinaryTree<int> bt;
	string input = "";
	int data = 0;

	while(cin) {

		cin.clear();
		cin >> input;
		upperCase(input);

		if(input == "INSERT") {
			cin >> data;
			bt.insert(data);
		} else if (input == "SEARCH") {
			cin >> data;
			if (bt.search(data)) cout << "Found " << data << endl;
			else cout << data << " not found\n";
		} else if (input == "PRINT") {
			bt.print();
		} else if (input == "QUIT") {
			exit(EXIT_SUCCESS);
		}
	}


	return 0;
}
