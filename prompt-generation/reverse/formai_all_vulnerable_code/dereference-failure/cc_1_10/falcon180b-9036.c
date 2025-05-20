//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 100
#define MAX_EMAIL_LEN 100

typedef struct {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
} contact;

int main() {
    FILE *file;
    contact *contacts = NULL;
    int num_contacts = 0;

    // Open the contacts file
    file = fopen("contacts.txt", "r");
    if (file == NULL) {
        printf("Error: could not open contacts file.\n");
        return 1;
    }

    // Read in the contacts
    char line[MAX_EMAIL_LEN];
    while (fgets(line, sizeof(line), file)!= NULL) {
        contact *new_contact = malloc(sizeof(contact));
        if (new_contact == NULL) {
            printf("Error: could not allocate memory for new contact.\n");
            return 1;
        }
        strcpy(new_contact->name, "");
        strcpy(new_contact->email, "");

        // Parse the line into name and email
        char *token = strtok(line, ",");
        if (token!= NULL) {
            strncpy(new_contact->name, token, MAX_NAME_LEN - 1);
            new_contact->name[MAX_NAME_LEN - 1] = '\0';
        }
        token = strtok(NULL, ",");
        if (token!= NULL) {
            strncpy(new_contact->email, token, MAX_EMAIL_LEN - 1);
            new_contact->email[MAX_EMAIL_LEN - 1] = '\0';
        }

        // Add the contact to the list
        contacts = realloc(contacts, sizeof(contact) * ++num_contacts);
        if (contacts == NULL) {
            printf("Error: could not reallocate memory for contacts.\n");
            return 1;
        }
        contacts[num_contacts - 1] = *new_contact;
        free(new_contact);
    }

    // Close the file
    fclose(file);

    // Print the list of contacts
    printf("Name\tEmail\n");
    for (int i = 0; i < num_contacts; i++) {
        printf("%s\t%s\n", contacts[i].name, contacts[i].email);
    }

    // Free memory
    for (int i = 0; i < num_contacts; i++) {
        free(contacts[i].name);
        free(contacts[i].email);
    }
    free(contacts);

    return 0;
}