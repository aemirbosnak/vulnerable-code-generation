//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100
#define MAX_EMAIL_LENGTH 100
#define MAX_SUBJECT_LENGTH 100
#define MAX_MESSAGE_LENGTH 1000

// Node structure for linked list
typedef struct node {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    struct node *next;
} Node;

// Function prototypes
Node *create_node(char *name, char *email);
Node *add_node(Node *head, char *name, char *email);
void print_list(Node *head);
void send_message(Node *node, char *subject, char *message);

int main() {
    Node *head = NULL;

    // Add nodes to the list
    head = add_node(head, "John Doe", "john.doe@example.com");
    head = add_node(head, "Jane Smith", "jane.smith@example.com");

    // Print the list
    printf("Mailing List:\n");
    print_list(head);

    // Send a message to everyone on the list
    send_message(head, "Hello, World!", "This is a test message. Please ignore.");

    return 0;
}

// Create a new node with the given name and email
Node *create_node(char *name, char *email) {
    Node *node = (Node *) malloc(sizeof(Node));
    strcpy(node->name, name);
    strcpy(node->email, email);
    node->next = NULL;

    return node;
}

// Add a new node to the end of the list
Node *add_node(Node *head, char *name, char *email) {
    Node *node = create_node(name, email);

    if (head == NULL) {
        head = node;
    } else {
        Node *current = head;
        while (current->next!= NULL) {
            current = current->next;
        }
        current->next = node;
    }

    return head;
}

// Print the mailing list
void print_list(Node *head) {
    Node *current = head;

    while (current!= NULL) {
        printf("%s (%s)\n", current->name, current->email);
        current = current->next;
    }
}

// Send a message to a node
void send_message(Node *node, char *subject, char *message) {
    printf("Sending message to %s (%s):\nSubject: %s\n\n%s\n", node->name, node->email, subject, message);
}