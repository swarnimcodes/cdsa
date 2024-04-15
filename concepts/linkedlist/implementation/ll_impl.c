#include <stdio.h>
#include <stdlib.h>

// Node
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

// Function to insert a new node at the beginning of LL
struct Node *insertAtBeginning(struct Node *head, int data)
{
  struct Node *newNode = createNode(data);
  newNode->next = head;
  return newNode;
}

struct Node *insertAtEnd(struct Node *head, int data)
{
  struct Node *newNode = createNode(data);
  if (head == NULL)
  {
    return newNode;
  }

  struct Node *temp = head;
  while (temp->next != NULL)
  {
    temp = temp->next;
  }
  temp->next = newNode;
  return head;
}

// Function to delete a node with a given value from a linked list
struct Node *deleteNode(struct Node *head, int data)
{
  if (head == NULL)
  {
    return NULL;
  }
  if (head->data == data)
  {
    struct Node *temp = head;
    head = head->next;
    free(temp);
    return head;
  }

  struct Node *temp = head;
  while (temp->next != NULL && temp->next->data != data)
  {
    temp = temp->next;
  }

  if (temp->next != NULL)
  {
    struct Node *toDelete = temp->next;
    temp->next = temp->next->next;
    free(toDelete);
  }
  return head;
}

// Function to search for a node with given value in the linked list
struct Node *searchNode(struct Node *head, int data)
{
  struct Node *temp = head;
  while (temp != NULL)
  {
    if (temp->data == data)
    {
      return temp;
    }
    temp = temp->next;
  }
  return NULL;
}

void printStack(struct Node *head)
{
  struct Node *temp = head;
  while (temp != NULL)
  {
    printf("%d -> ", temp->data);
    temp = temp->next;
  }
  printf("NULL\n");
}

void freeLinkedListMemory(struct Node *head)
{
  struct Node *temp;
  while (head != NULL)
  {
    temp = head;
    head = (*head).next;
    free(temp);
  }
}

int main()
{
  printf("Hello world\n");
  struct Node *head = NULL;
  head = insertAtBeginning(head, 3);
  head = insertAtBeginning(head, 2);
  head = insertAtBeginning(head, 1);
  printStack(head);
  head = deleteNode(head, 3);
  printStack(head);

  head = insertAtEnd(head, 4);
  head = insertAtEnd(head, 5);
  printStack(head);

  int toSearch = 3;
  struct Node *searchResult = searchNode(head, toSearch);
  if (searchResult != NULL)
  {
    printf("Element %d found in the LL.\n", toSearch);
  }
  else
  {
    printf("Element %d not found in the LL.\n", toSearch);
  }
  freeLinkedListMemory(head);
  return 0;
}
