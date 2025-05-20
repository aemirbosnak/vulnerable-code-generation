//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_PROCESSES 10

struct process {
  int id;
  int arrival_time;
  int burst_time;
  int priority;
  int waiting_time;
  int turnaround_time;
};

void roundrobin(struct process* processes, int n, int quantum);
void fcfs(struct process* processes, int n);
void sjf(struct process* processes, int n);
void priority(struct process* processes, int n);
void print_results(struct process* processes, int n);

int main() {
  int n, i, algorithm, quantum;
  struct process processes[MAX_PROCESSES];
  
  printf("Enter the number of processes (maximum %d): ", MAX_PROCESSES);
  scanf("%d", &n);
  
  if (n > MAX_PROCESSES) {
    printf("Error: too many processes.\n");
    return 1;
  }
  
  for (i = 0; i < n; i++) {
    printf("Enter arrival time of process %d: ", i);
    scanf("%d", &processes[i].arrival_time);
    printf("Enter burst time of process %d: ", i);
    scanf("%d", &processes[i].burst_time);
    printf("Enter priority of process %d: ", i);
    scanf("%d", &processes[i].priority);
    processes[i].id = i;
  }
  
  printf("Choose a scheduling algorithm:\n");
  printf("1. Round Robin\n");
  printf("2. First-Come First-Serve\n");
  printf("3. Shortest Job First\n");
  printf("4. Priority\n");
  scanf("%d", &algorithm);
  
  switch (algorithm) {
    case 1:
      printf("Enter time quantum: ");
      scanf("%d", &quantum);
      roundrobin(processes, n, quantum);
      break;
    case 2:
      fcfs(processes, n);
      break;
    case 3:
      sjf(processes, n);
      break;
    case 4:
      priority(processes, n);
      break;
    default:
      printf("Error: invalid algorithm.\n");
      return 1;
  }
  
  print_results(processes, n);
  
  return 0;
}

void roundrobin(struct process* processes, int n, int quantum) {
  int i, total_time = 0, remaining_time[n];
  bool done = false;
  
  for (i = 0; i < n; i++) {
    remaining_time[i] = processes[i].burst_time;
    total_time += processes[i].burst_time;
  }
  
  while (!done) {
    done = true;
    
    for (i = 0; i < n; i++) {
      if (remaining_time[i] > 0) {
        if (remaining_time[i] > quantum) {
          total_time += quantum;
          remaining_time[i] -= quantum;
        } else {
          total_time += remaining_time[i];
          processes[i].turnaround_time = total_time - processes[i].arrival_time;
          processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;
          remaining_time[i] = 0;
        }
        
        done = false;
      }
    }
  }
}

void fcfs(struct process* processes, int n) {
  int i, total_time = 0;
  
  for (i = 0; i < n; i++) {
    processes[i].waiting_time = total_time - processes[i].arrival_time;
    processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
    total_time += processes[i].burst_time;
  }
}

void sjf(struct process* processes, int n) {
  int i, j, min_index;
  
  for (i = 0; i < n; i++) {
    min_index = i;
    
    for (j = i + 1; j < n; j++) {
      if (processes[j].burst_time < processes[min_index].burst_time)
        min_index = j;
    }
    
    if (min_index != i) {
      struct process temp = processes[i];
      processes[i] = processes[min_index];
      processes[min_index] = temp;
    }
  }
  
  fcfs(processes, n);
}

void priority(struct process* processes, int n) {
  int i, j, min_index;
  
  for (i = 0; i < n; i++) {
    min_index = i;
    
    for (j = i + 1; j < n; j++) {
      if (processes[j].priority < processes[min_index].priority)
        min_index = j;
    }
    
    if (min_index != i) {
      struct process temp = processes[i];
      processes[i] = processes[min_index];
      processes[min_index] = temp;
    }
  }
  
  fcfs(processes, n);
}

void print_results(struct process* processes, int n) {
  int i;
  
  printf("Process\tArrival Time\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");
  
  for (i = 0; i < n; i++) {
    printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].id, processes[i].arrival_time,
           processes[i].burst_time, processes[i].priority, processes[i].waiting_time, processes[i].turnaround_time);
  }
}