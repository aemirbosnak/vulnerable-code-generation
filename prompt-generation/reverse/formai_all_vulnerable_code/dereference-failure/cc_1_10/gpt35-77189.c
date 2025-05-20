//FormAI DATASET v1.0 Category: Mailing list manager ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char email[50];
    struct Node* next;
} Node;

// Function prototypes
void printMenu();
Node* createNode(char email[50]);
void addToList(Node** head, char email[50]);
void printList(Node* head);
void deleteNode(Node** head, char email[50]);
void saveListToFile(Node* head, char filename[50]);
void loadListFromFile(Node** head, char filename[50]);

int main() {
    Node* head = NULL;
    int choice;
    char email[50], filename[50];

    // Load list from file
    printf("Enter file name to load mailing list from: ");
    fgets(filename, 50, stdin);
    filename[strcspn(filename, "\n")] = 0; // Remove newline character
    
    loadListFromFile(&head, filename);
    printf("Mailing list loaded successfully.\n");

    do {
        printMenu();
        scanf("%d", &choice);

        switch(choice) {
            case 1: // Add email to list
                printf("Enter email to add to list: ");
                scanf("%s", email);
                addToList(&head, email);
                printf("Email added to list.\n");
                break;

            case 2: // Print list
                printf("\nMailing List:\n");
                printList(head);
                break;

            case 3: // Delete email from list
                printf("Enter email to delete from list: ");
                scanf("%s", email);
                deleteNode(&head, email);
                break;

            case 4: // Save list to file
                printf("Enter file name to save mailing list to: ");
                scanf("%s", filename);
                saveListToFile(head, filename);
                printf("Mailing list saved successfully.\n");
                break;

            case 5: // Quit program
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

// Prints the menu of options for the user
void printMenu() {
    printf("\nMenu:\n");
    printf("1. Add email to list\n");
    printf("2. Print list\n");
    printf("3. Delete email from list\n");
    printf("4. Save list to file\n");
    printf("5. Quit program\n");
    printf("Enter your choice: ");
}

// Creates and returns a new Node
Node* createNode(char email[50]) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->email, email);
    newNode->next = NULL;
    return newNode;
}

// Adds a new email to the list
void addToList(Node** head, char email[50]) {
    Node* newNode = createNode(email);

    if (*head == NULL) { // List is empty
        *head = newNode;
    } else {
        Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Prints the entire mailing list
void printList(Node* head) {
    if (head == NULL) {
        printf("Mailing list is empty.\n");
    } else {
        Node* current = head;
        while (current != NULL) {
            printf("%s\n", current->email);
            current = current->next;
        }
    }
}

// Deletes a Node from the list with the specified email
void deleteNode(Node** head, char email[50]) {
    Node* current = *head;
    Node* prev;

    if (current != NULL && strcmp(current->email, email) == 0) { // Email is in first Node
        *head = current->next;
        free(current);
        printf("Email deleted from list.\n");
        return;
    }

    while (current != NULL && strcmp(current->email, email) != 0) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Email not found in list.\n");
    } else {
        prev->next = current->next;
        free(current);
        printf("Email deleted from list.\n");
    }
}

// Saves the mailing list to a file
void saveListToFile(Node* head, char filename[50]) {
    FILE* fp = fopen(filename, "w");

    if (fp == NULL) {
        printf("Error opening file.\n");
        return;
    }

    Node* current = head;
    while (current != NULL) {
        fprintf(fp, "%s\n", current->email);
        current = current->next;
    }

    fclose(fp);
}

// Loads the mailing list from a file
void loadListFromFile(Node** head, char filename[50]) {
    FILE* fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error opening file.\n");
        return;
    }

    char email[50];
    while (fgets(email, 50, fp) != NULL) {
        email[strcspn(email, "\n")] = 0; // Remove newline character
        addToList(head, email);
    }

    fclose(fp);
}