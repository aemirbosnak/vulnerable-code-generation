//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: future-proof
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define NUM_PROCESSORS 4
#define MAX_QUEUE_SIZE 10

typedef struct process {
  int id;
  char name[20];
  int arrival_time;
  int service_time;
  int remaining_time;
  struct process* next;
} process;

process* create_process(int id, char* name, int arrival_time, int service_time) {
  process* new_process = malloc(sizeof(process));
  new_process->id = id;
  strcpy(new_process->name, name);
  new_process->arrival_time = arrival_time;
  new_process->service_time = service_time;
  new_process->remaining_time = service_time;
  new_process->next = NULL;
  return new_process;
}

void add_process(process** head, process* new_process) {
  if (*head == NULL) {
    *head = new_process;
  } else {
    (*head)->next = new_process;
  }
}

int main() {
  srand(time(NULL));
  process* head = NULL;

  // Create a few processes
  process* process1 = create_process(1, "Process A", 0, 5);
  process* process2 = create_process(2, "Process B", 2, 3);
  process* process3 = create_process(3, "Process C", 4, 4);
  process* process4 = create_process(4, "Process D", 6, 2);

  // Add processes to the queue
  add_process(&head, process1);
  add_process(&head, process2);
  add_process(&head, process3);
  add_process(&head, process4);

  // Simulate CPU scheduling
  for (int i = 0; i < 10; i++) {
    // Get the process with the smallest remaining time
    process* current_process = head;
    for (process* process = head; process->next != NULL; process = process->next) {
      if (current_process->remaining_time > process->remaining_time) {
        current_process = process;
      }
    }

    // Reduce the remaining time of the current process
    current_process->remaining_time--;

    // Print the name of the current process
    printf("Process: %s\n", current_process->name);
  }

  return 0;
}