/**
 * Given the head of a linked list, remove the nth node from the end of the list and return its head
 *
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    //if listnode is null, return null
    if(!head)
        return NULL;
    int i = 1;
    struct ListNode* point = head;
    while(point->next){
        i++;
        point = point->next;
    }
    //if delete the first node, then return head->next
    if(n == i) 
        return head->next;
    int j = 0;
    point = head;
    while((j++) != i - n - 1){
        point = point->next;
    }
    point->next = point->next->next;
    return head;
}
