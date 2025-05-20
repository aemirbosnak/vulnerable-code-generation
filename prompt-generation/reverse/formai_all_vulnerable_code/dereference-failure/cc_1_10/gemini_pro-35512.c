//GEMINI-pro DATASET v1.0 Category: Automated Fortune Teller ; Style: multi-threaded
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

// Structure to store the fortune
typedef struct {
  char *fortune;
  int length;
} Fortune;

// Array of fortunes
const char *fortunes[] = {
  "You will have a long and happy life.",
  "You will be rich and famous.",
  "You will find true love.",
  "You will travel the world.",
  "You will make a difference in the world.",
  "You will be a great success.",
  "You will be a great leader.",
  "You will be a great teacher.",
  "You will be a great healer.",
  "You will be a great artist."
};

// Function to get a random fortune
Fortune *get_fortune() {
  // Get a random number
  int random = rand() % 10;

  // Allocate memory for the fortune
  Fortune *fortune = malloc(sizeof(Fortune));

  // Copy the fortune to the allocated memory
  fortune->fortune = fortunes[random];
  fortune->length = strlen(fortunes[random]);

  // Return the fortune
  return fortune;
}

// Function to print a fortune
void print_fortune(Fortune *fortune) {
  // Print the fortune
  printf("%s\n", fortune->fortune);

  // Free the memory allocated for the fortune
  free(fortune);
}

// Function to run the fortune teller
void *run_fortune_teller(void *arg) {
  // Get a random fortune
  Fortune *fortune = get_fortune();

  // Print the fortune
  print_fortune(fortune);

  // Return NULL to indicate that the thread has finished
  return NULL;
}

// Main function
int main() {
  // Initialize the random number generator
  srand(time(NULL));

  // Create a thread pool
  pthread_t thread_pool[10];

  // Create the threads
  for (int i = 0; i < 10; i++) {
    pthread_create(&thread_pool[i], NULL, run_fortune_teller, NULL);
  }

  // Join the threads
  for (int i = 0; i < 10; i++) {
    pthread_join(thread_pool[i], NULL);
  }

  // Return 0 to indicate that the program has finished successfully
  return 0;
}