//LLAMA2-13B DATASET v1.0 Category: Phone Book ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LENGTH 50
#define MAX_PHONE_NUMBER_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    char phone_number[MAX_PHONE_NUMBER_LENGTH];
} contact_t;

contact_t contacts[5];

void init_contacts(void);
void add_contact(const char* name, const char* phone_number);
void print_contacts(void);

int main(void) {
    srand(time(NULL));

    init_contacts();

    printf("Welcome to the Brave Phone Book!\n");

    while (1) {
        printf("Add a contact (y/n)? ");
        char input = getchar();

        if (input == 'y' || input == 'Y') {
            char name[MAX_NAME_LENGTH];
            char phone_number[MAX_PHONE_NUMBER_LENGTH];

            printf("Enter name: ");
            fgets(name, MAX_NAME_LENGTH, stdin);
            name[strcspn(name, "\n")] = 0; // remove newline

            printf("Enter phone number: ");
            fgets(phone_number, MAX_PHONE_NUMBER_LENGTH, stdin);
            phone_number[strcspn(phone_number, "\n")] = 0; // remove newline

            add_contact(name, phone_number);
        } else if (input == 'p' || input == 'P') {
            print_contacts();
        } else {
            break;
        }
    }

    return 0;
}

void init_contacts(void) {
    int i;

    for (i = 0; i < 5; i++) {
        contacts[i].name[0] = 0;
        contacts[i].phone_number[0] = 0;
    }
}

void add_contact(const char* name, const char* phone_number) {
    int i;

    for (i = 0; i < 5; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            // contact already exists, do nothing
            break;
        }
    }

    if (i == 5) {
        // contact does not exist, add it
        strcpy(contacts[i].name, name);
        strcpy(contacts[i].phone_number, phone_number);
    }
}

void print_contacts(void) {
    int i;

    for (i = 0; i < 5; i++) {
        printf("%d. %s (%s)\n", i + 1, contacts[i].name, contacts[i].phone_number);
    }
}