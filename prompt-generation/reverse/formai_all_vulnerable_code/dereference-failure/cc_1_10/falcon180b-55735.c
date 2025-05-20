//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure for a node in the linked list
typedef struct node {
    char *data;
    struct node *next;
} Node;

// Function to create a new node
Node* createNode(char *data) {
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to print the contents of a linked list
void printList(Node *head) {
    Node *currNode = head;
    while (currNode!= NULL) {
        printf("%s ", currNode->data);
        currNode = currNode->next;
    }
    printf("\n");
}

// Recursive function to reverse a linked list
Node* reverseList(Node *head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    Node *rest = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;
    return rest;
}

// Function to read an ebook from a text file
void readEbook(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }
    char ch;
    Node *head = NULL;
    while ((ch = fgetc(fp))!= EOF) {
        if (ch == '\n') {
            Node *newNode = createNode(head->data);
            head->data = (char*) realloc(head->data, strlen(head->data) - 1);
            head->data[strlen(head->data) - 1] = '\0';
            head->next = newNode;
            head = newNode;
        } else {
            head->data = (char*) realloc(head->data, strlen(head->data) + 2);
            strcat(head->data, &ch);
        }
    }
    fclose(fp);
    head = reverseList(head);
    printList(head);
}

// Main function
int main() {
    readEbook("ebook.txt");
    return 0;
}