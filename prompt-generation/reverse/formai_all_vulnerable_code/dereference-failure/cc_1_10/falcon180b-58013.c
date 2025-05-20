//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

#define MAX_LINE_SIZE 1024
#define MAX_THREADS 10

typedef struct {
    char *line;
    size_t len;
} csv_line;

typedef struct {
    FILE *file;
    pthread_t threads[MAX_THREADS];
    csv_line lines[MAX_THREADS];
    int num_threads;
} csv_data;

void *process_line(void *arg) {
    csv_line *line = arg;
    printf("Thread %ld: %s\n", pthread_self(), line->line);
}

void read_csv_file(csv_data *data) {
    char line[MAX_LINE_SIZE];
    while (fgets(line, MAX_LINE_SIZE, data->file)!= NULL) {
        csv_line *new_line = malloc(sizeof(csv_line));
        new_line->line = strdup(line);
        new_line->len = strlen(line);
        pthread_t thread;
        pthread_create(&thread, NULL, process_line, new_line);
        data->lines[data->num_threads++] = *new_line;
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <csv_file> <num_threads>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    csv_data data;
    data.file = file;
    data.num_threads = atoi(argv[2]);

    read_csv_file(&data);

    for (int i = 0; i < data.num_threads; i++) {
        pthread_join(data.threads[i], NULL);
    }

    fclose(file);
    return 0;
}