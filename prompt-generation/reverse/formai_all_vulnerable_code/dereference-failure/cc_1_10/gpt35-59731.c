//FormAI DATASET v1.0 Category: Linked list operations ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

/* Defining structure for a linked list */
struct Node {
  int data; //stores data
  struct Node* next; //points to the next node
};

/* Function to create a new node */
struct Node* create_node(int data) {
  struct Node* new_node = malloc(sizeof(struct Node));
  new_node->data = data;
  new_node->next = NULL;
  return new_node;
}

/* Function to insert a node at the beginning of the linked list */
void insert_beg(struct Node** head, int data) {
  struct Node* new_node = create_node(data);
  new_node->next = *head;
  *head = new_node;
}

/* Function to insert a node at the end of the linked list */
void insert_end(struct Node** head, int data) {
  struct Node* new_node = create_node(data);
  struct Node* temp = *head;
  if (*head == NULL) {
    *head = new_node;
    return;
  }
  while (temp->next != NULL)
    temp = temp->next;
  temp->next = new_node;
}

/* Function to delete a node */
void delete_node(struct Node** head, int key) {
  struct Node *temp = *head, *prev;
  if (temp != NULL && temp->data == key) {
    *head = temp->next;
    free(temp);
    return;
  }
  while (temp != NULL && temp->data != key) {
    prev = temp;
    temp = temp->next;
  }
  if (temp == NULL) return;
  prev->next = temp->next;
  free(temp);
}

/* Function to display the linked list */
void display(struct Node* head) {
  struct Node* temp = head;
  printf("Current Linked List: ");
  while (temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

/* Driver code */
int main() {
  int option, data;
  struct Node* head = NULL;
  printf("Welcome to the Sherlock Holmes Linked List Operations program.\n");
  printf("Please choose an option:\n");
  while (1) { 
    printf("1. Insert node at the beginning\n");
    printf("2. Insert node at the end\n");
    printf("3. Delete a node\n");
    printf("4. Display the linked list\n");
    printf("5. Exit\n");
    scanf("%d", &option);
    switch(option) {
      case 1:
        printf("Enter data to insert: ");
        scanf("%d", &data);
        insert_beg(&head, data);
        printf("Node inserted at the beginning.\n");
        break;
      case 2:
        printf("Enter data to insert: ");
        scanf("%d", &data);
        insert_end(&head, data);
        printf("Node inserted at the end.\n");
        break;
      case 3:
        printf("Enter data to delete: ");
        scanf("%d", &data);
        delete_node(&head, data);
        printf("Node deleted.\n");
        break;
      case 4:
        display(head);
        break;
      case 5:
        printf("Goodbye!\n");
        return 0;
      default:
        printf("Invalid option. Please try again.\n");
        break;
    }
  }
  return 0;
}