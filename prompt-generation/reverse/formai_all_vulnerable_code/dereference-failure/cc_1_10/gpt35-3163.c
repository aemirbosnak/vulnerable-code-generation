//FormAI DATASET v1.0 Category: Password management ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct password {
    char *service;
    char *username;
    char *password;
    struct password *next;
};

struct password *head = NULL;
struct password *current = NULL;

void insert_password() {
    struct password *new_password = malloc(sizeof(struct password));
    char* service = malloc(50 * sizeof(char));
    char* username = malloc(50 * sizeof(char));
    char* password = malloc(50 * sizeof(char));
    printf("Enter service name: ");
    scanf("%s", service);
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);
    new_password->service = service;
    new_password->username = username;
    new_password->password = password;
    new_password->next = NULL;
    if(head == NULL) {
        head = new_password;
        current = new_password;
    }
    else {
        current->next = new_password;
        current = new_password;
    }
}

struct password *find_password() {
  char* service = malloc(50 * sizeof(char));
  printf("Enter service name: ");
  scanf("%s", service);
  struct password *temp = head;
  while(temp != NULL) {
    if(strcmp(service, temp->service) == 0) {
      printf("Service: %s\n", temp->service);
      printf("Username: %s\n", temp->username);
      printf("Password: %s\n", temp->password);
        return NULL;
    }
    temp = temp->next;
  }
  printf("Service not found\n");
  return NULL;
}

void print_passwords() {
  printf("Service\t\tUsername\t\tPassword\n");
  struct password *temp = head;
  while(temp != NULL) {
    printf("%s\t\t%s\t\t%s\n", temp->service, temp->username, temp->password);
    temp = temp->next;
  }
}

void delete_password() {
  char* service = malloc(50 * sizeof(char));
    printf("Enter service name to delete: ");
    scanf("%s", service);
    struct password *temp = head;
    struct password *prev;
    if(temp != NULL && strcmp(service, temp->service) == 0) {
        head = temp->next;
        free(temp);
        return;
    }
    while(temp != NULL && strcmp(service, temp->service) != 0) {
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL) return;
    prev->next = temp->next;
    free(temp);
}

int main() {
    int choice = 0;
    while(choice != 5) {
        printf("\nPassword Management Menu:\n");
        printf("1. Insert password\n");
        printf("2. Find password\n");
        printf("3. Print all passwords\n");
        printf("4. Delete a password\n");
        printf("5. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: insert_password();
                break;
            case 2: find_password();
                break;
            case 3: print_passwords();
                break;
            case 4: delete_password();
                break;
            case 5: exit(0);
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}