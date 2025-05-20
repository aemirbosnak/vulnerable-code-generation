//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char *title;
    char *body;
    time_t timestamp;
} Entry;

typedef struct {
    Entry *entries;
    int num_entries;
} Diary;

Diary *create_diary() {
    Diary *diary = malloc(sizeof(Diary));
    diary->entries = NULL;
    diary->num_entries = 0;
    return diary;
}

void add_entry(Diary *diary, char *title, char *body) {
    diary->entries = realloc(diary->entries, (diary->num_entries + 1) * sizeof(Entry));
    diary->entries[diary->num_entries].title = strdup(title);
    diary->entries[diary->num_entries].body = strdup(body);
    diary->entries[diary->num_entries].timestamp = time(NULL);
    diary->num_entries++;
}

void print_diary(Diary *diary) {
    for (int i = 0; i < diary->num_entries; i++) {
        printf("%s\n", diary->entries[i].title);
        printf("%s\n", diary->entries[i].body);
        printf("%s\n", ctime(&diary->entries[i].timestamp));
    }
}

void free_diary(Diary *diary) {
    for (int i = 0; i < diary->num_entries; i++) {
        free(diary->entries[i].title);
        free(diary->entries[i].body);
    }
    free(diary->entries);
    free(diary);
}

int main() {
    Diary *diary = create_diary();
    add_entry(diary, "My first entry", "This is my first entry in my digital diary.");
    add_entry(diary, "My second entry", "This is my second entry in my digital diary.");
    print_diary(diary);
    free_diary(diary);
    return 0;
}