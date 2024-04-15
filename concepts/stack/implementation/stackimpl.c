#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// STACK: First In Last Out

struct Node
{
  int data;
  struct Node *next;
};

// Function to create a new node
struct Node *createNode(int data)
{
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

// Insert at beginning
struct Node *push(struct Node *head, int data)
{
  struct Node *newNode = createNode(data);
  newNode->next = head;
  return newNode;
}

// Pop from stack: remove first element
struct Node *pop(struct Node *head)
{
  if (head == NULL)
  {
    printf("Stack Underflow :: Cannot pop from an empty stack.\n");
    return NULL;
  }
  struct Node *temp = head;
  head = head->next;
  free(temp);
  return head;
}

// Function to print linked list
void printStack(struct Node *head)
{
  printf("STACK: ");
  while (head != NULL)
  {
    printf("%d -> ", head->data);
    head = head->next;
  }
  printf("NULL\n");
}

// Function to free stack
struct Node *freeStack(struct Node *head)
{
  while (head != NULL)
  {
    struct Node *temp = head;
    head = head->next;
    free(temp);
  }
  return NULL;
}

// Function to check if the stack is empty
int isEmpty(struct Node *head)
{
  return head == NULL;
}

int main()
{
  printf("Hello, world!\n");
  struct Node *head = NULL;
  head = push(head, 1);
  head = push(head, 2);
  head = push(head, 3);
  head = push(head, 4);
  head = push(head, 5);
  head = push(head, 6);
  head = push(head, 7);
  printStack(head);
  head = pop(head);
  printStack(head);
  printf("Is the stack empty? %s\n", isEmpty(head) ? "Yes" : "No");
  head = freeStack(head);
  printf("Is the stack empty? %s\n", isEmpty(head) ? "Yes" : "No");
  return 0;
}
