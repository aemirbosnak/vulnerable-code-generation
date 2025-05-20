//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <stdbool.h>

// Define a prime number check function
bool is_prime(int num) {
  if (num <= 1) return false;
  if (num <= 3) return true;

  if (num % 2 == 0 || num % 3 == 0) return false;

  for (int i = 5; i * i <= num; i = i + 6)
      if (num % i == 0 || num % (i + 2) == 0)
         return false;

  return true;
}

// Define a thread function to generate prime numbers
void* generate_prime_numbers(void* arg) {
  printf("Generating prime numbers...\n");
  int limit = *(int*)arg;
  
  for (int num = 2; num <= limit; num++) {
    if (is_prime(num)) printf("%d, ", num);
    usleep(100);
  }
  
  printf("\nPrime numbers generated.\n");
  pthread_exit(NULL);
}

// Main function to launch the generator thread
int main(int argc, char* argv[]) {
  if (argc < 2) {
    printf("Usage: primegen <max_num>\n");
    exit(1);
  }

  int limit = atoi(argv[1]);

  // Create a thread for prime number generation
  pthread_t tid;
  pthread_attr_t attr;
  pthread_attr_init(&attr);
  pthread_create(&tid, &attr, generate_prime_numbers, &limit);

  // Wait for the thread to complete
  pthread_join(tid, NULL);

  printf("Program terminated.\n");
  exit(0);
}