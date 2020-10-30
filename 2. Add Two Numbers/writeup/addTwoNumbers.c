/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include <stdio.h>
#include <stdlib.h>
#include "addTwoNumbers.h"

/* 创建空节点，next成员指向NULL */
struct ListNode *init_null(void)
{
    struct ListNode *l = (struct ListNode *)malloc(sizeof(struct ListNode));
    l->val = 9999;
    l->next = NULL;

    return l;
}

struct ListNode *addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    struct ListNode *l3 = init_null();
    struct ListNode *new_node = l3;

    int val;
    int carry = 0;

    /* 情况一：当l1、l2都不为空时，两者相加，注意进位 */
    while (l1 != NULL && l2 != NULL) {
        val = l1->val + l2->val + carry;
        carry = 0;

        if (val >= 10) {
            carry = 1;
            new_node->val = val - 10;
        } else {
            new_node->val = val;
        }

        l1 = l1->next;
        l2 = l2->next;

        // 当l1不为空，或者l2不为空时，创建l3的下一个节点
        if (l1 != NULL || l2 != NULL) {
            new_node->next = init_null();
            new_node = new_node->next;
        }
    }


    /* 情况二：当l1还有剩余元素，直接附加上去，注意进位 */
    if (l1 != NULL && l2 == NULL) {
        while (l1 != NULL) {
            val = l1->val + carry;
            carry = 0;

            if (val >= 10) {
                carry = 1;
                new_node->val = val - 10;
            } else {
                new_node->val = val;
            }

            l1 = l1->next;

            // 当l1不为空时，创建l3的下一个节点
            if (l1 != NULL) {
                new_node->next = init_null();
                new_node = new_node->next;
            }
        }
    }

    /* 情况三：当l2还有剩余元素，直接附加上去，注意进位 */
    if (l1 == NULL && l2 != NULL) {
        while (l2 != NULL) {
            val = l2->val + carry;
            carry = 0;

            if (val >= 10) {
                carry = 1;
                new_node->val = val - 10;
            } else {
                new_node->val = val;
            }

            l2 = l2->next;

            // 当l2不为空时，创建l3的下一个节点
            if (l2 != NULL) {
                new_node->next = init_null();
                new_node = new_node->next;
            }
        }
    }
    
    /* 情况四：当l1和l2都为空，但还有进位时 */
    if (l1 == NULL && l2 == NULL && carry == 1) {
        new_node->next = init_null();
        new_node = new_node->next;
        new_node->val = carry;
        new_node->next = NULL;
    }

    return l3;
}