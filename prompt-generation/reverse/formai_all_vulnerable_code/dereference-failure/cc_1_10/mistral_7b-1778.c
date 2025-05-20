//MISTRAL-7B DATASET v1.0 Category: Phone Book ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    char number[20];
} Entry;

void addEntry(Entry **phoneBook, int *numEntries, const char *name, const char *number) {
    Entry *newEntry = (Entry *)malloc(sizeof(Entry));

    strcpy(newEntry->name, name);
    strcpy(newEntry->number, number);

    (*numEntries)++;
    (*phoneBook) = realloc(*phoneBook, (*numEntries) * sizeof(Entry));

    (*phoneBook)[*numEntries - 1] = *newEntry;
}

void printPhoneBook(const Entry *phoneBook, int numEntries) {
    printf("\n********************************************\n");
    printf("*       Medieval Phone Book                *\n");
    printf("*                                          *\n");
    printf("********************************************\n");

    for (int i = 0; i < numEntries; i++) {
        printf("\n* %s (%s)                             *\n", phoneBook[i].name, phoneBook[i].number);
    }
}

int main() {
    int numEntries = 0;
    Entry *phoneBook = NULL;

    while (1) {
        printf("\n> What would you like to do? <\n");
        printf("1. Add a contact\n2. Display the phone book\n3. Quit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                char name[50], number[20];
                printf("Enter contact name: ");
                scanf("%s", name);
                printf("Enter contact number: ");
                scanf("%s", number);

                addEntry(&phoneBook, &numEntries, name, number);
                break;
            }
            case 2: {
                printPhoneBook(phoneBook, numEntries);
                break;
            }
            case 3: {
                free(phoneBook);
                exit(EXIT_SUCCESS);
            }
            default: {
                printf("Invalid choice, try again.\n");
                break;
            }
        }
    }

    return 0;
}