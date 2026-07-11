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
        ListNode* counter = head;
        int count = 0;
        while (counter) {
            count++;
            counter = counter->next;
        }
        if (count == n) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }

        int jumps = count - n - 1;

        ListNode* pointer = head;
        while (jumps--) {
            pointer = pointer->next;
        }

        if (pointer && pointer->next) {
            ListNode* temp = pointer->next;
            pointer->next = temp->next;
            delete temp;
        }

        return head;
    }
};
