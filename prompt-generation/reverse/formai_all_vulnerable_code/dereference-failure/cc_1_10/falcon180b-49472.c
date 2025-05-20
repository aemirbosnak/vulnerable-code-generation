//Falcon-180B DATASET v1.0 Category: Threading Library Implementation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

struct v {
    int *a;
    int n;
};

void *runner(void *param) {
    struct v *data = param;
    int sum = 0;
    for (int i = 0; i < data->n; i++) {
        sum += data->a[i];
    }
    printf("Thread %d calculated sum: %d\n", *(int*)param, sum);
    pthread_exit(0);
}

void *runner2(void *param) {
    struct v *data = param;
    int sum = 0;
    for (int i = 0; i < data->n; i++) {
        sum += data->a[i];
    }
    printf("Thread %d calculated sum: %d\n", *(int*)param, sum);
    pthread_exit(0);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int ids[NUM_THREADS];
    int i;
    int *a = malloc(10 * sizeof(int));
    for (i = 0; i < 10; i++) {
        a[i] = i;
    }
    struct v data;
    data.a = a;
    data.n = 10;
    for (i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, runner, &i);
        ids[i] = i;
    }
    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
    free(a);
    return 0;
}