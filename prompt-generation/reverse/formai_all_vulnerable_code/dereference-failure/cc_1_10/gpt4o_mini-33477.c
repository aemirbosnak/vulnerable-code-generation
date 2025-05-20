//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LENGTH 100
#define EMAIL_LENGTH 100

typedef struct User {
    int id;
    char name[NAME_LENGTH];
    char email[EMAIL_LENGTH];
    struct User *next;
} User;

User *head = NULL;

void addUser(int id, const char *name, const char *email) {
    User *newUser = (User *)malloc(sizeof(User));
    newUser->id = id;
    strncpy(newUser->name, name, NAME_LENGTH);
    strncpy(newUser->email, email, EMAIL_LENGTH);
    newUser->next = head;
    head = newUser;
    printf("User added: ID=%d, Name=%s, Email=%s\n", id, name, email);
}

void removeUser(int id) {
    User *temp = head;
    User *prev = NULL;
    
    while (temp != NULL && temp->id != id) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("User with ID=%d not found.\n", id);
        return;
    }

    if (prev == NULL) {
        head = temp->next;
    } else {
        prev->next = temp->next;
    }

    free(temp);
    printf("User with ID=%d has been removed.\n", id);
}

void displayUsers() {
    User *temp = head;
    if (temp == NULL) {
        printf("No users to display.\n");
        return;
    }
    
    printf("User List:\n");
    while (temp != NULL) {
        printf("ID: %d, Name: %s, Email: %s\n", temp->id, temp->name, temp->email);
        temp = temp->next;
    }
}

User* searchUser(int id) {
    User *temp = head;
    while (temp != NULL) {
        if (temp->id == id) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

void freeUsers() {
    User *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    int choice, id;
    char name[NAME_LENGTH], email[EMAIL_LENGTH];

    do {
        printf("\nUser Database Menu:\n");
        printf("1. Add User\n");
        printf("2. Remove User\n");
        printf("3. Display Users\n");
        printf("4. Search User\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter ID: ");
                scanf("%d", &id);
                printf("Enter Name: ");
                scanf("%s", name);
                printf("Enter Email: ");
                scanf("%s", email);
                addUser(id, name, email);
                break;
            case 2:
                printf("Enter ID of user to remove: ");
                scanf("%d", &id);
                removeUser(id);
                break;
            case 3:
                displayUsers();
                break;
            case 4:
                printf("Enter ID of user to search: ");
                scanf("%d", &id);
                User *foundUser = searchUser(id);
                if (foundUser) {
                    printf("User found - ID: %d, Name: %s, Email: %s\n", foundUser->id, foundUser->name, foundUser->email);
                } else {
                    printf("User with ID=%d not found.\n", id);
                }
                break;
            case 5:
                printf("Exiting program. Freeing resources...\n");
                freeUsers();
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 5);

    return 0;
}