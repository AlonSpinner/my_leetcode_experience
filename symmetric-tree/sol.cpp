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
    bool isSymmetric(TreeNode* root) {
        return this->isMirror(root -> left, root -> right);
    }
private:
    bool isMirror(TreeNode* left_tree, TreeNode* right_tree) {
        //is not a mirror by root value
        if (left_tree -> val != right_tree -> val)
            return false;
        
        //reached the end
        if (left_tree -> left == NULL && left_tree -> right == NULL
        && right_tree -> left == NULL && right_tree -> right == NULL)
            return true;

        //if cant mirror: return false
        if (left_tree -> left == NULL && right_tree -> right != NULL)
            return false;
        if (left_tree -> left != NULL && right_tree -> right == NULL)
            return false;
        if (left_tree -> right == NULL && right_tree -> left != NULL)
            return false;
        if (left_tree -> right != NULL && right_tree -> left == NULL)
            return false;

        //check mirroring possabilities
        bool case1 = true;
        if (left_tree -> right != NULL && right_tree -> left != NULL)
            case1 = isMirror(left_tree -> right, right_tree -> left);
        bool case2 = true;
        if (left_tree -> left != NULL && right_tree -> right != NULL)
            case2 = isMirror(left_tree -> left, right_tree -> right);
        if (case1 && case2)
            return true;
        
        return false; //there are more cases?
        
    }
};

int main() {
    Solution s;
    TreeNode tree1_left(3);
    TreeNode tree1_right(4);
    TreeNode tree1_root(2, &tree1_left, &tree1_right);

    TreeNode tree2_left(4);
    TreeNode tree2_right(3);
    TreeNode tree2_root(2, &tree2_left, &tree2_right);

    TreeNode tree(1, &tree1_root, &tree2_root);

    bool is_symmetric =  s.isSymmetric(&tree);
    std::cout << std::boolalpha <<is_symmetric << std::endl;
}

/** BETTER CODE
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return Helper(root, root);
    }
private:
    bool Helper(TreeNode* root1, TreeNode* root2) {
        if( !root1 && !root2 )  return true;
        if( !root1 || !root2 )  return false;
        return ( root1->val == root2->val &&
                 Helper(root1->left, root2->right) &&
                 Helper(root1->right, root2->left) );
        
    }
};