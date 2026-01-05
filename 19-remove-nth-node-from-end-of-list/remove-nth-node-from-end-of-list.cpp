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

        // Create a dummy node to handle edge cases smoothly
        ListNode* dummy = new ListNode(0, head);
        ListNode* fast = dummy;
        ListNode* slow = dummy;

        // Move fast pointer n steps ahead
        for(int i = 0; i < n; i++) {
            fast = fast->next;
        }

        // Move both pointers until fast reaches the end
        while(fast->next != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        // Delete the target node
        ListNode* del = slow->next;
        slow->next = del->next;
        delete del;

        return dummy->next; // New head
    }
};
