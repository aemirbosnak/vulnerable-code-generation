//GEMINI-pro DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

struct fib_sequence {
  unsigned long long int a;
  unsigned long long int b;
};

struct fib_sequence calculate_fib(unsigned int n) {
  struct fib_sequence fib = {0, 1};
  for (unsigned int i = 0; i < n; i++) {
    unsigned long long int temp = fib.a;
    fib.a = fib.a + fib.b;
    fib.b = temp;
  }
  return fib;
}

void* fib_sequence_generator(void* arg) {
  struct fib_sequence fib = {0, 1};
  unsigned int n = *(unsigned int*)arg;
  while (fib.a < n) {
    printf("%llu ", fib.a);
    unsigned long long int temp = fib.a;
    fib.a = fib.a + fib.b;
    fib.b = temp;
  }
  printf("\n");
  return NULL;
}

void fib_sequence_visualizer(unsigned int n, unsigned int threads) {
  pthread_t* threads_handles = (pthread_t*)calloc(threads, sizeof(pthread_t));
  for (unsigned int i = 0; i < threads; i++) {
    unsigned int n_per_thread = n / threads;
    pthread_create(&threads_handles[i], NULL, fib_sequence_generator,
                     &(n_per_thread));
  }
  for (unsigned int i = 0; i < threads; i++) {
    pthread_join(threads_handles[i], NULL);
  }
  free(threads_handles);
}

int main() {
  unsigned int n, threads;
  printf("Enter the number of Fibonacci terms to generate: ");
  scanf("%u", &n);
  printf("Enter the number of threads to use: ");
  scanf("%u", &threads);
  fib_sequence_visualizer(n, threads);
  return 0;
}