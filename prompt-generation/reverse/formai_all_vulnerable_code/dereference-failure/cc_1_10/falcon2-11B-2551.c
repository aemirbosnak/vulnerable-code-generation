//Falcon2-11B DATASET v1.0 Category: Palindrome Checker ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void* worker(void* arg) {
    char* string = (char*) arg;
    int length = strlen(string);
    int start = 0;
    int end = length - 1;

    while (start < end) {
        if (string[start]!= string[end]) {
            pthread_mutex_lock(&mutex);
            printf("%s is not a palindrome.\n", string);
            pthread_mutex_unlock(&mutex);
            return NULL;
        }
        start++;
        end--;
    }

    pthread_mutex_lock(&mutex);
    printf("%s is a palindrome.\n", string);
    pthread_mutex_unlock(&mutex);

    return NULL;
}

int main() {
    pthread_t threads[4];

    char* strings[] = {"madam", "racecar", "hello", "world", "bob", "civic"};
    int num_strings = sizeof(strings) / sizeof(char*);

    pthread_mutex_init(&mutex, NULL);

    for (int i = 0; i < num_strings; i++) {
        pthread_create(&threads[i], NULL, worker, (void*) strings[i]);
    }

    for (int i = 0; i < num_strings; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&mutex);

    return 0;
}