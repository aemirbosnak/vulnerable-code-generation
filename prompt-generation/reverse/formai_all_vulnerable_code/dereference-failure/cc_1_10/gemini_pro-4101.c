//GEMINI-pro DATASET v1.0 Category: Password management ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

// Structure to store a password
typedef struct password {
    char *username;
    char *password;
} password;

// Mutex to protect shared data
pthread_mutex_t mutex;

// Array of passwords
password *passwords;

// Number of passwords
int num_passwords;

// Thread function to add a password
void *add_password(void *args) {
    // Get the password to add
    password *new_password = (password *)args;

    // Lock the mutex
    pthread_mutex_lock(&mutex);

    // Add the password to the array
    passwords = realloc(passwords, (num_passwords + 1) * sizeof(password));
    passwords[num_passwords] = *new_password;
    num_passwords++;

    // Unlock the mutex
    pthread_mutex_unlock(&mutex);

    return NULL;
}

// Thread function to get a password
void *get_password(void *args) {
    // Get the username of the password to get
    char *username = (char *)args;

    // Lock the mutex
    pthread_mutex_lock(&mutex);

    // Find the password with the given username
    int i;
    for (i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            // Return the password
            return &passwords[i].password;
        }
    }

    // Unlock the mutex
    pthread_mutex_unlock(&mutex);

    // Return NULL if the password was not found
    return NULL;
}

// Thread function to delete a password
void *delete_password(void *args) {
    // Get the username of the password to delete
    char *username = (char *)args;

    // Lock the mutex
    pthread_mutex_lock(&mutex);

    // Find the password with the given username
    int i;
    for (i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            // Delete the password
            free(passwords[i].username);
            free(passwords[i].password);
            passwords[i] = passwords[num_passwords - 1];
            num_passwords--;
            break;
        }
    }

    // Unlock the mutex
    pthread_mutex_unlock(&mutex);

    return NULL;
}

int main() {
    // Initialize the mutex
    pthread_mutex_init(&mutex, NULL);

    // Initialize the array of passwords
    passwords = malloc(0);
    num_passwords = 0;

    // Create a thread to add a password
    pthread_t add_thread;
    password new_password;
    new_password.username = "bob";
    new_password.password = "password";
    pthread_create(&add_thread, NULL, add_password, &new_password);

    // Create a thread to get a password
    pthread_t get_thread;
    char *username = "bob";
    pthread_create(&get_thread, NULL, get_password, username);

    // Create a thread to delete a password
    pthread_t delete_thread;
    username = "bob";
    pthread_create(&delete_thread, NULL, delete_password, username);

    // Join the threads
    pthread_join(add_thread, NULL);
    char *password = (char *)pthread_join(get_thread, NULL);
    pthread_join(delete_thread, NULL);

    // Print the password
    printf("Password for %s: %s\n", username, password);

    // Free the array of passwords
    free(passwords);

    // Destroy the mutex
    pthread_mutex_destroy(&mutex);

    return 0;
}