//FormAI DATASET v1.0 Category: Text processing ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <ctype.h>
#include <pthread.h>

// Declare lock and condition variable
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

void *to_uppercase(void *arg) {
    char *input_str = (char *) arg;
    char *output_str = (char *) calloc(strlen(input_str), sizeof(char));
    int i;

    // Obtain lock before accessing shared variables
    pthread_mutex_lock(&lock);

    for (i = 0; i < strlen(input_str); i++) {
        output_str[i] = toupper(input_str[i]);
    }

    printf("Original string: %s\n", input_str);
    printf("Uppercase string: %s\n", output_str);
    printf("\n");

    // Release lock and signal waiting threads
    pthread_mutex_unlock(&lock);
    pthread_cond_signal(&cond);

    return NULL;
}

int main() {
    char *str1 = "hello world";
    char *str2 = "apple pie";
    pthread_t tid1, tid2;

    // Create two threads to convert two strings to uppercase
    pthread_create(&tid1, NULL, to_uppercase, str1);
    pthread_create(&tid2, NULL, to_uppercase, str2);

    // Wait for both threads to finish before exiting
    pthread_mutex_lock(&lock);

    // Wait for signal from both threads
    while (pthread_cond_wait(&cond, &lock) != 0);

    pthread_mutex_unlock(&lock);

    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    return 0;
}