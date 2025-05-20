//Gemma-7B DATASET v1.0 Category: Warehouse Management System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

struct Node {
  int item_no;
  char item_name[20];
  int quantity;
  struct Node* next;
};

void insert(struct Node** head, int item_no, char item_name[], int quantity)
{
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->item_no = item_no;
  strcpy(newNode->item_name, item_name);
  newNode->quantity = quantity;
  newNode->next = NULL;

  if (*head == NULL)
  {
    *head = newNode;
  }
  else
  {
    (*head)->next = newNode;
  }
}

void search(struct Node* head, int item_no)
{
  if (head == NULL)
  {
    printf("Item not found\n");
    return;
  }

  if (head->item_no == item_no)
  {
    printf("Item name: %s\n", head->item_name);
    printf("Quantity: %d\n", head->quantity);
  }
  else
  {
    search(head->next, item_no);
  }
}

int main()
{
  struct Node* head = NULL;

  insert(&head, 1, "Item 1", 10);
  insert(&head, 2, "Item 2", 20);
  insert(&head, 3, "Item 3", 30);

  search(head, 2);

  return 0;
}