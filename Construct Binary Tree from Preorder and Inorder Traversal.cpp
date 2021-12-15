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
    int prei=0;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
       return build(preorder,inorder,0,inorder.size()-1);
    }
    TreeNode*build(vector<int>& preorder, vector<int>& inorder,int start,int end)
    {
        
        if(start>end)
            return NULL;
        TreeNode*node=new TreeNode(preorder[prei++]);
        int pos;
        for(int i=0;i<inorder.size();i++)
        {
            if(inorder[i]==node->val)
               { pos=i;
            break;}
            
        }
        node->left=build(preorder,inorder,start,pos-1);
         node->right=build(preorder,inorder,pos+1,end);
    return node;
    }
   
};