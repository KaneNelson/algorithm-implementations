#include<iostream>
#include<ctime>

using namespace	std;

const int MAX_TREE_SIZE = 128;

struct  TreeNode
{
	int value;
	TreeNode* left = nullptr;
	TreeNode* right = nullptr;
};

void preorder(TreeNode* n);
void inorder(TreeNode* n);
void postorder(TreeNode* n);

int main()
{

	// Change n to desired size of binary tree. Keep under MAX_TREE_SIZE
	int n = 16;
	TreeNode* arr[MAX_TREE_SIZE] = {};
	
	// Assign each node's value as it's index
	for (int i = 0; i < n; i++) {
		arr[i] = new TreeNode;
		arr[i]->value = i;
	}

	for (int i = 0; i < n; i++) {
		
		// Add left child to node
		if ((2 * i + 1) < n) {
			arr[i]->left = arr[(2 * i + 1)];
		}

		// Add right child to node
		if ((2 * i + 2 < n)) {
			arr[i]->right = arr[(2 * i + 2)];
		}
	}

	TreeNode* root = arr[0];

	cout << "Preorder: ";
	preorder(root);
	cout << endl;
	cout << "Inorder: ";
	inorder(root);
	cout << endl;
	cout << "Postorder: ";
	postorder(root);
	cout << endl;

	return 0;
}

void preorder(TreeNode* n) {
	cout << (n->value) << ' ';

	if (n->left != nullptr) {
		preorder(n->left);
	}
	if (n->right != nullptr) {
		preorder(n->right);
	}

}
void inorder(TreeNode* n) {


	if (n->left != nullptr) {
		inorder(n->left);
	}
	cout << (n->value) << ' ';
	if (n->right != nullptr) {
		inorder(n->right);
	}

}
void postorder(TreeNode* n) {


	if (n->left != nullptr) {
		postorder(n->left);
	}
	if (n->right != nullptr) {
		postorder(n->right);
	}
	cout << (n->value) << ' ';
}


