//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define BUFFER_SIZE 1024 // buffer size for reading file data
#define NUM_THREADS 5 // number of worker threads

typedef struct {
    unsigned int checksum; // checksum value
    FILE *file; // pointer to file
} FileInfo;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER; // mutex variable for shared resources

void *worker(void *arg) {
    FileInfo *info = (FileInfo *)arg;
    unsigned char buffer[BUFFER_SIZE];
    int n;

    while ((n = fread(buffer, 1, BUFFER_SIZE, info->file))) {
        for (int i = 0; i < n; i++) {
            pthread_mutex_lock(&mutex);
            info->checksum += buffer[i];
            pthread_mutex_unlock(&mutex);
        }
    }

    fclose(info->file);
    free(info);

    return NULL;
}

unsigned int calculate_checksum(char *filename) {
    unsigned int checksum = 0;
    pthread_t threads[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; i++) {
        FileInfo *info = (FileInfo *)malloc(sizeof(FileInfo));
        info->checksum = 0;
        info->file = fopen(filename, "rb");
        fseek(info->file, i * (BUFFER_SIZE / NUM_THREADS), SEEK_SET); // move the file pointer to the correct chunk
        pthread_create(&threads[i], NULL, worker, (void *)info);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return checksum;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    unsigned int checksum = calculate_checksum(argv[1]);
    printf("Checksum: %u\n", checksum);

    return 0;
}