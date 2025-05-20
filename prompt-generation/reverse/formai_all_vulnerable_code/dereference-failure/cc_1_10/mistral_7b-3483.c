//MISTRAL-7B DATASET v1.0 Category: Digital Diary ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_ENTRY_LENGTH 256

typedef struct DiaryEntry {
    char title[MAX_ENTRY_LENGTH];
    char content[MAX_ENTRY_LENGTH];
    struct DiaryEntry *next;
} DiaryEntry;

DiaryEntry *diary = NULL;

void print_menu() {
    printf("\nDigital Diary\n");
    printf("1. Add entry\n");
    printf("2. View entries\n");
    printf("3. Delete entry\n");
    printf("4. Quit\n");
}

void add_entry(const char *title, const char *content) {
    DiaryEntry *new_entry = (DiaryEntry *)malloc(sizeof(DiaryEntry));
    strcpy(new_entry->title, title);
    strcpy(new_entry->content, content);
    new_entry->next = diary;
    diary = new_entry;
}

void view_entries() {
    DiaryEntry *current = diary;
    while (current != NULL) {
        printf("\nTitle: %s\nContent:\n%s", current->title, current->content);
        current = current->next;
    }
}

void delete_entry(const char *title) {
    DiaryEntry *current = diary;
    DiaryEntry *previous = NULL;
    while (current != NULL && strcmp(current->title, title) != 0) {
        previous = current;
        current = current->next;
    }
    if (current == NULL) {
        printf("Entry not found.\n");
        return;
    }
    if (previous == NULL) {
        diary = current->next;
    } else {
        previous->next = current->next;
    }
    free(current);
}

int main() {
    char command[10], title[MAX_ENTRY_LENGTH], content[MAX_ENTRY_LENGTH];
    bool quit = false;

    while (!quit) {
        print_menu();
        scanf("%s", command);
        switch (*command) {
            case '1':
                printf("Enter title: ");
                scanf("%s", title);
                printf("Enter content: ");
                scanf("%[^'\n']s", content);
                add_entry(title, content);
                break;
            case '2':
                view_entries();
                break;
            case '3':
                printf("Enter title of entry to delete: ");
                scanf("%s", title);
                delete_entry(title);
                break;
            case '4':
                quit = true;
                break;
            default:
                printf("Invalid command.\n");
        }
    }

    return 0;
}