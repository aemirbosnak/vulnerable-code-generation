//Falcon2-11B DATASET v1.0 Category: Classical Circuit Simulator ; Style: multi-threaded
#include <stdio.h>
#include <pthread.h>

int num_threads;
int *thread_id;
int *data;
pthread_mutex_t mutex;
pthread_cond_t cond;

void *thread_func(void *arg) {
    int tid = *(int *)arg;
    int *d = data + tid * num_threads;
    int i;

    for (i = tid; i < num_threads; i += tid) {
        pthread_mutex_lock(&mutex);
        *d = i;
        pthread_cond_signal(&cond);
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

int main() {
    num_threads = 4;
    thread_id = (int *)malloc(num_threads * sizeof(int));
    data = (int *)malloc(num_threads * num_threads * sizeof(int));

    for (int i = 0; i < num_threads; i++) {
        thread_id[i] = i;
    }

    pthread_t threads[num_threads];
    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&cond, NULL);

    for (int i = 0; i < num_threads; i++) {
        pthread_create(&threads[i], NULL, thread_func, (void *)&thread_id[i]);
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    for (int i = 0; i < num_threads; i++) {
        int *d = data + i * num_threads;
        for (int j = 0; j < num_threads; j++) {
            printf("%d ", *d);
            d++;
        }
        printf("\n");
    }

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);

    return 0;
}