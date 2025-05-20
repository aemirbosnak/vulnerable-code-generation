//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_THREADS 10
#define MAX_KEYS 1000

typedef struct {
    char *key;
    int value;
} KeyValue;

KeyValue *metadata = NULL;
int num_metadata = 0;

pthread_mutex_t metadata_mutex = PTHREAD_MUTEX_INITIALIZER;

void *metadata_thread(void *arg) {
    char *filename = (char *) arg;
    FILE *fp;
    char line[1024];
    char *key, *value;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    while (fgets(line, 1024, fp)!= NULL) {
        key = strtok(line, ":");
        value = strtok(NULL, ":");

        pthread_mutex_lock(&metadata_mutex);
        num_metadata++;
        metadata = (KeyValue *) realloc(metadata, num_metadata * sizeof(KeyValue));
        metadata[num_metadata - 1].key = strdup(key);
        metadata[num_metadata - 1].value = atoi(value);
        pthread_mutex_unlock(&metadata_mutex);
    }

    fclose(fp);
    return NULL;
}

int main(int argc, char *argv[]) {
    pthread_t threads[MAX_THREADS];
    int i, num_threads;

    if (argc < 2) {
        printf("Usage: %s file1 file2...\n", argv[0]);
        exit(1);
    }

    num_threads = 0;
    for (i = 1; i < argc; i++) {
        pthread_create(&threads[num_threads], NULL, metadata_thread, argv[i]);
        num_threads++;
    }

    for (i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Total metadata extracted: %d\n", num_metadata);

    for (i = 0; i < num_metadata; i++) {
        printf("%s: %d\n", metadata[i].key, metadata[i].value);
    }

    return 0;
}