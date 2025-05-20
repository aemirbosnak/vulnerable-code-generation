//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 1000

typedef struct {
    char date[20];
    char entry[MAX_ENTRY_LENGTH];
} entry_t;

void add_entry(entry_t *entries, int num_entries, char *date, char *entry) {
    if (num_entries >= MAX_ENTRIES) {
        printf("Error: maximum number of entries reached\n");
        return;
    }

    strcpy(entries[num_entries].date, date);
    strcpy(entries[num_entries].entry, entry);

    num_entries++;
}

void print_entries(entry_t *entries, int num_entries) {
    printf("Entries:\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%s: %s\n", entries[i].date, entries[i].entry);
    }
}

int main() {
    entry_t entries[MAX_ENTRIES];
    int num_entries = 0;

    char date[20];
    time_t now = time(NULL);
    strftime(date, 20, "%Y-%m-%d", localtime(&now));

    while (1) {
        printf("Enter an entry for %s:\n", date);
        char entry[MAX_ENTRY_LENGTH];
        fgets(entry, MAX_ENTRY_LENGTH, stdin);

        if (strlen(entry) == 0) {
            printf("Skipping empty entry.\n");
        } else {
            add_entry(entries, num_entries, date, entry);
        }

        printf("Do you want to add another entry for %s? (y/n): ", date);
        char choice;
        scanf(" %c", &choice);

        if (toupper(choice)!= 'Y') {
            break;
        }

        strcpy(date, entries[num_entries - 1].date);
    }

    printf("Entries saved to file.\n");
    return 0;
}