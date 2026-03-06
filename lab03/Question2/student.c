// Question2/student.c
// ------------------------------------------------------------
// CS Lab03 - Swap Nodes in Pairs 
//
// TODO:
//   Implement swapPairs(head) to swap every two adjacent nodes.
//
// Rules:
// - Do not allocate new nodes.
// - Do not swap values; swap nodes (rewire pointers).
// - Return the new head pointer.
// ------------------------------------------------------------
#include "student.h"

struct ListNode* swapPairs(struct ListNode* head) {
      if (head == NULL || head->next == NULL)
        return head;

    struct ListNode* newHead = head->next;
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;

    while (curr != NULL && curr->next != NULL) {

        struct ListNode* next = curr->next;

        curr->next = next->next;
        next->next = curr;

        if (prev != NULL)
            prev->next = next;

        prev = curr;
        curr = curr->next;
    }

    return newHead;
}