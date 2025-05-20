//Falcon2-11B DATASET v1.0 Category: Building a CSV Reader ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    char *address;
    char *phone;
} Contact;

int parse_csv(FILE *fp, Contact *contacts, int *n_contacts) {
    char line[100];
    int n_lines = 0;
    int n_contacts_read = 0;

    // Read each line from the CSV file
    while (fgets(line, sizeof(line), fp)) {
        n_lines++;

        // Parse the line and populate the Contact struct
        char *name_str = strtok(line, ",");
        char *address_str = strtok(NULL, ",");
        char *phone_str = strtok(NULL, ",");

        Contact *contact = (Contact *) malloc(sizeof(Contact));
        contact->name = strdup(name_str);
        contact->address = strdup(address_str);
        contact->phone = strdup(phone_str);

        // Add the Contact struct to the list
        contacts[n_contacts_read++] = *contact;

        // Check if we have reached the end of the file
        if (n_lines >= *n_contacts) {
            // We have reached the end of the file
            break;
        }
    }

    *n_contacts = n_contacts_read;
    return n_contacts_read;
}

int main() {
    FILE *fp = fopen("contacts.csv", "r");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file\n");
        return 1;
    }

    Contact *contacts = (Contact *) malloc(sizeof(Contact) * 100);
    int n_contacts = 0;
    int n_contacts_read = parse_csv(fp, contacts, &n_contacts);

    for (int i = 0; i < n_contacts; i++) {
        printf("Name: %s\n", contacts[i].name);
        printf("Address: %s\n", contacts[i].address);
        printf("Phone: %s\n", contacts[i].phone);
        printf("\n");
    }

    free(contacts);
    fclose(fp);

    return 0;
}