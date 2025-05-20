//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define NUM_THREADS 5
#define NUM_CONSPIRACIES 100
#define MAX_CONSPIRACY_LENGTH 50

char conspiracies[NUM_CONSPIRACIES][MAX_CONSPIRACY_LENGTH];

void generate_conspiracy(int index) {
    char *words[] = {"illuminati", "chemtrails", "lizard", "flat", "earth", "moon", "landing", "false", "flag", "9/11", "inside", "job", "covid", "hoax", "5g", "mind", "control", "new", "world", "order", "deep", "state", "qanon"};
    int num_words = sizeof(words) / sizeof(words[0]);
    int length = rand() % MAX_CONSPIRACY_LENGTH + 1;
    char conspiracy[MAX_CONSPIRACY_LENGTH];

    for (int i = 0; i < length; i++) {
        conspiracy[i] = words[rand() % num_words][rand() % strlen(words[rand() % num_words])];
    }

    strcpy(conspiracies[index], conspiracy);
}

void *thread_func(void *param) {
    int thread_id = (int) param;

    srand(time(NULL) + thread_id);

    for (int i = 0; i < NUM_CONSPIRACIES / NUM_THREADS; i++) {
        generate_conspiracy(i * NUM_THREADS + thread_id);
    }

    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    int rc;
    int i;

    for (i = 0; i < NUM_THREADS; i++) {
        rc = pthread_create(&threads[i], NULL, thread_func, (void *) i);
        if (rc) {
            printf("Error: unable to create thread, %d\n", rc);
            exit(-1);
        }
    }

    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Random conspiracy theories:\n");
    for (i = 0; i < NUM_CONSPIRACIES; i++) {
        printf("%s\n", conspiracies[i]);
    }

    return 0;
}