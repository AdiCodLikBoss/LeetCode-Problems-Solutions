// Problem_Link = https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/
#include<bits/stdc++.h>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

class Solution {
public:
    ListNode* middlenode(ListNode* head) {
        ListNode* slow, *fast;
        slow =  head;
        fast =  slow->next;
        
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
    }
    int pairSum(ListNode* head) {
        ListNode* mid = middlenode(head);
        ListNode* prev = head, *curr = prev->next;
        
        while(prev!=mid) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        
        int ans = 0;
        while(curr!=NULL) {
            ans = max(ans, curr->val + prev->val);
            curr = curr->next;
            prev = prev->next;
        }
        
        return ans;
    }
};