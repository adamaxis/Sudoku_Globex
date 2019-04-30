#include "Tree.h"
#include <string>

// Simple binary tree
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