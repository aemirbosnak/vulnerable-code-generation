//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct diary_entry {
    char *title;
    char *body;
    int date;
    int time;
};

struct digital_diary {
    struct diary_entry *entries;
    int num_entries;
    int max_entries;
};

struct digital_diary *create_digital_diary() {
    struct digital_diary *diary = malloc(sizeof(struct digital_diary));
    if (diary == NULL) {
        return NULL;
    }

    diary->entries = NULL;
    diary->num_entries = 0;
    diary->max_entries = 0;

    return diary;
}

void destroy_digital_diary(struct digital_diary *diary) {
    if (diary == NULL) {
        return;
    }

    for (int i = 0; i < diary->num_entries; i++) {
        free(diary->entries[i].title);
        free(diary->entries[i].body);
    }

    free(diary->entries);
    free(diary);
}

int add_entry(struct digital_diary *diary, char *title, char *body, int date, int time) {
    if (diary == NULL || title == NULL || body == NULL) {
        return -1;
    }

    if (diary->num_entries == diary->max_entries) {
        int new_max_entries = diary->max_entries + 10;
        struct diary_entry *new_entries = realloc(diary->entries, new_max_entries * sizeof(struct diary_entry));
        if (new_entries == NULL) {
            return -1;
        }

        diary->entries = new_entries;
        diary->max_entries = new_max_entries;
    }

    int index = diary->num_entries++;
    diary->entries[index].title = strdup(title);
    diary->entries[index].body = strdup(body);
    diary->entries[index].date = date;
    diary->entries[index].time = time;

    return 0;
}

int edit_entry(struct digital_diary *diary, int index, char *title, char *body, int date, int time) {
    if (diary == NULL || index < 0 || index >= diary->num_entries) {
        return -1;
    }

    free(diary->entries[index].title);
    free(diary->entries[index].body);

    diary->entries[index].title = strdup(title);
    diary->entries[index].body = strdup(body);
    diary->entries[index].date = date;
    diary->entries[index].time = time;

    return 0;
}

int delete_entry(struct digital_diary *diary, int index) {
    if (diary == NULL || index < 0 || index >= diary->num_entries) {
        return -1;
    }

    free(diary->entries[index].title);
    free(diary->entries[index].body);

    for (int i = index + 1; i < diary->num_entries; i++) {
        diary->entries[i - 1] = diary->entries[i];
    }

    diary->num_entries--;

    return 0;
}

int get_entry_count(struct digital_diary *diary) {
    if (diary == NULL) {
        return -1;
    }

    return diary->num_entries;
}

struct diary_entry *get_entry(struct digital_diary *diary, int index) {
    if (diary == NULL || index < 0 || index >= diary->num_entries) {
        return NULL;
    }

    return &diary->entries[index];
}

int main() {
    struct digital_diary *diary = create_digital_diary();

    add_entry(diary, "First Entry", "This is my first entry.", 20230308, 1030);
    add_entry(diary, "Second Entry", "This is my second entry.", 20230309, 1145);
    add_entry(diary, "Third Entry", "This is my third entry.", 20230310, 1200);

    int num_entries = get_entry_count(diary);

    for (int i = 0; i < num_entries; i++) {
        struct diary_entry *entry = get_entry(diary, i);

        printf("Entry %d:\n", i + 1);
        printf("Title: %s\n", entry->title);
        printf("Body: %s\n", entry->body);
        printf("Date: %d\n", entry->date);
        printf("Time: %d\n", entry->time);
        printf("\n");
    }

    destroy_digital_diary(diary);

    return 0;
}