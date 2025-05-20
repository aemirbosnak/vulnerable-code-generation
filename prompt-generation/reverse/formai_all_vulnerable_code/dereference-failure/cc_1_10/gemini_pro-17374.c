//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct diary_entry {
    char *date;
    char *title;
    char *body;
} diary_entry;

typedef struct digital_diary {
    int num_entries;
    diary_entry *entries;
} digital_diary;

digital_diary *create_digital_diary() {
    digital_diary *new_diary = malloc(sizeof(digital_diary));
    new_diary->num_entries = 0;
    new_diary->entries = NULL;
    return new_diary;
}

void add_entry_to_diary(digital_diary *diary, diary_entry *entry) {
    diary->entries = realloc(diary->entries, (diary->num_entries + 1) * sizeof(diary_entry));
    diary->entries[diary->num_entries] = *entry;
    diary->num_entries++;
}

void print_diary(digital_diary *diary) {
    for (int i = 0; i < diary->num_entries; i++) {
        printf("Entry %d:\n", i + 1);
        printf("Date: %s\n", diary->entries[i].date);
        printf("Title: %s\n", diary->entries[i].title);
        printf("Body: %s\n\n", diary->entries[i].body);
    }
}

void free_diary(digital_diary *diary) {
    for (int i = 0; i < diary->num_entries; i++) {
        free(diary->entries[i].date);
        free(diary->entries[i].title);
        free(diary->entries[i].body);
    }
    free(diary->entries);
    free(diary);
}

int main() {
    digital_diary *my_diary = create_digital_diary();

    diary_entry entry1 = {
        .date = "2023-02-14",
        .title = "Valentine's Day",
        .body = "Today I went on a date with my crush and it was amazing! We went to the movies and had dinner at a fancy restaurant. I had such a good time and I can't wait to see them again."
    };

    diary_entry entry2 = {
        .date = "2023-03-08",
        .title = "International Women's Day",
        .body = "Today I celebrated International Women's Day by attending a rally and listening to some inspiring speeches. I'm so grateful for all the women in my life who have supported me and made me who I am today."
    };

    add_entry_to_diary(my_diary, &entry1);
    add_entry_to_diary(my_diary, &entry2);

    print_diary(my_diary);

    free_diary(my_diary);

    return 0;
}