//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_SIZE 1024

typedef struct {
    char *entry;
    time_t timestamp;
} diary_entry_t;

typedef struct {
    diary_entry_t entries[MAX_ENTRIES];
    int num_entries;
    sem_t mutex;
} diary_t;

diary_t *diary;

void diary_init() {
    diary = malloc(sizeof(diary_t));
    diary->num_entries = 0;
    sem_init(&diary->mutex, 0, 1);
}

void diary_add_entry(char *entry) {
    sem_wait(&diary->mutex);
    if (diary->num_entries < MAX_ENTRIES) {
        diary->entries[diary->num_entries].entry = strdup(entry);
        diary->entries[diary->num_entries].timestamp = time(NULL);
        diary->num_entries++;
    }
    sem_post(&diary->mutex);
}

void diary_print_entry(int index) {
    if (index < 0 || index >= diary->num_entries) {
        printf("Invalid entry index.\n");
    } else {
        printf("%s\n", diary->entries[index].entry);
    }
}

void diary_print_all_entries() {
    for (int i = 0; i < diary->num_entries; i++) {
        printf("%s\n", diary->entries[i].entry);
    }
}

void diary_free_entry(int index) {
    if (index < 0 || index >= diary->num_entries) {
        printf("Invalid entry index.\n");
    } else {
        free(diary->entries[index].entry);
    }
}

void diary_free_all_entries() {
    for (int i = 0; i < diary->num_entries; i++) {
        free(diary->entries[i].entry);
    }
}

void diary_free() {
    diary_free_all_entries();
    free(diary);
}

int main() {
    diary_init();

    char *entry1 = "This is my first diary entry.";
    char *entry2 = "This is my second diary entry.";
    char *entry3 = "This is my third diary entry.";

    diary_add_entry(entry1);
    diary_add_entry(entry2);
    diary_add_entry(entry3);

    diary_print_all_entries();

    diary_free();

    return 0;
}