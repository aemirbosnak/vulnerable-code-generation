//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: introspective
#include<stdio.h>
#include<stdlib.h>

typedef struct process{
    int pid;    //process ID
    int arrivalTime;    //process arrival time
    int burstTime;  //process burst time
    int priority;   //process priority
    int remainingTime;  //remaining burst time
    int waitingTime;    //time process spends waiting
    int turnaroundTime; //time for process to complete
} Process;

void FCFS(Process *procs, int numProcs){
    int waitTime=0, turnTime=0;
    printf("\nFCFS CPU Scheduling Algorithm\n");
    for(int i=0; i<numProcs; i++){
        printf("Process ID: %d\n", procs[i].pid);
        printf("Arrival Time: %d\n", procs[i].arrivalTime);
        printf("Burst Time: %d\n", procs[i].burstTime);
        
        if(waitTime<procs[i].arrivalTime){
            waitTime = procs[i].arrivalTime;
        }
        
        procs[i].waitingTime = waitTime - procs[i].arrivalTime;
        waitTime += procs[i].burstTime;
        procs[i].turnaroundTime = procs[i].waitingTime + procs[i].burstTime;
        
        turnTime += procs[i].turnaroundTime;
        
        printf("Waiting Time: %d\n", procs[i].waitingTime);
        printf("Turnaround Time: %d\n", procs[i].turnaroundTime);
    }
    printf("\nAverage Waiting Time: %.2f\n", (float)turnTime/numProcs);
    printf("Average Turnaround Time: %.2f\n", (float)waitTime/numProcs);
}

void SJF(Process *procs, int numProcs){
    int waitTime=0, turnTime=0;
    Process temp;
    printf("\nSJF CPU Scheduling Algorithm\n");
    
    for(int i=0; i<numProcs; i++){
        for(int j=i+1; j<numProcs; j++){
            if(procs[i].burstTime > procs[j].burstTime){
                temp = procs[i];
                procs[i] = procs[j];
                procs[j] = temp;
            }
        }
    }
    
    for(int i=0; i<numProcs; i++){
        printf("Process ID: %d\n", procs[i].pid);
        printf("Arrival Time: %d\n", procs[i].arrivalTime);
        printf("Burst Time: %d\n", procs[i].burstTime);
        
        if(waitTime<procs[i].arrivalTime){
            waitTime = procs[i].arrivalTime;
        }
        
        procs[i].waitingTime = waitTime - procs[i].arrivalTime;
        waitTime += procs[i].burstTime;
        procs[i].turnaroundTime = procs[i].waitingTime + procs[i].burstTime;
        
        turnTime += procs[i].turnaroundTime;
        
        printf("Waiting Time: %d\n", procs[i].waitingTime);
        printf("Turnaround Time: %d\n", procs[i].turnaroundTime);
    }
    printf("\nAverage Waiting Time: %.2f\n", (float)turnTime/numProcs);
    printf("Average Turnaround Time: %.2f\n", (float)waitTime/numProcs);
}

void priorityScheduling(Process *procs, int numProcs){
    int totalBurstTime=0, waitTime=0, turnTime=0;
    Process temp;
    printf("\nPriority CPU Scheduling Algorithm\n");
    
    for(int i=0; i<numProcs; i++){
        totalBurstTime += procs[i].burstTime;
    }
    
    for(int i=0; i<numProcs; i++){
        for(int j=i+1; j<numProcs; j++){
            if(procs[i].priority > procs[j].priority){
                temp = procs[i];
                procs[i] = procs[j];
                procs[j] = temp;
            }
        }
    }
    
    for(int i=0; i<totalBurstTime; i++){
        int selectedProc = 0;
        int highestPriority = -1;
        
        for(int j=0; j<numProcs; j++){
            if(procs[j].arrivalTime <= i && procs[j].remainingTime > 0 && procs[j].priority > highestPriority){
                selectedProc = j;
                highestPriority = procs[j].priority;
            }
        }
        
        procs[selectedProc].remainingTime--;
        
        if(procs[selectedProc].remainingTime == 0){
            procs[selectedProc].turnaroundTime = i + 1 - procs[selectedProc].arrivalTime;
            procs[selectedProc].waitingTime = procs[selectedProc].turnaroundTime - procs[selectedProc].burstTime;
            turnTime += procs[selectedProc].turnaroundTime;
            waitTime += procs[selectedProc].waitingTime;
        }
    }
    
    for(int i=0; i<numProcs; i++){
        printf("Process ID: %d\n", procs[i].pid);
        printf("Arrival Time: %d\n", procs[i].arrivalTime);
        printf("Burst Time: %d\n", procs[i].burstTime);
        printf("Priority: %d\n", procs[i].priority);
        printf("Waiting Time: %d\n", procs[i].waitingTime);
        printf("Turnaround Time: %d\n", procs[i].turnaroundTime);
    }
    
    printf("\nAverage Waiting Time: %.2f\n", (float)waitTime/numProcs);
    printf("Average Turnaround Time: %.2f\n", (float)turnTime/numProcs);
}

int main(){
    printf("CPU Scheduling Algorithms\n");
    int numProcs;
    printf("Enter the number of processes: ");
    scanf("%d", &numProcs);
    
    Process *procs = malloc(numProcs*sizeof(Process));
    
    for(int i=0; i<numProcs; i++){
        printf("\nProcess %d\n", i+1);
        printf("Enter Arrival Time: ");
        scanf("%d", &procs[i].arrivalTime);
        printf("Enter Burst Time: ");
        scanf("%d", &procs[i].burstTime);
        printf("Enter Priority: ");
        scanf("%d", &procs[i].priority);
        procs[i].pid = i+1;
        procs[i].remainingTime = procs[i].burstTime;
        procs[i].waitingTime = 0;
        procs[i].turnaroundTime = 0;
    }
    
    FCFS(procs, numProcs);
    SJF(procs, numProcs);
    priorityScheduling(procs, numProcs);
    
    free(procs);
    return 0;
}