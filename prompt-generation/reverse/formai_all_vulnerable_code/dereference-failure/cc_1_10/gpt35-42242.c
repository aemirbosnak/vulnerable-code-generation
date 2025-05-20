//FormAI DATASET v1.0 Category: Password management ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <pthread.h>

#define PASSWORD_MAX_LENGTH 30
#define NUM_USERS 5

// Global variables
char *passwords[NUM_USERS];
pthread_mutex_t mutex;

// Function to generate a random password
void generate_password(char *password) {
    int i;
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    for (i = 0; i < PASSWORD_MAX_LENGTH; i++) {
        password[i] = charset[rand() % (sizeof(charset) - 1)];
    }
    password[PASSWORD_MAX_LENGTH] = '\0';
}

// Function to check if a password is valid
int is_valid_password(char *password) {
    int i, has_upper = 0, has_lower = 0, has_digit = 0;
    for (i = 0; i < strlen(password); i++) {
        if (isupper(password[i])) has_upper = 1;
        if (islower(password[i])) has_lower = 1;
        if (isdigit(password[i])) has_digit = 1;
    }
    return (has_upper && has_lower && has_digit);
}

// Function for the password manager thread
void *password_manager(void *arg) {
    int i;
    for (;;) {
        // Generate a new password
        char *new_password = malloc((PASSWORD_MAX_LENGTH + 1) * sizeof(char));
        generate_password(new_password);

        // Check if the new password is valid
        while (!is_valid_password(new_password)) {
            generate_password(new_password);
        }

        // Update all users' password
        pthread_mutex_lock(&mutex);
        for (i = 0; i < NUM_USERS; i++) {
            free(passwords[i]); // Free the old password
            passwords[i] = strdup(new_password); // Set the new password
        }
        pthread_mutex_unlock(&mutex);

        printf("New password generated: %s\n", new_password);
        free(new_password);

        // Sleep for 10 seconds
        sleep(10);
    }
}

// Function for the user threads
void *user(void *arg) {
    int id = *(int *)arg;
    char *password = passwords[id];

    // Print the user's password
    printf("User %d: My password is %s\n", id, password);

    // Sleep for a random time between 1 and 5 seconds
    int sleep_time = rand() % 5 + 1;
    sleep(sleep_time);

    // Change the user's password
    pthread_mutex_lock(&mutex);
    char *new_password = malloc((PASSWORD_MAX_LENGTH + 1) * sizeof(char));
    generate_password(new_password);
    while (!is_valid_password(new_password)) {
        generate_password(new_password);
    }
    free(password);
    passwords[id] = new_password;
    pthread_mutex_unlock(&mutex);

    printf("User %d: My password has been changed to %s\n", id, new_password);
    free(new_password);

    return NULL;
}

int main(int argc, char **argv) {
    int i;
    pthread_t pm_tid, user_tids[NUM_USERS];

    // Initialize the mutex
    pthread_mutex_init(&mutex, NULL);

    // Initialize the passwords
    for (i = 0; i < NUM_USERS; i++) {
        passwords[i] = malloc((PASSWORD_MAX_LENGTH + 1) * sizeof(char));
        generate_password(passwords[i]);
    }

    // Create the password manager thread
    pthread_create(&pm_tid, NULL, password_manager, NULL);

    // Create the user threads
    int ids[NUM_USERS];
    for (i = 0; i < NUM_USERS; i++) {
        ids[i] = i;
        pthread_create(&user_tids[i], NULL, user, &ids[i]);
    }

    // Join the password manager thread
    pthread_join(pm_tid, NULL);

    // Join the user threads
    for (i = 0; i < NUM_USERS; i++) {
        pthread_join(user_tids[i], NULL);
    }

    // Free the passwords
    for (i = 0; i < NUM_USERS; i++) {
        free(passwords[i]);
    }

    // Destroy the mutex
    pthread_mutex_destroy(&mutex);

    return 0;
}