#include <vector>
#include <iostream>
#include <deque>
#include <unordered_map>

using std::vector;
using std::deque;
using std::unordered_map;

/**
 * Definition for a binary tree node.
*/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0 || inorder.size() == 0) return nullptr;
        for (int i = 0; i < inorder.size(); i++) inorderMap[inorder[i]] = i;
        TreeNode *root = generate(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
        return root;
    }

private:
    unordered_map<int, int> inorderMap;
    TreeNode* generate(vector<int>& preorder, int ps, int pe, vector<int>& inorder, int is, int ie) {
        if (ps > pe) return nullptr;
        // int i = 0;
        // for (i = is; i <= ie; i++) if (preorder[ps] == inorder[i]) break;
        int i = inorderMap[preorder[ps]];
        int leftCount = i - is;
        TreeNode* node = new TreeNode(preorder[ps]);
        node->left = generate(preorder, ps+1, ps+leftCount, inorder, is, i-1);
        node->right = generate(preorder, ps+leftCount+1, pe, inorder, i+1, ie);
        return node;
    }
};

void bfs(TreeNode* root) {
    if (!root) return;
    deque<TreeNode*> queue;
    queue.push_back(root);
    while(!queue.empty()) {
        TreeNode* node = queue.front();
        queue.pop_front();
        std::cout << node->val << " ";
        if (node->left) queue.push_back(node->left);
        if (node->right) queue.push_back(node->right);
    }
    std::cout << std::endl;
}

void levelorder(TreeNode* root) {
    if (!root) return;
    bfs(root);
}

int main(int argc, char const *argv[])
{
    vector<int> preorder{3, 9, 20, 15, 7};
    vector<int> inorder{9, 3, 15, 20, 7};
    Solution s;
    TreeNode* root = s.buildTree(preorder, inorder);
    levelorder(root);
    return 0;
}
