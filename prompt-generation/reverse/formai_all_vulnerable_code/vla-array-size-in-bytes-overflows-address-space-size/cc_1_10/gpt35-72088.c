//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: curious
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
  srand(time(NULL)); // setting the seed for rand()

  int num_processes, timer, remaining_time, total_waiting_time = 0, total_turnaround_time = 0;
  printf("Enter the number of processes: ");
  scanf("%d", &num_processes);
  
  printf("\nCPU Scheduling Algorithm: Curious-Random Scheduling\n\n");

  // creating processes with random burst time between 1 and 10
  int burst_time[num_processes], remaining_burst_time[num_processes], arrival_time[num_processes], turnaround_time[num_processes], waiting_time[num_processes], process_id[num_processes];

  for(int i = 0; i < num_processes; i++)
  {
    burst_time[i] = rand()%10 + 1;  // generating random numbers between 1 and 10
    remaining_burst_time[i] = burst_time[i];
    arrival_time[i] = rand()%10;   // generating random arrival time
    process_id[i] = i+1;
  }

  // sorting the processes based on arrival time
  for(int i = 0; i < num_processes; i++)
  {
    for(int j = i+1; j < num_processes; j++)
    {
      if(arrival_time[i] > arrival_time[j])
      {
        int temp = burst_time[i];
        burst_time[i] = burst_time[j];
        burst_time[j] = temp;

        temp = remaining_burst_time[i];
        remaining_burst_time[i] = remaining_burst_time[j];
        remaining_burst_time[j] = temp;

        temp = arrival_time[i];
        arrival_time[i] = arrival_time[j];
        arrival_time[j] = temp;

        temp = process_id[i];
        process_id[i] = process_id[j];
        process_id[j] = temp;
      }
    }
  }

  // implementing Curious-Random Scheduling Algorithm
  timer = arrival_time[0];
  int i = 0, remaining_processes = num_processes;
  while(remaining_processes > 0)
  {
    i %= num_processes;
    if(remaining_burst_time[i] > 0 && arrival_time[i] <= timer)
    {
      printf("Executing Process %d at time=%d with remaining time=%d\n", process_id[i], timer, remaining_burst_time[i]);
      remaining_time = rand()%3 + 1;  // generating random number between 1 and 3
      remaining_burst_time[i] -= remaining_time;
      timer += remaining_time;

      if(remaining_burst_time[i] == 0)
      {
        remaining_processes--;
        turnaround_time[i] = timer - arrival_time[i];
        waiting_time[i] = turnaround_time[i] - burst_time[i];
        total_turnaround_time += turnaround_time[i];
        total_waiting_time += waiting_time[i];
        printf("Process %d completed at time=%d\nTurnaround Time=%d Waiting Time=%d\n\n", process_id[i], timer, turnaround_time[i], waiting_time[i]);
      }
    }
    i++;
  }

  // calculating average waiting time and average turnaround time
  float avg_waiting_time = (float)total_waiting_time/num_processes;
  float avg_turnaround_time = (float)total_turnaround_time/num_processes;

  printf("\nAverage Waiting Time: %f\n", avg_waiting_time);
  printf("Average Turnaround Time: %f\n", avg_turnaround_time);

  return 0;
}