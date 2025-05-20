//LLAMA2-13B DATASET v1.0 Category: Digital Diary ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define DIARY_SIZE 1000
#define ENTRY_SIZE 256

typedef struct {
    char date[20];
    char entry[ENTRY_SIZE];
} diary_entry_t;

typedef struct {
    diary_entry_t entries[DIARY_SIZE];
    int curr_entry;
} diary_t;

void init_diary(diary_t *d) {
    memset(d, 0, sizeof(diary_t));
}

void add_entry(diary_t *d, char *date, char *entry) {
    if (d->curr_entry >= DIARY_SIZE) {
        printf("Diary is full! Please delete some entries first.\n");
        return;
    }
    strcpy(d->entries[d->curr_entry].date, date);
    strcpy(d->entries[d->curr_entry].entry, entry);
    d->curr_entry++;
}

void view_entry(diary_t *d, int index) {
    if (index < 0 || index >= DIARY_SIZE) {
        printf("Invalid entry index.\n");
        return;
    }
    printf("Entry for %s\n", d->entries[index].date);
    printf("%s\n", d->entries[index].entry);
}

int main() {
    diary_t *d = malloc(sizeof(diary_t));
    init_diary(d);

    char date[20];
    char entry[ENTRY_SIZE];

    // Example entries
    add_entry(d, "2023-02-10", "Went to the park and saw a squirrel.");
    add_entry(d, "2023-02-11", "Had a delicious breakfast with my friend.");
    add_entry(d, "2023-02-12", "Learned a new programming language.");

    // View entries
    view_entry(d, 0);
    view_entry(d, 1);
    view_entry(d, 2);

    return 0;
}