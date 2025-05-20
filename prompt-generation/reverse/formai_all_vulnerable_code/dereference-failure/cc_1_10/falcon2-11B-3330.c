//Falcon2-11B DATASET v1.0 Category: Digital Diary ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DIARY_ENTRY 100
#define MAX_ENTRY_LENGTH 50

typedef struct diary_entry {
    char entry[MAX_ENTRY_LENGTH];
    struct diary_entry *next;
} diary_entry_t;

typedef struct diary {
    diary_entry_t *head;
    int num_entries;
} diary_t;

void diary_init(diary_t *diary) {
    diary->num_entries = 0;
    diary->head = NULL;
}

void diary_add_entry(diary_t *diary, char *entry) {
    diary_entry_t *new_entry = malloc(sizeof(diary_entry_t));
    if (new_entry == NULL) {
        printf("Memory allocation error.\n");
        return;
    }
    strncpy(new_entry->entry, entry, MAX_ENTRY_LENGTH - 1);
    new_entry->next = NULL;

    diary->head = new_entry;
    diary->num_entries++;
}

void diary_print(diary_t *diary) {
    diary_entry_t *current = diary->head;
    while (current!= NULL) {
        printf("%s\n", current->entry);
        current = current->next;
    }
}

int main() {
    diary_t diary;
    diary_init(&diary);

    diary_add_entry(&diary, "Today was a good day.");
    diary_add_entry(&diary, "I went for a run and felt great.");
    diary_add_entry(&diary, "I had a delicious dinner with my family.");

    diary_print(&diary);

    return 0;
}