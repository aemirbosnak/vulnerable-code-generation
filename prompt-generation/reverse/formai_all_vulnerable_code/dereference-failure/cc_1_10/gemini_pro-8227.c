//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: Cryptic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

struct entry {
    char *title;
    char *text;
    time_t timestamp;
};

struct diary {
    struct entry *entries;
    int num_entries;
    int capacity;
};

struct diary *create_diary()
{
    struct diary *diary = malloc(sizeof(struct diary));
    diary->entries = NULL;
    diary->num_entries = 0;
    diary->capacity = 0;
    return diary;
}

void add_entry(struct diary *diary, char *title, char *text)
{
    if (diary->num_entries >= diary->capacity) {
        diary->capacity *= 2;
        diary->entries = realloc(diary->entries, diary->capacity * sizeof(struct entry));
    }
    diary->entries[diary->num_entries].title = strdup(title);
    diary->entries[diary->num_entries].text = strdup(text);
    diary->entries[diary->num_entries].timestamp = time(NULL);
    diary->num_entries++;
}

void print_diary(struct diary *diary)
{
    for (int i = 0; i < diary->num_entries; i++) {
        printf("%s\n", diary->entries[i].title);
        printf("%s\n", diary->entries[i].text);
        printf("%lld\n", diary->entries[i].timestamp);
        printf("\n");
    }
}

void free_diary(struct diary *diary)
{
    for (int i = 0; i < diary->num_entries; i++) {
        free(diary->entries[i].title);
        free(diary->entries[i].text);
    }
    free(diary->entries);
    free(diary);
}

int main()
{
    struct diary *diary = create_diary();
    add_entry(diary, "My First Entry", "This is my first entry in my digital diary.");
    add_entry(diary, "My Second Entry", "This is my second entry in my digital diary.");
    add_entry(diary, "My Third Entry", "This is my third entry in my digital diary.");
    print_diary(diary);
    free_diary(diary);
    return 0;
}