#include <iostream>
using namespace std;

template <class T>
class BinaryTree {
	public:
		BinaryTree();
		void insert(T);
		void remove(T);
		void print();
		bool search(T);

	private:
		struct Branch {
			Branch *leftLeaf;
			Branch *rightLeaf;
			T data;
			Branch(Branch *l = NULL, Branch *r = NULL, T d = NULL):
				leftLeaf(l),
				rightLeaf(r),
				data(d){}
		};

		Branch *root;
		void b_insert(Branch *&, T);
		void b_print(Branch *);
		bool b_search(Branch *, T);
		unsigned int size;
};

template <class T>
BinaryTree<T>::BinaryTree() {
	size = 0;
};

template <class T>
void BinaryTree<T>::insert(T data) {
	if(!root) {
		root = new Branch(NULL, NULL, data);
		size++;
		return;
	}

	if(root->data == data) return;
	else if (root->data > data) b_insert(root->leftLeaf, data);
	else b_insert(root->rightLeaf, data);
};

template <class T>
void BinaryTree<T>::b_insert(Branch *&leaf, T data) {
	if (!leaf) {
		leaf = new Branch(NULL, NULL, data);
		size++;
	}

	if(leaf->data == data) return;
	else if (leaf->data > data) b_insert(leaf->leftLeaf, data);
	else b_insert(leaf->rightLeaf, data);
};

template <class T>
void BinaryTree<T>::print() {
	if(!root) return;
	b_print(root);
};

template <class T>
void BinaryTree<T>::b_print(Branch *leaf) {
	if(!leaf) return;
	
	cout << leaf->data << endl;
	b_print(leaf->leftLeaf);
	b_print(leaf->rightLeaf);
};

template <class T>
bool BinaryTree<T>::search(T data) {
	return b_search(root, data);
};

template <class T>
bool BinaryTree<T>::b_search(Branch *branch, T data) {
	if (!branch) return false;
	
	if (branch->data == data) return true;
	else if (branch->data > data) return b_search(branch->leftLeaf, data);
	else return b_search(branch->rightLeaf, data);
};
