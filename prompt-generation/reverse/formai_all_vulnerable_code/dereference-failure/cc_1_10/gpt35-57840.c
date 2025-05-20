//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Define a global variable for thread synchronization
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// Define a custom struct to hold thread arguments
typedef struct {
   int thread_num;
   int sleep_time;
} thread_data;

// Define the thread function
void *thread_function(void *arg) {
   // Cast the argument to the struct type
   thread_data *data = (thread_data *)arg;

   // Sleep for a random amount of time
   int random_num = rand() % 10;
   sleep(random_num + data->sleep_time + 1);

   // Lock the mutex to synchronize access to output
   pthread_mutex_lock(&mutex);

   // Display thread information and release the mutex
   printf("Thread %d slept for %d seconds\n", data->thread_num, random_num + data->sleep_time);
   pthread_mutex_unlock(&mutex);

   // Exit the thread with a status of 0
   pthread_exit(0);
}

// Define the main function
int main() {
   // Define an array to hold thread IDs and a counter variable
   pthread_t threads[5];
   int counter;

   // Seed the random number generator with the current time
   srand(time(NULL));

   // Create and start 5 threads
   for (counter = 0; counter < 5; counter++) {
      // Allocate memory for the thread data struct
      thread_data *data = (thread_data *)malloc(sizeof(thread_data));

      // Set the thread number and sleep time for this thread
      data->thread_num = counter;
      data->sleep_time = counter;

      // Create the thread and pass in the thread data as the argument
      pthread_create(&threads[counter], NULL, thread_function, (void *)data);
   }

   // Join all threads to wait for them to complete
   for (counter = 0; counter < 5; counter++) {
      pthread_join(threads[counter], NULL);
   }

   // Output completion message and exit the program with a status of 0
   printf("All threads have completed execution.\n");
   return 0;
}