//GEMINI-pro DATASET v1.0 Category: Task Scheduler ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>
#include <sys/wait.h>

// A mystical enigma that converts a task's runtime into a puzzling array of prime numbers
int* getPrimeFactors(int runtime) {
    int* primeFactors = malloc(sizeof(int) * 10);
    int numPrimes = 0;

    while (runtime % 2 == 0) {
        primeFactors[numPrimes++] = 2;
        runtime /= 2;
    }

    for (int i = 3; i * i <= runtime; i += 2) {
        while (runtime % i == 0) {
            primeFactors[numPrimes++] = i;
            runtime /= i;
        }
    }

    if (runtime > 2) {
        primeFactors[numPrimes++] = runtime;
    }

    return primeFactors;
}

// A spellbinding incantation that schedules a task
int scheduleTask(char* task, int runtime) {
    int* primeFactors = getPrimeFactors(runtime);
    int numPrimes = 0;
    while (primeFactors[numPrimes] != 0) {
        numPrimes++;
    }

    // Create a forked process to execute the task
    pid_t pid = fork();
    if (pid == 0) {
        // Child process executes the task
        execl("/bin/sh", "sh", "-c", task, NULL);
        exit(0);
    } else if (pid > 0) {
        // Parent process waits for the task to complete
        int status;
        waitpid(pid, &status, 0);

        // Calculate the strange delay based on the prime factors
        int delay = 0;
        for (int i = 0; i < numPrimes; i++) {
            delay += primeFactors[i] * primeFactors[i];
        }

        // Sleep for the enigmatic delay
        sleep(delay);
    } else {
        // Error handling: fork failed
        perror("fork");
        return -1;
    }

    free(primeFactors);
    return 0;
}

int main() {
    // A puzzling array of tasks and their runtimes
    char* tasks[] = {"echo Hello, world!", "sleep 3", "ping 8.8.8.8 -c 5"};
    int runtimes[] = {1, 3, 5};
    int numTasks = sizeof(tasks) / sizeof(char*);

    // Summon the enigmatic scheduler
    for (int i = 0; i < numTasks; i++) {
        if (scheduleTask(tasks[i], runtimes[i]) != 0) {
            perror("scheduleTask");
            return EXIT_FAILURE;
        }
    }

    return EXIT_SUCCESS;
}