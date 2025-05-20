//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure for linked list
struct Node {
    char *data;
    struct Node *next;
};

// Function to add a node to the end of the linked list
void addNode(struct Node **head, char *data) {
    struct Node *newNode = (struct Node *) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node *temp = *head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to print the linked list
void printList(struct Node *head) {
    struct Node *temp = head;
    while (temp!= NULL) {
        printf("%s ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to parse the resume and add nodes to the linked list
void parseResume(struct Node **head, char *resume) {
    char *token = strtok(resume, " ");
    while (token!= NULL) {
        if (strlen(token) > 0) {
            addNode(head, token);
        }
        token = strtok(NULL, " ");
    }
}

// Main function
int main() {
    char resume[1000];
    printf("Enter your resume: ");
    fgets(resume, sizeof(resume), stdin);
    struct Node *head = NULL;
    parseResume(&head, resume);
    printf("Your parsed resume:\n");
    printList(head);
    return 0;
}