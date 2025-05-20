//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_NUMBERS_PER_CONTACT 5
#define MAX_CONTACTS 50

typedef struct contact {
    char name[MAX_NAME_LENGTH];
    int num_numbers;
    char numbers[MAX_NUMBERS_PER_CONTACT][MAX_NAME_LENGTH];
} contact_t;

typedef struct phonebook {
    contact_t contacts[MAX_CONTACTS];
    int num_contacts;
} phonebook_t;

void add_contact(phonebook_t* pb) {
    printf("Enter contact name: ");
    scanf("%s", pb->contacts[pb->num_contacts].name);
    pb->contacts[pb->num_contacts].num_numbers = 0;
    pb->num_contacts++;
}

void add_number(phonebook_t* pb, int contact_index) {
    printf("Enter phone number for %s: ", pb->contacts[contact_index].name);
    scanf("%s", pb->contacts[contact_index].numbers[pb->contacts[contact_index].num_numbers]);
    pb->contacts[contact_index].num_numbers++;
}

void display_contact(contact_t* c) {
    printf("Name: %s\n", c->name);
    printf("Phone Numbers:\n");
    for (int i = 0; i < c->num_numbers; i++) {
        printf("%s\n", c->numbers[i]);
    }
}

void display_phonebook(phonebook_t* pb) {
    printf("Phone Book:\n");
    for (int i = 0; i < pb->num_contacts; i++) {
        printf("Contact %d:\n", i+1);
        display_contact(&pb->contacts[i]);
    }
}

int main() {
    phonebook_t pb;
    pb.num_contacts = 0;

    while (pb.num_contacts < MAX_CONTACTS) {
        printf("\nWhat would you like to do?\n");
        printf("1. Add contact\n2. Add phone number\n3. Display phone book\n4. Quit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            add_contact(&pb);
            break;
        case 2:
            printf("Enter contact index: ");
            int contact_index;
            scanf("%d", &contact_index);
            add_number(&pb, contact_index);
            break;
        case 3:
            display_phonebook(&pb);
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}