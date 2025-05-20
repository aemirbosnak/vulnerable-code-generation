//FormAI DATASET v1.0 Category: Interprocess communication ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <errno.h>

#define SHM_SIZE 1024

void parent_sig_handler(int signum);
void child_sig_handler(int signum);
void parent_read(int shmid);
void child_write(int shmid, char *msg);

int main(void)
{
    int shmid;
    key_t key;
    pid_t pid;
    char *msg;

    // Generate a key for shared memory
    key = ftok(".", 'S');
    if (key == -1) {
        perror("ftok");
        exit(1);
    }

    // Create shared memory
    shmid = shmget(key, SHM_SIZE, IPC_CREAT | IPC_EXCL | 0666);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }

    // Attach shared memory to parent process
    msg = shmat(shmid, NULL, 0);
    if (msg == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    // Set signal handlers for parent and child processes
    if (signal(SIGUSR1, parent_sig_handler) == SIG_ERR) {
        perror("signal");
        exit(1);
    }
    if (signal(SIGUSR2, child_sig_handler) == SIG_ERR) {
        perror("signal");
        exit(1);
    }

    // Fork child process
    pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(1);
    }

    if (pid == 0) { // Child process
        child_write(shmid, "Hello, parent!\n");
    } else { // Parent process
        parent_read(shmid);
    }

    // Detach and delete shared memory
    if (shmdt(msg) == -1) {
        perror("shmdt");
        exit(1);
    }
    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        perror("shmctl");
        exit(1);
    }

    return 0;
}

void parent_read(int shmid)
{
    char *msg = (char *) shmat(shmid, NULL, 0);
    printf("Parent process is waiting for message from child process...\n");
    pause();

    printf("Parent process received message from child process:\n%s", msg);
    kill(getpid(), SIGUSR1); // Signal to child process that parent is done reading

    shmdt(msg);
}

void child_write(int shmid, char *msg)
{
    char *shm = (char *) shmat(shmid, NULL, 0);
    strcpy(shm, msg);
    printf("Child process wrote message to shared memory:\n%s", shm);
    kill(getppid(), SIGUSR2); // Signal to parent process that child is done writing

    pause();
    shmdt(shm);
}

void parent_sig_handler(int signum)
{
    printf("Parent process received signal %d, exiting...\n", signum);
    exit(0);
}

void child_sig_handler(int signum)
{
    printf("Child process received signal %d, exiting...\n", signum);
    exit(0);
}