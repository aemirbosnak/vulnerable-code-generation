//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <unistd.h>

#define NUM_THREADS 4

typedef struct {
    char *text;
    int length;
    int start;
    int end;
    int correct;
    int incorrect;
    double time;
} thread_data;

void *thread_main(void *arg) {
    thread_data *data = (thread_data *)arg;
    time_t start = time(NULL);
    int i;
    for (i = data->start; i < data->end; i++) {
        if (data->text[i] == getchar()) {
            data->correct++;
        } else {
            data->incorrect++;
        }
    }
    data->time = difftime(time(NULL), start);
    return NULL;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s text\n", argv[0]);
        return 1;
    }

    char *text = argv[1];
    int length = strlen(text);

    pthread_t threads[NUM_THREADS];
    thread_data data[NUM_THREADS];

    int i;
    for (i = 0; i < NUM_THREADS; i++) {
        data[i].text = text;
        data[i].length = length;
        data[i].start = i * (length / NUM_THREADS);
        data[i].end = (i + 1) * (length / NUM_THREADS);
        data[i].correct = 0;
        data[i].incorrect = 0;
        data[i].time = 0;
        pthread_create(&threads[i], NULL, thread_main, &data[i]);
    }

    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    int total_correct = 0;
    int total_incorrect = 0;
    double total_time = 0;
    for (i = 0; i < NUM_THREADS; i++) {
        total_correct += data[i].correct;
        total_incorrect += data[i].incorrect;
        total_time += data[i].time;
    }

    printf("Correct: %d\n", total_correct);
    printf("Incorrect: %d\n", total_incorrect);
    printf("Time: %.2f seconds\n", total_time);

    return 0;
}