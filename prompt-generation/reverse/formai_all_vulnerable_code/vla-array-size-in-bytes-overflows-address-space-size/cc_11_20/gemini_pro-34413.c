//GEMINI-pro DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

#define ARR_LEN(arr) (int)(sizeof(arr) / sizeof(arr[0]))

typedef struct {
    int at, bt, ct, tat, wt, pri, rem;
} process;

int main() {
    int n, i, k, total_time, x;
    float avg_tat, avg_wt;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    process arr[n];
    printf("Enter the arrival time, burst time, and priority of each process:\n");
    for (i = 0; i < n; i++) {
        printf("Process %d:\n", i + 1);
        printf("Arrival Time: ");
        scanf("%d", &arr[i].at);
        printf("Burst Time: ");
        scanf("%d", &arr[i].bt);
        printf("Priority: ");
        scanf("%d", &arr[i].pri);
        arr[i].rem = arr[i].bt;
    }
    for (i = 0; i < n; i++) {
        for (k = i + 1; k < n; k++) {
            if (arr[i].pri < arr[k].pri) {
                process temp = arr[i];
                arr[i] = arr[k];
                arr[k] = temp;
            }
        }
    }
    total_time = 0;
    for (i = 0; i < n; i++) {
        if (arr[i].at > total_time) {
            total_time = arr[i].at;
        }
    }
    while (total_time != 0) {
        x = -1;
        for (i = 0; i < n; i++) {
            if (arr[i].rem > 0 && arr[i].at <= total_time) {
                if (x == -1 || arr[i].pri > arr[x].pri) {
                    x = i;
                }
            }
        }
        if (x != -1) {
            arr[x].rem -= 1;
            total_time += 1;
            if (arr[x].rem == 0) {
                arr[x].ct = total_time;
                arr[x].tat = arr[x].ct - arr[x].at;
                arr[x].wt = arr[x].tat - arr[x].bt;
                total_time -= arr[x].bt;
            }
        } else {
            total_time += 1;
        }
    }
    avg_tat = 0;
    avg_wt = 0;
    printf("Process | Arrival Time | Burst Time | Completion Time | Turnaround Time | Waiting Time\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, arr[i].at, arr[i].bt, arr[i].ct, arr[i].tat, arr[i].wt);
        avg_tat += arr[i].tat;
        avg_wt += arr[i].wt;
    }
    avg_tat /= n;
    avg_wt /= n;
    printf("Average Turnaround Time: %.2f\n", avg_tat);
    printf("Average Waiting Time: %.2f\n", avg_wt);
    return 0;
}