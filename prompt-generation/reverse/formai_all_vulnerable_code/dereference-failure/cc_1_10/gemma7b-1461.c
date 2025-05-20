//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSORS 8
#define MAX_QUEUE_SIZE 10

typedef struct Process {
  int id;
  int arrival_time;
  int service_time;
  struct Process* next;
} Process;

void simulate_cpu_scheduling() {
  // Create a list of processes
  Process* head = NULL;
  Process* tail = NULL;

  // Generate random arrival and service times for each process
  for (int i = 0; i < MAX_PROCESSORS; i++) {
    Process* new_process = malloc(sizeof(Process));
    new_process->id = i;
    new_process->arrival_time = rand() % MAX_QUEUE_SIZE;
    new_process->service_time = rand() % MAX_QUEUE_SIZE;

    if (head == NULL) {
      head = new_process;
      tail = new_process;
    } else {
      tail->next = new_process;
      tail = new_process;
    }
  }

  // Simulate the CPU scheduling algorithm
  time_t start_time = time(NULL);
  while (!head->next) {
    Process* current_process = head;
    int time_spent = 0;

    // Calculate the time spent by the process
    while (time_spent < current_process->service_time) {
      time_spent++;
      sleep(1);
    }

    // Print the process ID and the time spent
    printf("Process ID: %d, Time Spent: %d\n", current_process->id, time_spent);

    // Remove the process from the queue
    head = current_process->next;
  }

  time_t end_time = time(NULL);
  printf("Total Time: %d\n", end_time - start_time);
}

int main() {
  simulate_cpu_scheduling();

  return 0;
}