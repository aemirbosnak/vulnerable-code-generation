//Falcon2-11B DATASET v1.0 Category: Word Frequency Counter ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_SIZE 1000000
#define MAX_THREADS 4

char* word_freq[MAX_SIZE];
int word_freq_count[MAX_SIZE];

pthread_mutex_t lock;
pthread_cond_t cond;

void* thread_func(void* arg) {
    int tid = *(int*)arg;
    char* word = (char*)malloc(sizeof(char) * MAX_SIZE);
    int freq = 0;
    int index = 0;

    for (int i = 0; i < MAX_SIZE; i++) {
        word[i] = 0;
        word_freq_count[i] = 0;
    }

    while (1) {
        pthread_mutex_lock(&lock);
        if (word_freq[tid]!= NULL) {
            strcpy(word, word_freq[tid]);
            freq = word_freq_count[tid];
        }
        pthread_mutex_unlock(&lock);

        if (word[0]!= '\0') {
            pthread_mutex_lock(&lock);
            word_freq_count[tid] += freq;
            word_freq[tid] = word;
            pthread_mutex_unlock(&lock);
            printf("Thread %d: %s -> %d\n", tid, word, word_freq_count[tid]);
        } else {
            pthread_cond_signal(&cond);
            break;
        }
    }

    free(word);
    return NULL;
}

int main() {
    pthread_t threads[MAX_THREADS];
    int tid = 0;

    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_create(&threads[i], NULL, thread_func, &tid);
        tid++;
    }

    char* word = (char*)malloc(sizeof(char) * MAX_SIZE);
    int freq = 0;

    while (1) {
        pthread_mutex_lock(&lock);
        if (word_freq[tid]!= NULL) {
            strcpy(word, word_freq[tid]);
            freq = word_freq_count[tid];
        }
        pthread_mutex_unlock(&lock);

        if (word[0]!= '\0') {
            pthread_mutex_lock(&lock);
            word_freq_count[tid] += freq;
            word_freq[tid] = word;
            pthread_mutex_unlock(&lock);
            printf("Thread %d: %s -> %d\n", tid, word, word_freq_count[tid]);
        } else {
            pthread_cond_broadcast(&cond);
            break;
        }
    }

    pthread_join(threads[0], NULL);
    pthread_join(threads[1], NULL);
    pthread_join(threads[2], NULL);
    pthread_join(threads[3], NULL);

    return 0;
}