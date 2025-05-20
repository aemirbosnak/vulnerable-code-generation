//Falcon-180B DATASET v1.0 Category: Text to ASCII art generator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_THREADS 10
#define MAX_LINE_LENGTH 80
#define ASCII_ART_FILE "ascii_art.txt"

typedef struct {
    char *line;
    int line_num;
} LineData;

void *thread_func(void *arg) {
    LineData *data = (LineData *) arg;
    char *line = data->line;
    int line_num = data->line_num;

    printf("[%d] %s\n", line_num, line);
    free(line);
    return NULL;
}

int main() {
    FILE *file;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    int line_num = 0;
    pthread_t threads[MAX_THREADS];

    file = fopen(ASCII_ART_FILE, "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", ASCII_ART_FILE);
        exit(1);
    }

    while ((read = getline(&line, &len, file))!= -1) {
        if (line_num >= MAX_THREADS) {
            printf("Max number of threads reached.\n");
            break;
        }

        LineData *data = malloc(sizeof(LineData));
        data->line = line;
        data->line_num = line_num;

        pthread_create(&threads[line_num], NULL, thread_func, data);
        line_num++;

        line = NULL;
        len = 0;
    }

    fclose(file);

    for (int i = 0; i < line_num; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}