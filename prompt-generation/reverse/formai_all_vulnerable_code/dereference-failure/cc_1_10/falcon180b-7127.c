//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_THREADS 10
#define BUFFER_SIZE 1024

typedef struct {
    char *url;
    FILE *fp;
} ThreadData;

void *download_file(void *arg) {
    ThreadData *data = (ThreadData *) arg;
    char buffer[BUFFER_SIZE];
    long total_bytes_read = 0;

    while (fread(buffer, sizeof(char), BUFFER_SIZE, data->fp) > 0) {
        total_bytes_read += BUFFER_SIZE;
        printf("Downloading %s... %ld bytes read\n", data->url, total_bytes_read);
    }

    fclose(data->fp);
    free(data->url);
    free(data);

    return NULL;
}

int main() {
    pthread_t threads[MAX_THREADS];
    ThreadData data[MAX_THREADS];
    int i, num_threads = 0;

    printf("Enter URLs to download (press enter to finish):\n");

    while (num_threads < MAX_THREADS && fgets(data[num_threads].url, BUFFER_SIZE, stdin)!= NULL) {
        data[num_threads].fp = fopen(data[num_threads].url, "wb");
        if (data[num_threads].fp == NULL) {
            printf("Error opening file: %s\n", data[num_threads].url);
            num_threads--;
        } else {
            num_threads++;
        }
    }

    for (i = 0; i < num_threads; i++) {
        pthread_create(&threads[i], NULL, download_file, (void *) &data[i]);
    }

    for (i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}