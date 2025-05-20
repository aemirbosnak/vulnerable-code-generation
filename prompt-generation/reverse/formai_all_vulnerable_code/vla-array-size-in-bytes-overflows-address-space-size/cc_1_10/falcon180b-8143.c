//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_TASKS 100
#define INF 1000000

typedef struct {
    int id;
    int start_time;
    int end_time;
    int duration;
    int priority;
} Task;

int compare(const void *a, const void *b) {
    Task *task1 = (Task *)a;
    Task *task2 = (Task *)b;
    if (task1->priority > task2->priority)
        return 1;
    else if (task1->priority < task2->priority)
        return -1;
    else
        return 0;
}

void schedule(Task tasks[], int n) {
    qsort(tasks, n, sizeof(Task), compare);
    int current_task = 0;
    int current_time = 0;
    while (current_task < n) {
        if (tasks[current_task].start_time <= current_time) {
            if (tasks[current_task].end_time > current_time)
                current_time = tasks[current_task].end_time;
            else
                current_time = tasks[current_task].start_time + tasks[current_task].duration;
            current_task++;
        } else {
            current_time++;
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    Task tasks[n];
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d %d", &tasks[i].id, &tasks[i].start_time, &tasks[i].end_time, &tasks[i].duration);
        tasks[i].priority = rand() % 100;
    }
    schedule(tasks, n);
    for (int i = 0; i < n; i++) {
        printf("%d ", tasks[i].id);
    }
    return 0;
}