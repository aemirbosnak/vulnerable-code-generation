//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LENGTH 100
#define MAX_EMAIL_LENGTH 100
#define MAX_SUBJECT_LENGTH 200
#define MAX_MESSAGE_LENGTH 1000

// Node structure for linked list
typedef struct node {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    int subscribed;
    struct node *next;
} Node;

// Function prototypes
void add_node(Node **head, char *name, char *email);
void print_list(Node *head);
int count_nodes(Node *head);
void send_message(Node *head, char *subject, char *message);

int main() {
    Node *head = NULL;

    // Add some nodes to the list
    add_node(&head, "John Doe", "john@example.com");
    add_node(&head, "Jane Smith", "jane@example.com");
    add_node(&head, "Bob Johnson", "bob@example.com");

    // Print the list
    printf("Mailing list:\n");
    print_list(head);

    // Send a message to the list
    send_message(head, "Important update", "We have some exciting news to share!");

    return 0;
}

// Function to add a node to the linked list
void add_node(Node **head, char *name, char *email) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    strcpy(new_node->name, name);
    strcpy(new_node->email, email);
    new_node->subscribed = 1;
    new_node->next = *head;
    *head = new_node;
}

// Function to print the linked list
void print_list(Node *head) {
    while (head!= NULL) {
        printf("%s (%s)\n", head->name, head->email);
        head = head->next;
    }
}

// Function to count the number of nodes in the list
int count_nodes(Node *head) {
    int count = 0;
    while (head!= NULL) {
        count++;
        head = head->next;
    }
    return count;
}

// Function to send a message to the mailing list
void send_message(Node *head, char *subject, char *message) {
    printf("Sending message to %d subscribers:\n", count_nodes(head));
    while (head!= NULL) {
        if (head->subscribed) {
            printf("Sending message to %s (%s)\n", head->name, head->email);
        }
        head = head->next;
    }
}