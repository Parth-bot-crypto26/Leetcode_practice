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
public:
    int countNodes(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }
        int leftHt = 0;
        TreeNode* leftNode = root;
        while(leftNode != nullptr){
            leftHt++;
            leftNode = leftNode->left;
        }
        int rightHt = 0;
        TreeNode* rightNode = root;
        while(rightNode != nullptr){
            rightHt++;
            rightNode = rightNode->right;
        }
        if(leftHt == rightHt){
            return (1 << leftHt) - 1;
        }
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};