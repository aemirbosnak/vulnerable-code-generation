//FormAI DATASET v1.0 Category: Email Client ; Style: protected
#include <stdio.h>
#include <stdlib.h>

// Struct to hold email metadata
typedef struct {
    int id;
    char subject[100];
    char sender[50];
    char recipient[50];
    char timestamp[30];
} Email;

// Function to print email metadata
void printEmailMetadata(Email email) {
    printf("Email ID: %d\n", email.id);
    printf("Subject: %s\n", email.subject);
    printf("Sender: %s\n", email.sender);
    printf("Recipient: %s\n", email.recipient);
    printf("Timestamp: %s\n", email.timestamp);
}

int main() {
    int numEmails;
    printf("Enter the number of emails you want to send: ");
    scanf("%d", &numEmails);

    // Allocate memory for the emails
    Email *emails = (Email*) calloc(numEmails, sizeof(Email));

    // Get email data from the user
    for (int i = 0; i < numEmails; i++) {
        printf("\nEmail #%d\n", i+1);
        printf("Enter Subject: ");
        scanf("%s", emails[i].subject);
        printf("Enter Sender: ");
        scanf("%s", emails[i].sender);
        printf("Enter Recipient: ");
        scanf("%s", emails[i].recipient);
        printf("Enter Timestamp: ");
        scanf("%s", emails[i].timestamp);
        emails[i].id = i+1;
    }

    // Print email metadata
    for (int i = 0; i < numEmails; i++) {
        printf("\nEmail #%d Metadata\n", i+1);
        printEmailMetadata(emails[i]);
    }

    // Free up memory
    free(emails);

    return 0;
}