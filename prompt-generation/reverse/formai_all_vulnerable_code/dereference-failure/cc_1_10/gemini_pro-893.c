//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char *title;
    char *content;
    time_t timestamp;
} DiaryEntry;

DiaryEntry *create_entry(char *title, char *content) {
    DiaryEntry *entry = malloc(sizeof(DiaryEntry));
    entry->title = title;
    entry->content = content;
    entry->timestamp = time(NULL);
    return entry;
}

int main() {
    // Create a new diary
    DiaryEntry *diary = create_entry("My Digital Diary", "This is my first entry.");

    // Add a few more entries to the diary
    DiaryEntry *entry1 = create_entry("My First Day at Work", "Today was my first day at work and it was great!");
    DiaryEntry *entry2 = create_entry("My First Date", "I went on my first date last night and it was a disaster.");
    DiaryEntry *entry3 = create_entry("My First Apartment", "I just moved into my first apartment and I'm so excited!");

    // Print the diary entries to the console
    printf("%s\n", diary->title);
    printf("%s\n", diary->content);
    printf("%s\n", ctime(&diary->timestamp));
    printf("\n");
    printf("%s\n", entry1->title);
    printf("%s\n", entry1->content);
    printf("%s\n", ctime(&entry1->timestamp));
    printf("\n");
    printf("%s\n", entry2->title);
    printf("%s\n", entry2->content);
    printf("%s\n", ctime(&entry2->timestamp));
    printf("\n");
    printf("%s\n", entry3->title);
    printf("%s\n", entry3->content);
    printf("%s\n", ctime(&entry3->timestamp));

    // Free the memory allocated for the diary entries
    free(diary->title);
    free(diary->content);
    free(diary);
    free(entry1->title);
    free(entry1->content);
    free(entry1);
    free(entry2->title);
    free(entry2->content);
    free(entry2);
    free(entry3->title);
    free(entry3->content);
    free(entry3);

    return 0;
}