#include "Tree.h"
#include <string>

Tree::Tree() {
	root = nullptr;
}

void Tree::destroy_tree() {
	destroy_tree(root);
}

void Tree::destroy_tree(Node *t) {
	if (t == nullptr) return;
	destroy_tree(t->left);
	destroy_tree(t->right);
	delete t;
}

Node *Tree::search(int key) {
	return search(key, root);
}

Node *Tree::search(int key, Node *t) {
	if (t != nullptr) {
		if (key == t->val) return t;
		if (key < t->val) return search(key, t->left);
		else return search(key, t->right);
	}
	else return nullptr;
}

void Tree::insert(int key) {
	if (root == nullptr) {
		root = new Node;
		root->val = key;
		root->left = nullptr;
		root->right = nullptr;
	} else insert(key, root);
}

void Tree::insert(int key, Node *t) {
	if (key < t->val) {
		if (t->left == nullptr) {
			t->left = new Node;
			t->left->val = key;
			t->left->left = nullptr;
			t->left->right = nullptr;
		} else insert(key, t->left);
	} else if (key >= t->val) {
		if (t->right == nullptr) {
			t->right = new Node;
			t->right->val = key;
			t->right->left = nullptr;
			t->right->right = nullptr;
		} else insert(key, t->right);
	}
}
/*
Was going to implement this(it's my java implementation of depth-searching) when I realized we didn't need a binary tree. lol
String Tree::DFS() {
	String DFS;
	DFS = "Depth-based traversal: " + depth_traversal(&root, DFS) + "(end)";
	return DFS;
}

// depth-based traversal
String Tree::depth_traversal(Node *node, String curNode) {
	// recursive null check
	if (node == nullptr) return nullptr;
	// grab current node's position for our traversal string
	curNode += node.pos + "->";
	// start by recursing left
	if (node.left != nullptr) curNode = depth_traversal(node.left, curNode);
	// then recurse right
	if (node.right != nullptr) curNode = depth_traversal(node.right, curNode);
	// end of tree reached
	return curNode;
}
*/
=======
}

