class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1) return list2;
        if (!list2) return list1;

        ListNode dummy(0);
        ListNode* tail = &dummy;

        ListNode* p1 = list1;
        ListNode* p2 = list2;

        while (p1 && p2) {
            if (p1->val <= p2->val) {
                tail->next = p1;
                p1 = p1->next;
            } else {
                tail->next = p2;
                p2 = p2->next;
            }
            tail = tail->next;
        }

        tail->next = p1 ? p1 : p2;

        return dummy.next;
    }
};