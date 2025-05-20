//FormAI DATASET v1.0 Category: Phone Book ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50
#define MAX_PHONE_LEN 20

typedef struct PhoneBookEntry {
    char name[MAX_NAME_LEN];
    char phone[MAX_PHONE_LEN];
    struct PhoneBookEntry *next;
} PhoneEntry;

PhoneEntry *head = NULL;

void insertEntry(char name[], char phone[]) {
    PhoneEntry *newEntry = malloc(sizeof(PhoneEntry));
    strcpy(newEntry->name, name);
    strcpy(newEntry->phone, phone);
    newEntry->next = NULL;

    if (head == NULL) {
        head = newEntry;
        return;
    }

    PhoneEntry *currentEntry = head;
    while (currentEntry->next != NULL) {
        currentEntry = currentEntry->next;
    }
    currentEntry->next = newEntry;
}

void deleteEntry(char name[]) {
    if (head == NULL) {
        printf("Phone book is empty\n");
        return;
    }

    PhoneEntry *prevEntry = NULL;
    PhoneEntry *currentEntry = head;
    while (currentEntry != NULL && strcmp(currentEntry->name, name) != 0) {
        prevEntry = currentEntry;
        currentEntry = currentEntry->next;
    }

    if (currentEntry == NULL) {
        printf("Entry with name \"%s\" does not exist in phone book\n", name);
        return;
    }

    if (prevEntry != NULL)
        prevEntry->next = currentEntry->next;
    else
        head = currentEntry->next;

    free(currentEntry);
    printf("Entry with name \"%s\" deleted successfully from phone book\n", name);
}

void searchEntry(char name[]) {
    if (head == NULL) {
        printf("Phone book is empty\n");
        return;
    }

    PhoneEntry *currentEntry = head;
    while (currentEntry != NULL) {
        if (strcmp(currentEntry->name, name) == 0) {
            printf("Details for name \"%s\" are:\n", name);
            printf("Phone : %s\n", currentEntry->phone);
            return;
        }
        currentEntry = currentEntry->next;
    }

    printf("Entry with name \"%s\" does not exist in phone book\n", name);
}

void printPhoneBook() {
    if (head == NULL) {
        printf("Phone book is empty\n");
        return;
    }

    PhoneEntry *currentEntry = head;
    printf("Phone book entries are:\n");
    while (currentEntry != NULL) {
        printf("Name : %s\n", currentEntry->name);
        printf("Phone : %s\n", currentEntry->phone);
        printf("\n");
        currentEntry = currentEntry->next;
    }
}

void clearPhoneBook() {
    while (head != NULL) {
        PhoneEntry *tempEntry = head;
        head = head->next;
        free(tempEntry);
    }
    printf("Phone book cleared successfully\n");
}

void displayMenu() {
    printf("*************************\n");
    printf("* 1 - Add phone entry    *\n");
    printf("* 2 - Delete phone entry *\n");
    printf("* 3 - Search phone entry *\n");
    printf("* 4 - Print phone book   *\n");
    printf("* 5 - Clear phone book   *\n");
    printf("* 6 - Exit               *\n");
    printf("*************************\n");
}

int main() {
    int choice = 0;
    char name[MAX_NAME_LEN];
    char phone[MAX_PHONE_LEN];
    while (choice != 6) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter phone: ");
                scanf("%s", phone);
                insertEntry(name, phone);
                printf("Entry added successfully\n");
                break;
            case 2:
                printf("Enter name: ");
                scanf("%s", name);
                deleteEntry(name);
                break;
            case 3:
                printf("Enter name: ");
                scanf("%s", name);
                searchEntry(name);
                break;
            case 4:
                printPhoneBook();
                break;
            case 5:
                clearPhoneBook();
                break;
            case 6:
                printf("Exiting phone book\n");
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
        printf("\n");
    }
    return 0;
}