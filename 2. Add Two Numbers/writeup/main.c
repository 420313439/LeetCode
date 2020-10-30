/*
 *  gcc main.c addTwoNumbers.c -g -Wall -O3 -o a.out
 */
#include <stdio.h>
#include <stdlib.h>
#include "addTwoNumbers.h"

struct ListNode *init(int val)
{
    struct ListNode *l = (struct ListNode *)malloc(sizeof(struct ListNode));
    l->val = val;
    l->next = NULL;

    return l;
}

void print_node(struct ListNode *l)
{
    while (l != NULL) {
        printf("%d --> ", l->val);
        l = l->next;
    }
    puts("NULL");
}


int main(void)
{
    // l1: 2 --> 4 --> 3 
    struct ListNode *l1 = init(9);
    l1->next = init(9);
    l1->next->next = init(1);
    /*
    l1->next = init(9);
    l1->next->next = init(9);
    l1->next->next->next = init(9);
    l1->next->next->next->next = init(9);
    l1->next->next->next->next->next = init(9);
    l1->next->next->next->next->next->next = init(9);
    */
    // l2: 5 --> 6 --> 4
    struct ListNode *l2 = init(1);
    //l2->next = init(6);
    //l2->next->next = init(4);
    /*
    l2->next = init(9);
    l2->next->next = init(9);
    l2->next->next->next = init(9);
    */
    struct ListNode *l3 = addTwoNumbers(l1, l2);
    print_node(l3);

    return 0;
}