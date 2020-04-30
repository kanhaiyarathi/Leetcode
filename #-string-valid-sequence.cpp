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
    bool isLeaf(TreeNode* root){
        if(root==NULL)
         return 0;
        return root->left==NULL && root->right==NULL;
    }
    
    bool helper(TreeNode* root, vector<int>& arr, int pos){
        if(root==NULL || pos>=arr.size()){
            return 0;
        }else if(isLeaf(root) && pos==arr.size()-1){
            return root->val==arr[pos];
        }else{            
             if(root->val==arr[pos])
                return helper(root->left, arr, pos+1) || helper(root->right, arr, pos+1);
            else
                return 0;
        }
    }
    
    bool isValidSequence(TreeNode* root, vector<int>& arr) {
        return helper(root, arr, 0);
    }
};
