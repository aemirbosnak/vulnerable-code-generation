//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define MAX_SIZE 1000

// Node structure definition
typedef struct node {
    char data[MAX_SIZE];
    int freq;
    struct node* next;
} Node;

// Function prototypes
void create(Node** root, char str[]);
void display(Node* root);
int search(Node* root, char str[]);
void delete(Node** root, char str[]);

int main() {
    Node* root = NULL;

    create(&root, "Hello World");
    display(root);
    printf("\n");

    int result = search(root, "World");
    if (result == TRUE)
        printf("Found\n");
    else
        printf("Not Found\n");

    delete(&root, "World");
    display(root);

    return 0;
}

// Function to create a new node with given string
void create(Node** root, char str[]) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->data, str);
    newNode->freq = 1;
    newNode->next = *root;
    *root = newNode;
}

// Function to display all strings in the tree
void display(Node* root) {
    if (root == NULL)
        return;

    printf(" %s (%d)\n", root->data, root->freq);

    Node* temp = root->next;
    while (temp!= NULL) {
        display(temp);
        temp = temp->next;
    }
}

// Function to search for a string in the tree
int search(Node* root, char str[]) {
    if (root == NULL)
        return FALSE;

    if (strcmp(root->data, str) == 0)
        return TRUE;

    Node* temp = root->next;
    while (temp!= NULL) {
        if (search(temp, str))
            return TRUE;
        temp = temp->next;
    }

    return FALSE;
}

// Function to delete a string from the tree
void delete(Node** root, char str[]) {
    Node* temp = *root;
    Node* prev = NULL;

    if (strcmp(temp->data, str) == 0) {
        *root = temp->next;
        free(temp);
        return;
    }

    while (temp!= NULL && strcmp(temp->data, str)!= 0) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
        return;

    prev->next = temp->next;
    free(temp);
}