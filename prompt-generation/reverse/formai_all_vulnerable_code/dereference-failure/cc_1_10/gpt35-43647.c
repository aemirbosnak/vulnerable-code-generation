//FormAI DATASET v1.0 Category: Phone Book ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Structure for holding contact information */
struct contact {
    char name[50];
    char phone_number[20];
};

/* Function prototypes */
void add_contact(struct contact**, int*);
void search_contact(struct contact*, int);
void delete_contact(struct contact**, int*);
void print_contacts(struct contact*, int);

/* Main function */
int main() {
    int option, count = 0;
    struct contact* contacts = NULL;

    do {
        printf("\n\n**********************************\n");
        printf("\t PHONE BOOK MENU \n");
        printf("**********************************\n");
        printf("1. Add Contact\n");
        printf("2. Search Contact\n");
        printf("3. Delete Contact\n");
        printf("4. Print Contacts\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);

        switch(option) {
            case 1: /* Add contact */
                add_contact(&contacts, &count);
                break;

            case 2: /* Search contact */
                search_contact(contacts, count);
                break;

            case 3: /* Delete contact */
                delete_contact(&contacts, &count);
                break;

            case 4: /* Print contacts */
                print_contacts(contacts, count);
                break;

            case 5: /* Exit */
                printf("\nThank you for using the phone book!\n");
                break;

            default: /* Invalid option */
                printf("\nInvalid option.\n");
                break;
        }
    } while (option != 5);

    return 0;
}

/* Function to add a contact */
void add_contact(struct contact** contacts, int* count) {
    char buffer[50];
    struct contact new_contact;

    printf("\nEnter name: ");
    fgets(buffer, 50, stdin);
    strcpy(new_contact.name, buffer);

    printf("Enter phone number: ");
    fgets(buffer, 20, stdin);
    strcpy(new_contact.phone_number, buffer);

    *count += 1;
    *contacts = (struct contact*)realloc(*contacts, (*count) * sizeof(struct contact));
    (*contacts)[*count - 1] = new_contact;

    printf("\nContact added!\n");
}

/* Function to search for a contact */
void search_contact(struct contact* contacts, int count) {
    char search_name[50];
    int i, found = 0;

    printf("\nEnter name to search: ");
    fgets(search_name, 50, stdin);

    for (i = 0; i < count; i++) {
        if (strcmp(contacts[i].name, search_name) == 0) {
            printf("\nName: %sPhone Number: %s", contacts[i].name, contacts[i].phone_number);
            found = 1;
            break;
        }
    }

    if (found == 0) {
        printf("\nContact not found.\n");
    }
}

/* Function to delete a contact */
void delete_contact(struct contact** contacts, int* count) {
    char search_name[50];
    int i, found = 0;

    printf("\nEnter name to delete: ");
    fgets(search_name, 50, stdin);

    for (i = 0; i < *count; i++) {
        if (strcmp((*contacts)[i].name, search_name) == 0) {
            found = 1;
            *count -= 1;
            (*contacts)[i] = (*contacts)[*count];
            *contacts = (struct contact*)realloc(*contacts, (*count) * sizeof(struct contact));
            printf("\nContact deleted!\n");
            break;
        }
    }

    if (found == 0) {
        printf("\nContact not found.\n");
    }
}

/* Function to print all contacts */
void print_contacts(struct contact* contacts, int count) {
    int i;

    if (count == 0) {
        printf("\nNo contacts found.\n");
    } else {
        printf("\nContacts:\n");

        for (i = 0; i < count; i++) {
            printf("\nName: %sPhone Number: %s", contacts[i].name, contacts[i].phone_number);
        }
    }
}