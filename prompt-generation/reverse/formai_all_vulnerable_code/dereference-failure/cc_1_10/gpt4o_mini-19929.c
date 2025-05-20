//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LEN 50
#define MAX_USERS 100

typedef struct User {
    int id;
    char name[NAME_LEN];
    struct User* next;
} User;

User* head = NULL;
int userCount = 0;

void addUser(int id, const char* name) {
    if (userCount >= MAX_USERS) {
        printf("Database is full, cannot add more users.\n");
        return;
    }
    
    User* newUser = (User*)malloc(sizeof(User));
    newUser->id = id;
    strcpy(newUser->name, name);
    newUser->next = head; // New user points to current head
    head = newUser; // New user becomes the new head
    userCount++;
    
    printf("User added: ID=%d, Name=%s\n", id, name);
}

void displayUsers() {
    if (head == NULL) {
        printf("No users in the database.\n");
        return;
    }
    
    User* current = head;
    printf("User List:\n");
    while (current != NULL) {
        printf("ID: %d, Name: %s\n", current->id, current->name);
        current = current->next;
    }
}

User* searchUser(int id) {
    User* current = head;
    while (current != NULL) {
        if (current->id == id) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void freeUserDatabase() {
    User* current = head;
    User* temp;
    while (current != NULL) {
        temp = current;
        current = current->next;
        free(temp);
    }
    head = NULL;
    userCount = 0;
}

int main() {
    int choice, id;
    char name[NAME_LEN];
    
    do {
        printf("\nSimple User Database Menu:\n");
        printf("1. Add User\n");
        printf("2. Display Users\n");
        printf("3. Search User\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter User ID: ");
                scanf("%d", &id);
                printf("Enter User Name: ");
                scanf("%s", name);
                addUser(id, name);
                break;
                
            case 2:
                displayUsers();
                break;

            case 3:
                printf("Enter User ID to search: ");
                scanf("%d", &id);
                User* foundUser = searchUser(id);
                if (foundUser != NULL) {
                    printf("User found: ID=%d, Name=%s\n", foundUser->id, foundUser->name);
                } else {
                    printf("User with ID=%d not found.\n", id);
                }
                break;

            case 4:
                printf("Exiting...\n");
                freeUserDatabase();
                break;

            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 4);
    
    return 0;
}