class Solution {
public:
    void inorder(TreeNode* root, vector<int>& temp){
        if(root->left)inorder(root->left, temp);
        temp.push_back(root->val);
        if(root->right)inorder(root->right, temp);
    }
    void update(TreeNode* root, vector<int>& nums, int& idx){
        if(!root) return;

        update(root->left, nums, idx);
        root->val = nums[idx++];
        update(root->right, nums, idx);
    }
    TreeNode* bstToGst(TreeNode* root) {
        vector<int>temp;
        inorder(root, temp);

        int n = temp.size();
        vector<int>suffix(n, 0);
        suffix[n-1] = temp[n-1];

        for(int i=n-2;i>=0;i--){
            suffix[i] = suffix[i+1] + temp[i];
        }

        int index = 0;
        update(root, suffix, index);

        return root;
    }
};