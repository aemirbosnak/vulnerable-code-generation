//FormAI DATASET v1.0 Category: Phone Book ; Style: expert-level
#include <stdio.h>
#include <string.h>

#define MAX_NAME_LEN 50
#define MAX_PHONE_LEN 15
#define MAX_ADDRESS_LEN 100
#define MAX_EMAIL_LEN 100

struct PhoneBookEntry {
    char name[MAX_NAME_LEN];
    char phoneNumber[MAX_PHONE_LEN];
    char address[MAX_ADDRESS_LEN];
    char email[MAX_EMAIL_LEN];
};

void addEntry(struct PhoneBookEntry* phoneBook, int* numEntries);
void removeEntry(struct PhoneBookEntry* phoneBook, int* numEntries);
void searchEntry(struct PhoneBookEntry* phoneBook, int numEntries);
void printEntries(struct PhoneBookEntry* phoneBook, int numEntries);

int main() {
    struct PhoneBookEntry phoneBook[100];
    int numEntries = 0;
    int option;

    do {
        printf("\n---Welcome to the Phone Book Application---\n");
        printf("Please select an option:\n");
        printf("\t1. Add entry\n");
        printf("\t2. Remove entry\n");
        printf("\t3. Search for an entry\n");
        printf("\t4. Print all entries\n");
        printf("\t5. Exit\n");

        printf("Option: ");
        scanf("%d", &option);
        getchar(); // Consume the newline char

        switch (option) {
            case 1:
                addEntry(phoneBook, &numEntries);
                break;
            case 2:
                removeEntry(phoneBook, &numEntries);
                break;
            case 3:
                searchEntry(phoneBook, numEntries);
                break;
            case 4:
                printEntries(phoneBook, numEntries);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option selected.\n");
                break;
        }
    } while (option != 5);

    return 0;
}

void addEntry(struct PhoneBookEntry* phoneBook, int* numEntries) {
    if (*numEntries >= 100) {
        printf("Cannot add any more entries. Phone book is full.\n");
        return;
    }

    printf("\n---Adding an entry---\n");

    printf("Name: ");
    fgets(phoneBook[*numEntries].name, MAX_NAME_LEN, stdin);
    phoneBook[*numEntries].name[strlen(phoneBook[*numEntries].name) - 1] = '\0'; // Remove trailing newline char

    printf("Phone number: ");
    fgets(phoneBook[*numEntries].phoneNumber, MAX_PHONE_LEN, stdin);
    phoneBook[*numEntries].phoneNumber[strlen(phoneBook[*numEntries].phoneNumber) - 1] = '\0'; // Remove trailing newline char

    printf("Address: ");
    fgets(phoneBook[*numEntries].address, MAX_ADDRESS_LEN, stdin);
    phoneBook[*numEntries].address[strlen(phoneBook[*numEntries].address) - 1] = '\0'; // Remove trailing newline char

    printf("Email: ");
    fgets(phoneBook[*numEntries].email, MAX_EMAIL_LEN, stdin);
    phoneBook[*numEntries].email[strlen(phoneBook[*numEntries].email) - 1] = '\0'; // Remove trailing newline char

    (*numEntries)++;
    printf("Entry added.\n");
}

void removeEntry(struct PhoneBookEntry* phoneBook, int* numEntries) {
    if (*numEntries <= 0) {
        printf("Cannot remove any entry. Phone book is empty.\n");
        return;
    }

    char name[MAX_NAME_LEN];

    printf("\n---Removing an entry---\n");
    printf("Name: ");
    fgets(name, MAX_NAME_LEN, stdin);
    name[strlen(name) - 1] = '\0'; // Remove trailing newline char

    for (int i = 0; i < *numEntries; i++) {
        if (strcmp(phoneBook[i].name, name) == 0) {
            *numEntries -= 1;

            for (int j = i; j < *numEntries; j++) {
                strcpy(phoneBook[j].name, phoneBook[j + 1].name);
                strcpy(phoneBook[j].phoneNumber, phoneBook[j + 1].phoneNumber);
                strcpy(phoneBook[j].address, phoneBook[j + 1].address);
                strcpy(phoneBook[j].email, phoneBook[j + 1].email);
            }

            printf("Entry removed.\n");
            return;
        }
    }

    printf("No matching entry found.\n");
}

void searchEntry(struct PhoneBookEntry* phoneBook, int numEntries) {
    if (numEntries <= 0) {
        printf("Cannot search for any entry. Phone book is empty.\n");
        return;
    }

    char name[MAX_NAME_LEN];

    printf("\n---Searching for an entry---\n");
    printf("Name: ");
    fgets(name, MAX_NAME_LEN, stdin);
    name[strlen(name) - 1] = '\0'; // Remove trailing newline char

    for (int i = 0; i < numEntries; i++) {
        if (strcmp(phoneBook[i].name, name) == 0) {
            printf("Name: %s\n", phoneBook[i].name);
            printf("Phone number: %s\n", phoneBook[i].phoneNumber);
            printf("Address: %s\n", phoneBook[i].address);
            printf("Email: %s\n", phoneBook[i].email);
            return;
        }
    }

    printf("No matching entry found.\n");
}

void printEntries(struct PhoneBookEntry* phoneBook, int numEntries) {
    if (numEntries <= 0) {
        printf("Phone book is empty.\n");
        return;
    }

    printf("\n---Printing all entries---\n");

    for (int i = 0; i < numEntries; i++) {
        printf("Name: %s\n", phoneBook[i].name);
        printf("Phone number: %s\n", phoneBook[i].phoneNumber);
        printf("Address: %s\n", phoneBook[i].address);
        printf("Email: %s\n\n", phoneBook[i].email);
    }
}