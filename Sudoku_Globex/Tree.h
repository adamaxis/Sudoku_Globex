#ifndef _TREE_H
#define _TREE_H
#include <string>

// Node class for tree
struct Node {
	int val;
	Node *left;
	Node *right;
};

// Binary Tree class
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