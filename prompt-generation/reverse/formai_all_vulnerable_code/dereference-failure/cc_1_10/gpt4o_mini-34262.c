//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definition for a Node to be used in a linked list
typedef struct Node {
    char *data;
    struct Node *next;
} Node;

// Function prototypes
Node* createNode(const char *data);
void appendNode(Node **head, const char *data);
void printList(Node *head);
void freeList(Node *head);
char* getInput(const char *prompt);

// Main function
int main() {
    Node *head = NULL;  // Initialize the head of the linked list to NULL
    char choice;
    char *data;

    printf("Welcome to the Interactive Linked List Program!\n");

    do {
        data = getInput("Enter a string to append to the list (or 'exit' to terminate): ");
        
        if (strcmp(data, "exit") == 0) {
            free(data);  // Free the memory allocated for the input string
            break;
        }

        appendNode(&head, data);
        free(data);  // Free the memory after it's appended to the list
        
        printf("Do you want to continue adding nodes? (y/n): ");
        scanf(" %c", &choice);
        while(getchar() != '\n'); // Clear the input buffer.

    } while (choice == 'y' || choice == 'Y');

    printf("\nHere's the list you created:\n");
    printList(head);

    // Free the linked list before exiting
    freeList(head);
    return 0;
}

// Function to create a new node
Node* createNode(const char *data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        fprintf(stderr, "Error: Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = (char *)malloc(strlen(data) + 1);
    if (newNode->data == NULL) {
        fprintf(stderr, "Error: Memory allocation for data failed!\n");
        exit(EXIT_FAILURE);
    }
    strcpy(newNode->data, data);
    newNode->next = NULL;
    return newNode;
}

// Function to append a node to the linked list
void appendNode(Node **head, const char *data) {
    Node *newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to print the linked list
void printList(Node *head) {
    Node *temp = head;
    while (temp != NULL) {
        printf("%s -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to free the linked list
void freeList(Node *head) {
    Node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp->data); // Free the memory allocated for data
        free(temp);       // Free the node itself
    }
}

// Function to get user input with a prompt
char* getInput(const char *prompt) {
    char *buffer = (char *)malloc(256);
    if (buffer == NULL) {
        fprintf(stderr, "Error: Memory allocation failed for input buffer!\n");
        exit(EXIT_FAILURE);
    }

    printf("%s", prompt);
    fgets(buffer, 256, stdin);
    buffer[strcspn(buffer, "\n")] = 0; // Remove newline character
    return buffer;
}