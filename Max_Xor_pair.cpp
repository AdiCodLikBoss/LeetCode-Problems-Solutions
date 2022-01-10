#include<bits/stdc++.h>
using namespace std;

// Class of a single Trie Node
class Node {
    public:
     Node* left;
     Node* right;
};

// Trie Class
class Trie {
    Node* root;
    public:
     Trie() {
         root = new Node();
     }
     
     void insert(int value) {
         Node* temp = root;
         for(int j=31;j>=0;j--) {
             if((value&(1<<j))!=0) {
                 if(temp->right==NULL) {
                     temp->right = new Node();
                }
                 temp = temp->right;
             }else {
                 if(temp->left==NULL) {
                     temp->left = new Node();
                }
                 temp = temp->left;
             }
         }
     }
    int max_val(int value) {
        int curr_ans = 0;
        Node* temp = root;
        for(int j=31;j>=0;j--) {
            if((value&(1<<j))!=0) {
                if(temp->left!=NULL) {
                    temp = temp->left;
                    curr_ans+=(1<<j);
                }else {
                    temp = temp->right;
                }
            }else {
                if(temp->right!=NULL) {
                    curr_ans+=(1<<j);
                    temp = temp->right;
                }else {
                    temp = temp->left;
                }
            }
        }
        return curr_ans;
    }
    int max_xor_helper(vector<int> &vec) {
        int i;
        int max_xor = 0;
        for(i=0;i<vec.size();i++) {
            int value = vec[i];
            insert(value);
            max_xor = max(max_xor,max_val(value));
        }
        return max_xor;
    }
};

// class to find maximum xor pair in a vector
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie t;
        int ans = t.max_xor_helper(nums);
        return ans;
    }
};