//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

struct entry {
    char *text;
    int day;
    int month;
    int year;
};

struct diary {
    struct entry *entries;
    int num_entries;
};

struct diary *create_diary() {
    struct diary *diary = malloc(sizeof(struct diary));
    if (!diary) {
        return NULL;
    }
    diary->entries = NULL;
    diary->num_entries = 0;
    return diary;
}

void free_diary(struct diary *diary) {
    for (int i = 0; i < diary->num_entries; i++) {
        free(diary->entries[i].text);
    }
    free(diary->entries);
    free(diary);
}

int add_entry(struct diary *diary, char *text, int day, int month, int year) {
    struct entry *new_entry = malloc(sizeof(struct entry));
    if (!new_entry) {
        return -1;
    }
    new_entry->text = strdup(text);
    new_entry->day = day;
    new_entry->month = month;
    new_entry->year = year;
    diary->entries = realloc(diary->entries, (diary->num_entries + 1) * sizeof(struct entry));
    if (!diary->entries) {
        free(new_entry);
        return -1;
    }
    diary->entries[diary->num_entries] = *new_entry;
    diary->num_entries++;
    free(new_entry);
    return 0;
}

void print_entry(struct entry *entry) {
    printf("%s\n", entry->text);
}

void print_diary(struct diary *diary) {
    for (int i = 0; i < diary->num_entries; i++) {
        print_entry(&diary->entries[i]);
    }
}

int main() {
    struct diary *diary = create_diary();
    add_entry(diary, "This is my first entry.", 1, 1, 2023);
    add_entry(diary, "This is my second entry.", 2, 1, 2023);
    add_entry(diary, "This is my third entry.", 3, 1, 2023);
    print_diary(diary);
    free_diary(diary);
    return 0;
}