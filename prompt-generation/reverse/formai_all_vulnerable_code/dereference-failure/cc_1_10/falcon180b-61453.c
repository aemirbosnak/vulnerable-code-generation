//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SUBJECT_LENGTH 80
#define MAX_BODY_LENGTH 1024
#define MAX_EMAIL_LENGTH 256
#define MAX_COMMAND_LENGTH 16

// Node structure for linked list of emails
typedef struct email_node {
    char email[MAX_EMAIL_LENGTH];
    struct email_node* next;
} EmailNode;

// Function prototypes
EmailNode* create_email_node(char* email);
void add_email_to_list(EmailNode** head, char* email);
int is_email_in_list(EmailNode* head, char* email);
void print_email_list(EmailNode* head);
void send_email(char* subject, char* body, char* email);

int main() {
    EmailNode* head = NULL;
    char input[MAX_COMMAND_LENGTH];
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
    char email[MAX_EMAIL_LENGTH];

    // Initialize the linked list
    head = create_email_node("example@example.com");

    // Main loop
    while (1) {
        // Prompt user for command
        printf("Enter command (add, send, print, quit): ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        // Parse command
        if (strcmp(input, "add") == 0) {
            // Add email to list
            printf("Enter email address: ");
            fgets(email, MAX_EMAIL_LENGTH, stdin);
            add_email_to_list(&head, email);
        } else if (strcmp(input, "send") == 0) {
            // Send email
            printf("Enter subject: ");
            fgets(subject, MAX_SUBJECT_LENGTH, stdin);
            printf("Enter body: ");
            fgets(body, MAX_BODY_LENGTH, stdin);
            send_email(subject, body, email);
        } else if (strcmp(input, "print") == 0) {
            // Print email list
            print_email_list(head);
        } else if (strcmp(input, "quit") == 0) {
            // Quit program
            break;
        } else {
            // Invalid command
            printf("Invalid command.\n");
        }
    }

    return 0;
}

// Create a new email node with the given email address
EmailNode* create_email_node(char* email) {
    EmailNode* new_node = (EmailNode*)malloc(sizeof(EmailNode));
    strcpy(new_node->email, email);
    new_node->next = NULL;
    return new_node;
}

// Add an email address to the linked list
void add_email_to_list(EmailNode** head, char* email) {
    EmailNode* new_node = create_email_node(email);
    new_node->next = *head;
    *head = new_node;
}

// Check if an email address is in the linked list
int is_email_in_list(EmailNode* head, char* email) {
    while (head!= NULL) {
        if (strcmp(head->email, email) == 0) {
            return 1;
        }
        head = head->next;
    }
    return 0;
}

// Print the contents of the linked list
void print_email_list(EmailNode* head) {
    while (head!= NULL) {
        printf("%s\n", head->email);
        head = head->next;
    }
}

// Send an email to the given email address with the given subject and body
void send_email(char* subject, char* body, char* email) {
    // TODO: Implement sending email functionality
}