//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char *title;
    char *content;
    time_t timestamp;
} Entry;

typedef struct {
    int size;
    Entry *entries;
} Diary;

Diary *create_diary() {
    Diary *diary = malloc(sizeof(Diary));
    diary->size = 0;
    diary->entries = NULL;
    return diary;
}

void destroy_diary(Diary *diary) {
    for (int i = 0; i < diary->size; i++) {
        free(diary->entries[i].title);
        free(diary->entries[i].content);
    }
    free(diary->entries);
    free(diary);
}

void add_entry(Diary *diary, char *title, char *content) {
    diary->entries = realloc(diary->entries, (diary->size + 1) * sizeof(Entry));
    diary->entries[diary->size].title = strdup(title);
    diary->entries[diary->size].content = strdup(content);
    diary->entries[diary->size].timestamp = time(NULL);
    diary->size++;
}

void print_entry(Entry entry) {
    printf("Title: %s\n", entry.title);
    printf("Content: %s\n", entry.content);
    printf("Timestamp: %s\n", ctime(&entry.timestamp));
}

void print_diary(Diary *diary) {
    for (int i = 0; i < diary->size; i++) {
        print_entry(diary->entries[i]);
        printf("\n");
    }
}

int main() {
    Diary *diary = create_diary();

    add_entry(diary, "My First Entry", "This is my first entry in my digital diary.");
    add_entry(diary, "My Second Entry", "This is my second entry in my digital diary.");
    add_entry(diary, "My Third Entry", "This is my third entry in my digital diary.");

    print_diary(diary);

    destroy_diary(diary);

    return 0;
}