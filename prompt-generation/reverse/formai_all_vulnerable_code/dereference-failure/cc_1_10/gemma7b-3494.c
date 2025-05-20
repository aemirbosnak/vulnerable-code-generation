//Gemma-7B DATASET v1.0 Category: Email Client ; Style: Romeo and Juliet
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_Recipients 10

typedef struct Mailbox {
    char **recipients;
    int capacity;
    int numRecipients;
    char subject;
    char message[1024];
} Mailbox;

Mailbox *createMailbox(int capacity) {
    Mailbox *mailbox = malloc(sizeof(Mailbox));
    mailbox->recipients = malloc(sizeof(char *) * capacity);
    mailbox->capacity = capacity;
    mailbox->numRecipients = 0;
    mailbox->subject = '\0';
    mailbox->message[0] = '\0';
    return mailbox;
}

void addRecipient(Mailbox *mailbox, char *recipient) {
    if (mailbox->numRecipients >= mailbox->capacity) {
        return;
    }
    mailbox->recipients[mailbox->numRecipients++] = recipient;
}

void setSubject(Mailbox *mailbox, char subject) {
    mailbox->subject = subject;
}

void setMessage(Mailbox *mailbox, char *message) {
    strcpy(mailbox->message, message);
}

void sendMail(Mailbox *mailbox) {
    printf("From: %s\n", mailbox->recipients[0]);
    printf("To: ");
    for (int i = 0; i < mailbox->numRecipients; i++) {
        printf("%s, ", mailbox->recipients[i]);
    }
    printf("\nSubject: %c\n\n", mailbox->subject);
    printf("%s\n", mailbox->message);
    printf("\n");
}

int main() {
    Mailbox *mailbox = createMailbox(MAX_Recipients);
    addRecipient(mailbox, "Montague@capitol.com");
    addRecipient(mailbox, "Capulet@manor.com");
    setSubject(mailbox, 'A');
    setMessage(mailbox, "Peace at last!");
    sendMail(mailbox);

    return 0;
}