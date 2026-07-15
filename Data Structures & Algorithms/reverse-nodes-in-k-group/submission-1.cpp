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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;

        for (int i = 0; i < k; i++) {
            if (!temp) return head;
            temp = temp->next;
        }

        ListNode* prev = nullptr;
        ListNode* curr = head;
        int tries = 0;

        while (curr && tries < k) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
            tries++;
        }

        head->next = reverseKGroup(curr, k);

        return prev;
    }
};