//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LEN 100
#define MAX_EMAIL_LEN 100

// Node structure for linked list
typedef struct node {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
    struct node* next;
} Node;

Node* create_node(char* name, char* email) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    strcpy(new_node->name, name);
    strcpy(new_node->email, email);
    new_node->next = NULL;
    return new_node;
}

// Function to add a new subscriber to the list
void add_subscriber(Node** head, char* name, char* email) {
    Node* new_node = create_node(name, email);
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    Node* curr_node = *head;
    while (curr_node->next!= NULL) {
        curr_node = curr_node->next;
    }
    curr_node->next = new_node;
}

// Function to remove a subscriber from the list
void remove_subscriber(Node** head, char* email) {
    Node* curr_node = *head;
    Node* prev_node = NULL;
    while (curr_node!= NULL && strcmp(curr_node->email, email)!= 0) {
        prev_node = curr_node;
        curr_node = curr_node->next;
    }
    if (curr_node == NULL) {
        printf("Subscriber not found.\n");
        return;
    }
    if (prev_node == NULL) {
        *head = curr_node->next;
    } else {
        prev_node->next = curr_node->next;
    }
    free(curr_node);
}

// Function to print the list of subscribers
void print_list(Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("Name\tEmail\n");
    Node* curr_node = head;
    while (curr_node!= NULL) {
        printf("%s\t%s\n", curr_node->name, curr_node->email);
        curr_node = curr_node->next;
    }
}

int main() {
    Node* head = NULL;

    add_subscriber(&head, "John", "john@example.com");
    add_subscriber(&head, "Jane", "jane@example.com");
    add_subscriber(&head, "Doe", "doe@example.com");

    print_list(head);

    remove_subscriber(&head, "john@example.com");

    print_list(head);

    return 0;
}