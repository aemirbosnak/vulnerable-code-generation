//Falcon-180B DATASET v1.0 Category: Email Client ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char *name;
    char *email;
} contact;

contact *email_contacts = NULL;
int num_contacts = 0;

void add_contact(char *name, char *email) {
    contact *new_contact = (contact *)malloc(sizeof(contact));
    new_contact->name = strdup(name);
    new_contact->email = strdup(email);
    email_contacts = (contact *)realloc(email_contacts, sizeof(contact) * ++num_contacts);
    email_contacts[num_contacts - 1] = *new_contact;
    free(new_contact);
}

void print_contacts() {
    for (int i = 0; i < num_contacts; i++) {
        printf("%s <%s>\n", email_contacts[i].name, email_contacts[i].email);
    }
}

int main() {
    char line[MAX_LINE_LENGTH];
    FILE *file = fopen("contacts.txt", "r");

    if (file == NULL) {
        printf("Error: contacts.txt not found.\n");
        return 1;
    }

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        char *name = strtok(line, " ");
        char *email = strtok(NULL, "\n");

        if (name!= NULL && email!= NULL) {
            add_contact(name, email);
        }
    }

    fclose(file);

    print_contacts();

    return 0;
}