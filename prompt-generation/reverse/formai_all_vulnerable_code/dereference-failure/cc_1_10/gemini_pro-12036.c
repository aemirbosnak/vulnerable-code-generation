//GEMINI-pro DATASET v1.0 Category: Database simulation ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[20];
    char email[40];
    char phone[20];
} Contact;

Contact *contacts;
int num_contacts = 0;

void add_contact() {
    Contact new_contact;

    printf("Enter name: ");
    scanf(" %s", new_contact.name);

    printf("Enter email: ");
    scanf(" %s", new_contact.email);

    printf("Enter phone: ");
    scanf(" %s", new_contact.phone);

    contacts = realloc(contacts, (num_contacts + 1) * sizeof(Contact));
    contacts[num_contacts] = new_contact;
    num_contacts++;
}

void list_contacts() {
    for (int i = 0; i < num_contacts; i++) {
        printf("%s\t%s\t%s\n", contacts[i].name, contacts[i].email, contacts[i].phone);
    }
}

void edit_contact() {
    char name[20];

    printf("Enter name of contact to edit: ");
    scanf(" %s", name);

    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            printf("Enter new name: ");
            scanf(" %s", contacts[i].name);

            printf("Enter new email: ");
            scanf(" %s", contacts[i].email);

            printf("Enter new phone: ");
            scanf(" %s", contacts[i].phone);

            break;
        }
    }
}

void delete_contact() {
    char name[20];

    printf("Enter name of contact to delete: ");
    scanf(" %s", name);

    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            for (int j = i + 1; j < num_contacts; j++) {
                contacts[j - 1] = contacts[j];
            }

            num_contacts--;
            break;
        }
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n1. Add contact\n2. List contacts\n3. Edit contact\n4. Delete contact\n5. Quit\n\nEnter your choice: ");
        scanf(" %d", &choice);

        switch (choice) {
            case 1:
                add_contact();
                break;
            case 2:
                list_contacts();
                break;
            case 3:
                edit_contact();
                break;
            case 4:
                delete_contact();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}