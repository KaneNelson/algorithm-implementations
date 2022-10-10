#include<iostream>

using namespace	std;

struct  TreeNode {
	int info;
	TreeNode* left = nullptr;
	TreeNode* right = nullptr;
};

void inorder(TreeNode* n);
void insert(TreeNode** n, int x);
int countNodes(TreeNode* n);
TreeNode* TreeSearch(TreeNode* n, int x);

int main()
{
	// Set root values
	TreeNode* root = new TreeNode;
	root->info = 10;

	// Change array values to set what values are added to Binary Search Tree
	int values[] = { 18, 7, 2, 20, 15 };

	// Add values to tree in order
	for (int i = 0; i < sizeof(values) / sizeof(int); i++)
		insert(&root, values[i]);

	cout << "Binary Search Tree Traversal: ";
	inorder(root);
	cout << endl << endl;

	cout << "Node Count: " << countNodes(root);
	cout << endl << endl;

	int n = 0;
	cout << "Enter value to search for: ";
	cin >> n;
	
	TreeSearch(root, n);
	cout << endl;
	
	return 0;
}

void inorder(TreeNode* n) {


	if (n->left != nullptr) {
		inorder(n->left);
	}
	cout << (n->info) << ' ';
	if (n->right != nullptr) {
		inorder(n->right);
	}

}

// Insert node into binary search tree
void insert(TreeNode** n, int x) {
	if (*n == nullptr) {
		*n = new TreeNode;
		(*n)->info = x;
	}
	else if (x < (*n)->info)
		insert(&(*n)->left, x);
	else
		insert(&(*n)->right, x);
}

int countNodes(TreeNode* n) {
	if (n == nullptr) {
		return 0;
	}

	return 1 + countNodes(n->left) + countNodes(n->right);
}

// Search for given value
TreeNode* TreeSearch(TreeNode* n, int x) {
	if (n == nullptr) {
		cout << x << " is not in the tree. ";
		return n;
	}
	else if (x == n->info) {
		cout << x << " is in the tree. ";
		return n;
	}

	if (x < n->info)
		TreeSearch(n->left, x);
	else
		TreeSearch(n->right, x);
}
