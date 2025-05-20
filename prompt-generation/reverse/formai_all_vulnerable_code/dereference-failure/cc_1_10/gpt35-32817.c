//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    char *email;
    char *phone;
} Contact;

int main() {
    FILE *file;
    char buffer[1024];
    Contact *contacts;
    int num_contacts = 0;
    int max_contacts = 10;

    // Allocate memory for contacts array
    contacts = (Contact *)malloc(sizeof(Contact) * max_contacts);

    // Open file for reading
    file = fopen("contacts.csv", "r");
    if(!file) {
        printf("Error opening file\n");
        return 1;
    }

    // Read each line of the file
    while(fgets(buffer, 1024, file)) {
        // Remove newline character
        buffer[strcspn(buffer, "\n")] = 0;

        // Parse the line
        char *name = strtok(buffer, ",");
        char *email = strtok(NULL, ",");
        char *phone = strtok(NULL, ",");

        // Add contact to array
        contacts[num_contacts].name = strdup(name);
        contacts[num_contacts].email = strdup(email);
        contacts[num_contacts].phone = strdup(phone);

        num_contacts++;

        // Increase array size if necessary
        if(num_contacts == max_contacts) {
            max_contacts *= 2;
            contacts = (Contact *)realloc(contacts, sizeof(Contact) * max_contacts);
        }
    }

    // Close file
    fclose(file);

    // Print all contacts
    for(int i = 0; i < num_contacts; i++) {
        printf("Name: %s\n", contacts[i].name);
        printf("Email: %s\n", contacts[i].email);
        printf("Phone: %s\n\n", contacts[i].phone);
    }

    // Free memory
    for(int i = 0; i < num_contacts; i++) {
        free(contacts[i].name);
        free(contacts[i].email);
        free(contacts[i].phone);
    }
    free(contacts);

    printf("CSV reader program finished successfully!\n");

    return 0;
}