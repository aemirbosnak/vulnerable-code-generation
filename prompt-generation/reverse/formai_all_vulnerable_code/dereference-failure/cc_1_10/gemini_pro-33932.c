//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: Linus Torvalds
// Linus-style Digital Diary

// I'm too busy fixing kernel bugs to write proper comments.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Entry structure
struct entry {
    time_t timestamp;
    char *text;
};

// Diary structure
struct diary {
    struct entry *entries;
    int num_entries;
};

// Create a new diary
struct diary *diary_create()
{
    struct diary *diary = malloc(sizeof(struct diary));
    if (!diary)
        return NULL;

    diary->entries = NULL;
    diary->num_entries = 0;

    return diary;
}

// Destroy a diary
void diary_destroy(struct diary *diary)
{
    if (!diary)
        return;

    for (int i = 0; i < diary->num_entries; i++)
        free(diary->entries[i].text);
    free(diary->entries);
    free(diary);
}

// Add a new entry to the diary
int diary_add_entry(struct diary *diary, const char *text)
{
    if (!diary || !text)
        return -1;

    struct entry *new_entry = malloc(sizeof(struct entry));
    if (!new_entry)
        return -1;

    new_entry->timestamp = time(NULL);
    new_entry->text = strdup(text);

    diary->entries = realloc(diary->entries, (diary->num_entries + 1) * sizeof(struct entry));
    if (!diary->entries) {
        free(new_entry);
        return -1;
    }

    diary->entries[diary->num_entries++] = *new_entry;
    free(new_entry);

    return 0;
}

// Print the diary
void diary_print(struct diary *diary)
{
    if (!diary)
        return;

    for (int i = 0; i < diary->num_entries; i++)
        printf("%s: %s\n", ctime(&diary->entries[i].timestamp), diary->entries[i].text);
}

// Main function
int main()
{
    struct diary *diary = diary_create();
    if (!diary) {
        printf("Failed to create diary\n");
        return 1;
    }

    diary_add_entry(diary, "Today I fixed a bug in the kernel");
    diary_add_entry(diary, "I'm so smart");
    diary_add_entry(diary, "I should get a raise");

    diary_print(diary);

    diary_destroy(diary);

    return 0;
}