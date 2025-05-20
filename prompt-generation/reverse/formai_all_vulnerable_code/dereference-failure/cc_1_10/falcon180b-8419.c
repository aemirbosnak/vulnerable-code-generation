//Falcon-180B DATASET v1.0 Category: File handling ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

typedef struct {
    char *name;
    char *phone_number;
} Contact;

int compare_contacts(const void *a, const void *b) {
    Contact *contact_a = (Contact *) a;
    Contact *contact_b = (Contact *) b;

    int result = strcmp(contact_a->name, contact_b->name);

    if (result == 0) {
        result = strcmp(contact_a->phone_number, contact_b->phone_number);
    }

    return result;
}

int main() {
    FILE *file = fopen("contacts.txt", "r");

    if (file == NULL) {
        printf("Error: could not open file.\n");
        return 1;
    }

    Contact *contacts = NULL;
    int num_contacts = 0;

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        char *name = strtok(line, ",");
        char *phone_number = strtok(NULL, ",");

        if (name == NULL || phone_number == NULL) {
            printf("Error: invalid line format.\n");
            return 1;
        }

        Contact *new_contact = malloc(sizeof(Contact));
        new_contact->name = strdup(name);
        new_contact->phone_number = strdup(phone_number);

        contacts = realloc(contacts, sizeof(Contact) * ++num_contacts);
        contacts[num_contacts - 1] = *new_contact;
    }

    qsort(contacts, num_contacts, sizeof(Contact), compare_contacts);

    for (int i = 0; i < num_contacts; i++) {
        printf("%s: %s\n", contacts[i].name, contacts[i].phone_number);
    }

    free(contacts);
    fclose(file);

    return 0;
}