//FormAI DATASET v1.0 Category: Digital Diary ; Style: irregular
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
    A digital diary implementation with C language.
    The diary will store entries containing date and content. 
*/

struct Entry {
    char date[11];
    char content[500];
    struct Entry* next;
};

struct Entry* head = NULL; // Start of linked list

void addEntry(char date[11], char content[500]) {
    struct Entry* newEntry = (struct Entry*)malloc(sizeof(struct Entry));
    strcpy(newEntry->date, date);
    strcpy(newEntry->content, content);
    newEntry->next = head;
    head = newEntry;
}

void printEntries() {
    struct Entry* current = head;
    while (current != NULL) {
        printf("Date: %s\nContent: %s\n\n", current->date, current->content);
        current = current->next;
    }
}

int main() {
    printf("\nWelcome to your digital diary.\n\n");

    char choice;
    char date[11];
    char content[500];

    do {
        printf("Select an option:\n");
        printf("a - Add a new entry\n");
        printf("p - Print all diary entries\n");
        printf("q - Quit\n");
        scanf(" %c", &choice);

        switch (choice) {
            case 'a':
                printf("\nEnter today's date (DD-MM-YYYY): ");
                scanf("%s", date);
                printf("\nEnter your content:\n");
                scanf(" %[^\n]s", content);
                addEntry(date, content);
                break;

            case 'p':
                printf("\n--- Diary Entries ---\n\n");
                printEntries();
                break;

            case 'q':
                printf("\nGoodbye!\n");
                break;

            default:
                printf("\nInvalid choice.\n");
                break;
        }

    } while (choice != 'q');

    return 0;
}