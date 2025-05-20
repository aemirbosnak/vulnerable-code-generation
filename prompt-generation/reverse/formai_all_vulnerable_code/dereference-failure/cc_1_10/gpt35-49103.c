//FormAI DATASET v1.0 Category: Mailing list manager ; Style: irregular
// Welcome to Mailify 3.0 - The Ultimate Mailing List Manager
// Let's start by including necessary libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a linked list node
typedef struct Node {
    char email[50];
    struct Node *next;
} Node;

// Define the header node for the linked list
Node *head = NULL;

// Declare function prototypes
void addEmail();
void removeEmail();
void displayEmails();
void saveToFile();
void loadFromFile();

int main() {
    printf("Welcome to Mailify 3.0 - The Ultimate Mailing List Manager!\n");

    int choice = 0;
    while (choice != 5) {
        printf("\nSelect an option:\n");
        printf("1. Add new email\n");
        printf("2. Remove email\n");
        printf("3. Display all emails\n");
        printf("4. Save to file\n");
        printf("5. Load from file and exit\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEmail();
                break;
            case 2:
                removeEmail();
                break;
            case 3:
                displayEmails();
                break;
            case 4:
                saveToFile();
                break;
            case 5:
                loadFromFile();
                break;
            default:
                printf("Invalid input!");
                break;
        }
    }

    return 0;
}

// Function to add a new email
void addEmail() {
    printf("Enter email address: ");
    char email[50];
    scanf("%s", email);

    Node *newNode = (Node *) malloc(sizeof(Node));
    strcpy(newNode->email, email);
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    printf("Email added successfully!\n");
}

// Function to remove an email
void removeEmail() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    printf("Enter email address to remove: ");
    char email[50];
    scanf("%s", email);

    Node *temp = head;
    Node *prev = NULL;
    while (temp != NULL) {
        if (strcmp(temp->email, email) == 0) {
            if (prev == NULL) {
                head = head->next;
            } else {
                prev->next = temp->next;
            }
            free(temp);
            printf("Email removed successfully!\n");
            return;
        }
        prev = temp;
        temp = temp->next;
    }

    printf("Email not found!\n");
}

// Function to display all emails
void displayEmails() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    printf("Mailing List:\n");
    Node *temp = head;
    while (temp != NULL) {
        printf("- %s\n", temp->email);
        temp = temp->next;
    }
}

// Function to save the mailing list to a file
void saveToFile() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    printf("Enter file name to save: ");
    char fileName[50];
    scanf("%s", fileName);

    FILE *file = fopen(fileName, "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    Node *temp = head;
    while (temp != NULL) {
        fprintf(file, "%s\n", temp->email);
        temp = temp->next;
    }

    fclose(file);
    printf("File saved successfully!\n");
}

// Function to load a mailing list from a file
void loadFromFile() {
    printf("Enter file name to load: ");
    char fileName[50];
    scanf("%s", fileName);

    FILE *file = fopen(fileName, "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    char email[50];
    while (fscanf(file, "%s", email) != EOF) {
        Node *newNode = (Node *) malloc(sizeof(Node));
        strcpy(newNode->email, email);
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        } else {
            Node *temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    fclose(file);
    printf("Mailing list loaded successfully!\n");

    displayEmails();
}