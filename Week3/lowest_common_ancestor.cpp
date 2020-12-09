#include <vector>
#include <iostream>
#include <stdlib.h>

using std::vector;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (root == nullptr) return nullptr;
		if (root == p) return p;
		if (root == q) return q;
		TreeNode* left = lowestCommonAncestor(root->left, p, q);
		TreeNode* right = lowestCommonAncestor(root->right, p, q);
		if (left && right) return root;
		return left ? left : right;
	}
};

int main(int argc, char const *argv[])
{
	// [3,5,1,6,2,0,8,null,null,7,4]
	// 5
	// 1
	// XXXX: TODO add an function generate Tree from a list, null -> -1
	TreeNode* root = new TreeNode(3);
	TreeNode* n1 = new TreeNode(5);
	TreeNode* n2 = new TreeNode(1);
	TreeNode* n3 = new TreeNode(6);
	TreeNode* n4 = new TreeNode(2);
	TreeNode* n5 = new TreeNode(0);
	TreeNode* n6 = new TreeNode(8);
	TreeNode* n7 = nullptr;
	TreeNode* n8 = nullptr;
	TreeNode* n9 = new TreeNode(7);
	TreeNode* n10 = new TreeNode(4);

	root->left = n1; // i * 2 + 1
	root->right = n2; // (i + 1) * 2
	n1->left = n3;
	n1->right = n4;
	n2->left = n5;
	n2->right = n6;
	n3->left = n7;
	n3->right = n8;
	n4->left = n9;
	n4->right = n10;

	TreeNode* p = n1;
	TreeNode* q = n2;

	Solution s;
	TreeNode* node = s.lowestCommonAncestor(root, p, q);
	std::cout << node->val << std::endl;

	return 0;
}
