//Falcon-180B DATASET v1.0 Category: Syntax parsing ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 10
#define MAX_LINE_LENGTH 1000

int num_threads = 0;
pthread_t threads[MAX_THREADS];

struct thread_data {
    char *line;
    int line_num;
};

void *count_words(void *arg) {
    struct thread_data *data = (struct thread_data *) arg;

    char *token = strtok(data->line, " ");
    int word_count = 0;

    while (token!= NULL) {
        word_count++;
        token = strtok(NULL, " ");
    }

    printf("Line %d has %d words.\n", data->line_num, word_count);

    pthread_exit(NULL);
}

int main() {
    FILE *file = fopen("input.txt", "r");

    if (file == NULL) {
        printf("Error: Unable to open input file.\n");
        exit(1);
    }

    char line[MAX_LINE_LENGTH];
    int line_num = 0;

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        line_num++;

        struct thread_data data;
        data.line = line;
        data.line_num = line_num;

        pthread_create(&threads[num_threads], NULL, count_words, &data);
        num_threads++;
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    fclose(file);
    return 0;
}