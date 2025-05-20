//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

typedef struct {
    pthread_t thread;
    char *msg;
} ThreadData;

void *threadFunc(void *arg) {
    ThreadData *data = (ThreadData *)arg;
    printf("%s\n", data->msg);
    pthread_exit(NULL);
}

void createThread(char *msg) {
    ThreadData *data = (ThreadData *)malloc(sizeof(ThreadData));
    data->msg = msg;

    if (pthread_create(&(data->thread), NULL, &threadFunc, data)) {
        fprintf(stderr, "Error creating thread\n");
        return;
    }

    pthread_join(data->thread, NULL);
}

int main() {
    srand(time(NULL));
    char *msgs[] = {
        "I see trees of green, red roses too",
        "I see them bloom, for me and you",
        "And I think to myself, what a wonderful world",
        "I see skies of blue and clouds of white",
        "The bright blessed day, the dark sacred night",
        "And I think to myself, what a wonderful world"
    };

    int num_threads = sizeof(msgs) / sizeof(char *);

    for (int i = 0; i < num_threads; i++) {
        int sleep_time = rand() % 5 + 1;
        printf("Creating thread %d...\n", i);
        createThread(msgs[i]);
        printf("Thread %d finished\n", i);
        sleep(sleep_time);
    }

    return 0;
}