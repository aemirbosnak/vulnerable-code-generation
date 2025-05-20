//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 64
#define MAX_NUM_LEN 16

typedef struct contact {
    char name[MAX_NAME_LEN];
    char number[MAX_NUM_LEN];
} contact_t;

int main() {
    FILE *fp;
    contact_t contact;
    char choice;
    char name[MAX_NAME_LEN];
    char number[MAX_NUM_LEN];

    fp = fopen("phonebook.txt", "r");
    if (fp == NULL) {
        printf("Phonebook file not found.\n");
        exit(1);
    }

    printf("Welcome to the Cyberpunk Phonebook!\n");

    while (1) {
        printf("Choose an option:\n");
        printf("A - Add contact\n");
        printf("S - Search contact\n");
        printf("Q - Quit\n");
        scanf(" %c", &choice);

        switch (choice) {
            case 'A':
                printf("Enter contact name: ");
                scanf(" %s", name);
                printf("Enter contact number: ");
                scanf(" %s", number);

                fseek(fp, 0, SEEK_END);
                fprintf(fp, "%s %s\n", name, number);
                printf("Contact added successfully!\n");
                break;

            case 'S':
                printf("Enter contact name to search: ");
                scanf(" %s", name);

                rewind(fp);
                while (fscanf(fp, "%s %s", contact.name, contact.number)!= EOF) {
                    if (strcmp(contact.name, name) == 0) {
                        printf("Contact found:\n");
                        printf("Name: %s\n", contact.name);
                        printf("Number: %s\n", contact.number);
                        break;
                    }
                }

                if (feof(fp)) {
                    printf("Contact not found.\n");
                }
                break;

            case 'Q':
                printf("Exiting program...\n");
                exit(0);

            default:
                printf("Invalid option.\n");
        }
    }

    fclose(fp);

    return 0;
}