class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int>> result;

      
        if (!root) return result;

        
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
           
            vector<int> level;
            int size = q.size(); 

            for (int i = 0; i < size; ++i) {
                TreeNode* current = q.front();
                q.pop();

                
                level.push_back(current->val);

                
                if (current->left) q.push(current->left);
                if (current->right) q.push(current->right);
            }

           
            result.push_back(level);
        }

        return result;
    }
};
