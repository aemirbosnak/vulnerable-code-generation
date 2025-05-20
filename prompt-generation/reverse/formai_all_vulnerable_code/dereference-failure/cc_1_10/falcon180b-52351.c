//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 1000

typedef struct {
    char name[100];
    char phone[20];
} Contact;

int main() {
    int num_contacts = 0;
    Contact contacts[MAX_CONTACTS];

    // Read in contacts from file
    FILE *file = fopen("contacts.txt", "r");
    if (file == NULL) {
        printf("Error: Unable to open contacts file.\n");
        exit(1);
    }

    char line[200];
    while (fgets(line, sizeof(line), file)!= NULL) {
        char *name = strtok(line, ",");
        char *phone = strtok(NULL, ",");

        strcpy(contacts[num_contacts].name, name);
        strcpy(contacts[num_contacts].phone, phone);

        num_contacts++;
    }

    fclose(file);

    // Search for contact
    char search_name[100];
    printf("Enter name to search for: ");
    scanf("%s", search_name);

    int contact_index = -1;
    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(contacts[i].name, search_name) == 0) {
            contact_index = i;
            break;
        }
    }

    if (contact_index == -1) {
        printf("Contact not found.\n");
    } else {
        printf("Contact found:\n");
        printf("Name: %s\n", contacts[contact_index].name);
        printf("Phone: %s\n", contacts[contact_index].phone);
    }

    return 0;
}