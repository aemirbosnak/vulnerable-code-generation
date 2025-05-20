//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 64
#define MAX_EMAILS 1000

// Define the structure for each email address in the list
typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_NAME_LENGTH];
} EmailAddress;

// Function to compare two email addresses (for sorting)
int compareEmailAddresses(const void *a, const void *b) {
    EmailAddress *emailA = (EmailAddress *)a;
    EmailAddress *emailB = (EmailAddress *)b;

    return strcmp(emailA->email, emailB->email);
}

// Function to print the entire email list
void printEmailList(EmailAddress emails[], int numEmails) {
    printf("Email List:\n");
    for (int i = 0; i < numEmails; i++) {
        printf("%s (%s)\n", emails[i].name, emails[i].email);
    }
}

int main() {
    // Initialize variables
    EmailAddress emails[MAX_EMAILS];
    int numEmails = 0;

    // Read in email addresses from user input
    char input[MAX_NAME_LENGTH];
    while (fgets(input, MAX_NAME_LENGTH, stdin)!= NULL) {
        if (numEmails >= MAX_EMAILS) {
            printf("Error: Maximum number of email addresses reached.\n");
            break;
        }

        // Split input into name and email
        char *name = strtok(input, " ");
        char *email = strtok(NULL, "\n");

        // Copy name and email into struct
        strcpy(emails[numEmails].name, name);
        strcpy(emails[numEmails].email, email);

        numEmails++;
    }

    // Sort email list alphabetically by name
    qsort(emails, numEmails, sizeof(EmailAddress), compareEmailAddresses);

    // Print sorted email list
    printf("Sorted Email List:\n");
    printEmailList(emails, numEmails);

    return 0;
}