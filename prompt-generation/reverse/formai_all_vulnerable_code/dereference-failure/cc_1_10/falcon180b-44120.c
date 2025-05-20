//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 100
#define MAX_EMAIL_LEN 100
#define MAX_LIST_SIZE 1000

typedef struct {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
} Contact;

typedef struct {
    Contact *contacts;
    int num_contacts;
} MailingList;

void add_contact(MailingList *list, char *name, char *email) {
    if (list->num_contacts >= MAX_LIST_SIZE) {
        printf("Error: Mailing list is full.\n");
        return;
    }
    list->contacts[list->num_contacts] = (Contact) {
       .name = strdup(name),
       .email = strdup(email)
    };
    list->num_contacts++;
}

void remove_contact(MailingList *list, char *email) {
    int i;
    for (i = 0; i < list->num_contacts; i++) {
        if (strcmp(list->contacts[i].email, email) == 0) {
            free(list->contacts[i].name);
            free(list->contacts[i].email);
            memmove(&list->contacts[i], &list->contacts[i + 1], sizeof(Contact) * (list->num_contacts - i - 1));
            list->num_contacts--;
            return;
        }
    }
    printf("Error: Contact not found.\n");
}

void print_contacts(MailingList *list) {
    int i;
    for (i = 0; i < list->num_contacts; i++) {
        printf("%s <%s>\n", list->contacts[i].name, list->contacts[i].email);
    }
}

int main() {
    MailingList list = {0};
    char name[MAX_NAME_LEN], email[MAX_EMAIL_LEN];
    int choice;

    printf("Welcome to the Mailing List Manager!\n");
    while (1) {
        printf("\n");
        printf("1. Add contact\n");
        printf("2. Remove contact\n");
        printf("3. Print contacts\n");
        printf("4. Exit\n");
        printf("\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter email: ");
                scanf("%s", email);
                add_contact(&list, name, email);
                break;
            case 2:
                printf("Enter email: ");
                scanf("%s", email);
                remove_contact(&list, email);
                break;
            case 3:
                print_contacts(&list);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}