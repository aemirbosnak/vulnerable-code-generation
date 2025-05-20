//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: optimized
#include<stdio.h>
#include<stdlib.h>

struct Process {
    int pid;
    int arrival_time;
    int burst_time;
    int waiting_time;
    int turnaround_time;
    int remaining_time; 
};

struct Process* create_process(int pid, int arrival_time, int burst_time) {
  struct Process* process = (struct Process*) malloc(sizeof(struct Process));
  process->pid = pid;
  process->arrival_time = arrival_time;
  process->burst_time = burst_time;
  process->waiting_time = 0;
  process->turnaround_time = 0;
  process->remaining_time = burst_time;  
  return process;  
}

void print_processes(struct Process** processes, int num_processes) {
  printf("Process\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");

  int total_waiting_time = 0;
  int total_turnaround_time = 0;

  for (int i=0; i<num_processes; i++) {
    printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", processes[i]->pid, processes[i]->arrival_time, processes[i]->burst_time, processes[i]->waiting_time, processes[i]->turnaround_time);
    total_waiting_time += processes[i]->waiting_time;
    total_turnaround_time += processes[i]->turnaround_time;
  }
  
  printf("\nAverage Waiting Time: %.2f\n", (float)total_waiting_time / (float)num_processes);
  printf("Average Turnaround Time: %.2f\n", (float)total_turnaround_time / (float)num_processes);  
}

void swap(struct Process** a, struct Process** b) {
  struct Process* t = *a;
  *a = *b;
  *b = t;
}

void sort_processes(struct Process** processes, int num_processes) {
  for (int i=0; i<num_processes-1; i++) {
    for (int j=0; j<num_processes-i-1; j++) {
      if (processes[j]->arrival_time > processes[j+1]->arrival_time) {
        swap(&processes[j], &processes[j+1]);
      }
    }
  }
}

void round_robin(struct Process** processes, int num_processes, int quantum_time) {
  sort_processes(processes, num_processes);
  
  int completed_processes = 0;
  int current_time = 0;
  int* remaining_times = (int*) malloc(num_processes * sizeof(int));
  
  for (int i=0; i<num_processes; i++) {
    remaining_times[i] = processes[i]->burst_time;
  }
  
  while (completed_processes < num_processes) {
    for (int i=0; i<num_processes; i++) {
      if (remaining_times[i] > 0 && processes[i]->arrival_time <= current_time) {
        if (remaining_times[i] <= quantum_time) {
          current_time += remaining_times[i];
          processes[i]->waiting_time = current_time - processes[i]->burst_time - processes[i]->arrival_time;
          remaining_times[i] = 0;
          completed_processes++;
          processes[i]->turnaround_time = processes[i]->waiting_time + processes[i]->burst_time;
        } else {
          current_time += quantum_time;
          remaining_times[i] -= quantum_time;
        }
      }
    }
  }

  print_processes(processes, num_processes);
}

int main() {
  int num_processes = 4;
  int quantum_time = 2;
  
  struct Process* process_1 = create_process(1, 0, 5);
  struct Process* process_2 = create_process(2, 1, 3);
  struct Process* process_3 = create_process(3, 2, 7);
  struct Process* process_4 = create_process(4, 3, 4);

  struct Process* processes[] = {process_1, process_2, process_3, process_4};

  round_robin(processes, num_processes, quantum_time);

  return 0;
}