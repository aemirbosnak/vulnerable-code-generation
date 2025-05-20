//FormAI DATASET v1.0 Category: Interprocess communication ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <signal.h>

#define SHM_KEY 0x1234
#define SHM_SIZE 1024
#define MSG "Hello World!"

void sig_handler(int signum);

int main(void) {
    int shmid;
    char *shared_mem, *msg;
    struct sigaction action;

    // Create shared memory segment
    shmid = shmget(SHM_KEY, SHM_SIZE, IPC_CREAT | 0666);
    if (shmid < 0) {
        perror("shmget");
        exit(1);
    }

    // Attach shared memory segment
    shared_mem = shmat(shmid, NULL, 0);
    if (shared_mem == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    // Register signal handler
    action.sa_handler = sig_handler;
    sigemptyset(&action.sa_mask);
    action.sa_flags = 0;
    sigaction(SIGUSR1, &action, NULL);

    printf("Master process (PID %d) waiting for child process...\n", getpid());

    pause(); // Wait for child process to signal

    printf("Child process has signaled, writing message to shared memory...\n");

    // Write message to shared memory
    msg = MSG;
    for (int i = 0; i < sizeof(MSG); i++) {
        shared_mem[i] = msg[i];
    }

    printf("Message successfully written to shared memory\n");

    // Detach shared memory segment
    shmdt(shared_mem);

    // Wait for child process to read message
    pause();

    printf("Child process has read message, detaching shared memory segment...\n");

    // Deallocate shared memory segment
    shmctl(shmid, IPC_RMID, NULL);

    printf("Shared memory segment deallocated, exiting program\n");

    return 0;
}

void sig_handler(int signum) {
    // Child process signals parent process
    if (signum == SIGUSR1) {
        printf("Child process (PID %d) signaled parent process (PID %d)\n", getpid(), getppid());
    }
}