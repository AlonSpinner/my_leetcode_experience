#include <iostream>

 //Definition for a binary tree node.
struct TreeNode {
    int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root)
            return root;
        if (root->left) {
            invertTree(root -> left);
        }
        if (root->right) {
            invertTree(root -> right);
        }
        if (root -> left && root->right) {
            std::swap(root -> left, root -> right);
        }
        return root;
    }
};

int main() {
    Solution s;
    TreeNode tree1_left(1);
    TreeNode tree1_right(5);
    TreeNode tree1_root(2, &tree1_left, &tree1_right);

    TreeNode tree2_left(5);
    TreeNode tree2_right(3);
    TreeNode tree2_root(2, &tree2_left, &tree2_right);

    TreeNode tree(1, &tree1_root, &tree2_root);
    
    TreeNode* result = s.invertTree(&tree);    
}