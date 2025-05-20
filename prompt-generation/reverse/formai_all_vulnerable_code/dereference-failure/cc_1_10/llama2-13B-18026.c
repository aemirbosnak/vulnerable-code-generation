//LLAMA2-13B DATASET v1.0 Category: Digital Diary ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define DIARY_SIZE 1000
#define ENTRY_SIZE 256

typedef struct {
    char date[16];
    char entry[ENTRY_SIZE];
} diary_entry_t;

typedef struct {
    diary_entry_t entries[DIARY_SIZE];
    int curr_entry;
} digital_diary_t;

void init_digital_diary(digital_diary_t *dd) {
    memset(dd, 0, sizeof(digital_diary_t));
    srand(time(NULL));
}

void add_entry(digital_diary_t *dd, const char *date, const char *entry) {
    int i = dd->curr_entry % DIARY_SIZE;
    strcpy(dd->entries[i].date, date);
    strcpy(dd->entries[i].entry, entry);
    dd->curr_entry++;
}

void view_entry(digital_diary_t *dd, int index) {
    printf("--- %s ---\n", dd->entries[index].date);
    printf("%s\n", dd->entries[index].entry);
}

int main() {
    digital_diary_t *dd = malloc(sizeof(digital_diary_t));
    init_digital_diary(dd);

    char date[16];
    char entry[ENTRY_SIZE];

    // Add some entries
    add_entry(dd, "January 1st", "New Year's Day");
    add_entry(dd, "January 2nd", "First day of work");
    add_entry(dd, "January 3rd", "First coffee break");

    // View an entry
    view_entry(dd, 1);

    // Randomly shuffle the entries
    for (int i = 0; i < DIARY_SIZE; i++) {
        int j = rand() % DIARY_SIZE;
        diary_entry_t temp = dd->entries[i];
        dd->entries[i] = dd->entries[j];
        dd->entries[j] = temp;
    }

    // View another entry
    view_entry(dd, rand() % DIARY_SIZE);

    return 0;
}