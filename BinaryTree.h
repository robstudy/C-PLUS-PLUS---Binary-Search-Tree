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
		unsigned int size();	
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
		void b_remove(Branch *&, T);
		T swapLeft(Branch *&);
		T swapRight(Branch *&);
		unsigned int _size;
};

template <class T>
BinaryTree<T>::BinaryTree() {
	_size = 0;
};

template <class T>
void BinaryTree<T>::insert(T data) {
	if(!root) {
		root = new Branch(NULL, NULL, data);
		_size++;
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
		_size++;
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

template <class T>
void BinaryTree<T>::remove(T data) {
	b_remove(root, data);
};

template <class T>
void BinaryTree<T>::b_remove(Branch *&branch, T data) {
	if (!branch) return;

	if (branch->data == data) {

		if (!branch->leftLeaf && !branch->rightLeaf) {
			branch = NULL;
			delete branch;
			_size--;
			return;
		}

		if (branch->leftLeaf && branch->rightLeaf) {
			branch->data = swapRight(branch->rightLeaf);
		} else if (branch->leftLeaf && !branch->rightLeaf) {
			branch->data = swapRight(branch->leftLeaf);
		} else {
			branch->data = swapLeft(branch->rightLeaf);
		}
	}

	if (branch->data > data) b_remove(branch->leftLeaf, data);
	else b_remove(branch->rightLeaf, data);
};

template <class T>
T BinaryTree<T>::swapRight(Branch *&branch) {
	if(branch->rightLeaf) return swapRight(branch->rightLeaf);
	else if (!branch->leftLeaf && !branch->rightLeaf) { 
		T hold = branch->data;
		branch = NULL;
		delete branch;
		_size--;
		return hold;
	} else {
		T hold = branch->data;
		if(branch->leftLeaf) 
			branch->data = swapLeft(branch->leftLeaf);
		return hold;
	}
};

template <class T>
T BinaryTree<T>::swapLeft(Branch *&branch) {
	if(branch->leftLeaf) return swapLeft(branch->leftLeaf);
	else if (!branch->leftLeaf && !branch->rightLeaf) {
		T hold = branch->data;
		branch = NULL;
		delete branch;
		_size--;
		return hold;
	} else {
		T hold = branch->data;
		if(branch->rightLeaf) 
			branch->data = swapRight(branch->rightLeaf);
		return hold;
	}
};

template <class T>
unsigned int BinaryTree<T>::size() {
	return _size;
};
