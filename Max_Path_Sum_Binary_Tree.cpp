#include<bits/stdc++.h>
using namespace std;
class TreeNode{
public:
     int val;
     TreeNode* left;
     TreeNode* right;
};
class Solution {
public:
    int ans = INT_MIN;
    int dfs(TreeNode* root){
        if(!root)
            return 0;
        
        int val = root->val;
        int m1 = dfs(root->left);
        int m2 = dfs(root->right);
        // 4 types of paths which include this node
        
        int path1,path2,path3,path4;
        path1 = m1+val;
        path2 = m2+val;
        path3 = m1+m2+val;
        path4 = val;
        ans = max(ans,max(path1,path2));
        ans = max(ans,max(path3,path4));
        return max(path1,max(path2,path4));
        
    }
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return ans;
    }
};