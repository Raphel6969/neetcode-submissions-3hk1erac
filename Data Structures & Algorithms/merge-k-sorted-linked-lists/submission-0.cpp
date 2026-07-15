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
    ListNode* mergeTwoList(ListNode* p1, ListNode* p2) {
        ListNode* i = p1;
        ListNode* j = p2;
        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (i && j) {
            if (i->val <= j->val) {
                tail->next = i;
                i = i->next;
            } else {
                tail->next = j;
                j = j->next;
            }

            tail = tail->next;
        }

        tail->next = i ? i : j;

        return dummy.next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;

        if (lists.size() == 1) return lists[0];

        for (int i = 1; i < lists.size(); i++) {
            lists[i] = mergeTwoList(lists[i - 1], lists[i]);
        }

        return lists.back();
    }
};
