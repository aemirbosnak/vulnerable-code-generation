//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char *text;
    time_t timestamp;
} Entry;

Entry *entries;
int num_entries = 0;

void add_entry(const char *text) {
    Entry *new_entry = malloc(sizeof(Entry));
    new_entry->text = strdup(text);
    new_entry->timestamp = time(NULL);
    entries = realloc(entries, (num_entries + 1) * sizeof(Entry));
    entries[num_entries++] = *new_entry;
    free(new_entry);
}

void print_entries() {
    for (int i = 0; i < num_entries; i++) {
        printf("%s\n", entries[i].text);
        printf("Timestamp: %s\n", ctime(&entries[i].timestamp));
        printf("-----------------------------------\n");
    }
}

void save_entries() {
    FILE *fp = fopen("diary.txt", "w");
    for (int i = 0; i < num_entries; i++) {
        fprintf(fp, "%s\n", entries[i].text);
        fprintf(fp, "%ld\n", entries[i].timestamp);
    }
    fclose(fp);
}

void load_entries() {
    FILE *fp = fopen("diary.txt", "r");
    if (fp == NULL) {
        return;
    }

    char buf[1024];

    while (fgets(buf, sizeof(buf), fp)) {
        Entry *new_entry = malloc(sizeof(Entry));
        new_entry->text = strdup(buf);
        fgets(buf, sizeof(buf), fp);
        new_entry->timestamp = atol(buf);
        entries = realloc(entries, (num_entries + 1) * sizeof(Entry));
        entries[num_entries++] = *new_entry;
        free(new_entry);
    }

    fclose(fp);
}

int main() {
    load_entries();
    add_entry("This is my first entry.");
    add_entry("This is my second entry.");
    add_entry("This is my third entry.");
    print_entries();
    save_entries();
    return 0;
}