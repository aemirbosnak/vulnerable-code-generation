//FormAI DATASET v1.0 Category: Interprocess communication ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE 1024 // shared memory size

int main(int argc, char *argv[])
{
    int shmid1, shmid2, status;
    key_t key1, key2; // IPC keys

    pid_t pid; // process identifier
    char *shm1, *shm2; // shared memory pointers

    char message[SHM_SIZE];
    char config_file[SHM_SIZE] = "config.txt"; // default config file name
    int delay_time = 0; // default delay time
    int i, j;

    // command-line argument parsing
    for (i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-c") == 0 && i+1 < argc) {
            strncpy(config_file, argv[i+1], sizeof(config_file));
            config_file[sizeof(config_file)-1] = '\0';
            i++;
        } else if (strcmp(argv[i], "-d") == 0 && i+1 < argc) {
            delay_time = atoi(argv[i+1]);
            i++;
        } else {
            printf("Usage: %s [-c config_file] [-d delay_time]\n", argv[0]);
            exit(EXIT_FAILURE);
        }
    }

    // get IPC keys
    if ((key1 = ftok(config_file, 'a')) == -1) {
        perror("ftok");
        exit(EXIT_FAILURE);
    }

    if ((key2 = ftok(config_file, 'b')) == -1) {
        perror("ftok");
        exit(EXIT_FAILURE);
    }

    // create shared memory segments
    if ((shmid1 = shmget(key1, SHM_SIZE, 0644 | IPC_CREAT)) == -1) {
        perror("shmget");
        exit(EXIT_FAILURE);
    }

    if ((shmid2 = shmget(key2, SHM_SIZE, 0644 | IPC_CREAT)) == -1) {
        perror("shmget");
        exit(EXIT_FAILURE);
    }

    // attach shared memory segments
    if ((shm1 = shmat(shmid1, NULL, 0)) == (char *) -1) {
        perror("shmat");
        exit(EXIT_FAILURE);
    }

    if ((shm2 = shmat(shmid2, NULL, 0)) == (char *) -1) {
        perror("shmat");
        exit(EXIT_FAILURE);
    }

    // initialize shared memory segments
    memset(shm1, 0, SHM_SIZE);
    memset(shm2, 0, SHM_SIZE);

    // fork child process
    if ((pid = fork()) == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) { // child process
        printf("Child process %d started\n", getpid());

        // read message from shared memory
        while (strncmp(shm1, "exit", 4)) {
            if (strncmp(shm1, "dummy", 5)) {
                printf("Child process %d received message: %s\n", getpid(), shm1);
            }

            sleep(delay_time);
        }

        printf("Child process %d exiting\n", getpid());

        // detach shared memory segments
        if (shmdt(shm1) == -1) {
            perror("shmdt");
            exit(EXIT_FAILURE);
        }

        if (shmdt(shm2) == -1) {
            perror("shmdt");
            exit(EXIT_FAILURE);
        }

        exit(EXIT_SUCCESS);
    } else { // parent process
        printf("Parent process %d started\n", getpid());

        // write message to shared memory
        for (j = 0; j < 5; j++) {
            sprintf(message, "Message #%d from parent process %d", j+1, getpid());

            strncpy(shm1, message, SHM_SIZE);
            printf("Parent process %d sent message: %s\n", getpid(), message);

            sleep(delay_time);
        }

        // signal child process to exit
        strncpy(shm1, "exit", 4);

        // wait for child process to exit
        wait(&status);
        printf("Parent process %d waited for child process %d to exit\n", getpid(), pid);

        // detach shared memory segments
        if (shmdt(shm1) == -1) {
            perror("shmdt");
            exit(EXIT_FAILURE);
        }

        if (shmdt(shm2) == -1) {
            perror("shmdt");
            exit(EXIT_FAILURE);
        }

        // delete shared memory segments
        if (shmctl(shmid1, IPC_RMID, NULL) == -1) {
            perror("shmctl");
            exit(EXIT_FAILURE);
        }

        if (shmctl(shmid2, IPC_RMID, NULL) == -1) {
            perror("shmctl");
            exit(EXIT_FAILURE);
        }

        printf("Parent process %d exiting\n", getpid());
        exit(EXIT_SUCCESS);
    }

    return 0;
}