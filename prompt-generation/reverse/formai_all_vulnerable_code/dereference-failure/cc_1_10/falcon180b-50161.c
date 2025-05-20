//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100
#define MAX_EMAIL_LENGTH 100
#define MAX_SUBJECT_LENGTH 100
#define MAX_MESSAGE_LENGTH 1000

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} Contact;

typedef struct {
    char subject[MAX_SUBJECT_LENGTH];
    char message[MAX_MESSAGE_LENGTH];
    int num_recipients;
    Contact *recipients;
} Message;

int main() {
    // Initialize mailing list
    Contact mailing_list[10];
    int num_contacts = 0;

    // Add contacts to mailing list
    strcpy(mailing_list[num_contacts].name, "John Doe");
    strcpy(mailing_list[num_contacts].email, "john.doe@example.com");
    num_contacts++;

    strcpy(mailing_list[num_contacts].name, "Jane Doe");
    strcpy(mailing_list[num_contacts].email, "jane.doe@example.com");
    num_contacts++;

    // Send message to mailing list
    Message message;
    strcpy(message.subject, "Test Message");
    strcpy(message.message, "Hello world!");
    message.num_recipients = num_contacts;
    message.recipients = (Contact *) malloc(num_contacts * sizeof(Contact));

    for (int i = 0; i < num_contacts; i++) {
        memcpy(&message.recipients[i], &mailing_list[i], sizeof(Contact));
    }

    // Send message
    for (int i = 0; i < num_contacts; i++) {
        printf("Sending message to %s (%s)\n", message.recipients[i].name, message.recipients[i].email);
    }

    free(message.recipients);

    return 0;
}