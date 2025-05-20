//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 4

struct v {
    int *a;
    int *b;
    int *c;
    int n;
};

void *runner(void *param) {
    struct v *data = (struct v *) param;
    int i;
    for (i = 0; i < data->n; i++) {
        data->a[i] = data->a[i] + data->b[i] * data->c[i];
    }
    return NULL;
}

int main() {
    int i;
    pthread_t threads[NUM_THREADS];
    struct v data;
    data.a = (int *) malloc(10 * sizeof(int));
    data.b = (int *) malloc(10 * sizeof(int));
    data.c = (int *) malloc(10 * sizeof(int));
    data.n = 10;

    for (i = 0; i < data.n; i++) {
        data.a[i] = i;
        data.b[i] = i * 2;
        data.c[i] = i * 3;
    }

    for (i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, runner, &data);
    }

    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    for (i = 0; i < data.n; i++) {
        printf("%d\n", data.a[i]);
    }

    return 0;
}