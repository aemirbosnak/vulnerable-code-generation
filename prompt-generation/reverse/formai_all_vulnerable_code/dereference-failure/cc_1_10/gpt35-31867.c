//FormAI DATASET v1.0 Category: Password management ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Linked list node to hold passwords
typedef struct node {
    char *name;
    char *password;
    struct node *next;
} Node;

// Function to display menu options
void displayMenu() {
    printf("\nWelcome to your password manager!\n");
    printf("1. Add new password\n");
    printf("2. Retrieve password\n");
    printf("3. Update password\n");
    printf("4. Delete password\n");
    printf("5. Display all passwords\n");
    printf("6. Quit\n\n");
}

// Function to add a new password
Node* addPassword(Node *head) {
    char name[50];
    char password[50];

    printf("Enter name for password (max 50 characters): ");
    scanf("%s", name);

    printf("Enter password for %s (max 50 characters): ", name);
    scanf("%s", password);

    Node *newNode = malloc(sizeof(Node));
    newNode->name = malloc(strlen(name) + 1);
    strcpy(newNode->name, name);
    newNode->password = malloc(strlen(password) + 1);
    strcpy(newNode->password, password);

    newNode->next = head;
    printf("Password added successfully!\n");

    return newNode;
}

// Function to retrieve a password
void retrievePassword(Node *head) {
    char name[50];

    printf("Enter name for password to retrieve: ");
    scanf("%s", name);

    Node *currentNode = head;
    while (currentNode != NULL) {
        if (strcmp(currentNode->name, name) == 0) {
            printf("Password for %s: %s\n", currentNode->name, currentNode->password);
            return;
        }
        currentNode = currentNode->next;
    }

    printf("Password for %s not found.\n", name);
}

// Function to update a password
Node* updatePassword(Node *head) {
    char name[50];
    char password[50];

    printf("Enter name for password to update: ");
    scanf("%s", name);

    Node *currentNode = head;
    while (currentNode != NULL) {
        if (strcmp(currentNode->name, name) == 0) {
            printf("Enter new password for %s (max 50 characters): ", name);
            scanf("%s", password);

            free(currentNode->password);
            currentNode->password = malloc(strlen(password) + 1);
            strcpy(currentNode->password, password);

            printf("Password for %s updated successfully!\n", currentNode->name);
            return head;
        }
        currentNode = currentNode->next;
    }

    printf("Password for %s not found.\n", name);
    return head;
}

// Function to delete a password
Node* deletePassword(Node *head) {
    char name[50];

    printf("Enter name for password to delete: ");
    scanf("%s", name);

    Node *currentNode = head;
    Node *previousNode;

    while (currentNode != NULL) {
        if (strcmp(currentNode->name, name) == 0) {
            if (currentNode == head) {
                head = head->next;
            }
            else {
                previousNode->next = currentNode->next;
            }
            free(currentNode->name);
            free(currentNode->password);
            free(currentNode);
            printf("Password for %s deleted successfully!\n", name);
            return head;
        }
        previousNode = currentNode;
        currentNode = currentNode->next;
    }

    printf("Password for %s not found.\n", name);
    return head;
}

// Function to display all passwords
void displayPasswords(Node *head) {
    if (head == NULL) {
        printf("No passwords found.\n");
        return;
    }

    Node *currentNode = head;
    while (currentNode != NULL) {
        printf("%s: %s\n", currentNode->name, currentNode->password);
        currentNode = currentNode->next;
    }
}

// Function to free memory and exit program
void exitProgram(Node *head) {
    Node *currentNode = head;
    Node *nextNode;

    while (currentNode != NULL) {
        nextNode = currentNode->next;
        free(currentNode->name);
        free(currentNode->password);
        free(currentNode);
        currentNode = nextNode;
    }

    printf("Goodbye!\n");
    exit(0);
}

int main() {
    Node *head = NULL;
    int choice;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                head = addPassword(head);
                break;
            case 2:
                retrievePassword(head);
                break;
            case 3:
                head = updatePassword(head);
                break;
            case 4:
                head = deletePassword(head);
                break;
            case 5:
                displayPasswords(head);
                break;
            case 6:
                exitProgram(head);
                break;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    }

    return 0;
}