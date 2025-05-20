//Gemma-7B DATASET v1.0 Category: Email Client ; Style: dynamic
#include <stdio.h>
#include <string.h>

#define MAX_Recipients 10

typedef struct Mailbox {
    char **recipients;
    int numRecipients;
    char subject[256];
    char message[2048];
} Mailbox;

Mailbox mailbox;

void initMailbox() {
    mailbox.recipients = (char **)malloc(MAX_Recipients * sizeof(char *));
    mailbox.numRecipients = 0;
    mailbox.subject[0] = '\0';
    mailbox.message[0] = '\0';
}

void addRecipient(char *recipient) {
    mailbox.recipients[mailbox.numRecipients++] = recipient;
}

void setSubject(char *subject) {
    strcpy(mailbox.subject, subject);
}

void setMessage(char *message) {
    strcpy(mailbox.message, message);
}

void sendMail() {
    printf("To: ");
    for (int i = 0; i < mailbox.numRecipients; i++) {
        printf("%s, ", mailbox.recipients[i]);
    }
    printf("\nSubject: %s\n", mailbox.subject);
    printf("Message:\n%s\n", mailbox.message);

    printf("Mail sent successfully!\n");
}

int main() {
    initMailbox();

    addRecipient("john.doe@gmail.com");
    addRecipient("jane.doe@gmail.com");

    setSubject("Test Email");

    setMessage("This is a test email.");

    sendMail();

    return 0;
}