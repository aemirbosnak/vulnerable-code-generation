//GPT-4o-mini DATASET v1.0 Category: String manipulation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <ctype.h>

#define MAX_STRING_SIZE 1024
#define NUM_THREADS 3

pthread_mutex_t mutex;
char shared_string[MAX_STRING_SIZE] = "Hello, World!";

void* reverse_string(void* arg) {
    pthread_mutex_lock(&mutex);
    
    int len = strlen(shared_string);
    char* reversed = malloc(len + 1);
    
    for (int i = 0; i < len; i++) {
        reversed[i] = shared_string[len - 1 - i];
    }
    reversed[len] = '\0';
    
    printf("Reversed String: %s\n", reversed);
    pthread_mutex_unlock(&mutex);
    
    free(reversed);
    return NULL;
}

void* uppercase_string(void* arg) {
    pthread_mutex_lock(&mutex);
    
    char* uppercased = malloc(strlen(shared_string) + 1);
    for(int i = 0; shared_string[i]; i++) {
        uppercased[i] = toupper(shared_string[i]);
    }
    uppercased[strlen(shared_string)] = '\0';
    
    printf("Uppercased String: %s\n", uppercased);
    pthread_mutex_unlock(&mutex);
    
    free(uppercased);
    return NULL;
}

void* append_suffix(void* arg) {
    pthread_mutex_lock(&mutex);
    
    strcat(shared_string, " - Suffix");
    printf("Appended String: %s\n", shared_string);
    pthread_mutex_unlock(&mutex);
    
    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    pthread_mutex_init(&mutex, NULL);
    
    // Create threads to manipulate the shared string
    if (pthread_create(&threads[0], NULL, reverse_string, NULL) != 0) {
        perror("Failed to create thread for reversing string");
        return 1;
    }
    
    if (pthread_create(&threads[1], NULL, uppercase_string, NULL) != 0) {
        perror("Failed to create thread for uppercasing string");
        return 1;
    }
    
    if (pthread_create(&threads[2], NULL, append_suffix, NULL) != 0) {
        perror("Failed to create thread for appending suffix");
        return 1;
    }
    
    // Wait for all threads to complete
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
    
    pthread_mutex_destroy(&mutex);
    
    return 0;
}