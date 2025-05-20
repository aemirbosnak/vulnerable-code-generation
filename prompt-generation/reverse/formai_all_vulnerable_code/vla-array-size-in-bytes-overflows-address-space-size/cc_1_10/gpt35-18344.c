//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Ken Thompson
#include<stdio.h>
#define MAX 100

struct process {
  int pid;
  int burst_time;
  int wait_time;
  int turnaround_time;
};

void sort_arrival_time(struct process p[], int n) {
  int i, j;
  struct process temp;
  for(i = 0; i < n - 1; i++) {
    for(j = 0; j < n - i - 1; j++) {
      if(p[j].pid > p[j+1].pid) {
        temp = p[j];
        p[j] = p[j+1];
        p[j+1] = temp;
      }
    }
  }
}

void sort_burst_time(struct process p[], int n) {
  int i, j;
  struct process temp;
  for(i = 0; i < n - 1; i++) {
    for(j = 0; j < n - i - 1; j++) {
      if(p[j].burst_time > p[j+1].burst_time) {
        temp = p[j];
        p[j] = p[j+1];
        p[j+1] = temp;
      }
    }
  }
}

void fcfs(struct process p[], int n) {
  int i;
  p[0].wait_time = 0;
  p[0].turnaround_time = p[0].burst_time;
  for(i = 1; i < n; i++) {
    p[i].wait_time = p[i-1].wait_time + p[i-1].burst_time;
    p[i].turnaround_time = p[i].wait_time + p[i].burst_time;
  }
  printf("\nFCFS Scheduling:\n");
  printf("Process ID\tBurst Time\tWaiting Time\tTurnaround Time\n");
  for(i = 0; i < n; i++) {
    printf("%d\t\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].burst_time, p[i].wait_time, p[i].turnaround_time);
  }
}

void sjf(struct process p[], int n) {
  int i;
  p[0].wait_time = 0;
  p[0].turnaround_time = p[0].burst_time;
  for(i = 1; i < n; i++) {
    p[i].wait_time = p[i-1].wait_time + p[i-1].burst_time;
    p[i].turnaround_time = p[i].wait_time + p[i].burst_time;
  }
  float avg_wait_time = 0, avg_turnaround_time = 0;
  for(i = 0; i < n; i++) {
    avg_wait_time += p[i].wait_time;
    avg_turnaround_time += p[i].turnaround_time;
  }
  avg_wait_time /= n;
  avg_turnaround_time /= n;
  printf("\nSJF Scheduling:\n");
  printf("Process ID\tBurst Time\tWaiting Time\tTurnaround Time\n");
  for(i = 0; i < n; i++) {
    printf("%d\t\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].burst_time, p[i].wait_time, p[i].turnaround_time);
  }
  printf("Average Waiting Time: %.2f\n", avg_wait_time);
  printf("Average Turnaround Time: %.2f\n", avg_turnaround_time);
}

void round_robin(struct process p[], int n, int quantum) {
  int i, j, remaining_time[n];
  for(i = 0; i < n; i++) {
    remaining_time[i] = p[i].burst_time;
  }
  int time = 0;
  while(1) {
    int flag = 1;
    for(i = 0; i < n; i++) {
      if(remaining_time[i] > 0) {
        flag = 0;
        if(remaining_time[i] > quantum) {
          time += quantum;
          remaining_time[i] -= quantum;
        }
        else {
          time += remaining_time[i];
          p[i].wait_time = time - p[i].burst_time;
          remaining_time[i] = 0;
        }
      }
    }
    if(flag == 1) {
      break;
    }
  }
  for(i = 0; i < n; i++) {
    p[i].turnaround_time = p[i].burst_time + p[i].wait_time;
  }
  float avg_wait_time = 0, avg_turnaround_time = 0;
  printf("\nRound Robin Scheduling:\n");
  printf("Process ID\tBurst Time\tWaiting Time\tTurnaround Time\n");
  for(i = 0; i < n; i++) {
    avg_wait_time += p[i].wait_time;
    avg_turnaround_time += p[i].turnaround_time;
    printf("%d\t\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].burst_time, p[i].wait_time, p[i].turnaround_time);
  }
  avg_wait_time /= n;
  avg_turnaround_time /= n;
  printf("Average Waiting Time: %.2f\n", avg_wait_time);
  printf("Average Turnaround Time: %.2f\n", avg_turnaround_time);
}

int main() {
  int i, n, quantum;
  struct process p[MAX];
  printf("Enter the number of processes: ");
  scanf("%d", &n);
  for(i = 0; i < n; i++) {
    printf("Enter the burst time of process %d: ", i+1);
    scanf("%d", &p[i].burst_time);
    p[i].pid = i+1;
  }
  printf("Enter the quantum time for Round Robin Scheduling: ");
  scanf("%d", &quantum);
  sort_arrival_time(p, n);
  fcfs(p, n);
  sort_burst_time(p, n);
  sjf(p, n);
  round_robin(p, n, quantum);
  return 0;
}