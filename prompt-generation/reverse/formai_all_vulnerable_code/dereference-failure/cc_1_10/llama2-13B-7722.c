//LLAMA2-13B DATASET v1.0 Category: Digital Diary ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define ENTRY_SIZE 100

struct entry {
    char date[20];
    char topic[50];
    char text[100];
};

typedef struct entry entry;

entry *entries;
int num_entries;

void init_digital_diary() {
    entries = malloc(MAX_ENTRIES * sizeof(entry));
    num_entries = 0;
}

void add_entry(const char *date, const char *topic, const char *text) {
    entry *new_entry = malloc(sizeof(entry));
    strcpy(new_entry->date, date);
    strcpy(new_entry->topic, topic);
    strcpy(new_entry->text, text);
    if (num_entries == MAX_ENTRIES) {
        printf("Warning: Digital diary is full. Oldest entries will be overwritten.\n");
    }
    entries[num_entries] = *new_entry;
    num_entries++;
}

void display_entries() {
    printf("Digital Diary\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%s - %s\n", entries[i].date, entries[i].topic);
        printf("    %s\n", entries[i].text);
    }
}

int main() {
    init_digital_diary();

    // Example usage
    add_entry("2023-02-10", "Breakfast", "Overnight oats with banana and almond milk");
    add_entry("2023-02-11", "Work", "Met with team to discuss project plan");
    add_entry("2023-02-12", "Lunch", "Sushi with colleagues");

    display_entries();

    return 0;
}