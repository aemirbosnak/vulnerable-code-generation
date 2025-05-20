//FormAI DATASET v1.0 Category: Mailing list manager ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAIL 100
#define MAX_SUBJECT 100
#define MAX_MESSAGE 500

struct email {
    char subject[MAX_SUBJECT];
    char message[MAX_MESSAGE];
    struct email* next;
};

struct mailing_list {
    char email[MAX_EMAIL];
    struct email* inbox;
    struct mailing_list* next;
};

void print_emails(struct email* emails) {
    while (emails != NULL) {
        printf("Subject: %s\n", emails->subject);
        printf("Message: %s\n", emails->message);
        printf("------------------------\n");
        emails = emails->next;
    }
}

void print_mailing_list(struct mailing_list* list) {
    while (list != NULL) {
        printf("Email: %s\n", list->email);
        printf("------------------------\n");
        print_emails(list->inbox);
        list = list->next;
    }
}

int main() {
    struct mailing_list* list = NULL;

    // Add email to mailing list
    char new_email[MAX_EMAIL];
    printf("Enter email address to add to mailing list: ");
    fgets(new_email, MAX_EMAIL, stdin);
    new_email[strcspn(new_email, "\n")] = 0;  // Remove newline from input

    struct mailing_list* curr = list;
    while (curr != NULL) {
        if (strcmp(curr->email, new_email) == 0) {
            printf("Email already exists in mailing list!\n");
            return 0;
        }
        curr = curr->next;
    }

    struct mailing_list* new_list = malloc(sizeof(struct mailing_list));
    strncpy(new_list->email, new_email, MAX_EMAIL);
    new_list->inbox = NULL;
    new_list->next = list;
    list = new_list;

    // Send email to mailing list
    char subject[MAX_SUBJECT];
    char message[MAX_MESSAGE];
    printf("Enter subject line for email: ");
    fgets(subject, MAX_SUBJECT, stdin);
    subject[strcspn(subject, "\n")] = 0;  // Remove newline from input
    printf("Enter message for email: ");
    fgets(message, MAX_MESSAGE, stdin);
    message[strcspn(message, "\n")] = 0;  // Remove newline from input

    curr = list;
    while (curr != NULL) {
        struct email* new_email = malloc(sizeof(struct email));
        strncpy(new_email->subject, subject, MAX_SUBJECT);
        strncpy(new_email->message, message, MAX_MESSAGE);
        new_email->next = curr->inbox;
        curr->inbox = new_email;
        curr = curr->next;
    }

    print_mailing_list(list);

    return 0;
}