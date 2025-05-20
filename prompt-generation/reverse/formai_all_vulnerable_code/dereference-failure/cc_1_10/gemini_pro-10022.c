//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: Linus Torvalds
// Linus Torvalds-style C Mailing List Manager Example Program

// Hey there, kernel hackers! This is a mailing list manager I whipped up in a kernel-hacking frenzy.
// It's got all the bells and whistles you need to keep your mailing lists nice and tidy.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define some useful macros and data structures.
#define MAX_SUBJECT_LENGTH 1024
#define MAX_EMAIL_LENGTH 1024
#define MAX_LIST_SIZE 1024

typedef struct email {
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_EMAIL_LENGTH];
    char sender[MAX_EMAIL_LENGTH];
    char recipients[MAX_LIST_SIZE][MAX_EMAIL_LENGTH];
} email;

typedef struct mailing_list {
    char name[1024];
    int num_subscribers;
    char subscribers[MAX_LIST_SIZE][MAX_EMAIL_LENGTH];
} mailing_list;

// Create a new mailing list.
mailing_list* create_mailing_list(char *name) {
    mailing_list *list = malloc(sizeof(mailing_list));
    strcpy(list->name, name);
    list->num_subscribers = 0;
    return list;
}

// Add a subscriber to a mailing list.
void add_subscriber(mailing_list *list, char *email) {
    strcpy(list->subscribers[list->num_subscribers], email);
    list->num_subscribers++;
}

// Remove a subscriber from a mailing list.
void remove_subscriber(mailing_list *list, char *email) {
    int i;
    for (i = 0; i < list->num_subscribers; i++) {
        if (strcmp(list->subscribers[i], email) == 0) {
            list->num_subscribers--;
            strcpy(list->subscribers[i], list->subscribers[list->num_subscribers]);
            break;
        }
    }
}

// Send an email to a mailing list.
void send_email(mailing_list *list, email *email) {
    int i;
    for (i = 0; i < list->num_subscribers; i++) {
        printf("To: %s\n", list->subscribers[i]);
        printf("From: %s\n", email->sender);
        printf("Subject: %s\n", email->subject);
        printf("Body: %s\n", email->body);
    }
}

// Main function.
int main(int argc, char **argv) {
    // Create a new mailing list.
    mailing_list *list = create_mailing_list("linux-kernel");

    // Add some subscribers to the mailing list.
    add_subscriber(list, "torvalds@linux-foundation.org");
    add_subscriber(list, "gregkh@linuxfoundation.org");
    add_subscriber(list, "linus@kernel.org");

    // Send an email to the mailing list.
    email *email = malloc(sizeof(email));
    strcpy(email->subject, "Kernel 5.10 released!");
    strcpy(email->body, "The latest version of the Linux kernel has been released! It includes many new features and improvements. For more information, please visit https://www.kernel.org.");
    strcpy(email->sender, "torvalds@linux-foundation.org");
    send_email(list, email);

    // Free the memory allocated for the mailing list and email.
    free(list);
    free(email);

    return 0;
}