//FormAI DATASET v1.0 Category: Email Client ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LEN 100

// Struct for Email Message
typedef struct EmailMsg {
    char to[MAX_STRING_LEN];
    char from[MAX_STRING_LEN];
    char subject[MAX_STRING_LEN];
    char message[MAX_STRING_LEN*10];
    struct EmailMsg *next;
} EmailMsg;

// Function to create a new Email Message
EmailMsg *newEmailMsg(char *to, char *from, char *subject, char *message) {
    EmailMsg *email = (EmailMsg*) malloc(sizeof(EmailMsg));
    strcpy(email->to, to);
    strcpy(email->from, from);
    strcpy(email->subject, subject);
    strcpy(email->message, message);
    email->next = NULL;
    return email;
}

// Struct for Email Inbox
typedef struct EmailInbox {
    int count;
    EmailMsg *head;
    EmailMsg *tail;
} EmailInbox;

// Function to create a new Email Inbox
EmailInbox *newEmailInbox() {
    EmailInbox *inbox = (EmailInbox*) malloc(sizeof(EmailInbox));
    inbox->count = 0;
    inbox->head = NULL;
    inbox->tail = NULL;
    return inbox;
}

// Function to add an Email Message to the Inbox
void addToInbox(EmailInbox *inbox, EmailMsg *email) {
    if(inbox->count == 0) {
        inbox->head = email;
        inbox->tail = email;
        inbox->count = 1;
    }
    else {
        inbox->tail->next = email;
        inbox->tail = email;
        inbox->count++;
    }
}

// Function to remove an Email Message from the Inbox
void removeFromInbox(EmailInbox *inbox, int index) {
    if(index < inbox->count) {
        if(index == 0) {
            inbox->head = inbox->head->next;
            inbox->count--;
        }
        else {
            EmailMsg *current = inbox->head;
            for(int i=0; i<index-1; i++) {
                current = current->next;
            }
            current->next = current->next->next;
            if(index == inbox->count-1) {
                inbox->tail = current;
            }
            inbox->count--;
        }
    }
}

// Function to display all Email Messages in the Inbox
void displayInbox(EmailInbox *inbox) {
    printf("\nINBOX:\n");
    if(inbox->count == 0) {
        printf("No email messages\n");
    }
    else {
        EmailMsg *current = inbox->head;
        int index = 0;
        while(current != NULL) {
            printf("%d. To: %s\n   From: %s\n   Subject: %s\n   Message: %s\n",
                    index+1, current->to, current->from, current->subject, current->message);
            current = current->next;
            index++;
        }
    }
}

int main() {
    EmailInbox *inbox = newEmailInbox();

    EmailMsg *email1 = newEmailMsg("jane@example.com", "john@example.com", "Hello World", "This is a test email message.");
    addToInbox(inbox, email1);

    EmailMsg *email2 = newEmailMsg("jack@example.com", "jill@example.com", "Greetings!", "Hope you're doing well.");
    addToInbox(inbox, email2);

    EmailMsg *email3 = newEmailMsg("bob@example.com", "alice@example.com", "Important Notice", "Please read the attached document.");
    addToInbox(inbox, email3);

    displayInbox(inbox);

    removeFromInbox(inbox, 1);
    printf("\nRemoved email at index 2\n");

    displayInbox(inbox);

    return 0;
}