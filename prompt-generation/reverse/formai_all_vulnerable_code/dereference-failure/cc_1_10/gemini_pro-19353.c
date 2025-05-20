//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct diary_entry {
    char *date;
    char *title;
    char *body;
};

struct digital_diary {
    int num_entries;
    struct diary_entry *entries;
};

struct digital_diary *create_diary() {
    struct digital_diary *diary = malloc(sizeof(struct digital_diary));
    diary->num_entries = 0;
    diary->entries = NULL;
    return diary;
}

void add_entry(struct digital_diary *diary, char *date, char *title, char *body) {
    diary->num_entries++;
    diary->entries = realloc(diary->entries, sizeof(struct diary_entry) * diary->num_entries);
    diary->entries[diary->num_entries - 1].date = strdup(date);
    diary->entries[diary->num_entries - 1].title = strdup(title);
    diary->entries[diary->num_entries - 1].body = strdup(body);
}

void print_diary(struct digital_diary *diary) {
    for (int i = 0; i < diary->num_entries; i++) {
        printf("%s: %s\n", diary->entries[i].date, diary->entries[i].title);
        printf("%s\n\n", diary->entries[i].body);
    }
}

void free_diary(struct digital_diary *diary) {
    for (int i = 0; i < diary->num_entries; i++) {
        free(diary->entries[i].date);
        free(diary->entries[i].title);
        free(diary->entries[i].body);
    }
    free(diary->entries);
    free(diary);
}

int main() {
    struct digital_diary *diary = create_diary();

    add_entry(diary, "2023-02-23", "First entry", "This is my first entry in my digital diary. I'm so excited to start using it!");
    add_entry(diary, "2023-02-24", "Second entry", "I'm starting to get the hang of this. I'm really enjoying being able to track my thoughts and feelings in one place.");
    add_entry(diary, "2023-02-25", "Third entry", "I'm starting to see how this can be a valuable tool for self-improvement. I'm able to identify patterns in my behavior and thoughts, which is helping me to make positive changes.");

    print_diary(diary);

    free_diary(diary);

    return 0;
}