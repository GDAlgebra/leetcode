/**
 * Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)
 * 
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* swapPairs(struct ListNode* head){
    if(!head || !head->next)
        return head;
    struct ListNode* result = head->next, *nextpair = head->next->next;
    result->next = head;
    head->next = swapPairs(nextpair);
    return result;
}
