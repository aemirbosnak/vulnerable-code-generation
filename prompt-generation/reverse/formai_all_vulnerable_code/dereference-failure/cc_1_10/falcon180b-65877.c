//Falcon-180B DATASET v1.0 Category: HTML beautifier ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure definition
typedef struct node {
    char *tag;
    char *content;
    struct node *next;
} Node;

// Function to create a new node
Node* newNode(char *tag, char *content) {
    Node *node = (Node*) malloc(sizeof(Node));
    node->tag = tag;
    node->content = content;
    node->next = NULL;
    return node;
}

// Function to print the HTML beautified
void printHTML(Node *root) {
    if (root == NULL)
        return;

    printf("<%s>", root->tag);

    if (root->content!= NULL) {
        printf("%s", root->content);
    }

    Node *child = root->next;

    while (child!= NULL) {
        printHTML(child);
        child = child->next;
    }

    printf("</%s>", root->tag);
    printf("\n");
}

// Main function
int main() {
    // Test case
    Node *root = newNode("html", "");
    Node *head = newNode("head", "");
    Node *title = newNode("title", "My Website");
    Node *body = newNode("body", "");

    root->next = head;
    head->next = title;
    body->next = NULL;

    printHTML(root);

    return 0;
}