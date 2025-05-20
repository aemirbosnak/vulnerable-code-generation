//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct entry {
    char* date;
    char* time;
    char* text;
} entry_t;

entry_t* create_entry(char* date, char* time, char* text) {
    entry_t* entry = malloc(sizeof(entry_t));
    entry->date = strdup(date);
    entry->time = strdup(time);
    entry->text = strdup(text);
    return entry;
}

void free_entry(entry_t* entry) {
    free(entry->date);
    free(entry->time);
    free(entry->text);
    free(entry);
}

int main() {
    // Create a new digital diary
    entry_t* diary = malloc(sizeof(entry_t));
    diary->date = strdup("2023-03-08");
    diary->time = strdup("10:00 AM");
    diary->text = strdup("I can't believe it's already March! Time flies when you're having fun.");

    // Add a new entry to the diary
    entry_t* new_entry = create_entry("2023-03-09", "11:00 AM", "I went for a walk in the park today. It was a beautiful day and I saw lots of birds and squirrels.");

    // Print the diary
    printf("My Digital Diary:\n\n");
    printf("%s (%s) - %s\n", diary->date, diary->time, diary->text);
    printf("%s (%s) - %s\n\n", new_entry->date, new_entry->time, new_entry->text);

    // Free the memory allocated for the diary and its entries
    free(diary->date);
    free(diary->time);
    free(diary->text);
    free(diary);
    free(new_entry->date);
    free(new_entry->time);
    free(new_entry->text);
    free(new_entry);

    return 0;
}