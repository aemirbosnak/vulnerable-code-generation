//Falcon-180B DATASET v1.0 Category: System boot optimizer ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_PROCESSES 10

int main(int argc, char **argv) {
    int num_processes = 0;
    int *process_ids = malloc(MAX_PROCESSES * sizeof(int));
    int *process_statuses = malloc(MAX_PROCESSES * sizeof(int));

    while (num_processes < MAX_PROCESSES) {
        int pid = fork();

        if (pid == 0) { // Child process
            printf("Child process started with ID %d\n", getpid());
            sleep(5);
            exit(0);
        } else if (pid < 0) { // Error
            printf("Error forking process\n");
        } else { // Parent process
            process_ids[num_processes] = pid;
            process_statuses[num_processes] = 0;
            num_processes++;
        }
    }

    while (num_processes > 0) {
        int status;
        pid_t pid = waitpid(0, &status, WNOHANG);

        if (pid == -1) { // Error
            printf("Error waiting for process\n");
        } else if (pid == 0) { // No child processes have exited
            printf("No child processes have exited\n");
        } else { // Child process has exited
            int index = 0;

            for (int i = 0; i < num_processes; i++) {
                if (process_ids[i] == pid) {
                    index = i;
                    break;
                }
            }

            printf("Child process with ID %d exited with status %d\n", process_ids[index], status);

            free(process_ids[index]);
            free(process_statuses[index]);

            process_ids[index] = 0;
            process_statuses[index] = 0;

            num_processes--;
        }
    }

    return 0;
}