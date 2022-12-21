#include <vector>
#include <unordered_map>
#include <iostream>


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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p -> val != q -> val)
            return false;
        if (p->left == NULL && q->left == NULL && p-> right == NULL && q ->right == NULL)
            return true;
        if (p->left == NULL && q->left == NULL)
            return isSameTree(p -> right, q -> right);
        if (p->right == NULL && q->right == NULL)
            return isSameTree(p -> left, q -> left);
        if (p->left != NULL && q->left != NULL && p-> right != NULL && q ->right != NULL)
            return isSameTree(p -> left, q -> left) && isSameTree(p -> right, q -> right);
        return false; //all other cases 
    }
};

int main() {
    Solution s;
    TreeNode tree1_left(2);
    TreeNode tree1_right(4);
    TreeNode tree1_root(1, &tree1_left, &tree1_right);

    TreeNode tree2_left(2);
    TreeNode tree2_right(4);
    TreeNode tree2_root(1, &tree2_left, &tree2_right);

    bool same_tree =  s.isSameTree(&tree1_root, &tree2_root);
    std::cout << std::boolalpha <<same_tree << std::endl;
}