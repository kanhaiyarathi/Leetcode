/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int rangeSumBST(TreeNode* root, int L, int R) {
        int ans = 0;
        if(root==NULL){
            return ans;
        }
        if(root->val >=L && root->val <=R){
            return root->val + rangeSumBST(root->left, L, R) + rangeSumBST(root->right, L,R);
        }
        else if(root->val >R){
            return rangeSumBST(root->left, L, R);
        }else{
            return rangeSumBST(root->right, L,R);
        }
    }
};
