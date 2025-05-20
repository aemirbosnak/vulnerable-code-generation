//FormAI DATASET v1.0 Category: Mailing list manager ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct for an email
typedef struct email {
    char* recipient;
    char* subject;
    char* message;
} Email;

// Struct for a mailing list node
typedef struct mailing_list_node {
    char* email_address;
    struct mailing_list_node* next;
    Email** emails;
    int num_emails;
} MailingList;

// Helper function to create a new email
Email* create_email(char* recipient, char* subject, char* message) {
    Email* email = malloc(sizeof(Email));
    email->recipient = strdup(recipient);
    email->subject = strdup(subject);
    email->message = strdup(message);
    return email;
}

// Helper function to delete an email
void delete_email(Email* email) {
    free(email->recipient);
    free(email->subject);
    free(email->message);
    free(email);
}

// Helper function to create a new mailing list node
MailingList* create_mailing_list_node(char* email_address) {
    MailingList* node = malloc(sizeof(MailingList));
    node->email_address = strdup(email_address);
    node->next = NULL;
    node->emails = NULL;
    node->num_emails = 0;
    return node;
}

// Helper function to delete a mailing list node
void delete_mailing_list_node(MailingList* node) {
    free(node->email_address);
    for (int i = 0; i < node->num_emails; i++) {
        delete_email(node->emails[i]);
    }
    free(node->emails);
    free(node);
}

// Adds an email to a mailing list node
void add_email_to_node(MailingList* node, Email* email) {
    node->num_emails++;
    node->emails = realloc(node->emails, sizeof(Email*) * node->num_emails);
    node->emails[node->num_emails - 1] = email;
}

// Prints all emails in a mailing list node
void print_emails_in_node(MailingList* node) {
    printf("Emails for %s:\n", node->email_address);
    for (int i = 0; i < node->num_emails; i++) {
        printf("Recipient: %s\nSubject: %s\nMessage: %s\n", node->emails[i]->recipient, node->emails[i]->subject, node->emails[i]->message);
    }
}

// Adds a new email to a mailing list
void add_email_to_list(MailingList* list, char* email_address, char* recipient, char* subject, char* message) {
    MailingList* node = list;
    while (node != NULL && strcmp(node->email_address, email_address) != 0) {
        node = node->next;
    }

    if (node == NULL) {
        node = create_mailing_list_node(email_address);

        if (list == NULL) {
            list = node;
        } else {
            MailingList* last_node = list;
            while (last_node->next != NULL) {
                last_node = last_node->next;
            }
            last_node->next = node;
        }
    }

    Email* email = create_email(recipient, subject, message);
    add_email_to_node(node, email);
}

// Prints all emails in a mailing list
void print_emails_in_list(MailingList* list) {
    MailingList* node = list;
    while (node != NULL) {
        print_emails_in_node(node);
        node = node->next;
    }
}

// Deletes a mailing list
void delete_mailing_list(MailingList* list) {
    while (list != NULL) {
        MailingList* next_node = list->next;
        delete_mailing_list_node(list);
        list = next_node;
    }
}

int main() {
    MailingList* list = NULL;

    add_email_to_list(list, "user1@example.com", "user2@example.com", "Subject 1", "Message 1");
    add_email_to_list(list, "user1@example.com", "user3@example.com", "Subject 2", "Message 2");
    add_email_to_list(list, "user2@example.com", "user1@example.com", "Subject 3", "Message 3");

    print_emails_in_list(list);

    delete_mailing_list(list);

    return 0;
}