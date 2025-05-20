//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Node structure for linked list
struct Node {
    char *data;
    struct Node *next;
};

// Function prototypes
void addNode(struct Node **head, char *data);
void printList(struct Node *head);
void freeList(struct Node *head);

// Main function
int main() {
    FILE *fp;
    char line[1000];
    char *token;
    struct Node *head = NULL;

    // Open input file
    fp = fopen("resume.txt", "r");
    if (fp == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    // Read each line from input file
    while (fgets(line, sizeof(line), fp)!= NULL) {
        // Remove newline character
        line[strcspn(line, "\n")] = '\0';

        // Tokenize line into words
        token = strtok(line, " ");
        while (token!= NULL) {
            // Add each word to linked list
            addNode(&head, token);
            token = strtok(NULL, " ");
        }
    }

    // Print linked list
    printf("Resume data:\n");
    printList(head);

    // Free memory
    freeList(head);

    // Close input file
    fclose(fp);

    return 0;
}

// Function to add node to linked list
void addNode(struct Node **head, char *data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = strdup(data);
    newNode->next = *head;
    *head = newNode;
}

// Function to print linked list
void printList(struct Node *head) {
    struct Node *currNode = head;
    while (currNode!= NULL) {
        printf("%s ", currNode->data);
        currNode = currNode->next;
    }
    printf("\n");
}

// Function to free memory used by linked list
void freeList(struct Node *head) {
    struct Node *currNode = head;
    while (currNode!= NULL) {
        struct Node *tempNode = currNode;
        currNode = currNode->next;
        free(tempNode->data);
        free(tempNode);
    }
}