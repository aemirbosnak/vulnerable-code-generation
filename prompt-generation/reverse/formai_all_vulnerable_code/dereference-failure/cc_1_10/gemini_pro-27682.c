//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char *title;
    char *content;
    time_t timestamp;
} DiaryEntry;

DiaryEntry *entries = NULL;
int num_entries = 0;

void init_diary() {
    entries = malloc(sizeof(DiaryEntry) * 10);
    num_entries = 0;
}

void add_entry(char *title, char *content) {
    if (num_entries >= 10) {
        entries = realloc(entries, sizeof(DiaryEntry) * (num_entries + 10));
    }
    entries[num_entries].title = strdup(title);
    entries[num_entries].content = strdup(content);
    entries[num_entries].timestamp = time(NULL);
    num_entries++;
}

void print_entry(DiaryEntry *entry) {
    printf("Title: %s\n", entry->title);
    printf("Content: %s\n", entry->content);
    printf("Timestamp: %s\n", ctime(&entry->timestamp));
}

void print_all_entries() {
    for (int i = 0; i < num_entries; i++) {
        print_entry(&entries[i]);
        printf("\n");
    }
}

void free_diary() {
    for (int i = 0; i < num_entries; i++) {
        free(entries[i].title);
        free(entries[i].content);
    }
    free(entries);
}

int main() {
    init_diary();
    add_entry("My First Entry", "This is my first entry in my digital diary.");
    add_entry("My Second Entry", "This is my second entry in my digital diary.");
    print_all_entries();
    free_diary();
    return 0;
}