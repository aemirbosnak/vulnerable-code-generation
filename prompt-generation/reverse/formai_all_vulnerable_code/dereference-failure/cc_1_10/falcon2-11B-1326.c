//Falcon2-11B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: portable
#include <stdio.h>
#include <stdlib.h>

// Define a structure for the CPU Scheduling algorithm
struct SchedulingAlgorithm {
    int waitingTime;
    int burstTime;
    int arrivalTime;
};

// Define a structure for the CPU Scheduling problem
struct CPUProblem {
    struct SchedulingAlgorithm* jobs;
    int numJobs;
};

// Function to initialize the CPU Scheduling problem
struct CPUProblem initializeProblem(int numJobs, int numProcesses) {
    struct CPUProblem problem;
    problem.jobs = (struct SchedulingAlgorithm*) malloc(numJobs * sizeof(struct SchedulingAlgorithm));
    problem.numJobs = numJobs;

    for (int i = 0; i < numJobs; i++) {
        problem.jobs[i].waitingTime = 0;
        problem.jobs[i].burstTime = 0;
        problem.jobs[i].arrivalTime = i;
    }

    return problem;
}

// Function to print the CPU Scheduling problem
void printProblem(struct CPUProblem problem) {
    printf("Num jobs: %d\n", problem.numJobs);
    printf("Job # Waiting Time Burst Time Arrival Time\n");
    for (int i = 0; i < problem.numJobs; i++) {
        printf("%2d %4d %4d %4d\n", i, problem.jobs[i].waitingTime, problem.jobs[i].burstTime, problem.jobs[i].arrivalTime);
    }
}

// Function to solve the CPU Scheduling problem using First Come First Serve (FCFS) algorithm
struct SchedulingAlgorithm solveFCFS(struct CPUProblem problem) {
    struct SchedulingAlgorithm result = {0, 0, 0};
    int currentTime = 0;

    for (int i = 0; i < problem.numJobs; i++) {
        if (problem.jobs[i].arrivalTime <= currentTime) {
            result.waitingTime += currentTime - problem.jobs[i].arrivalTime;
            result.burstTime += problem.jobs[i].burstTime;
            currentTime += problem.jobs[i].burstTime;
        }
    }

    result.waitingTime += currentTime;

    return result;
}

// Function to print the result of the CPU Scheduling problem
void printResult(struct SchedulingAlgorithm result) {
    printf("Waiting Time: %d\n", result.waitingTime);
    printf("Burst Time: %d\n", result.burstTime);
}

int main() {
    int numJobs = 5;
    int numProcesses = 2;

    struct CPUProblem problem = initializeProblem(numJobs, numProcesses);
    printProblem(problem);

    struct SchedulingAlgorithm result = solveFCFS(problem);
    printResult(result);

    return 0;
}