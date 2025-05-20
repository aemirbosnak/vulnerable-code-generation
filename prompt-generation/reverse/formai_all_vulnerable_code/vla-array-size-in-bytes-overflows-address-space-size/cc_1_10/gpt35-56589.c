//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: decentralized
#include <stdio.h>
#define MAX_PROCESS 10

int priority[MAX_PROCESS], burst_time[MAX_PROCESS], waiting_time[MAX_PROCESS], turnaround_time[MAX_PROCESS], at[MAX_PROCESS];
int n;

float average_waiting_time = 0, average_turnaround_time = 0;

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void bubble_sort(int arr[], int index[]) {
    for(int i=0; i<n-1; i++) {
        for(int j=0; j<n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
                swap(&index[j], &index[j+1]);
            }
        }
    }
}

void compute_waiting_time(int index[]) {
    waiting_time[0] = 0;
    for(int i=1; i<n; i++) {
        waiting_time[i] = burst_time[index[i-1]] + waiting_time[i-1];
    }
}

void compute_turnaround_time(int index[]) {
    for(int i=0; i<n; i++) {
        turnaround_time[i] = burst_time[index[i]] + waiting_time[i];
    }
}

void print_gantt_chart(int index[]) {
    printf("\n");
    for(int i=0; i<80; i++) {
        printf("-");
    }
    printf("\n|");
    for(int i=0; i<n; i++) {
        for(int j=0; j<burst_time[index[i]]; j++) {
            printf(" ");
        }
        printf("P%d", index[i]+1);
        for(int j=0; j<burst_time[index[i]]; j++) {
            printf(" ");
        }
        printf("|");
    }
    printf("\n");
    for(int i=0; i<80; i++) {
        printf("-");
    }
}

void compute_average_time(int index[]) {
    for(int i=0; i<n; i++) { 
        average_waiting_time += waiting_time[i];
        average_turnaround_time += turnaround_time[i];
    }
    average_waiting_time /= n;
    average_turnaround_time /= n;
}

void print_table(int index[]) {
    printf("\n\n");
    printf("Processes     Arrival Time     Burst time     Waiting Time     Turnaround Time\n");

    for(int i=0; i<n; i++) {
        printf("P%-13d%-17d%-15d%-18d%d\n", index[i]+1, at[index[i]], burst_time[index[i]], waiting_time[i], turnaround_time[i]);
    }

    printf("\nAverage Waiting Time: %.2f", average_waiting_time);
    printf("\nAverage Turnaround Time: %.2f\n", average_turnaround_time);
}

int main() {
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("\nEnter the arrival time, burst time and priority of each process:\n");
    for(int i=0; i<n; i++) {
        printf("Process %d: ", i+1);
        scanf("%d%d%d", &at[i], &burst_time[i], &priority[i]);
    }

    int index[n];
    for(int i=0; i<n; i++) {
        index[i] = i;
    }

    bubble_sort(at, index);
    compute_waiting_time(index);
    compute_turnaround_time(index);
    compute_average_time(index);

    print_gantt_chart(index);
    print_table(index);

    return 0;
}