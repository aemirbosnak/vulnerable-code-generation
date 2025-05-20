//Falcon-180B DATASET v1.0 Category: Threading Library Implementation ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

struct v {
    int *a;
    int *b;
    int *c;
};

void *runner(void *param) {
    struct v *data = (struct v *) param;
    int sum = data->a[0] + data->b[0] + data->c[0];
    printf("Thread %d calculated sum: %d\n", *(int *) param, sum);
    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    int i, rc;
    struct v data;

    data.a = (int *) malloc(NUM_THREADS * sizeof(int));
    data.b = (int *) malloc(NUM_THREADS * sizeof(int));
    data.c = (int *) malloc(NUM_THREADS * sizeof(int));

    for (i = 0; i < NUM_THREADS; i++) {
        data.a[i] = i;
        data.b[i] = i * 2;
        data.c[i] = i * 3;
    }

    for (i = 0; i < NUM_THREADS; i++) {
        rc = pthread_create(&threads[i], NULL, runner, (void *) &i);
        if (rc) {
            printf("Error: unable to create thread, %d\n", rc);
            exit(-1);
        }
    }

    for (i = 0; i < NUM_THREADS; i++) {
        rc = pthread_join(threads[i], NULL);
        if (rc) {
            printf("Error: unable to join with thread, %d\n", rc);
            exit(-1);
        }
    }

    free(data.a);
    free(data.b);
    free(data.c);

    return 0;
}