//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: multi-threaded
#include <stdio.h>
#include <pthread.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

pthread_t threadId[2];
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void* calculatePasswordStrength(void* argument);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <password>\n", argv[0]);
        return EXIT_FAILURE;
    }
    char *password = argv[1];
    if (strlen(password) < 9) {
        printf("Password too short. Minimum 9 characters.\n");
        return EXIT_FAILURE;
    }
    for (int i = 0; i < 2; i++) {
        pthread_create(&threadId[i], NULL, &calculatePasswordStrength, password);
    }
    for (int i = 0; i < 2; i++) {
        pthread_join(threadId[i], NULL);
    }
    printf("Password strength checked.\n");
    return EXIT_SUCCESS;
}

void* calculatePasswordStrength(void* argument) {
    char *password = (char*) argument;

    bool containsDigits = false;
    bool containsSpecialChars = false;

    pthread_mutex_lock(&mutex);
    for (int i = 0; i < strlen(password); i++) {
        if (isdigit(password[i])) {
            containsDigits = true;
        } else if (!isalpha(password[i])) {
            containsSpecialChars = true;
        }
    }

    if (!containsDigits) {
        printf("Weak password. Must contain digits.\n");
    }
    if (!containsSpecialChars) {
        printf("Weak password. Must contain special characters.\n");
    }
    pthread_mutex_unlock(&mutex);
    pthread_exit(NULL);
}