//Falcon-180B DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define NUM_THREADS 4

int data[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

struct v {
    int *data;
    int thread_id;
};

void *runner(void *param);

int main() {
    pthread_t threads[NUM_THREADS];
    int i, rc;
    struct v *vars = (struct v *) malloc(NUM_THREADS * sizeof(struct v));

    srand(time(NULL));

    for (i = 0; i < NUM_THREADS; i++) {
        vars[i].data = &data[rand() % 10];
        vars[i].thread_id = i;
    }

    for (i = 0; i < NUM_THREADS; i++) {
        rc = pthread_create(&threads[i], NULL, runner, (void *) &vars[i]);
        if (rc) {
            printf("Error: unable to create thread, %d\n", rc);
            exit(-1);
        }
    }

    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    free(vars);
    return 0;
}

void *runner(void *param) {
    struct v *v = param;
    int sum = 0;

    printf("Thread %d started...\n", v->thread_id);

    for (int i = 0; i < 10; i++) {
        sum += v->data[i];
    }

    printf("Thread %d finished with sum: %d\n", v->thread_id, sum);

    return NULL;
}