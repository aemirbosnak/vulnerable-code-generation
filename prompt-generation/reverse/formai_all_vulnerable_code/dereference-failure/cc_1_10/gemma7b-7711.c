//Gemma-7B DATASET v1.0 Category: Email Client ; Style: surrealist
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_Recipients 5

typedef struct Recipient {
    char name[255];
    char email[255];
    struct Recipient* next;
} Recipient;

typedef struct Mailbox {
    Recipient** recipients;
    int numRecipients;
    struct Mailbox* next;
} Mailbox;

void addRecipient(Mailbox* mailbox, char* name, char* email) {
    Recipient* newRecipient = (Recipient*)malloc(sizeof(Recipient));
    strcpy(newRecipient->name, name);
    strcpy(newRecipient->email, email);
    newRecipient->next = NULL;

    if (mailbox->numRecipients == 0) {
        mailbox->recipients = &newRecipient;
    } else {
        mailbox->recipients[mailbox->numRecipients++] = newRecipient;
    }
}

void sendMail(Mailbox* mailbox, char* subject, char* message) {
    for (int i = 0; i < mailbox->numRecipients; i++) {
        printf("Sending email to: %s <%s>\n", mailbox->recipients[i]->name, mailbox->recipients[i]->email);
        printf("Subject: %s\n", subject);
        printf("Message: %s\n", message);
        printf("\n");
    }
}

int main() {
    Mailbox* mailbox = (Mailbox*)malloc(sizeof(Mailbox));
    mailbox->recipients = NULL;
    mailbox->numRecipients = 0;
    mailbox->next = NULL;

    addRecipient(mailbox, "Salvador Dalí", "salvador@surrealist.com");
    addRecipient(mailbox, "Pablo Picasso", "pablo@surrealist.com");
    addRecipient(mailbox, "Vincent van Gogh", "vincent@surrealist.com");

    sendMail(mailbox, "The Meaning of Life", "It is not what you think.");

    return 0;
}