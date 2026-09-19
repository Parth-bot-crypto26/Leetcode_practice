/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    bool isIdentical(TreeNode* p, TreeNode* q){
        if(p == nullptr || q == nullptr){
            return p == q;
        }
        return p->val == q->val && isIdentical(p->left, q->left) && isIdentical(p->right, q->right);
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == nullptr || subRoot == nullptr){
            return root == subRoot;
        }
        if(root->val == subRoot->val && isIdentical(root, subRoot)){
            return true;
        }
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};