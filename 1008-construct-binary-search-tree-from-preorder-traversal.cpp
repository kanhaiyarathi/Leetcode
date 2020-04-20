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
    TreeNode* rootRet(vector<int>& preorder, int start, int end){
        if(start>end)
            return NULL;
        int x = preorder[start];
        TreeNode* temp = new TreeNode(x);
        
        if(start==end)
            return temp;                        
        int i = start+1;
        while(i<=end){
            if(preorder[start]<preorder[i])
                break;
            i++;
        }
        
        
        temp->left = rootRet(preorder, start+1, i-1);
        temp->right= rootRet(preorder, i,end);
        return temp;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return rootRet(preorder, 0, preorder.size()-1);
    }
};
