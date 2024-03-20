// You are given two linked lists: list1 and list2 of sizes n and m respectively.
// Remove list1's nodes from the ath node to the bth node, and put list2 in their place.
// The blue edges and nodes in the following figure indicate the result:
// Build the result list and return its head.

class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* head1 = list1;
        ListNode* head2 = list2;
        ListNode* ptr1 = list1;
        for (int i = 1; i < a; i++) {
            ptr1 = ptr1->next;
        }
        ListNode* ptr2 = ptr1;
        for (int i = a; i <= b + 1; i++) {
            ptr2 = ptr2->next;
        }
        ListNode* ptr2_end = head2;
        while (ptr2_end->next != nullptr) {
            ptr2_end = ptr2_end->next;
        }
        ptr1->next = head2;
        ptr2_end->next = ptr2;

        return head1;
    }
};
