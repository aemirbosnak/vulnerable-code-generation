//Falcon2-11B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct job {
    int arrival_time;
    int burst_time;
    int priority;
} Job;

typedef struct {
    Job* jobs;
    int size;
    int capacity;
    int head;
    int tail;
} JobQueue;

void enqueue(JobQueue* q, Job job) {
    if (q->size == q->capacity) {
        printf("Job queue is full\n");
        return;
    }
    q->jobs[q->tail] = job;
    q->tail = (q->tail + 1) % q->capacity;
    q->size++;
}

Job dequeue(JobQueue* q) {
    if (q->size == 0) {
        printf("Job queue is empty\n");
        return (Job){0, 0, 0};
    }
    Job job = q->jobs[q->head];
    q->head = (q->head + 1) % q->capacity;
    q->size--;
    return job;
}

void print_jobs(JobQueue* q) {
    printf("Job queue: ");
    for (int i = 0; i < q->capacity; i++) {
        Job job = q->jobs[i];
        printf("%d ", job.priority);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));
    JobQueue q = {NULL, 0, 10, 0, 0};

    Job job1 = {0, 3, 2};
    Job job2 = {5, 4, 1};
    Job job3 = {7, 2, 3};

    enqueue(&q, job1);
    enqueue(&q, job2);
    enqueue(&q, job3);

    print_jobs(&q);

    while (q.size > 0) {
        Job job = dequeue(&q);
        printf("Executing job %d with priority %d\n", job.arrival_time, job.priority);
        printf("Job burst time: %d\n", job.burst_time);
        printf("Job arrival time: %d\n", job.arrival_time);
        printf("Job priority: %d\n", job.priority);

        int sleep_time = rand() % 5;
        sleep(sleep_time);

        enqueue(&q, job);

        print_jobs(&q);
    }

    return 0;
}