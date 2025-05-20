//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 500

struct entry {
    char date[20];
    char time[20];
    char content[MAX_ENTRY_LENGTH];
};

void add_entry(struct entry* entries, int num_entries, char* content) {
    time_t now = time(NULL);
    struct tm* tm = localtime(&now);

    strftime(entries[num_entries].date, 20, "%Y-%m-%d", tm);
    strftime(entries[num_entries].time, 20, "%H:%M:%S", tm);

    strncpy(entries[num_entries].content, content, MAX_ENTRY_LENGTH - 1);
    entries[num_entries].content[MAX_ENTRY_LENGTH - 1] = '\0';

    num_entries++;
}

void print_entries(struct entry* entries, int num_entries) {
    for (int i = 0; i < num_entries; i++) {
        printf("%s %s: %s\n", entries[i].date, entries[i].time, entries[i].content);
    }
}

int main() {
    int num_entries = 0;
    struct entry entries[MAX_ENTRIES];

    char* content = malloc(MAX_ENTRY_LENGTH);

    while (1) {
        printf("Enter your diary entry (or type 'exit' to quit):\n");
        fgets(content, MAX_ENTRY_LENGTH, stdin);

        if (strcmp(content, "exit") == 0) {
            break;
        }

        add_entry(entries, num_entries, content);
        num_entries++;
    }

    print_entries(entries, num_entries);

    return 0;
}