class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Min heap based on node value
        priority_queue<ListNode*, vector<ListNode*>, 
            function<bool(ListNode*, ListNode*)>> pq(
                [](ListNode* a, ListNode* b) {
                    return a->val > b->val;
                }
            );

        // Push head of each non-empty list
        for (auto list : lists) {
            if (list != nullptr) {
                pq.push(list);
            }
        }

        // Dummy node to build result
        ListNode dummy(0);
        ListNode* tail = &dummy;

        // Merge process
        while (!pq.empty()) {
            ListNode* node = pq.top();
            pq.pop();

            tail->next = node;
            tail = tail->next;

            if (node->next != nullptr) {
                pq.push(node->next);
            }
        }

        return dummy.next;
    }
};
