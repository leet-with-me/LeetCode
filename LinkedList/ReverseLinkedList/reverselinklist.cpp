/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include <stack>

// https://leetcode.com/submissions/detail/911708147/?from=explore&item_id=560

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL)
        {
            return NULL;
        }
        
        // Use a stack to move to the end of the linked list
        // and accumulate all the nodes.
        // Then remove one at a time from the stack starting with the head and each
        // pop with the next value
        stack<ListNode*> nodeStack;
        ListNode* node = head;
        while(node->next != NULL)
        {
            nodeStack.push(node);
            node = node->next;
        }
        
        // Put the last node in the stack
        nodeStack.push(node);
        
        // Repopulate the linked list starting with the first
        // entry in the stack which is the last node in the linked list
        if(nodeStack.size() >= 1)
        {
            // Get the first value off the stack
            head = nodeStack.top();
            nodeStack.pop();
            ListNode* temp = head;

            // Get remain values off the stack
            while(!nodeStack.empty())
            {
                temp->next = nodeStack.top();
                nodeStack.pop();
                temp = temp->next;
            }
            
            // Set the last node next to null
            temp->next = NULL;
        }
        
        return head;
        
    }
};