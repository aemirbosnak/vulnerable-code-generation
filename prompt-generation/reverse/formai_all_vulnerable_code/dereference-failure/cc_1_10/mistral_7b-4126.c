//MISTRAL-7B DATASET v1.0 Category: System process viewer ; Style: romantic
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <signal.h>

#define SHM_KEY 0x1234
#define MAX_PROC 256
#define PROC_NAME_LEN 32

typedef struct {
    pid_t pid;
    char name[PROC_NAME_LEN];
} proc_t;

volatile sig_atomic_t running = 1;

void signal_handler(int sig) {
    running = 0;
}

int main() {
    int shmid;
    proc_t *shm_data;

    sigset_t mask;
    sigemptyset(&mask);
    sigaddset(&mask, SIGTERM);

    shmid = shmget(SHM_KEY, sizeof(proc_t) * MAX_PROC, 0666 | IPC_CREAT);
    if (shmid == -1) {
        perror("shmget failed");
        return 1;
    }

    shm_data = (proc_t *)shmget(SHM_KEY, sizeof(proc_t) * MAX_PROC, 0);
    if (!shm_data) {
        perror("shmget failed");
        shmctl(shmid, IPC_RMID, 0);
        return 1;
    }

    signal(SIGTERM, signal_handler);

    printf("\n%s\n", "Once upon a time in a far-off land, there existed a magical process viewer...");
    fflush(stdout);

    while (running) {
        int i;
        for (i = 0; i < MAX_PROC; i++) {
            if (shm_data[i].pid == 0) {
                pid_t child_pid = fork();

                if (child_pid == 0) {
                    char cmd[64];
                    snprintf(cmd, sizeof(cmd), "/usr/bin/ps -p %d -o pid,comm --no-headers", getppid());
                    FILE *ps_file = popen(cmd, "r");
                    fgets(shm_data[i].name, sizeof(shm_data[i].name), ps_file);
                    shm_data[i].name[strlen(shm_data[i].name) - 1] = '\0';
                    pclose(ps_file);
                    shm_data[i].pid = getppid();
                    printf("\n%s: %s", "A new process was born!", shm_data[i].name);
                    fflush(stdout);
                    break;
                } else if (child_pid > 0) {
                    shm_data[i].pid = child_pid;
                }
            }
            sleep(1);
        }
    }

    shmdt(shm_data);
    shmctl(shmid, IPC_RMID, 0);

    printf("\n%s\n", "And so, the magical process viewer continued to watch over the land...");

    return 0;
}