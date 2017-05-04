#include <iostream>
using namespace std;

template <class T>
class BinaryTree {
	public:
		void insert(T);
		void remove(T);
		bool search(T);

	private:
		struct Branch {
			Branch *leftLeaf;
			Branch *rightLeft;
			Branch *parent;
			T data;
		};

		Branch *root;
};
