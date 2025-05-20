//Falcon-180B DATASET v1.0 Category: Threading Library Implementation ; Style: ephemeral
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
    int i;
    for (i = 0; i < data->n; i++) {
        data->a[i] *= 2;
    }
    return NULL;
}

int main() {
    int i, ret;
    pthread_t threads[NUM_THREADS];
    struct v data;

    data.a = (int *) malloc(10 * sizeof(int));
    data.n = 10;
    for (i = 0; i < data.n; i++) {
        data.a[i] = i;
    }

    for (i = 0; i < NUM_THREADS; i++) {
        ret = pthread_create(&threads[i], NULL, runner, &data);
        if (ret) {
            printf("Error: unable to create thread, %d\n", ret);
            exit(-1);
        }
    }

    for (i = 0; i < NUM_THREADS; i++) {
        ret = pthread_join(threads[i], NULL);
        if (ret) {
            printf("Error: unable to join thread, %d\n", ret);
            exit(-1);
        }
    }

    for (i = 0; i < data.n; i++) {
        printf("%d ", data.a[i]);
    }

    printf("\n");
    return 0;
}