//GEMINI-pro DATASET v1.0 Category: Password management ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#define MAX_ENTRIES 100
#define MAX_PASS_LEN 50

typedef struct {
    char website[64];
    char username[64];
    char password[MAX_PASS_LEN];
} PasswordEntry;

static PasswordEntry entries[MAX_ENTRIES];
static int num_entries = 0;

void add_entry(const char *website, const char *username, const char *password) {
    if (num_entries >= MAX_ENTRIES) {
        printf("Error: Cannot add more entries.\n");
        return;
    }

    strcpy(entries[num_entries].website, website);
    strcpy(entries[num_entries].username, username);
    strcpy(entries[num_entries].password, password);
    num_entries++;
}

void print_entries() {
    for (int i = 0; i < num_entries; i++) {
        printf("%s: %s, %s\n", entries[i].website, entries[i].username, entries[i].password);
    }
}

void search_entries(const char *keyword) {
    for (int i = 0; i < num_entries; i++) {
        if (strstr(entries[i].website, keyword) != NULL ||
            strstr(entries[i].username, keyword) != NULL ||
            strstr(entries[i].password, keyword) != NULL) {
            printf("%s: %s, %s\n", entries[i].website, entries[i].username, entries[i].password);
        }
    }
}

int main(int argc, char **argv) {
    if (argc == 5 && strcmp(argv[1], "add") == 0) {
        add_entry(argv[2], argv[3], argv[4]);
    } else if (argc == 2 && strcmp(argv[1], "list") == 0) {
        print_entries();
    } else if (argc == 3 && strcmp(argv[1], "search") == 0) {
        search_entries(argv[2]);
    } else {
        printf("Usage:\n");
        printf(" - add <website> <username> <password>\n");
        printf(" - list\n");
        printf(" - search <keyword>\n");
    }

    return 0;
}