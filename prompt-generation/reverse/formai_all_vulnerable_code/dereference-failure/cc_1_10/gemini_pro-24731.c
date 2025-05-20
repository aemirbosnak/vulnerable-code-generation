//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct DiaryEntry {
    char *title;
    char *content;
    char *date;
};

void add_entry(struct DiaryEntry **diary, int *num_entries, char *title, char *content, char *date) {
    *diary = realloc(*diary, (*num_entries + 1) * sizeof(struct DiaryEntry));
    (*diary)[*num_entries].title = strdup(title);
    (*diary)[*num_entries].content = strdup(content);
    (*diary)[*num_entries].date = strdup(date);
    (*num_entries)++;
}

void print_entry(struct DiaryEntry entry) {
    printf("Title: %s\n", entry.title);
    printf("Content: %s\n", entry.content);
    printf("Date: %s\n", entry.date);
    printf("\n");
}

void print_diary(struct DiaryEntry *diary, int num_entries) {
    for (int i = 0; i < num_entries; i++) {
        print_entry(diary[i]);
    }
}

void free_diary(struct DiaryEntry *diary, int num_entries) {
    for (int i = 0; i < num_entries; i++) {
        free(diary[i].title);
        free(diary[i].content);
        free(diary[i].date);
    }
    free(diary);
}

int main() {
    struct DiaryEntry *diary = NULL;
    int num_entries = 0;

    char title1[] = "My first day";
    char content1[] = "I started my new job today. It was a great day and I met a lot of nice people.";
    char date1[] = "2023-01-01";

    char title2[] = "My second day";
    char content2[] = "I worked on my first project today. It was a challenging project but I learned a lot.";
    char date2[] = "2023-01-02";

    add_entry(&diary, &num_entries, title1, content1, date1);
    add_entry(&diary, &num_entries, title2, content2, date2);

    print_diary(diary, num_entries);

    free_diary(diary, num_entries);

    return 0;
}