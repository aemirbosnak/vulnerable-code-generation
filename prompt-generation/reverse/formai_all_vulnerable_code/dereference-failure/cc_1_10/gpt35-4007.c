//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_THREADS 10

pthread_mutex_t mutex;
pthread_cond_t cond;

int count = 0;

void* increment_count(void* arg){
    int id = *(int*) arg;
    for(int i=0; i<5; i++){
        pthread_mutex_lock(&mutex);
        count++;
        printf("Thread %d incremented count to %d\n", id, count);
        if(count%2==0){
            pthread_cond_signal(&cond);
        }
        pthread_mutex_unlock(&mutex);
        sleep(1);
    }
    pthread_exit(NULL);
}

void* even_thread(void* arg){
    pthread_mutex_lock(&mutex);
    while(count%2==1){
        pthread_cond_wait(&cond, &mutex);
    }
    printf("Even thread detected even count of %d\n", count);
    pthread_mutex_unlock(&mutex);
    pthread_exit(NULL);
}

int main(){
    pthread_t threads[NUM_THREADS];
    int* thread_ids[NUM_THREADS];
    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&cond, NULL);

    for(int i=0; i<NUM_THREADS; i++){
        thread_ids[i] = (int*) malloc(sizeof(int));
        *thread_ids[i] = i;
        pthread_create(&threads[i], NULL, increment_count, (void*) thread_ids[i]);
    }

    for(int i=0; i<NUM_THREADS; i++){
        pthread_join(threads[i], NULL);
        free(thread_ids[i]);
    }

    pthread_t even_thread_id;
    pthread_create(&even_thread_id, NULL, even_thread, NULL);
    pthread_join(even_thread_id, NULL);

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);

    return 0;
}