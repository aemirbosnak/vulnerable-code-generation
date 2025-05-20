//Falcon-180B DATASET v1.0 Category: Threading Library Implementation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

struct v {
    int *a;
    int *b;
    int *c;
};

void *runner(void *arg) {
    struct v *data = arg;
    int *a = data->a;
    int *b = data->b;
    int *c = data->c;

    for (int i = 0; i < 10; i++) {
        *a += *b;
        *b += *c;
        *c += *a;
    }

    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    int i, ret;
    struct v data;

    data.a = malloc(sizeof(int));
    data.b = malloc(sizeof(int));
    data.c = malloc(sizeof(int));

    *data.a = 1;
    *data.b = 2;
    *data.c = 3;

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

    printf("All threads completed successfully.\n");

    free(data.a);
    free(data.b);
    free(data.c);

    return 0;
}