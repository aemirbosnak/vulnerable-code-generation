//GEMINI-pro DATASET v1.0 Category: Performance-Critical Component ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// A data structure to represent a single-thread
struct thread {
  int tid;                 // Thread ID
  int *local_array;       // Thread-local array
  clock_t start_time;      // Start time of the thread
  clock_t end_time;        // End time of the thread
  unsigned long long sum;  // Sum of the array elements
};

// A data structure to represent the shared data
struct shared_data {
  int *array;      // Array to be updated by threads
  int num_threads;  // Number of threads
  int num_elements;  // Number of elements in the array
  int num_updates;  // Number of updates per thread
};

// Initialize the shared data
void init_shared_data(struct shared_data *sd, int num_threads, int num_elements, int num_updates) {
  sd->num_threads = num_threads;
  sd->num_elements = num_elements;
  sd->num_updates = num_updates;
  sd->array = (int *)malloc(sizeof(int) * num_elements);
  for (int i = 0; i < num_elements; i++) {
    sd->array[i] = rand() % 100;
  }
}

// Initialize a thread
void init_thread(struct thread *t, int tid, struct shared_data *sd) {
  t->tid = tid;
  t->local_array = (int *)malloc(sizeof(int) * sd->num_elements);
  for (int i = 0; i < sd->num_elements; i++) {
    t->local_array[i] = sd->array[i];
  }
  t->start_time = clock();
  t->end_time = 0;
  t->sum = 0;
}

// Run the thread
void run_thread(struct thread *t, struct shared_data *sd) {
  for (int i = 0; i < sd->num_updates; i++) {
    int idx = rand() % sd->num_elements;
    t->local_array[idx] = rand() % 100;
  }
  for (int i = 0; i < sd->num_elements; i++) {
    t->sum += t->local_array[i];
  }
  t->end_time = clock();
}

// Join the thread
void join_thread(struct thread *t) {
  while (t->end_time == 0) {
    // Busy wait until the thread finishes
  }
}

// Update the shared data
void update_shared_data(struct shared_data *sd, struct thread *t) {
  for (int i = 0; i < sd->num_elements; i++) {
    sd->array[i] = t->local_array[i];
  }
}

// Print the results
void print_results(struct thread *t, int num_threads, struct shared_data *sd) {
  printf("Thread %d:\n", t->tid);
  printf("  Start time: %ld\n", t->start_time);
  printf("  End time: %ld\n", t->end_time);
  printf("  Sum: %llu\n\n", t->sum);

  printf("Shared data:\n");
  for (int i = 0; i < sd->num_elements; i++) {
    printf("  a[%d] = %d\n", i, sd->array[i]);
  }
}

// Main function
int main() {
  const int num_threads = 4;
  const int num_elements = 1000000;
  const int num_updates = 10000;

  // Initialize the random number generator
  srand(time(NULL));

  // Initialize the shared data
  struct shared_data sd;
  init_shared_data(&sd, num_threads, num_elements, num_updates);

  // Initialize the threads
  struct thread threads[num_threads];
  for (int i = 0; i < num_threads; i++) {
    init_thread(&threads[i], i, &sd);
  }

  // Run the threads
  for (int i = 0; i < num_threads; i++) {
    run_thread(&threads[i], &sd);
  }

  // Join the threads
  for (int i = 0; i < num_threads; i++) {
    join_thread(&threads[i]);
  }

  // Update the shared data
  for (int i = 0; i < num_threads; i++) {
    update_shared_data(&sd, &threads[i]);
  }

  // Print the results
  for (int i = 0; i < num_threads; i++) {
    print_results(&threads[i], num_threads, &sd);
  }

  return 0;
}