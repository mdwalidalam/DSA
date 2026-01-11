class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Dummy node to simplify edge cases
        ListNode dummy;
        ListNode* current = &dummy;

        // Merge while both lists have nodes
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                current->next = list1;
                list1 = list1->next;
            } else {
                current->next = list2;
                list2 = list2->next;
            }
            current = current->next;
        }

        // Attach remaining nodes (only one list can be non-null)
        current->next = (list1 != nullptr) ? list1 : list2;

        return dummy.next;
    }
};
