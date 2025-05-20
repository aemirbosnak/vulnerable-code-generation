//FormAI DATASET v1.0 Category: Email Client ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

#define MAX_STR_LEN 1000 // Maximum string length for email message and fields
#define MAX_ADDR_LEN 50 // Maximum length of email address
#define MAX_SUBJECT_LEN 200 // Maximum length of email subject

typedef struct email {
    char* to_address;
    char* from_address;
    char* subject;
    char* message;
} Email;

int main() {
    char to_address[MAX_ADDR_LEN], from_address[MAX_ADDR_LEN], subject[MAX_SUBJECT_LEN], message[MAX_STR_LEN];
    printf("Enter to address: ");
    scanf("%s", to_address);
    printf("Enter from address: ");
    scanf("%s", from_address);
    printf("Enter subject: ");
    scanf("%s", subject);
    printf("Enter message: ");
    scanf("%s", message);

    // Creating a new email struct
    Email* new_email = (Email*) malloc(sizeof(Email));
    new_email->to_address = (char*) malloc(MAX_ADDR_LEN * sizeof(char));
    new_email->from_address = (char*) malloc(MAX_ADDR_LEN * sizeof(char));
    new_email->subject = (char*) malloc(MAX_SUBJECT_LEN * sizeof(char));
    new_email->message = (char*) malloc(MAX_STR_LEN * sizeof(char));

    // Assigning user input to email fields
    int i;
    for (i = 0; i < MAX_ADDR_LEN && to_address[i] != '\0'; i++) {
        new_email->to_address[i] = to_address[i];
    }
    new_email->to_address[i] = '\0';
    for (i = 0; i < MAX_ADDR_LEN && from_address[i] != '\0'; i++) {
        new_email->from_address[i] = from_address[i];
    }
    new_email->from_address[i] = '\0';
    for (i = 0; i < MAX_SUBJECT_LEN && subject[i] != '\0'; i++) {
        new_email->subject[i] = subject[i];
    }
    new_email->subject[i] = '\0';
    for (i = 0; i < MAX_STR_LEN && message[i] != '\0'; i++) {
        new_email->message[i] = message[i];
    }
    new_email->message[i] = '\0';

    printf("New email:\nTo: %s\nFrom: %s\nSubject: %s\nMessage: %s\n", new_email->to_address, new_email->from_address, new_email->subject, new_email->message);

    // Freeing malloc()ed memory
    free(new_email->to_address);
    free(new_email->from_address);
    free(new_email->subject);
    free(new_email->message);
    free(new_email);

    return 0;
}