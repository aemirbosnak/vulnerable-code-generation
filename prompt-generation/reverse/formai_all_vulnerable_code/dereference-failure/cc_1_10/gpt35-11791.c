//FormAI DATASET v1.0 Category: Benchmarking ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000000

struct Person {
  char *name;
  int age;
  float height;
};

typedef struct Person Person;

int main() {

  // Create an array of Person struct pointers
  Person **people = (Person **) malloc(SIZE * sizeof(Person *));
  int i;

  // Measure time to allocate all struct memory
  clock_t start_all = clock();

  for (i = 0; i < SIZE; i++) {
    people[i] = (Person *) malloc(sizeof(Person));
    people[i]->name = "John Doe";
    people[i]->age = 30;
    people[i]->height = 6.0;
  }

  clock_t end_all = clock();

  printf("Time to allocate all Person structs: %f seconds\n",
         (float)(end_all - start_all) / CLOCKS_PER_SEC);

  // Measure time to only insert values into struct fields
  clock_t start_fields = clock();

  for (i = 0; i < SIZE; i++) {
    people[i]->name = "Jane Doe";
    people[i]->age = 40;
    people[i]->height = 5.5;
  }

  clock_t end_fields = clock();

  printf("Time to insert values into Person fields only: %f seconds\n",
         (float)(end_fields - start_fields) / CLOCKS_PER_SEC);

  // Free all struct memory
  clock_t start_free = clock();

  for (i = 0; i < SIZE; i++) {
    free(people[i]);
  }

  clock_t end_free = clock();

  printf("Time to free all Person structs: %f seconds\n",
         (float)(end_free - start_free) / CLOCKS_PER_SEC);

  // Free the array of struct pointers
  free(people);

  return 0;
}