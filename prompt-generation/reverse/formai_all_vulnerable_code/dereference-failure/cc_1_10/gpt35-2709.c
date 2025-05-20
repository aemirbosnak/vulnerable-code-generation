//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_THREADS 10

typedef struct {
    int id; // thread id
    char* file_name; // name of file to extract metadata from
} thread_args;

void* extract_metadata(void* args) {
    thread_args* t_args = (thread_args*) args;
    printf("Thread with id %d extracting metadata from %s\n", t_args->id, t_args->file_name);
    // logic to extract metadata goes here
    printf("Thread with id %d has finished extracting metadata from %s\n", t_args->id, t_args->file_name);
    free(t_args->file_name);
    free(t_args);
    pthread_exit(NULL);
}

int main(int argc, char** argv) {
    if(argc < 2) {
        printf("Usage: %s file1 [file2] [file3] ...\n", argv[0]);
        return 0;
    }

    int num_files = argc - 1;
    if(num_files > MAX_THREADS) {
        printf("Too many files, maximum number of threads is %d\n", MAX_THREADS);
        return 0;
    }

    pthread_t threads[num_files];
    int i;
    for(i = 0; i < num_files; i++) {
        thread_args* args = (thread_args*) malloc(sizeof(thread_args));
        args->id = i;
        args->file_name = strdup(argv[i+1]);
        pthread_create(&threads[i], NULL, extract_metadata, (void*) args);
    }

    for(i = 0; i < num_files; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("All metadata extracted!\n");
    return 0;
}