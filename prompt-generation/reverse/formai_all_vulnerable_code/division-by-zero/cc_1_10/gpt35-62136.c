//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: irregular
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_PROCESS 20
#define MAX_BURST_TIME 30
#define QUANTUM 4

typedef struct Process{
    int process_id;
    int burst_time;
    int remaining_time;
    int arrival_time;
    int waiting_time;
    int response_time;
    int completion_time;
} Process;

void fcfs(Process*, const int);
void sjf(Process*, const int);
void rr(Process*, const int);

int main(){
    srand(time(0));
    Process processes[MAX_PROCESS];
    int num_processes = 0, i;

    //randomly generating processes
    num_processes = (rand() % MAX_PROCESS) + 1;
    for(i = 0; i < num_processes; i++){
        processes[i].process_id = i+1;
        processes[i].burst_time = (rand() % MAX_BURST_TIME) + 1;
        processes[i].remaining_time = processes[i].burst_time;
        processes[i].arrival_time = rand() % (num_processes/2);
    }

    //invoking the scheduling algorithms
    fcfs(processes, num_processes);
    sjf(processes, num_processes);
    rr(processes, num_processes);

    return 0;
}

void fcfs(Process* processes, const int num_processes){
    printf("\nFirst Come First Serve Scheduling\n");
    int total_waiting_time = 0, total_turnaround_time = 0;
    int i, time_elapsed = 0;

    for(i = 0; i < num_processes; i++){
        if(processes[i].arrival_time > time_elapsed){//simulation of idle CPU time
            time_elapsed = processes[i].arrival_time;
        }
        processes[i].waiting_time = time_elapsed - processes[i].arrival_time;
        processes[i].response_time = processes[i].waiting_time;
        processes[i].completion_time = time_elapsed + processes[i].burst_time;

        time_elapsed += processes[i].burst_time;
        total_waiting_time += processes[i].waiting_time;
        total_turnaround_time += (processes[i].completion_time - processes[i].arrival_time);

        printf("Process %d: Waiting time %d, Response time %d, Completion time %d\n", 
            processes[i].process_id, processes[i].waiting_time, processes[i].response_time, processes[i].completion_time);
    }
    printf("Average Waiting time: %.2f, Average Turnaround time: %.2f\n", 
        (float)total_waiting_time/num_processes, (float)total_turnaround_time/num_processes);
}

void sjf(Process* processes, const int num_processes){
    printf("\nShortest Job First Scheduling\n");
    int total_waiting_time = 0, total_turnaround_time = 0;
    int i, j, time_elapsed = 0;

    for(i = 0; i < num_processes; i++){
        int shortest_index = i;
        for(j = i; j < num_processes; j++){
            if(processes[j].arrival_time <= time_elapsed && 
                processes[j].burst_time < processes[shortest_index].burst_time){
                shortest_index = j;
            }
        }
        if(shortest_index != i){//sorting based on burst time
            Process temp = processes[i];
            processes[i] = processes[shortest_index];
            processes[shortest_index] = temp;
        }
        processes[i].waiting_time = time_elapsed - processes[i].arrival_time;
        processes[i].response_time = processes[i].waiting_time;
        processes[i].completion_time = time_elapsed + processes[i].burst_time;

        time_elapsed += processes[i].burst_time;
        total_waiting_time += processes[i].waiting_time;
        total_turnaround_time += (processes[i].completion_time - processes[i].arrival_time);

        printf("Process %d: Waiting time %d, Response time %d, Completion time %d\n",
            processes[i].process_id, processes[i].waiting_time, processes[i].response_time, processes[i].completion_time);
    }
    printf("Average Waiting time: %.2f, Average Turnaround time: %.2f\n",
        (float)total_waiting_time/num_processes, (float)total_turnaround_time/num_processes);
}

void rr(Process* processes, const int num_processes){
    printf("\nRound Robin Scheduling\n");
    int total_waiting_time = 0, total_turnaround_time = 0;
    int i, j, remaining_processes = num_processes, time_elapsed = 0;

    while(remaining_processes > 0){
        for(i = 0; i < num_processes; i++){
            if(processes[i].arrival_time <= time_elapsed && processes[i].remaining_time > 0){
                if(processes[i].remaining_time <= QUANTUM){
                    time_elapsed += processes[i].remaining_time;
                    processes[i].completion_time = time_elapsed;
                    processes[i].waiting_time = (time_elapsed - processes[i].arrival_time) - processes[i].burst_time;
                    processes[i].response_time = processes[i].waiting_time;

                    total_waiting_time += processes[i].waiting_time;
                    total_turnaround_time += processes[i].completion_time - processes[i].arrival_time;
                    processes[i].remaining_time = 0;//process is done
                    remaining_processes--;
                }
                else{
                    time_elapsed += QUANTUM;
                    processes[i].remaining_time -= QUANTUM;
                }
            }
        }
    }

    for(i = 0; i < num_processes; i++){
        printf("Process %d: Waiting time %d, Response time %d, Completion time %d\n",
            processes[i].process_id, processes[i].waiting_time, processes[i].response_time, processes[i].completion_time);
    }
    printf("Average Waiting time: %.2f, Average Turnaround time: %.2f\n",
        (float)total_waiting_time/num_processes, (float)total_turnaround_time/num_processes);
}