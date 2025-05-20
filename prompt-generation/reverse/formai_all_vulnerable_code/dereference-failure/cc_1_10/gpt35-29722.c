//FormAI DATASET v1.0 Category: Mailing list manager ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 100

typedef struct Node { 
  char name[MAX_NAME_LENGTH]; 
  char email[MAX_EMAIL_LENGTH]; 
  struct Node *next; 
} Node;

Node *createNode(char *name, char *email) {
  Node *newNode = (Node*)malloc(sizeof(Node));
  if(newNode == NULL) {
    printf("Failed to allocate memory.\n");
    exit(0);
  }
  strcpy(newNode->name, name);
  strcpy(newNode->email, email);
  newNode->next = NULL;
  return newNode;
}

void insertNode(Node **head, Node *newNode) {
  if(*head == NULL) {
    *head = newNode;
    return;
  }
  Node *curr = *head;
  Node *prev = NULL;
  while(curr != NULL && strcmp(newNode->name, curr->name) > 0) {
    prev = curr;
    curr = curr->next;
  }
  if(prev == NULL) {
    newNode->next = *head;
    *head = newNode;
  } else {
    prev->next = newNode;
    newNode->next = curr;
  }
}

void deleteNode(Node **head, char *name) {
  Node *curr = *head;
  Node *prev = NULL;
  while(curr != NULL && strcmp(name, curr->name) != 0) {
    prev = curr;
    curr = curr->next;
  }
  if(curr == NULL) {
    printf("Node not found.\n");
    return;
  }
  if(prev == NULL) *head = (*head)->next;
  else prev->next = curr->next;
  free(curr);
}

void printList(Node *head) {
  if(head == NULL) {
    printf("List is empty.\n");
    return;
  }
  Node *curr = head;
  printf("Name\tEmail\n");
  while(curr != NULL) {
    printf("%s\t%s\n", curr->name, curr->email);
    curr = curr->next;
  }
}

void saveToFile(Node *head) {
  FILE *fp = fopen("mailingList.txt", "w");
  if(fp == NULL) {
    printf("Failed to open file.\n");
    return;
  }
  Node *curr = head;
  while(curr != NULL) {
    fprintf(fp, "%s,%s\n", curr->name, curr->email);
    curr = curr->next;
  }
  fclose(fp);
  printf("Mailing list saved to file.\n");
}

void loadFromFile(Node **head) {
  FILE *fp = fopen("mailingList.txt", "r");
  if(fp == NULL) {
    printf("Failed to open file.\n");
    return;
  }
  char buffer[MAX_NAME_LENGTH + MAX_EMAIL_LENGTH + 2];
  while(fgets(buffer, MAX_NAME_LENGTH + MAX_EMAIL_LENGTH + 2, fp) != NULL) {
    char *name = strtok(buffer, ",");
    char *email = strtok(NULL, "\n");
    insertNode(head, createNode(name, email));
  }
  fclose(fp);
  printf("Mailing list loaded from file.\n");
}

void menu() {
  printf("\nMenu:\n");
  printf("1. Add new contact\n");
  printf("2. Delete a contact\n");
  printf("3. Print the mailing list\n");
  printf("4. Save the mailing list to file\n");
  printf("5. Load the mailing list from file\n");
  printf("6. Exit\n");
}

int main() {
  Node *head = NULL;
  int choice;
  char name[MAX_NAME_LENGTH], email[MAX_EMAIL_LENGTH];
  while(1) {
    menu();
    printf("Enter your choice: ");
    scanf("%d", &choice);
    getchar(); //consume new line character
    switch(choice) {
      case 1:
        printf("Enter name: ");
        fgets(name, MAX_NAME_LENGTH, stdin);
        name[strcspn(name, "\n")] = 0;
        printf("Enter email: ");
        fgets(email, MAX_EMAIL_LENGTH, stdin);
        email[strcspn(email, "\n")] = 0;
        insertNode(&head, createNode(name, email));
        printf("Contact added.\n");
        break;
      case 2:
        printf("Enter name to delete: ");
        fgets(name, MAX_NAME_LENGTH, stdin);
        name[strcspn(name, "\n")] = 0;
        deleteNode(&head, name);
        break;
      case 3:
        printList(head);
        break;
      case 4:
        saveToFile(head);
        break;
      case 5:
        loadFromFile(&head);
        break;
      case 6:
        printf("Goodbye!\n");
        return 0;
      default:
        printf("Invalid choice.\n");
    }
  }
  return 0;
}