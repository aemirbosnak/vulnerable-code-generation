//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ENTRIES 1000
#define MAX_NAME_LENGTH 50
#define MAX_NUMBER_LENGTH 20

struct entry {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];
};

void add_entry(struct entry *book[], int count) {
    printf("Enter name: ");
    scanf("%s", book[count]->name);
    printf("Enter number: ");
    scanf("%s", book[count]->number);
    book[count]->name[strcspn(book[count]->name, "\n")] = '\0';
    book[count]->number[strcspn(book[count]->number, "\n")] = '\0';
}

void search_entry(struct entry *book[], int count) {
    char name[MAX_NAME_LENGTH];
    printf("Enter name to search: ");
    scanf("%s", name);
    for (int i = 0; i < count; i++) {
        if (strcmp(book[i]->name, name) == 0) {
            printf("Name: %s\nNumber: %s\n", book[i]->name, book[i]->number);
            return;
        }
    }
    printf("Entry not found.\n");
}

void delete_entry(struct entry *book[], int count) {
    char name[MAX_NAME_LENGTH];
    printf("Enter name to delete: ");
    scanf("%s", name);
    for (int i = 0; i < count; i++) {
        if (strcmp(book[i]->name, name) == 0) {
            for (int j = i; j < count - 1; j++) {
                strcpy(book[j]->name, book[j + 1]->name);
                strcpy(book[j]->number, book[j + 1]->number);
            }
            count--;
            break;
        }
    }
}

void print_entries(struct entry *book[], int count) {
    for (int i = 0; i < count; i++) {
        printf("Name: %s\nNumber: %s\n\n", book[i]->name, book[i]->number);
    }
}

int main() {
    struct entry *book[MAX_ENTRIES];
    int count = 0;

    printf("Enter number of entries to add: ");
    scanf("%d", &count);

    for (int i = 0; i < count; i++) {
        add_entry(book, i);
    }

    while (1) {
        printf("\nPhone Book Menu:\n");
        printf("1. Add entry\n2. Search entry\n3. Delete entry\n4. Print entries\n5. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_entry(book, count);
                break;
            case 2:
                printf("Enter name to search: ");
                char name[MAX_NAME_LENGTH];
                scanf("%s", name);
                search_entry(book, count);
                break;
            case 3:
                printf("Enter name to delete: ");
                char name_del[MAX_NAME_LENGTH];
                scanf("%s", name_del);
                delete_entry(book, count);
                break;
            case 4:
                print_entries(book, count);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}