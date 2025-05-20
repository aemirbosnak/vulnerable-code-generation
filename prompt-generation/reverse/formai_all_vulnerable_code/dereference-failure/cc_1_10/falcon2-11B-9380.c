//Falcon2-11B DATASET v1.0 Category: Digital Diary ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>

#define NUM_THREADS 4
#define NUM_ENTRIES 100
#define MAX_ENTRY_LEN 100

typedef struct entry {
    char data[MAX_ENTRY_LEN];
    struct entry *next;
} entry_t;

typedef struct diary {
    entry_t *entries;
    pthread_mutex_t mutex;
} diary_t;

void *thread_entry(void *diary_ptr) {
    diary_t *diary = (diary_t *)diary_ptr;
    pthread_mutex_lock(&diary->mutex);
    int entry_num = 0;
    while (entry_num < NUM_ENTRIES) {
        struct timeval start_time;
        gettimeofday(&start_time, NULL);
        char entry[MAX_ENTRY_LEN];
        sprintf(entry, "Entry %d: %s\n", entry_num, "Thread %d");
        entry_num++;
        struct timeval end_time;
        gettimeofday(&end_time, NULL);
        double elapsed_time = (end_time.tv_sec - start_time.tv_sec) + (end_time.tv_usec - start_time.tv_usec) / 1000000.0;
        printf("Thread %d: %s in %f seconds\n", entry_num, entry, elapsed_time);
    }
    pthread_mutex_unlock(&diary->mutex);
    return NULL;
}

int main() {
    diary_t diary;
    diary.entries = malloc(NUM_ENTRIES * sizeof(entry_t));
    diary.entries[0].next = NULL;
    pthread_t threads[NUM_THREADS];
    int i;
    for (i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, thread_entry, (void *)&diary);
    }
    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
    free(diary.entries);
    return 0;
}