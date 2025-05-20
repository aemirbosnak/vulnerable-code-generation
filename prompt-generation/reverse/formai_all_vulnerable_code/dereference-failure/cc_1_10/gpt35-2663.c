//FormAI DATASET v1.0 Category: Linked list operations ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

struct node {
   int data;
   struct node *next;
};

typedef struct node Node;

Node *head = NULL;

void insertNode(int data) {
   Node *newNode = (Node*)malloc(sizeof(Node));
   newNode->data = data;
   newNode->next = head;
   head = newNode;
}

void deleteNode(int key) {
   Node *temp = head, *prev;
   if (temp != NULL && temp->data == key) {
       head = temp->next;
       free(temp);
       return;
   }
   while (temp != NULL && temp->data != key) {
       prev = temp;
       temp = temp->next;
   }
   if (temp == NULL)
       return;
   prev->next = temp->next;
   free(temp);
}

void displayList() {
   Node *ptr = head;
   while (ptr != NULL) {
       printf("%d ", ptr->data);
       ptr = ptr->next;
   }
   printf("\n");
}

void reverseList() {
   Node *prev = NULL;
   Node *current = head;
   Node *next = NULL;
   while (current != NULL) {
       next = current->next;
       current->next = prev;
       prev = current;
       current = next;
   }
   head = prev;
}

int main() {
    insertNode(1);
    insertNode(2);
    insertNode(3);
    insertNode(4);
    printf("Initial List: ");
    displayList();
    deleteNode(3);
    printf("After deleting 3: ");
    displayList();
    reverseList();
    printf("List after reversing: ");
    displayList();
    return 0;
}