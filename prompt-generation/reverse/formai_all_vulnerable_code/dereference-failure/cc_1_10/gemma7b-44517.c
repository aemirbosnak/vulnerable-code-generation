//Gemma-7B DATASET v1.0 Category: Mailing list manager ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NAME_LENGTH 25
#define MAX_ADDRESS_LENGTH 50

typedef struct AddressBookEntry {
    char name[MAX_NAME_LENGTH];
    char address[MAX_ADDRESS_LENGTH];
    struct AddressBookEntry* next;
} AddressBookEntry;

AddressBookEntry* addEntry(AddressBookEntry* head) {
    AddressBookEntry* newEntry = malloc(sizeof(AddressBookEntry));

    printf("Enter name: ");
    scanf("%s", newEntry->name);

    printf("Enter address: ");
    scanf("%s", newEntry->address);

    newEntry->next = head;
    head = newEntry;

    return head;
}

void printEntries(AddressBookEntry* head) {
    printf("List of entries:\n");
    while (head) {
        printf("Name: %s\n", head->name);
        printf("Address: %s\n", head->address);
        printf("\n");
        head = head->next;
    }
}

int main() {
    AddressBookEntry* head = NULL;

    // Add some entries
    head = addEntry(head);
    addEntry(head);
    addEntry(head);

    // Print the entries
    printEntries(head);

    return 0;
}