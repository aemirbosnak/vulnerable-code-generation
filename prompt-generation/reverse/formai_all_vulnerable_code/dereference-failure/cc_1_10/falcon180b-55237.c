//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100
#define MAX_EMAIL_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} contact;

int main() {
    FILE *file;
    char line[200];
    char *token;
    contact *contacts = NULL;
    int count = 0;

    // Open the mailing list file
    file = fopen("mailing_list.txt", "r");
    if (file == NULL) {
        printf("Error opening mailing list file.\n");
        exit(1);
    }

    // Read the contacts from the file
    while (fgets(line, sizeof(line), file)!= NULL) {
        // Allocate memory for a new contact
        contact *new_contact = malloc(sizeof(contact));
        if (new_contact == NULL) {
            printf("Error allocating memory for new contact.\n");
            exit(1);
        }

        // Initialize the new contact
        strcpy(new_contact->name, "");
        strcpy(new_contact->email, "");

        // Parse the line into name and email
        token = strtok(line, ",");
        strcpy(new_contact->name, token);
        token = strtok(NULL, ",");
        strcpy(new_contact->email, token);

        // Add the new contact to the list
        contacts = realloc(contacts, sizeof(contact) * (count + 1));
        if (contacts == NULL) {
            printf("Error reallocating memory for contacts.\n");
            exit(1);
        }
        contacts[count] = *new_contact;
        free(new_contact);
        count++;
    }

    // Close the mailing list file
    fclose(file);

    // Print the list of contacts
    printf("Mailing list:\n");
    for (int i = 0; i < count; i++) {
        printf("%s <%s>\n", contacts[i].name, contacts[i].email);
    }

    // Free the memory used by the contacts
    for (int i = 0; i < count; i++) {
        free(contacts[i].name);
        free(contacts[i].email);
    }
    free(contacts);

    return 0;
}