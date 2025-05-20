//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Shape-Shifting CPU Scheduling Algorithm

// Function Prototypes
void fcfs(int *bt, int n);
void sjf(int *bt, int n);
void rr(int *bt, int n);

int main() {
    // Initialize Variables
    int n, *bt;
    srand(time(NULL));
    
    // Prompt User for Input
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    bt = (int *) malloc(sizeof(int) * n);
    
    // Generate Random Burst Times for Each Process
    for (int i = 0; i < n; i++) {
        bt[i] = rand() % 51 + 1;
    }
    
    // Display Generated Burst Times
    printf("Generated Burst Times:\n");
    for (int i = 0; i < n; i++) {
        printf("P%d: %d\n", i + 1, bt[i]);
    }
    
    // Execute First-Come, First-Serve Algorithm
    printf("Executing First-Come, First-Serve Algorithm...\n");
    fcfs(bt, n);
    
    // Execute Shortest-Job-First Algorithm
    printf("\nExecuting Shortest-Job-First Algorithm...\n");
    sjf(bt, n);
    
    // Execute Round-Robin Algorithm
    printf("\nExecuting Round-Robin Algorithm...\n");
    rr(bt, n);
    
    return 0;
}

void fcfs(int *bt, int n) {
    // Initialize Variables
    int wt = 0, tat = 0;
    
    // Calculate Waiting Time and Turnaround Time for Each Process
    for (int i = 0; i < n; i++) {
        wt += bt[i];
        tat += wt + bt[i];
    }
    
    // Display Results
    printf("First-Come, First-Serve Algorithm:\n");
    printf("Average Waiting Time: %.2f\n", (float) wt / n);
    printf("Average Turnaround Time: %.2f\n", (float) tat / n);
}

void sjf(int *bt, int n) {
    // Initialize Variables
    int *bt_copy = (int *) malloc(sizeof(int) * n);
    float wt = 0, tat = 0;
    
    // Copy Burst Times to Temporary Array
    for (int i = 0; i < n; i++) {
        bt_copy[i] = bt[i];
    }
    
    // Sort Burst Times in Ascending Order
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (bt_copy[j] > bt_copy[j + 1]) {
                int temp = bt_copy[j];
                bt_copy[j] = bt_copy[j + 1];
                bt_copy[j + 1] = temp;
            }
        }
    }
    
    // Calculate Waiting Time and Turnaround Time for Each Process
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (bt_copy[i] == bt[j]) {
                wt += bt_copy[i];
                tat += wt + bt_copy[i];
                break;
            }
        }
    }
    
    // Display Results
    printf("Shortest-Job-First Algorithm:\n");
    printf("Average Waiting Time: %.2f\n", (float) wt / n);
    printf("Average Turnaround Time: %.2f\n", (float) tat / n);
    
    // Free Dynamically Allocated Memory
    free(bt_copy);
}

void rr(int *bt, int n) {
    // Initialize Variables
    int *bt_copy = (int *) malloc(sizeof(int) * n);
    int quantum = 5, *wt = (int *) malloc(sizeof(int) * n), *tat = (int *) malloc(sizeof(int) * n);
    int total_wt = 0, total_tat = 0, *rt = (int *) malloc(sizeof(int) * n);
    int t = 0, done = 0;
    
    // Copy Burst Times to Temporary Array
    for (int i = 0; i < n; i++) {
        bt_copy[i] = bt[i];
        rt[i] = bt_copy[i];
    }
    
    // Execute Round-Robin Algorithm
    while (1) {
        done = 1;
        
        for (int i = 0; i < n; i++) {
            if (rt[i] > 0) {
                done = 0;
                
                if (rt[i] > quantum) {
                    t += quantum;
                    rt[i] -= quantum;
                } else {
                    t += rt[i];
                    tat[i] = t;
                    rt[i] = 0;
                }
            }
        }
        
        if (done == 1) {
            break;
        }
    }
    
    // Calculate Waiting Time for Each Process
    for (int i = 0; i < n; i++) {
        wt[i] = tat[i] - bt[i];
        total_wt += wt[i];
        total_tat += tat[i];
    }
    
    // Display Results
    printf("Round-Robin Algorithm:\n");
    printf("Average Waiting Time: %.2f\n", (float) total_wt / n);
    printf("Average Turnaround Time: %.2f\n", (float) total_tat / n);
    
    // Free Dynamically Allocated Memory
    free(bt_copy);
    free(wt);
    free(tat);
    free(rt);
}