class Solution {
public:
    void dfs(TreeNode* node, string current_path, vector<string>& result) {
        if (!node) return;
        
        if (!current_path.empty()) {
            current_path += "->";
        }
        current_path += to_string(node->val);
        
        if (!node->left && !node->right) {
            result.push_back(current_path);
            return;
        }
        
        if (node->left) dfs(node->left, current_path, result);
        if (node->right) dfs(node->right, current_path, result);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        dfs(root, "", result);
        return result;
    }
};