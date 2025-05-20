//GEMINI-pro DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

// Welcome to the labyrinth of CPU scheduling algorithms!

// Our intrepid explorers:
typedef struct Process {
  int arrival; // When they arrived at the party
  int burst;   // How long they plan to stay
  int priority; // How important they think they are
} Process;

// The party venue:
typedef struct Queue {
  Process *processes;
  int size;
} Queue;

// Some handy functions to manage our queue:
void enqueue(Queue *q, Process *p) {
  q->processes = realloc(q->processes, (q->size + 1) * sizeof(Process));
  q->processes[q->size++] = *p;
}

Process *dequeue(Queue *q) {
  if (q->size == 0) return NULL;

  Process *p = &q->processes[0];
  for (int i = 1; i < q->size; i++) {
    q->processes[i - 1] = q->processes[i];
  }
  q->size--;

  return p;
}

// Now for the algorithms that will govern the party:

// First-Come, First-Served: The old-fashioned way
void fcfs(Queue *q) {
  int waitTimes[q->size]; // How long each process waited
  int totalWait = 0;

  for (int i = 0; i < q->size; i++) {
    if (i > 0) waitTimes[i] = waitTimes[i - 1];
    waitTimes[i] += q->processes[i].burst;
    totalWait += waitTimes[i];
  }

  // Let's showcase the results:
  printf("First-Come, First-Served:\n");
  for (int i = 0; i < q->size; i++) {
    printf("Process %d: %d\n", q->processes[i].arrival, waitTimes[i]);
  }

  printf("Average wait time: %.2f\n", (double)totalWait / q->size);
}

// Shortest-Job-First: Giving priority to the quickest
void sjf(Queue *q) {
  // Sort the processes by burst time
  for (int i = 0; i < q->size; i++) {
    for (int j = i + 1; j < q->size; j++) {
      if (q->processes[i].burst > q->processes[j].burst) {
        Process temp = q->processes[i];
        q->processes[i] = q->processes[j];
        q->processes[j] = temp;
      }
    }
  }

  int waitTimes[q->size];
  int totalWait = 0;

  for (int i = 0; i < q->size; i++) {
    if (i > 0) waitTimes[i] = waitTimes[i - 1];
    waitTimes[i] += q->processes[i].burst;
    totalWait += waitTimes[i];
  }

  printf("\nShortest-Job-First:\n");
  for (int i = 0; i < q->size; i++) {
    printf("Process %d: %d\n", q->processes[i].arrival, waitTimes[i]);
  }

  printf("Average wait time: %.2f\n", (double)totalWait / q->size);
}

// Round Robin: Sharing the spotlight equally
void roundRobin(Queue *q, int quantum) {
  // Initialize some variables
  int time = 0;
  int completedProcesses = 0;

  while (completedProcesses < q->size) {
    // Loop through the processes
    for (int i = 0; i < q->size; i++) {
      // If the process has arrived and not completed, process it
      if (q->processes[i].arrival <= time && q->processes[i].burst > 0) {
        // Give the process its quantum
        int burstTime = q->processes[i].burst > quantum ? quantum : q->processes[i].burst;
        time += burstTime;
        q->processes[i].burst -= burstTime;

        // If the process is completed, remove it from the queue
        if (q->processes[i].burst == 0) {
          completedProcesses++;
          dequeue(q);
          i--;
        }
      }
    }
  }

  printf("\nRound Robin (quantum: %d):\n", quantum);
  for (int i = 0; i < q->size; i++) {
    printf("Process %d: %d\n", q->processes[i].arrival, time - q->processes[i].arrival);
  }
}

// Priority Scheduling: Treating VIPs first
void priority(Queue *q) {
  // Sort the processes by priority
  for (int i = 0; i < q->size; i++) {
    for (int j = i + 1; j < q->size; j++) {
      if (q->processes[i].priority > q->processes[j].priority) {
        Process temp = q->processes[i];
        q->processes[i] = q->processes[j];
        q->processes[j] = temp;
      }
    }
  }

  int waitTimes[q->size];
  int totalWait = 0;

  for (int i = 0; i < q->size; i++) {
    if (i > 0) waitTimes[i] = waitTimes[i - 1];
    waitTimes[i] += q->processes[i].burst;
    totalWait += waitTimes[i];
  }

  printf("\nPriority Scheduling:\n");
  for (int i = 0; i < q->size; i++) {
    printf("Process %d: %d\n", q->processes[i].arrival, waitTimes[i]);
  }

  printf("Average wait time: %.2f\n", (double)totalWait / q->size);
}

// Let's test our algorithms with some random processes:
int main() {
  Queue q;
  q.size = 5;
  q.processes = malloc(q.size * sizeof(Process));

  printf("Processes:\n");

  for (int i = 0; i < q.size; i++) {
    srand(time(NULL));
    q.processes[i].arrival = rand() % 10;
    q.processes[i].burst = rand() % 10;
    q.processes[i].priority = rand() % 5;

    printf("Process %d: %d %d %d\n", i, q.processes[i].arrival, q.processes[i].burst, q.processes[i].priority);
  }

  // Execute the algorithms:
  fcfs(&q);
  sjf(&q);
  roundRobin(&q, 3);
  priority(&q);

  return 0;
}