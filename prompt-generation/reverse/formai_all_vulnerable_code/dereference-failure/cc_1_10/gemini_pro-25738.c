//GEMINI-pro DATASET v1.0 Category: Benchmarking ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

#define MAX_SIZE 10000000
#define NUM_TRIALS 10000
#define MAX_STR_LEN 1000

// Simulates memory access patterns by generating random memory addresses
unsigned int* generate_memory_addresses(int size) {
  unsigned int* addresses = malloc(sizeof(unsigned int) * size);
  for (int i = 0; i < size; i++) {
    addresses[i] = rand() % MAX_SIZE;
  }
  return addresses;
}

// Simulates cache pollution by generating random strings and storing them in a hash table
char** generate_random_strings(int size) {
  char** strings = malloc(sizeof(char*) * size);
  for (int i = 0; i < size; i++) {
    char* str = malloc(MAX_STR_LEN);
    for (int j = 0; j < MAX_STR_LEN - 1; j++) {
      str[j] = 'a' + (rand() % 26);
    }
    str[MAX_STR_LEN - 1] = '\0';
    strings[i] = str;
  }
  return strings;
}

// Measures the time taken to access memory addresses
unsigned int measure_memory_access_time(unsigned int* addresses, int size) {
  clock_t start = clock();
  for (int i = 0; i < size; i++) {
    volatile unsigned int dummy = *(addresses + i);  // Prevent compiler optimizations
    (void)dummy;
  }
  clock_t end = clock();
  return (unsigned int)(end - start);
}

// Measures the time taken to perform cache pollution
unsigned int measure_cache_pollution_time(char** strings, int size) {
  clock_t start = clock();
  for (int i = 0; i < size; i++) {
    // Simulate cache pollution by accessing a random key in the hash table
    int index = rand() % size;
    volatile char* str = strings[index];  // Prevent compiler optimizations
    (void)str;
  }
  clock_t end = clock();
  return (unsigned int)(end - start);
}

int main(int argc, char** argv) {
  srand(time(NULL));

  // Initialize variables
  int size = 0;
  if (argc > 1) {
    size = atoi(argv[1]);
  }
  if (size <= 0) {
    printf("Error: Invalid size specified\n");
    return -1;
  }

  // Warm up the CPU
  for (int i = 0; i < NUM_TRIALS; i++) {
    unsigned int* addresses = generate_memory_addresses(size);
    char** strings = generate_random_strings(size);
    measure_memory_access_time(addresses, size);
    measure_cache_pollution_time(strings, size);
    free(addresses);
    for (int j = 0; j < size; j++) {
      free(strings[j]);
    }
    free(strings);
  }

  // Measure memory access time
  unsigned int* addresses = generate_memory_addresses(size);
  unsigned int total_memory_access_time = 0;
  for (int i = 0; i < NUM_TRIALS; i++) {
    total_memory_access_time += measure_memory_access_time(addresses, size);
  }
  free(addresses);

  // Measure cache pollution time
  char** strings = generate_random_strings(size);
  unsigned int total_cache_pollution_time = 0;
  for (int i = 0; i < NUM_TRIALS; i++) {
    total_cache_pollution_time += measure_cache_pollution_time(strings, size);
  }
  for (int j = 0; j < size; j++) {
    free(strings[j]);
  }
  free(strings);

  // Calculate and print results
  printf("Memory access time (ns): %f\n", (double)total_memory_access_time / NUM_TRIALS);
  printf("Cache pollution time (ns): %f\n", (double)total_cache_pollution_time / NUM_TRIALS);

  return 0;
}