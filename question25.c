/**
 * Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.
 * k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.
 * You may not alter the values in the list's nodes, only nodes themselves may be changed.
 *
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseKGroup(struct ListNode* head, int k){
    struct ListNode* point = head, *group[k];
    int i = 0;
    for(; i < k; i++){
        if(!point)
            return head;
        group[i] = point;
        point = point->next;
    }
    for(i--; i > 0; i--){
        group[i]->next = group[i - 1];
    }
    group[0]->next = reverseKGroup(point, k);
    return group[k - 1];
}
