// Question1/student.c
// ------------------------------------------------------------
// CS Lab03 - Reverse Linked List 
//
// TODO:
//   Implement reverseList(head) to reverse a singly linked list.
//
// Rules:
// - Do not allocate new nodes.
// - Do not use recursion.
// - Return the new head pointer.
// ------------------------------------------------------------

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include "student.h"

struct ListNode* reverseList(struct ListNode* head) {
    // TODO: implement
    // Hints (optional):
    // - Keep track of previous and current pointers.
    // - Iterate until current becomes NULL.

struct ListNode* prev = NULL;
    struct ListNode* curr = head;
    struct ListNode* next = NULL;

    while (curr != NULL) {

        next = curr->next;   // Save next node
        curr->next = prev;   // Reverse pointer
        prev = curr;         // Move prev forward
        curr = next;         // Move curr forward
    }

    return prev;  // New head of reversed list
}
