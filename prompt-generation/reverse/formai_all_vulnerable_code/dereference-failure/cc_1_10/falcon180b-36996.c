//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Node structure for linked list
typedef struct node {
    char *data;
    struct node *next;
} Node;

// Function prototypes
Node *create_node(char *data);
Node *insert_node(Node *head, char *data);
void print_list(Node *head);
void free_list(Node *head);

// Main function
int main() {
    FILE *fp;
    char line[1000];
    char *token;
    Node *head = NULL;

    // Open input file
    fp = fopen("input.txt", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    // Parse each line
    while (fgets(line, sizeof(line), fp)!= NULL) {
        token = strtok(line, " ");
        while (token!= NULL) {
            // Check if token is a keyword
            if (strcmp(token, "Education") == 0 || strcmp(token, "Experience") == 0 || strcmp(token, "Skills") == 0) {
                // Create new node for section
                Node *section = create_node(token);
                insert_node(head, section);
            }
            else {
                // Create new node for data
                Node *data = create_node(token);
                insert_node(head, data);
            }
            // Get next token
            token = strtok(NULL, " ");
        }
    }

    // Print parsed data
    print_list(head);

    // Free memory
    free_list(head);

    // Close input file
    fclose(fp);

    return 0;
}

// Create new node with given data
Node *create_node(char *data) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = strdup(data);
    node->next = NULL;
    return node;
}

// Insert new node at beginning of list
Node *insert_node(Node *head, char *data) {
    Node *node = create_node(data);
    node->next = head;
    return node;
}

// Print linked list
void print_list(Node *head) {
    Node *current = head;
    while (current!= NULL) {
        printf("%s ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Free memory used by linked list
void free_list(Node *head) {
    Node *current = head;
    while (current!= NULL) {
        free(current->data);
        current = current->next;
    }
    free(head);
}