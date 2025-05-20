//LLAMA2-13B DATASET v1.0 Category: Benchmarking ; Style: curious
#include <stdio.h>
#include <time.h>

int main() {
  int kittens = 10;
  int puppies = 5;
  int pizzas = 20;
  int candles = 100;

  printf("Welcome to the Great Benchmarking Adventure! Let's start with some basic math...\n");

  clock_t start, end;

  start = clock();
  for (int i = 0; i < kittens; i++) {
    int x = 42 / i;
    if (x > pizzas) {
      x = pizzas;
    }
    if (x > candles) {
      x = candles;
    }
    printf("Kittens love to play with %d toys! %d x %d = %d\n", i, x, x, x * i);
    if (x == pizzas) {
      printf("Ooh, pizza party! %d pizzas for everyone!\n", x);
    }
  }

  end = clock();
  double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
  printf("Time taken: %fs\n", time_taken);

  start = clock();

  for (int i = 0; i < puppies; i++) {
    int x = 42 / i;
    if (x > pizzas) {
      x = pizzas;
    }
    if (x > candles) {
      x = candles;
    }
    printf("Puppies love to play with %d toys! %d x %d = %d\n", i, x, x, x * i);
    if (x == pizzas) {
      printf("Ooh, pizza party! %d pizzas for everyone!\n", x);
    }
  }

  end = clock();
  time_taken = (double)(end - start) / CLOCKS_PER_SEC;
  printf("Time taken: %fs\n", time_taken);

  return 0;
}