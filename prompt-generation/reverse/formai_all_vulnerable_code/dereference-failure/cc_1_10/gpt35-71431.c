//FormAI DATASET v1.0 Category: Password management ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLENGTH 20
#define MAXUSERNAME 20
#define MAXPASSWORD 50

typedef struct Node {
    char username[MAXUSERNAME];
    char password[MAXPASSWORD];
    struct Node* next;
} Node;

Node* head = NULL;

void printMenu() {
    printf("Password Management System\n");
    printf("--------------------------\n");
    printf("1. Add a new password \n");
    printf("2. Search for a password \n");
    printf("3. Update a password \n");
    printf("4. Delete a password \n");
    printf("5. Display all passwords \n");
    printf("6. Exit \n");
    printf("--------------------------\n");
}

Node* createNode(char* username, char* password) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->username, username);
    strcpy(newNode->password, password);
    newNode->next = NULL;
    return newNode;
}

void addPassword() {
    char username[MAXUSERNAME];
    char password[MAXPASSWORD];
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);
    Node* newNode = createNode(username, password);

    if (head == NULL) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }

    printf("Password added successfully!\n");
}

void searchPassword() {
    char username[MAXUSERNAME];
    printf("Enter username: ");
    scanf("%s", username);
    Node* current = head;
    while (current != NULL) {
        if (strcmp(current->username, username) == 0) {
            printf("Password found: %s\n", current->password);
            return;
        }
        current = current->next;
    }

    printf("Password not found for this username.\n");
}

void updatePassword() {
    char username[MAXUSERNAME];
    char password[MAXPASSWORD];
    printf("Enter username: ");
    scanf("%s", username);
    Node* current = head;
    while (current != NULL) {
        if (strcmp(current->username, username) == 0) {
            printf("Enter new password: ");
            scanf("%s", password);
            strcpy(current->password, password);
            printf("Password updated successfully!\n");
            return;
        }
        current = current->next;
    }

    printf("Password not found for this username.\n");
}

void deletePassword() {
    char username[MAXUSERNAME];
    printf("Enter username: ");
    scanf("%s", username);
    if (head == NULL) {
        printf("No passwords found.\n");
        return;
    }
    if (strcmp(head->username, username) == 0) {
        Node* temp = head;
        head = head->next;
        free(temp);
        printf("Password deleted successfully!\n");
        return;
    }
    Node* prev = head;
    Node* current = head->next;
    while (current != NULL) {
        if (strcmp(current->username, username) == 0) {
            prev->next = current->next;
            free(current);
            printf("Password deleted successfully!\n");
            return;
        }
        prev = current;
        current = current->next;
    }

    printf("Password not found for this username.\n");
}

void displayPasswords() {
    if (head == NULL) {
        printf("No passwords found.\n");
        return;
    }
    Node* current = head;
    while (current != NULL) {
        printf("Username: %s, Password: %s\n", current->username, current->password);
        current = current->next;
    }
}

int main() {
    int option;
    while (1) {
        printMenu();
        printf("Enter an option: ");
        scanf("%d", &option);
        switch (option) {
            case 1:
                addPassword();
                break;
            case 2:
                searchPassword();
                break;
            case 3:
                updatePassword();
                break;
            case 4:
                deletePassword();
                break;
            case 5:
                displayPasswords();
                break;
            case 6:
                printf("Exiting program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
}