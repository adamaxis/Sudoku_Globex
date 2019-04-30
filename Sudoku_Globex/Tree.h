#ifndef _TREE_H
#define _TREE_H
#include <string>

struct Node {
	int val;
	Node *left;
	Node *right;
};

class Tree {
	Node *root;
public:

	Tree();
	~Tree();

	void insert(int);
	Node *search(int);
	void destroy_tree();

private:
	void destroy_tree(Node *);
	void insert(int, Node *);
	Node *search(int, Node *);
};
#endif