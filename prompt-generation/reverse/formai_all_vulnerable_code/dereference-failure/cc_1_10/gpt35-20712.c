//FormAI DATASET v1.0 Category: Interprocess communication ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

#define MAX_PIPES 3
#define MAX_WORKERS 4

int num_workers = 0;
int num_pipes = 0;

pid_t workers[MAX_WORKERS];
int pipes[MAX_PIPES][2];

void worker_process(int worker_id)
{
    int result;
    char buffer[256];

    close(pipes[worker_id][0]);

    printf("Worker %d started\n", worker_id);

    // Read from pipe
    result = read(pipes[worker_id][1], buffer, sizeof(buffer));
    if (result > 0) {
        printf("Worker %d received: %s\n", worker_id, buffer);
    }

    // Write to pipe
    sprintf(buffer, "Worker %d processed data", worker_id);
    write(pipes[worker_id][1], buffer, strlen(buffer) + 1);

    printf("Worker %d finished\n", worker_id);

    close(pipes[worker_id][1]);
    exit(0);
}

void spawn_worker_processes()
{
    int i;

    for (i = 0; i < num_workers; i++) {
        if ((workers[i] = fork()) == 0) {
            worker_process(i);
        }
    }
}

void cleanup_worker_processes()
{
    int i, status;

    for (i = 0; i < num_workers; i++) {
        kill(workers[i], SIGTERM);
        waitpid(workers[i], &status, 0);
    }
}

int main()
{
    int i, result;
    char buffer[256];

    // Create pipes
    for (i = 0; i < num_pipes; i++) {
        result = pipe(pipes[i]);
        if (result != 0) {
            printf("Failed to create pipe %d\n", i);
            return 1;
        }
    }

    // Spawn worker processes
    num_workers = num_pipes;
    spawn_worker_processes();

    // Write data to pipe
    sprintf(buffer, "Hello from main process");
    result = write(pipes[0][0], buffer, strlen(buffer) + 1);
    if (result != -1) {
        printf("Main process sent: %s\n", buffer);
    }

    // Read data from pipe
    result = read(pipes[0][1], buffer, sizeof(buffer));
    if (result != -1) {
        printf("Main process received: %s\n", buffer);
    }

    // Cleanup worker processes and pipes
    cleanup_worker_processes();
    for (i = 0; i < num_pipes; i++) {
        close(pipes[i][0]);
        close(pipes[i][1]);
    }

    return 0;
}