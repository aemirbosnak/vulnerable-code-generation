//MISTRAL-7B DATASET v1.0 Category: Digital Diary ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ENTRY_LENGTH 100
#define ENTRY_NODE_SIZE sizeof(struct EntryNode)

typedef struct EntryNode {
    char title[MAX_ENTRY_LENGTH];
    char content[MAX_ENTRY_LENGTH];
    struct EntryNode *next;
} EntryNode;

EntryNode *head = NULL;
EntryNode *current = NULL;

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    printf("\033[2J");
#endif
}

void printTitle(const char *title) {
    printf("\n%s\n", title);
}

void printSeparator() {
    printf("--------------------------------------------------\n");
}

void printEntry(EntryNode *entry) {
    printf("\nTitle: %s", entry->title);
    printf("\nContent: %s\n", entry->content);
}

void addEntry() {
    EntryNode *newEntry = (EntryNode *)malloc(ENTRY_NODE_SIZE);

    printTitle("Add New Entry:");
    printf("Enter Title: ");
    scanf("%s", newEntry->title);
    getchar();

    printf("Enter Content: ");
    fgets(newEntry->content, MAX_ENTRY_LENGTH, stdin);
    newEntry->next = head;
    head = newEntry;

    printTitle("Entry Added Successfully!");
}

void viewEntries() {
    clearScreen();
    printTitle("Diary Entries:");

    if (head == NULL) {
        printTitle("No Entries Found!");
        return;
    }

    current = head;

    while (current != NULL) {
        printSeparator();
        printEntry(current);
        current = current->next;
    }
}

void deleteEntry() {
    char title[MAX_ENTRY_LENGTH];
    EntryNode *prev = NULL, *current = head;

    printTitle("Delete Entry:");
    printf("Enter Title: ");
    scanf("%s", title);
    getchar();

    while (current != NULL && strcmp(current->title, title) != 0) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printTitle("Entry Not Found!");
        return;
    }

    if (prev == NULL) {
        head = current->next;
    } else {
        prev->next = current->next;
    }

    free(current);

    printTitle("Entry Deleted Successfully!");
}

void mainMenu() {
    int choice;

    while (1) {
        clearScreen();
        printTitle("Digital Diary Menu:");
        printSeparator();
        printf("\n1. Add Entry\n2. View Entries\n3. Delete Entry\n4. Exit\n");
        printf("Enter Your Choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                addEntry();
                break;
            case 2:
                viewEntries();
                break;
            case 3:
                deleteEntry();
                break;
            case 4:
                exit(0);
                break;
            default:
                printTitle("Invalid Choice!");
        }
    }
}

int main() {
    mainMenu();
    return 0;
}