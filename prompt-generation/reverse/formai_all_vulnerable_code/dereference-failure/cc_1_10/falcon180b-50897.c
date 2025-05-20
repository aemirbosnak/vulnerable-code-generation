//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_NAME_LEN 50
#define MAX_EMAIL_LEN 100
#define MAX_SUBJECT_LEN 100
#define MAX_BODY_LEN 1024

typedef struct {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
} contact;

typedef struct {
    int num_contacts;
    contact *contacts;
} mailing_list;

void init_contact(contact *c) {
    strcpy(c->name, "");
    strcpy(c->email, "");
}

void init_mailing_list(mailing_list *ml) {
    ml->num_contacts = 0;
    ml->contacts = NULL;
}

void add_contact(mailing_list *ml, contact c) {
    ml->contacts = realloc(ml->contacts, sizeof(contact) * (ml->num_contacts + 1));
    ml->contacts[ml->num_contacts] = c;
    ml->num_contacts++;
}

void print_contact(contact c) {
    printf("Name: %s\n", c.name);
    printf("Email: %s\n", c.email);
}

void print_mailing_list(mailing_list ml) {
    int i;
    for (i = 0; i < ml.num_contacts; i++) {
        print_contact(ml.contacts[i]);
    }
}

int main() {
    mailing_list ml;
    init_mailing_list(&ml);

    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];

    int choice;
    do {
        printf("\nMailing List Manager\n");
        printf("1. Add contact\n");
        printf("2. Print mailing list\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter name: ");
            scanf("%s", name);
            printf("Enter email: ");
            scanf("%s", email);
            init_contact(&ml.contacts[ml.num_contacts]);
            strcpy(ml.contacts[ml.num_contacts].name, name);
            strcpy(ml.contacts[ml.num_contacts].email, email);
            ml.num_contacts++;
            break;
        case 2:
            print_mailing_list(ml);
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    } while (1);

    return 0;
}