//FormAI DATASET v1.0 Category: Phone Book ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Phonebook structure
typedef struct Phonebook {
    char name[50];
    char number[15];
    struct Phonebook* next;
} Phonebook;

// Function to add a new entry to the phonebook
void addEntry(Phonebook** head, char* name, char* number) {
    // Allocate memory for the new entry
    Phonebook* newEntry = (Phonebook*)malloc(sizeof(Phonebook));
    strcpy(newEntry->name, name);
    strcpy(newEntry->number, number);
    newEntry->next = NULL;

    // Check if the phonebook is empty
    if (*head == NULL) {
        *head = newEntry;
        return;
    }

    // Find the correct position to insert the new entry
    Phonebook* current = *head;
    Phonebook* prev = NULL;
    while (current != NULL && strcmp(current->name, name) < 0) {
        prev = current;
        current = current->next;
    }

    // Check if the new entry should be the head of the phonebook
    if (prev == NULL) {
        *head = newEntry;
    } else {
        prev->next = newEntry;
    }
    newEntry->next = current;
}

// Function to search for an entry in the phonebook
void search(Phonebook* head, char* name) {
    Phonebook* current = head;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            printf("%s: %s\n", current->name, current->number);
            return;
        }
        current = current->next;
    }
    printf("Entry not found.\n");
}

// Function to print the entire phonebook
void printPhonebook(Phonebook* head) {
    Phonebook* current = head;
    while (current != NULL) {
        printf("%s: %s\n", current->name, current->number);
        current = current->next;
    }
}

int main() {
    Phonebook* head = NULL;
    char name[50];
    char number[15];
    int choice;

    while (1) {
        printf("\nSelect an option:\n");
        printf("1. Add entry\n");
        printf("2. Search for entry\n");
        printf("3. Print phonebook\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter number: ");
                scanf("%s", number);
                addEntry(&head, name, number);
                printf("Entry added.\n");
                break;

            case 2:
                printf("Enter name to search for: ");
                scanf("%s", name);
                search(head, name);
                break;

            case 3:
                printPhonebook(head);
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    }

    return 0;
}