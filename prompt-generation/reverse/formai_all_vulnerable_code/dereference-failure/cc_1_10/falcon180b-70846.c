//Falcon-180B DATASET v1.0 Category: Email Client ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1000
#define MAX_EMAIL_LENGTH 100
#define MAX_SUBJECT_LENGTH 100

typedef struct {
    char name[MAX_EMAIL_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} contact;

int main() {
    char line[MAX_LINE_LENGTH];
    char *token;
    contact contacts[100];
    int num_contacts = 0;

    printf("Welcome to the Email Client!\n");

    // Read in the contacts file
    FILE *file = fopen("contacts.txt", "r");
    if (file == NULL) {
        printf("Error: contacts.txt not found.\n");
        return 1;
    }

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        // Parse the line and add the contact to the list
        token = strtok(line, ",");
        strcpy(contacts[num_contacts].name, token);
        token = strtok(NULL, ",");
        strcpy(contacts[num_contacts].email, token);
        num_contacts++;
    }
    fclose(file);

    // Main menu loop
    while (1) {
        printf("\nEmail Client Menu:\n");
        printf("1. Compose email\n");
        printf("2. View contacts\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &num_contacts);

        switch (num_contacts) {
        case 1:
            // Compose email
            printf("\nCompose email:\n");
            printf("To: ");
            scanf("%s", contacts[0].email);
            printf("Subject: ");
            scanf("%s", contacts[0].name);
            printf("Message: ");
            fgets(line, MAX_LINE_LENGTH, stdin);

            // Send the email
            printf("\nEmail sent to %s.\n", contacts[0].name);
            break;

        case 2:
            // View contacts
            printf("\nView contacts:\n");
            for (int i = 0; i < num_contacts; i++) {
                printf("%s (%s)\n", contacts[i].name, contacts[i].email);
            }
            break;

        case 3:
            // Exit
            printf("\nExiting...\n");
            return 0;

        default:
            printf("\nInvalid choice.\n");
        }
    }

    return 0;
}