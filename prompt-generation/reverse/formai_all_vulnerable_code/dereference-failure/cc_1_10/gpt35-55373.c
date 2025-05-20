//FormAI DATASET v1.0 Category: Phone Book ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 20
#define MAX_NUM_LEN 10
#define MAX_ENTRIES 100

struct entry {
    char name[MAX_NAME_LEN];
    char number[MAX_NUM_LEN];
};

struct phone_book {
    struct entry entries[MAX_ENTRIES];
    int num_entries;
};

void print_prompt();
char* get_input();
int add_entry(struct phone_book *book, char *name, char *number);
int delete_entry(struct phone_book *book, char *name);
void find_number(struct phone_book *book, char *name);
void print_phone_book(struct phone_book *book);

int main() {
    struct phone_book book;
    book.num_entries = 0;

    while (1) {
        print_prompt();
        char *input = get_input();

        if (strcmp(input, "quit") == 0 || strcmp(input, "exit") == 0) {
            break;
        } else if (strcmp(input, "show") == 0) {
            print_phone_book(&book);
        } else if (strncmp(input, "add", 3) == 0) {
            char *name = input + 4;
            char *number = strchr(name, ' ') + 1;
            *strchr(name, ' ') = '\0';
            if (add_entry(&book, name, number)) {
                printf("Added entry for %s\n", name);
            } else {
                printf("Failed to add entry for %s\n", name);
            }
        } else if (strncmp(input, "delete", 6) == 0) {
            char *name = input + 7;
            if (delete_entry(&book, name)) {
                printf("Deleted entry for %s\n", name);
            } else {
                printf("Failed to delete entry for %s\n", name);
            }
        } else if (strncmp(input, "find", 4) == 0) {
            char *name = input + 5;
            find_number(&book, name);
        } else {
            printf("Invalid command\n");
        }

        free(input);
    }

    return 0;
}

void print_prompt() {
    printf("\nCommand Options:\n"
           "  add <name> <number>: Add an entry to the phone book\n"
           "  delete <name>: Delete an entry from the phone book\n"
           "  find <name>: Find a phone number by name\n"
           "  show: Show the entire phone book\n"
           "  quit / exit: Quit the program\n"
           "Enter a command: ");
}

char* get_input() {
    char *input = malloc(sizeof(char) * 100);
    fgets(input, 100, stdin);
    input[strcspn(input, "\n")] = '\0'; // Remove trailing newline
    return input;
}

int add_entry(struct phone_book *book, char *name, char *number) {
    if (book->num_entries >= MAX_ENTRIES) {
        return 0;
    }

    for (int i = 0; i < book->num_entries; i++) {
        if (strcmp(book->entries[i].name, name) == 0) {
            return 0;
        }
    }

    strncpy(book->entries[book->num_entries].name, name, MAX_NAME_LEN - 1);
    strncpy(book->entries[book->num_entries].number, number, MAX_NUM_LEN - 1);
    book->entries[book->num_entries].name[MAX_NAME_LEN - 1] = '\0';
    book->entries[book->num_entries].number[MAX_NUM_LEN - 1] = '\0';
    book->num_entries++;

    return 1;
}

int delete_entry(struct phone_book *book, char *name) {
    for (int i = 0; i < book->num_entries; i++) {
        if (strcmp(book->entries[i].name, name) == 0) {
            for (int j = i; j < book->num_entries - 1; j++) {
                strncpy(book->entries[j].name, book->entries[j + 1].name, MAX_NAME_LEN);
                strncpy(book->entries[j].number, book->entries[j + 1].number, MAX_NUM_LEN);
            }
            book->num_entries--;
            return 1;
        }
    }

    return 0;
}

void find_number(struct phone_book *book, char *name) {
    for (int i = 0; i < book->num_entries; i++) {
        if (strcmp(book->entries[i].name, name) == 0) {
            printf("%s's number is %s\n", name, book->entries[i].number);
            return;
        }
    }

    printf("No entry found for %s\n", name);
}

void print_phone_book(struct phone_book *book) {
    if (book->num_entries == 0) {
        printf("Phone book is empty\n");
        return;
    }

    printf("\nName\t\tNumber\n");
    printf("----------------------------\n");
    for (int i = 0; i < book->num_entries; i++) {
        printf("%s\t\t%s\n", book->entries[i].name, book->entries[i].number);
    }
}