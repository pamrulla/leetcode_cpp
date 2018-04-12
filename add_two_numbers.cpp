/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* root= NULL;
        ListNode* end= NULL;
        
        int remainder = 0;
        
        while(l1 || l2)
        {
            int x = l1 ? l1->val : 0;
            int y = l2 ? l2->val : 0;
            
            int res = x + y + remainder;
            
            remainder = res / 10;
            
            res = res % 10;
            
            ListNode* temp = new ListNode(res);
            
            if(root == NULL)
            {
                root = temp;
                end = temp;
            }
            else
            {
                end->next = temp;
                end = temp;
            }
            
            l1 = l1 ? l1->next : NULL; 
            l2 = l2 ? l2->next : NULL;
        }
        
        if(remainder != 0)
        {
            ListNode* temp = new ListNode(remainder);
            if(root == NULL)
            {
                root = temp;
                end = temp;
            }
            else
            {
                end->next = temp;
                end = temp;
            }
        }
        
        return root;
        
        
    }
};