//FormAI DATASET v1.0 Category: Email Client ; Style: relaxed
// Hey there, welcome to my email client program written in C!
// This program is designed to allow users to send, receive, and manage their email all from the comfort of their terminal.
// Let's dive into the code, shall we?

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// First, we define our email struct which will hold all of the necessary information about each email.
struct email {
    char *sender;
    char *receiver;
    char *subject;
    char *body;
};

// Next, we define our email receiver function which will allow users to receive new emails.
void receive_email(struct email **emails, int *num_emails) {
    // Let's create a new email struct to hold the received email.
    struct email *new_email = malloc(sizeof(struct email));

    // Now, let's prompt the user for the sender, receiver, subject, and body of the email.
    printf("Sender: ");
    new_email->sender = malloc(100 * sizeof(char));
    scanf("%s", new_email->sender);

    printf("Receiver: ");
    new_email->receiver = malloc(100 * sizeof(char));
    scanf("%s", new_email->receiver);

    printf("Subject: ");
    new_email->subject = malloc(100 * sizeof(char));
    scanf("%s", new_email->subject);

    printf("Body: ");
    new_email->body = malloc(1000 * sizeof(char));
    scanf("%s", new_email->body);

    // Finally, let's add the new email to our array of emails and update the number of emails.
    *num_emails += 1;
    *emails = realloc(*emails, (*num_emails) * sizeof(struct email));
    (*emails)[*num_emails - 1] = *new_email;

    printf("Email received!\n");
}

// Now, let's define our email display function which will allow users to view all of their emails.
void display_emails(struct email *emails, int num_emails) {
    // Let's loop through each email in the array and print out its information.
    for (int i = 0; i < num_emails; i++) {
        printf("\nEmail %d:\n", i+1);
        printf("Sender: %s\n", emails[i].sender);
        printf("Receiver: %s\n", emails[i].receiver);
        printf("Subject: %s\n", emails[i].subject);
        printf("Body: %s\n", emails[i].body);
    }
}

// Finally, let's create our main function which will allow users to interact with the program.
int main() {
    // First, let's allocate space for our array of emails and initialize the number of emails to 0.
    struct email *emails = malloc(sizeof(struct email));
    int num_emails = 0;

    // Now, let's prompt the user for what they would like to do.
    while (1) {
        printf("\nWhat would you like to do?\n");
        printf("1. Receive Email\n");
        printf("2. Display Emails\n");
        printf("3. Exit\n");

        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            receive_email(&emails, &num_emails);
        } else if (choice == 2) {
            display_emails(emails, num_emails);
        } else if (choice == 3) {
            printf("Goodbye!\n");
            exit(0);
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}