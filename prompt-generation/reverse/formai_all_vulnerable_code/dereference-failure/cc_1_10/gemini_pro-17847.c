//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: distributed
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>

typedef struct {
    char *data;
    int size;
} Book;

typedef struct {
    Book *book;
    int start;
    int end;
} ReaderTask;

sem_t semaphore;

void *reader_task(void *arg) {
    ReaderTask *task = (ReaderTask *)arg;
    sem_wait(&semaphore);
    for (int i = task->start; i < task->end; i++) {
        printf("%c", task->book->data[i]);
    }
    printf("\n");
    sem_post(&semaphore);
    return NULL;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", argv[1]);
        return 1;
    }

    fseek(file, 0, SEEK_END);
    int size = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *data = malloc(size);
    fread(data, 1, size, file);
    fclose(file);

    Book book = {data, size};

    sem_init(&semaphore, 0, 1);

    int num_threads = 4;
    pthread_t threads[num_threads];

    int chunk_size = size / num_threads;
    for (int i = 0; i < num_threads; i++) {
        ReaderTask task = {&book, i * chunk_size, (i + 1) * chunk_size};
        pthread_create(&threads[i], NULL, reader_task, &task);
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    sem_destroy(&semaphore);
    free(data);

    return 0;
}