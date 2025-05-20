//GEMINI-pro DATASET v1.0 Category: Greedy Algorithms ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

typedef struct Job {
    int id;
    int deadline;
    int profit;
} Job;

int compare(const void *a, const void *b) {
    Job *j1 = (Job *)a;
    Job *j2 = (Job *)b;
    return j2->profit - j1->profit;
}

int main() {
    int n;
    scanf("%d", &n);

    Job jobs[n];

    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &jobs[i].id, &jobs[i].deadline, &jobs[i].profit);
    }

    qsort(jobs, n, sizeof(Job), compare);

    int time_slots[n];
    for (int i = 0; i < n; i++) {
        time_slots[i] = 0;
    }

    int profit = 0;
    for (int i = 0; i < n; i++) {
        int j = jobs[i].deadline - 1;
        while (j >= 0 && time_slots[j] != 0) {
            j--;
        }

        if (j >= 0) {
            time_slots[j] = jobs[i].id;
            profit += jobs[i].profit;
        }
    }

    printf("Maximum profit: %d\n", profit);
    printf("Jobs scheduled:\n");
    for (int i = 0; i < n; i++) {
        if (time_slots[i] != 0) {
            printf("%d ", time_slots[i]);
        }
    }
    printf("\n");

    return 0;
}