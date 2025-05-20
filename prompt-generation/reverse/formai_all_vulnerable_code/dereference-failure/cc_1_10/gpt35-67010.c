//FormAI DATASET v1.0 Category: Mailing list manager ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50
#define MAX_EMAIL_LEN 100
#define MAX_ENTRIES 100

typedef struct {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
} Entry;

Entry *list[MAX_ENTRIES];

int num_entries = 0;

void print_menu() {
    printf("Menu:\n");
    printf("1. Add entry\n");
    printf("2. Remove entry\n");
    printf("3. Print all entries\n");
    printf("4. Quit\n");
    printf("Enter your choice (1-4): ");
}

int get_choice() {
    int choice;
    scanf("%d", &choice);
    return choice;
}

void add_entry() {
    if (num_entries >= MAX_ENTRIES) {
        printf("Error: list full\n");
        return;
    }

    Entry *entry = malloc(sizeof(Entry));
    printf("Enter name: ");
    char name[MAX_NAME_LEN];
    scanf("%s", name);
    strncpy(entry->name, name, MAX_NAME_LEN);
    printf("Enter email: ");
    char email[MAX_EMAIL_LEN];
    scanf("%s", email);
    strncpy(entry->email, email, MAX_EMAIL_LEN);
    list[num_entries] = entry;
    num_entries++;
}

void remove_entry() {
    printf("Enter name to remove: ");
    char name[MAX_NAME_LEN];
    scanf("%s", name);
    int i;
    for (i = 0; i < num_entries; i++) {
        if (strncmp(list[i]->name, name, MAX_NAME_LEN) == 0) {
            free(list[i]);
            int j;
            for (j = i; j < num_entries - 1; j++) {
                list[j] = list[j+1];
            }
            num_entries--;
            printf("Entry removed\n");
            return;
        }
    }
    printf("Entry not found\n");
}

void print_all_entries() {
    int i;
    for (i = 0; i < num_entries; i++) {
        printf("%s\t%s\n", list[i]->name, list[i]->email);
    }
}

int main() {
    printf("Mailing list manager\n");
    printf("====================\n");

    while (1) {
        print_menu();
        int choice = get_choice();
        switch (choice) {
            case 1:
                add_entry();
                break;
            case 2:
                remove_entry();
                break;
            case 3:
                print_all_entries();
                break;
            case 4:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}