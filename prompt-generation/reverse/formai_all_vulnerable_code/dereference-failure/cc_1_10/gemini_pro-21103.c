//GEMINI-pro DATASET v1.0 Category: Password management ; Style: multi-threaded
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum password length
#define MAX_PASSWORD_LENGTH 256

// Define the number of threads to use
#define NUM_THREADS 4

// Create a mutex to protect the password database
pthread_mutex_t password_mutex = PTHREAD_MUTEX_INITIALIZER;

// Create a condition variable to signal when a password has been updated
pthread_cond_t password_cond = PTHREAD_COND_INITIALIZER;

// Create an array of passwords
char *passwords[NUM_THREADS];

// Create a function to generate a random password
char *generate_password() {
  // Create a buffer to store the password
  char *password = malloc(MAX_PASSWORD_LENGTH);

  // Generate a random password
  for (int i = 0; i < MAX_PASSWORD_LENGTH; i++) {
    password[i] = (char)((rand() % 26) + 97);
  }

  // Return the password
  return password;
}

// Create a function to update the password database
void update_password(int thread_id, char *password) {
  // Lock the password database
  pthread_mutex_lock(&password_mutex);

  // Update the password
  passwords[thread_id] = password;

  // Signal that the password has been updated
  pthread_cond_signal(&password_cond);

  // Unlock the password database
  pthread_mutex_unlock(&password_mutex);
}

// Create a function to get the password for a given thread
char *get_password(int thread_id) {
  // Lock the password database
  pthread_mutex_lock(&password_mutex);

  // Wait until the password has been updated
  while (passwords[thread_id] == NULL) {
    pthread_cond_wait(&password_cond, &password_mutex);
  }

  // Get the password
  char *password = passwords[thread_id];

  // Unlock the password database
  pthread_mutex_unlock(&password_mutex);

  // Return the password
  return password;
}

// Create a function to run a thread
void *thread_function(void *arg) {
  // Get the thread ID
  int thread_id = (int)arg;

  // Generate a random password
  char *password = generate_password();

  // Update the password database
  update_password(thread_id, password);

  // Get the password from the password database
  char *password_from_database = get_password(thread_id);

  // Print the password
  printf("Thread %d: %s\n", thread_id, password_from_database);

  // Free the password
  free(password);

  // Return NULL
  return NULL;
}

// Create a function to create and run threads
void create_and_run_threads() {
  // Create an array of thread IDs
  pthread_t thread_ids[NUM_THREADS];

  // Create the threads
  for (int i = 0; i < NUM_THREADS; i++) {
    pthread_create(&thread_ids[i], NULL, thread_function, (void *)i);
  }

  // Join the threads
  for (int i = 0; i < NUM_THREADS; i++) {
    pthread_join(thread_ids[i], NULL);
  }
}

// Main function
int main() {
  // Create and run the threads
  create_and_run_threads();

  // Destroy the mutex and condition variable
  pthread_mutex_destroy(&password_mutex);
  pthread_cond_destroy(&password_cond);

  // Free the passwords
  for (int i = 0; i < NUM_THREADS; i++) {
    free(passwords[i]);
  }

  // Return 0
  return 0;
}