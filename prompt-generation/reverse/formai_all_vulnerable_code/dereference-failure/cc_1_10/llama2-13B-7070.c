//LLAMA2-13B DATASET v1.0 Category: Digital Diary ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define DIARY_SIZE 1000
#define GRATITUDE_SIZE 100

typedef struct {
    char date[20];
    char entry[100];
    char gratitude[GRATITUDE_SIZE];
} diary_t;

diary_t *diary = NULL;

void init_diary() {
    diary = (diary_t *)malloc(sizeof(diary_t));
    strcpy(diary->date, "");
    strcpy(diary->entry, "");
    strcpy(diary->gratitude, "");
}

void add_entry(char *date, char *entry) {
    char *new_entry = (char *)malloc(strlen(date) + strlen(entry) + 1);
    sprintf(new_entry, "%s - %s", date, entry);
    strcpy(diary->entry, new_entry);
}

void add_gratitude(char *gratitude) {
    strcpy(diary->gratitude, gratitude);
}

void print_diary() {
    printf("Date: %s\n", diary->date);
    printf("Entry: %s\n", diary->entry);
    printf("Gratitude: %s\n", diary->gratitude);
}

int main() {
    init_diary();

    // Add entries and gratitude
    add_entry("January 1st", "New Year's Day");
    add_gratitude("My family and friends");
    add_entry("January 15th", "First snowfall of the year");
    add_gratitude("Warm tea and a cozy blanket");

    // Print the diary
    print_diary();

    return 0;
}