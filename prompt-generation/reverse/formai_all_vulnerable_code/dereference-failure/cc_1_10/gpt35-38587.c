//FormAI DATASET v1.0 Category: Text processing ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_THREADS 5
#define MAX_STRING_LEN 100

char input_strings[MAX_THREADS][MAX_STRING_LEN];
int string_lengths[MAX_THREADS] = {0};
int longest_string_index = 0;

pthread_mutex_t mutex;

void *read_input_string(void *thread_index) {
    int index = *(int*)thread_index;
    printf("Enter String %d: ", index+1);
    fgets(input_strings[index], sizeof(input_strings[index]), stdin);
    string_lengths[index] = strlen(input_strings[index]);
    pthread_exit(NULL);
}

void *find_longest_string(void *arg) {
    int total_strings = *(int*)arg;
    for(int i=0; i<total_strings; i++) {
        pthread_mutex_lock(&mutex);
        if(string_lengths[i] > string_lengths[longest_string_index]) {
            longest_string_index = i;
        }
        pthread_mutex_unlock(&mutex);
    }
    pthread_exit(NULL);
}

int main() {

    pthread_t threads[MAX_THREADS+1];
    pthread_attr_t attr;
    void *status;

    pthread_mutex_init(&mutex, NULL);
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

    for(int i=0; i<MAX_THREADS; i++) {
        int *thread_index = (int *)malloc(sizeof(int));
        *thread_index = i;
        pthread_create(&threads[i], &attr, read_input_string, (void *)thread_index);
    }

    int total_threads = MAX_THREADS;
    pthread_create(&threads[MAX_THREADS], &attr, find_longest_string, (void *)&total_threads);

    pthread_attr_destroy(&attr);

    for(int i=0; i<MAX_THREADS; i++) {
        pthread_join(threads[i], &status);
    }

    pthread_join(threads[MAX_THREADS], &status);

    printf("The longest string is:\n%s\n", input_strings[longest_string_index]);

    pthread_mutex_destroy(&mutex);
    pthread_exit(NULL);

    return 0;
}