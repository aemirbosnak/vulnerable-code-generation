//Falcon-180B DATASET v1.0 Category: System administration ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <pthread.h>

#define MAX_THREADS 10
#define MAX_FILE_SIZE 1000000

pthread_mutex_t file_mutex = PTHREAD_MUTEX_INITIALIZER;

typedef struct {
    char filename[100];
    int filesize;
    int thread_id;
} thread_data;

void *thread_function(void *arg) {
    thread_data *data = (thread_data *) arg;
    FILE *fp;
    char ch;
    int count = 0;

    fp = fopen(data->filename, "r");
    if (fp == NULL) {
        printf("Error: Unable to open file %s\n", data->filename);
        exit(1);
    }

    while ((ch = fgetc(fp))!= EOF) {
        count++;
    }

    data->filesize = count;

    fclose(fp);

    pthread_exit(0);
}

int main(int argc, char *argv[]) {
    int i, num_threads;
    pthread_t threads[MAX_THREADS];
    thread_data data[MAX_THREADS];

    if (argc < 2) {
        printf("Error: Please provide a list of filenames\n");
        exit(1);
    }

    num_threads = argc - 1;

    for (i = 0; i < num_threads; i++) {
        strcpy(data[i].filename, argv[i+1]);
        data[i].filesize = 0;
        data[i].thread_id = i;
    }

    for (i = 0; i < num_threads; i++) {
        pthread_create(&threads[i], NULL, thread_function, &data[i]);
    }

    for (i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    for (i = 0; i < num_threads; i++) {
        printf("File %s has %d bytes\n", data[i].filename, data[i].filesize);
    }

    return 0;
}