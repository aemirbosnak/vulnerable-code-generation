//FormAI DATASET v1.0 Category: Email Client ; Style: multivariable
// A multi-variable C Email Client example program
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBJECT_LENGTH 100
#define MAX_BODY_LENGTH 500

typedef struct email {
    char sender[50];
    char recipient[50];
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
    struct email* next;
} Email;

Email* head = NULL;
Email* tail = NULL;

// Function to add emails to the linked list
void add_email(char* sender, char* recipient, char* subject, char* body) {
    Email* new_email = (Email*)malloc(sizeof(Email));
    strcpy(new_email->sender, sender);
    strcpy(new_email->recipient, recipient);
    strcpy(new_email->subject, subject);
    strcpy(new_email->body, body);
    new_email->next = NULL;

    if (head == NULL) {
        head = tail = new_email;
    } else {
        tail->next = new_email;
        tail = new_email;
    }
}

// Function to display all emails in the linked list
void display_all_emails() {
    Email* current = head;

    if (current == NULL) {
        printf("No emails to display.\n");
    } else {
        printf("All Emails:\n");
        while (current != NULL) {
            printf("Sender: %s\n", current->sender);
            printf("Recipient: %s\n", current->recipient);
            printf("Subject: %s\n", current->subject);
            printf("Body: %s\n\n", current->body);
            current = current->next;
        }
    }
}

int main() {
    char sender[50];
    char recipient[50];
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
    int choice;

    do {
        printf("Email Client Menu:\n");
        printf("1. Send Email\n");
        printf("2. Display All Emails\n");
        printf("3. Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Sender: ");
                scanf("%s", sender);
                printf("Enter Recipient: ");
                scanf("%s", recipient);
                printf("Enter Subject: ");
                scanf("%s", subject);
                printf("Enter Body: ");
                scanf("%s", body);
                add_email(sender, recipient, subject, body);
                printf("Email Sent.\n");
                break;
            case 2:
                display_all_emails();
                break;
            case 3:
                printf("Exiting Email Client.\n");
                break;
            default:
                printf("Invalid Choice. Please Try Again.\n");
                break;
        }
    } while (choice != 3);

    return 0;
}