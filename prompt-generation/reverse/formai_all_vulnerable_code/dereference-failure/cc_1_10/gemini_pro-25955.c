//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LEN 1024

typedef struct {
    char *text;
    time_t timestamp;
} Entry;

Entry entries[MAX_ENTRIES];
int num_entries = 0;

void add_entry(char *text) {
    if (num_entries == MAX_ENTRIES) {
        fprintf(stderr, "Error: diary is full.\n");
        return;
    }

    entries[num_entries].text = strdup(text);
    entries[num_entries].timestamp = time(NULL);
    num_entries++;
}

void print_entries() {
    for (int i = 0; i < num_entries; i++) {
        printf("%s\n", entries[i].text);
    }
}

int main() {
    char input[MAX_ENTRY_LEN];

    while (1) {
        printf("> ");
        fgets(input, MAX_ENTRY_LEN, stdin);

        if (strcmp(input, "quit\n") == 0) {
            break;
        } else if (strcmp(input, "print\n") == 0) {
            print_entries();
        } else {
            add_entry(input);
        }
    }

    return 0;
}