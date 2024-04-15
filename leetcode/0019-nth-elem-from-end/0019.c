#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *removeNthFromEnd(struct ListNode *head, int n)
{
    if (head->next == NULL) return head->next; // case 1 element
    struct ListNode *slow = head;
    struct ListNode *fast = head;

    while (n--) {
        fast = fast->next;
    }

    if (fast!=NULL) {
        while(fast->next != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
        slow->next = slow->next->next;
    } else {
        slow->val = slow->next->val;
        slow->next = slow->next->next;
    }
    return head;
    
}

int main()
{
    // Create a sample linked list for testing
    struct listnode *head = malloc(sizeof(struct listnode));
    head->val = 1;

    struct ListNode *second = malloc(sizeof(struct ListNode));
    second->val = 2;
    head->next = second;

    struct ListNode *third = malloc(sizeof(struct ListNode));
    third->val = 3;
    second->next = third;
    third->next = NULL;

    // Print the linked list
    struct ListNode *current = head;
    while (current != NULL)
    {
        printf("%d -> ", current->val);
        current = current->next;
    }
    printf("NULL\n");

    // Remove nth from end
    removeNthFromEnd(head, 2);

    current = head;
    while (current != NULL)
    {
        printf("%d -> ", current->val);
        current = current->next;
    }
    printf("NULL\n");

    // Don't forget to free the allocated memory for the linked list nodes
    // Free the nodes in the reverse order they were created
    free(third);
    free(second);
    free(head);

    return 0;
}
