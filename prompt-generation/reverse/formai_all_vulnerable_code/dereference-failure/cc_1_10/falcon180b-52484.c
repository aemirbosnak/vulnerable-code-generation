//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_ENTRIES 500
#define MAX_ENTRY_LENGTH 500

typedef struct {
    char date[11];
    char entry[MAX_ENTRY_LENGTH];
} entry_t;

void print_entries(entry_t *entries, int num_entries);

int main() {
    entry_t *entries = NULL;
    int num_entries = 0;
    char input[MAX_ENTRY_LENGTH];

    printf("Welcome to your digital diary!\n\n");

    while (1) {
        printf("Enter a new entry:\n");
        fgets(input, MAX_ENTRY_LENGTH, stdin);

        if (strlen(input) == 0) {
            continue;
        }

        time_t now = time(NULL);
        struct tm *tm = localtime(&now);
        strftime(entries[num_entries].date, 11, "%Y-%m-%d %H:%M:%S", tm);
        strcpy(entries[num_entries].entry, input);

        num_entries++;
        if (num_entries == MAX_ENTRIES) {
            printf("You have reached the maximum number of entries.\n");
            break;
        }
    }

    print_entries(entries, num_entries);

    free(entries);
    return 0;
}

void print_entries(entry_t *entries, int num_entries) {
    printf("\nEntries:\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%s - %s\n", entries[i].date, entries[i].entry);
    }
}