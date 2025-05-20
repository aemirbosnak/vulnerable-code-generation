//Falcon-180B DATASET v1.0 Category: Threading Library Implementation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

struct v {
    int sum;
    int id;
};

void *runner(void *param);

int main(int argc, char **argv) {
    pthread_t threads[NUM_THREADS];
    int i, ret;
    struct v *v = malloc(sizeof(struct v) * NUM_THREADS);

    for (i = 0; i < NUM_THREADS; i++) {
        v[i].id = i + 1;
        v[i].sum = 0;
        ret = pthread_create(&threads[i], NULL, runner, &v[i]);
        if (ret) {
            printf("Error: unable to create thread, %d\n", ret);
            exit(-1);
        }
    }

    for (i = 0; i < NUM_THREADS; i++) {
        ret = pthread_join(threads[i], NULL);
        if (ret) {
            printf("Error: unable to join with thread, %d\n", ret);
            exit(-1);
        }
    }

    printf("Total sum is %d\n", v[0].sum);
    return 0;
}

void *runner(void *param) {
    struct v *v = param;
    int i;

    for (i = 1; i <= 1000000; i++) {
        v->sum += i;
    }

    pthread_exit(0);
}