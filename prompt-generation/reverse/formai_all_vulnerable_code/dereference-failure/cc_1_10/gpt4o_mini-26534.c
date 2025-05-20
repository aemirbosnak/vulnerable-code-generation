//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct User {
    int id;
    char name[50];
    char email[50];
    struct User* next;
} User;

User* head = NULL;

void addUser(int id, char* name, char* email);
void displayUsers();
void deleteUser(int id);
void freeList(User* node);
void menu();

int main() {
    menu();
    freeList(head); // Free the allocated memory before exiting
    return 0;
}

void menu() {
    int choice, id;
    char name[50], email[50];

    do {
        printf("\n--- User Database Menu ---\n");
        printf("1. Add User\n");
        printf("2. Display Users\n");
        printf("3. Delete User\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter User ID: ");
                scanf("%d", &id);
                printf("Enter User Name: ");
                scanf("%s", name);
                printf("Enter User Email: ");
                scanf("%s", email);
                addUser(id, name, email);
                break;
            case 2:
                displayUsers();
                break;
            case 3:
                printf("Enter User ID to delete: ");
                scanf("%d", &id);
                deleteUser(id);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);
}

void addUser(int id, char* name, char* email) {
    User* newUser = (User*)malloc(sizeof(User));
    newUser->id = id;
    strcpy(newUser->name, name);
    strcpy(newUser->email, email);
    newUser->next = head;
    head = newUser;
    printf("User added successfully!\n");
}

void displayUsers() {
    if (head == NULL) {
        printf("No users found.\n");
        return;
    }
    
    User* temp = head;
    printf("\n--- User List ---\n");
    while (temp != NULL) {
        printf("ID: %d, Name: %s, Email: %s\n", temp->id, temp->name, temp->email);
        temp = temp->next;
    }
}

void deleteUser(int id) {
    if (head == NULL) {
        printf("No users to delete.\n");
        return;
    }

    User* current = head;
    User* previous = NULL;

    while (current != NULL && current->id != id) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("User with ID %d not found.\n", id);
        return;
    }

    if (previous == NULL) {
        head = current->next; // Deleting the head
    } else {
        previous->next = current->next;
    }

    free(current);
    printf("User with ID %d deleted successfully.\n", id);
}

void freeList(User* node) {
    if (node == NULL) return; // Base case
    freeList(node->next); // Recursive call
    free(node); // Free the current node
}