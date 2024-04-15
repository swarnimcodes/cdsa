#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *reverseList(struct ListNode *head)
{
    struct ListNode *c, *p, *n;
    c = head;

    while (c != NULL)
    {
        n = c->next;
        c->next = p;
        p = c;
        c = n;
    }
    head = p;
    return head;
}

int main()
{
    // Create a sample linked list for testing
    struct ListNode *head = malloc(sizeof(struct ListNode));
    head->val = 1;

    struct ListNode *second = malloc(sizeof(struct ListNode));
    second->val = 2;
    head->next = second;

    struct ListNode *third = malloc(sizeof(struct ListNode));
    third->val = 3;
    second->next = third;
    third->next = NULL;

    // Call your reverseList function here
    struct ListNode *reversedHead = reverseList(head);

    // Print the reversed list to check the result
    struct ListNode *current = reversedHead;
    while (current != NULL)
    {
        printf("%d ", current->val);
        current = current->next;
    }

    // Don't forget to free the allocated memory for the linked list nodes
    // Free the nodes in the reverse order they were created
    free(third);
    free(second);
    free(head);

    return 0;
}