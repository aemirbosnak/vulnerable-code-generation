//FormAI DATASET v1.0 Category: Data structures visualization ; Style: careful
#include<stdio.h>
#include<stdlib.h>

// Structure definition for doubly linked list node
struct node 
{
   int data;
   struct node *prev;
   struct node *next;
};

// Function to create a new node.
struct node* createNode(int element)
{
  // Block of memory allocation using malloc
  struct node* newNode = malloc(sizeof(struct node));
  newNode->data = element;
  newNode->prev = NULL;
  newNode->next = NULL;
  return newNode;
}

// Display function to print linked list structure to console.
// For visualization, we're going to use a rectangle to represent 
// each node with arrows showing the direction of the linked list.
void display(struct node* head)
{
   struct node* current = head;
   printf("\n\n");
   while(current != NULL)
   {
      printf(" -----------------\n");
      printf("|    %d    |\n", current->data);
      printf("|     |         |\n");
      printf("|     V         |\n");
      printf(" -----------------\n");
      current = current->next;
   }
   printf("\n\n");
}

// Function to insert a new node at the beginning of the list.
void insertAtBeginning(struct node** head, int element)
{
   struct node* newNode = createNode(element);
   if(*head == NULL)
   {
      *head = newNode;
      return;
   }
   newNode->next = *head;
   (*head)->prev = newNode;
   *head = newNode;
}

// Function to insert a new node at the end of the list.
void insertAtEnd(struct node** head, int element)
{
   struct node* newNode = createNode(element);
   if(*head == NULL)
   {
      *head = newNode;
      return;
   }
   struct node* current = *head;
   while(current->next != NULL)
   {
      current = current->next;
   }
   current->next = newNode;
   newNode->prev = current;
}

// Main function to demonstrate the program.
int main()
{
   struct node* head = NULL;

   // Create the doubly linked list
   insertAtBeginning(&head, 10);
   insertAtEnd(&head, 20);
   insertAtEnd(&head, 30);
   insertAtEnd(&head, 40);

   // Display the list structure to console using built-in visualization function
   display(head);

   return 0;
}