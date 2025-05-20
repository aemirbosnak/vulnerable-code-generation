//Falcon2-11B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#define MAX_THREADS 10
#define MAX_JOB_TIME 100
typedef struct {
    int id;
    int arrivalTime;
    int burstTime;
    int cpuTime;
    int completionTime;
} job;
pthread_mutex_t mutex;
int numThreads;
int numJobs;
int jobArray[MAX_THREADS][3];
int jobCompletionTimes[MAX_THREADS];
int numActiveJobs;
int numCompletedJobs;
int totalJobTime;
int totalCpuTime;
int numCompletedJobs = 0;
int numActiveJobs = 0;
int numThreads = 0;
int totalJobTime = 0;
int totalCpuTime = 0;
void* threadFunction(void* arg) {
    int id = *((int*)arg);
    int arrivalTime = jobArray[id][0];
    int burstTime = jobArray[id][1];
    int cpuTime = jobArray[id][2];
    int completionTime;
    pthread_mutex_lock(&mutex);
    completionTime = arrivalTime + burstTime;
    jobCompletionTimes[id] = completionTime;
    numActiveJobs--;
    if (numActiveJobs == 0) {
        numCompletedJobs++;
        totalJobTime += completionTime;
        totalCpuTime += cpuTime;
    }
    pthread_mutex_unlock(&mutex);
    return NULL;
}
void printResults() {
    printf("Number of jobs: %d\n", numJobs);
    printf("Number of completed jobs: %d\n", numCompletedJobs);
    printf("Average completion time: %d\n", totalJobTime / numCompletedJobs);
    printf("Average CPU utilization: %d\n", totalCpuTime / totalJobTime);
}
int main() {
    srand(time(NULL));
    int i, j;
    int numJobs = 10;
    for (i = 0; i < numJobs; i++) {
        int jobId = rand() % numThreads;
        int arrivalTime = rand() % 100;
        int burstTime = rand() % 100;
        jobArray[jobId][0] = jobId;
        jobArray[jobId][1] = arrivalTime;
        jobArray[jobId][2] = burstTime;
        numActiveJobs++;
    }
    for (i = 0; i < numThreads; i++) {
        jobArray[i][2] = jobArray[i][1] + jobArray[i][2];
        totalCpuTime += jobArray[i][2];
    }
    for (i = 0; i < numThreads; i++) {
        jobArray[i][2] = jobArray[i][1] + jobArray[i][2];
        totalCpuTime += jobArray[i][2];
    }
    pthread_t threads[numThreads];
    pthread_mutex_init(&mutex, NULL);
    for (i = 0; i < numThreads; i++) {
        pthread_create(&threads[i], NULL, threadFunction, &(jobArray[i][0]));
    }
    for (i = 0; i < numThreads; i++) {
        pthread_join(threads[i], NULL);
    }
    printResults();
    return 0;
}