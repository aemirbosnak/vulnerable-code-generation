//GEMINI-pro DATASET v1.0 Category: File Synchronizer ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_FILE_SIZE 1024
#define MAX_THREADS 4

typedef struct {
    char *file1;
    char *file2;
    int start;
    int end;
} sync_args;

void *sync_thread(void *args) {
    sync_args *arg = (sync_args *)args;
    char buffer[MAX_FILE_SIZE];
    FILE *fp1 = fopen(arg->file1, "r");
    FILE *fp2 = fopen(arg->file2, "a");
    if (fp1 == NULL || fp2 == NULL) {
        perror("Error opening files");
        exit(1);
    }
    fseek(fp1, arg->start, SEEK_SET);
    while (fgets(buffer, MAX_FILE_SIZE, fp1) != NULL) {
        if (arg->end > 0 && ftell(fp1) > arg->end) {
            break;
        }
        fputs(buffer, fp2);
    }
    fclose(fp1);
    fclose(fp2);
    return NULL;
}

int main(int argc, char **argv) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s file1 file2 start [end]\n", argv[0]);
        return 1;
    }
    int start = atoi(argv[3]);
    int end = (argc >= 5) ? atoi(argv[4]) : 0;
    int file_size = end - start + 1;
    int num_threads = file_size / MAX_FILE_SIZE + 1;
    if (num_threads > MAX_THREADS) {
        fprintf(stderr, "Error: Number of threads (%d) exceeds maximum (%d)\n", num_threads, MAX_THREADS);
        return 1;
    }
    sync_args args[num_threads];
    pthread_t threads[num_threads];
    for (int i = 0; i < num_threads; i++) {
        args[i].file1 = argv[1];
        args[i].file2 = argv[2];
        args[i].start = start + i * MAX_FILE_SIZE;
        args[i].end = start + (i + 1) * MAX_FILE_SIZE - 1;
        if (i == num_threads - 1) {
            args[i].end = end;
        }
        pthread_create(&threads[i], NULL, sync_thread, &args[i]);
    }
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }
    return 0;
}