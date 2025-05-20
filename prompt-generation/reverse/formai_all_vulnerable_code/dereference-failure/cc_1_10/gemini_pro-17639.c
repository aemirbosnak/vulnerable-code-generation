//GEMINI-pro DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: random
/* 🏃 C CPU Scheduling Algorithms 🏃

In the realm of CPUs, where processes dance and cycles tick,
We'll conjure up four algorithms, a programmer's trick!

Let's define our players, each with a unique trait,
Process, CPU, time slice, and a whole lotta wait. */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
  int arrivalTime;
  int burstTime;
  int processID;
} Process;

/* FCFS: First-Come, First-Served

A simple soul, this algorithm,
Processes line up, like dancers in a rhythm.
No fancy tricks, just patience and time,
First in the queue, their execution climbs. */

float fcfs(Process *processes, int numProcesses) {
  float avgWaitingTime = 0.0;
  float avgTurnaroundTime = 0.0;

  for (int i = 0; i < numProcesses; i++) {
    if (i > 0) {
      avgWaitingTime += processes[i].arrivalTime - processes[i - 1].arrivalTime;
    }
    avgTurnaroundTime += processes[i].burstTime + avgWaitingTime;
  }

  avgWaitingTime /= numProcesses;
  avgTurnaroundTime /= numProcesses;

  return avgWaitingTime + avgTurnaroundTime;
}

/* SJF: Shortest Job First

A clever algorithm, it seeks the shortest task,
Prioritizing speed, like a supersonic blast.
Processes with small bursts get the CPU's nod,
Minimizing waiting time, like a magic wand! */

float sjf(Process *processes, int numProcesses) {
  float avgWaitingTime = 0.0;
  float avgTurnaroundTime = 0.0;

  for (int i = 0; i < numProcesses; i++) {
    int minIndex = i;
    for (int j = i + 1; j < numProcesses; j++) {
      if (processes[j].burstTime < processes[minIndex].burstTime) {
        minIndex = j;
      }
    }

    Process temp = processes[i];
    processes[i] = processes[minIndex];
    processes[minIndex] = temp;
  }

  for (int i = 0; i < numProcesses; i++) {
    if (i > 0) {
      avgWaitingTime += processes[i].arrivalTime - processes[i - 1].arrivalTime;
    }
    avgTurnaroundTime += processes[i].burstTime + avgWaitingTime;
  }

  avgWaitingTime /= numProcesses;
  avgTurnaroundTime /= numProcesses;

  return avgWaitingTime + avgTurnaroundTime;
}

/* RR: Round Robin

A fair algorithm, a time-slicing delight,
Processes get their turn, like a dance in the night.
A quantum of time, then pass the CPU's baton,
Ensuring no process gets left out, like a forgotten pawn. */

float rr(Process *processes, int numProcesses, int quantum) {
  float avgWaitingTime = 0.0;
  float avgTurnaroundTime = 0.0;
  int time = 0;

  int *remainingTime = malloc(sizeof(int) * numProcesses);
  for (int i = 0; i < numProcesses; i++) {
    remainingTime[i] = processes[i].burstTime;
  }

  while (1) {
    int completed = 0;
    for (int i = 0; i < numProcesses; i++) {
      if (remainingTime[i] <= 0) {
        completed++;
        continue;
      }

      if (quantum > remainingTime[i]) {
        time += remainingTime[i];
        avgWaitingTime += time - processes[i].arrivalTime - processes[i].burstTime;
        remainingTime[i] = 0;
        avgTurnaroundTime += time - processes[i].arrivalTime;
      } else {
        time += quantum;
        avgWaitingTime += time - processes[i].arrivalTime - processes[i].burstTime;
        remainingTime[i] -= quantum;
      }
    }

    if (completed == numProcesses) {
      break;
    }
  }

  avgWaitingTime /= numProcesses;
  avgTurnaroundTime /= numProcesses;

  free(remainingTime);

  return avgWaitingTime + avgTurnaroundTime;
}

/* A-SJF: Average Shortest Job First

A cunning algorithm, it predicts the best,
Using burst time averages, putting processes to the test.
It estimates remaining time, a clever ruse,
Prioritizing processes with the smallest average juice. */

float asjf(Process *processes, int numProcesses) {
  float avgWaitingTime = 0.0;
  float avgTurnaroundTime = 0.0;
  int time = 0;

  for (int i = 0; i < numProcesses; i++) {
    processes[i].arrivalTime = time;
    time += processes[i].burstTime;
  }

  float avgBurstTime = 0.0;
  for (int i = 0; i < numProcesses; i++) {
    avgBurstTime += processes[i].burstTime;
  }
  avgBurstTime /= numProcesses;

  for (int i = 0; i < numProcesses; i++) {
    processes[i].burstTime = processes[i].burstTime / avgBurstTime;
  }

  for (int i = 0; i < numProcesses; i++) {
    int minIndex = i;
    for (int j = i + 1; j < numProcesses; j++) {
      if (processes[j].burstTime < processes[minIndex].burstTime) {
        minIndex = j;
      }
    }

    Process temp = processes[i];
    processes[i] = processes[minIndex];
    processes[minIndex] = temp;
  }

  for (int i = 0; i < numProcesses; i++) {
    if (i > 0) {
      avgWaitingTime += processes[i].arrivalTime - processes[i - 1].arrivalTime;
    }
    avgTurnaroundTime += processes[i].burstTime + avgWaitingTime;
  }

  avgWaitingTime /= numProcesses;
  avgTurnaroundTime /= numProcesses;

  return avgWaitingTime + avgTurnaroundTime;
}

int main() {
  /* Let's create a batch of processes, a whimsical band,
  With random arrival times and burst times, hand in hand. */

  srand(time(NULL));
  int numProcesses = rand() % 10 + 1;
  Process processes[numProcesses];

  for (int i = 0; i < numProcesses; i++) {
    processes[i].arrivalTime = rand() % 10;
    processes[i].burstTime = rand() % 10 + 1;
    processes[i].processID = i + 1;
  }

  /* Now, let's unleash the algorithms, a wondrous sight,
  And calculate the metrics, bringing knowledge to light. */

  float fcfsAvg = fcfs(processes, numProcesses);
  float sjfAvg = sjf(processes, numProcesses);
  float rrAvg = rr(processes, numProcesses, 5);
  float asjfAvg = asjf(processes, numProcesses);

  /* Time to unveil the results, a captivating show,
  Displaying the metrics, letting the numbers glow. */

  printf("Algorithm    Average Waiting Time + Average Turnaround Time\n");
  printf("FCFS        %.2f\n", fcfsAvg);
  printf("SJF         %.2f\n", sjfAvg);
  printf("RR          %.2f\n", rrAvg);
  printf("A-SJF       %.2f\n", asjfAvg);

  return 0;
}