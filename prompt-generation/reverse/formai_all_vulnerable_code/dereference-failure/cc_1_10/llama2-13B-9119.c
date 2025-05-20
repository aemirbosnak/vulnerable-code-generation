//LLAMA2-13B DATASET v1.0 Category: Digital Diary ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/mman.h>
#include <sys/shm.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include <pthread.h>
#include <semaphore.h>

#define DIARY_SIZE (1024 * 1024)
#define MAX_ENTRIES (100)
#define ENTRY_SIZE (1024)

typedef struct {
    char date[16];
    char entry[ENTRY_SIZE];
} diary_entry_t;

typedef struct {
    char *name;
    size_t size;
    size_t num_entries;
    diary_entry_t *entries;
} diary_t;

static diary_t *diary;
static sem_t *sem;

void init_diary(void) {
    diary = (diary_t *)calloc(1, sizeof(diary_t));
    sem = (sem_t *)calloc(1, sizeof(sem_t));

    diary->name = "My Digital Diary";
    diary->size = DIARY_SIZE;
    diary->num_entries = 0;
    diary->entries = (diary_entry_t *)calloc(DIARY_SIZE / ENTRY_SIZE, sizeof(diary_entry_t));

    sem_init(sem, 0, DIARY_SIZE);
}

void add_entry(const char *entry) {
    size_t entry_size = strlen(entry) + 1;
    size_t remaining = DIARY_SIZE - diary->num_entries * ENTRY_SIZE;

    if (remaining < entry_size) {
        printf("Diary is full. Please delete some entries before adding more.\n");
        return;
    }

    diary->num_entries++;

    // Allocate memory for the new entry
    diary_entry_t *new_entry = (diary_entry_t *)calloc(1, sizeof(diary_entry_t));
    new_entry->date[15] = 0;  // Null-terminate the date string
    strcpy(new_entry->entry, entry);

    // Write the new entry to the shared memory
    mmap(new_entry, sizeof(diary_entry_t), -1, PROT_READ | PROT_WRITE, MAP_SHARED, diary->name);

    // Signal the semaphore to allow other threads to continue
    sem_post(sem);
}

void read_entries(void) {
    size_t num_entries = diary->num_entries;

    for (size_t i = 0; i < num_entries; i++) {
        diary_entry_t *entry = diary->entries + i;

        printf("%s - %s\n", entry->date, entry->entry);
    }
}

void cleanup(void) {
    sem_destroy(sem);
    free(diary);
}

int main(void) {
    init_diary();

    for (size_t i = 0; i < 10; i++) {
        char entry[ENTRY_SIZE];
        printf("Enter a diary entry: ");
        fgets(entry, ENTRY_SIZE, stdin);
        add_entry(entry);
    }

    read_entries();

    cleanup();

    return 0;
}