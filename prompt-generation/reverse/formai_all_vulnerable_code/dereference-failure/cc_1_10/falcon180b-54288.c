//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50
#define MAX_EMAIL_LEN 100
#define MAX_SUBJECTS 100
#define MAX_BODY 1000

// Node structure for linked list
typedef struct node {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
    int subscribed;
    struct node* next;
} Node;

// Function prototypes
void add_subscriber(Node** head, char* name, char* email);
void remove_subscriber(Node** head, char* email);
void send_email(char* subject, char* body, Node* subscriber);
void print_subscribers(Node* node);

int main() {
    Node* head = NULL;

    // Add subscribers
    add_subscriber(&head, "John Doe", "john.doe@example.com");
    add_subscriber(&head, "Jane Smith", "jane.smith@example.com");

    // Remove subscriber
    remove_subscriber(&head, "john.doe@example.com");

    // Send email to all subscribers
    send_email("Test Email", "Hello World!", head);

    // Print list of subscribers
    print_subscribers(head);

    return 0;
}

void add_subscriber(Node** head, char* name, char* email) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    strcpy(new_node->name, name);
    strcpy(new_node->email, email);
    new_node->subscribed = 1;
    new_node->next = *head;
    *head = new_node;
}

void remove_subscriber(Node** head, char* email) {
    Node* curr_node = *head;
    Node* prev_node = NULL;

    while (curr_node!= NULL && strcmp(curr_node->email, email)!= 0) {
        prev_node = curr_node;
        curr_node = curr_node->next;
    }

    if (curr_node == NULL) {
        printf("Subscriber not found.\n");
    } else {
        if (prev_node == NULL) {
            *head = curr_node->next;
        } else {
            prev_node->next = curr_node->next;
        }
        free(curr_node);
    }
}

void send_email(char* subject, char* body, Node* subscriber) {
    printf("Sending email to %s (%s)...\n", subscriber->name, subscriber->email);
}

void print_subscribers(Node* node) {
    while (node!= NULL) {
        printf("Name: %s\nEmail: %s\n", node->name, node->email);
        node = node->next;
    }
}