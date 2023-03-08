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
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* p1 = head;
        ListNode* p2 = head;
        
        if(n > 1)
        {
            // Separate P1 and P2 by n
            for(int x = 0; x < n-1; x++)
            {
                p2 = p2->next;
            }
        }
        else
        {
            // Chere if there are only 2 nodes
            // Then move 1 node apart
            if(p1->next != NULL)
            {
                p2 = p1->next;
            }
            else
            {
                // Only 1 node, so remove it
                head = NULL;
                return head;
            }
        }
        
        // Let P2 find the end
        // Now P1 and P2 are separated by N
        // and P2 is at the end, so P1
        // is at the Nth node
        while(p2->next != NULL)
        {
            p1 = p1->next;
            p2 = p2->next;
        }
        
        if(n > 1)
        {
            // Remove the node by replacing its value with next
            p1->val = p1->next->val;
            p1->next = p1->next->next;
        }
        else
        {
            // N=1, so remove the last node
            p1->next = NULL;
        }
        
        return head;
    }
};