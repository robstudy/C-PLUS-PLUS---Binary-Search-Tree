#include <iostream>
#include "BinaryTree.h"
using namespace std;

int main() {
	BinaryTree<int> bt;
	bt.insert(10);
	bt.insert(4);
	bt.insert(20);
	bt.insert(5);
	bt.insert(15);
	bt.insert(3);
	bt.insert(7);
	bt.insert(13);
	bt.print();
	return 0;
}
