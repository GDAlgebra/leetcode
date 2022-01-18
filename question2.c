/**
 * You are given two non-empty linked lists representing two non-negative integers. 
 * The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
 * You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
  struct ListNode* p1 = l1;
  struct ListNode* p2 = l2;
  struct ListNode* l = (struct ListNode*)malloc(sizeof(struct ListNode));
  struct ListNode* p = l;
  int jw = 0;

  while(p1!=NULL || p2!=NULL){
    if (p1!=NULL && p2!=NULL){
      p->next = (struct ListNode*)malloc(sizeof(struct ListNode));
      p = p->next;
      p->val = p1->val + p2->val;
      p1 = p1->next;
      p2 = p2->next;
    }
    else if (p1 != NULL){
      p->next = (struct ListNode*)malloc(sizeof(struct ListNode));
      p = p->next;
      p->val = p1->val;
      p1 = p1->next;
    }
    else if (p2 != NULL){
      p->next = (struct ListNode*)malloc(sizeof(struct ListNode));
      p = p->next;
      p->val = p2->val;
      p2 = p2->next;
    }
  }
  p->next = NULL;

  p = l;
  while (p->next != NULL) {
    p->next->val += jw;
    if (p->next->val >= 10) {
      p->next->val -= 10;
      jw = 1;
    } else {
      jw = 0;
    }
    p = p->next;
  }

  if (jw == 1)
  {
    jw = 0;
    p->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    p = p->next;
    p->val = 1;
    p->next = NULL;
  }

  return l->next;
}
