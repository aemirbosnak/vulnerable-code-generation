//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 4

typedef struct {
    char *filename;
    int thread_id;
} thread_data_t;

void *extract_metadata(void *arg) {
    thread_data_t *data = (thread_data_t *) arg;
    FILE *fp = fopen(data->filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file '%s'\n", data->filename);
        exit(1);
    }
    fseek(fp, 0, SEEK_END);
    long filesize = ftell(fp);
    rewind(fp);
    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), fp)!= NULL) {
        printf("Thread %d: %s", data->thread_id, buffer);
    }
    fclose(fp);
    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    char filenames[NUM_THREADS][100] = {"file1.txt", "file2.txt", "file3.txt", "file4.txt"};
    int rc;
    for (int i = 0; i < NUM_THREADS; i++) {
        thread_data_t *data = (thread_data_t *) malloc(sizeof(thread_data_t));
        data->filename = filenames[i];
        data->thread_id = i + 1;
        rc = pthread_create(&threads[i], NULL, extract_metadata, data);
        if (rc) {
            printf("Error: unable to create thread, %d\n", rc);
            exit(-1);
        }
    }
    for (int i = 0; i < NUM_THREADS; i++) {
        rc = pthread_join(threads[i], NULL);
        if (rc) {
            printf("Error: unable to join with thread, %d\n", rc);
            exit(-1);
        }
    }
    return 0;
}