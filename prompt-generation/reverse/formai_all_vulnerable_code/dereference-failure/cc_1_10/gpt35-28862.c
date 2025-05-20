//FormAI DATASET v1.0 Category: Mailing list manager ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// node structure for storing email addresses
typedef struct Node {
  char email[100];
  struct Node* next;
} Node;

// function to add email to the mailing list
void addEmail(Node** headRef, char* email) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  strcpy(newNode->email, email);
  newNode->next = NULL;

  // if list is empty, make the newNode the head
  if (*headRef == NULL) {
    *headRef = newNode;
    return;
  }

  // traverse to the end of the list and add the newNode
  Node* current = *headRef;
  while (current->next != NULL) {
    current = current->next;
  }
  current->next = newNode;
}

// function to remove email from the mailing list
void removeEmail(Node** headRef, char* email) {
  // if list is empty, do nothing
  if (*headRef == NULL) {
    return;
  }

  // if head is the email to be removed, update head
  if (strcmp((*headRef)->email, email) == 0) {
    Node* temp = *headRef;
    *headRef = (*headRef)->next;
    free(temp);
    return;
  }

  // traverse through the list to find the email to be removed
  Node* current = *headRef;
  while (current->next != NULL && strcmp(current->next->email, email) != 0) {
    current = current->next;
  }

  // if email is not found, do nothing
  if (current->next == NULL) {
    return;
  }

  // remove the email from the list
  Node* temp = current->next;
  current->next = current->next->next;
  free(temp);
}

// function to print all emails in the mailing list
void printList(Node* head) {
  printf("Mailing List:\n");
  Node* current = head;
  while (current != NULL) {
    printf(" - %s\n", current->email);
    current = current->next;
  }
}

// main function to test the mailing list manager
int main() {
  Node* head = NULL;
  
  // add some emails to the list
  addEmail(&head, "john@gmail.com");
  addEmail(&head, "jane@yahoo.com");
  addEmail(&head, "bob@hotmail.com");
  addEmail(&head, "alice@gmail.com");
  
  // print the list
  printList(head);
  
  // remove an email from the list
  removeEmail(&head, "jane@yahoo.com");

  // print the updated list
  printList(head);

  return 0;
}