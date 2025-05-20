//FormAI DATASET v1.0 Category: Interprocess communication ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>

#define SHM_SIZE 1024  // size of shared memory

int main(void) {
    int shmid, status;
    key_t key;
    pid_t pid;
    char *shm, *s;
    char str1[] = "Hello";
    char str2[] = "World";
    char str3[] = "from";
    char str4[] = "the";
    char str5[] = "child";

    // generate key for shared memory
    if ((key = ftok(".", 'R')) == -1) {
        perror("ftok");
        exit(1);
    }

    // create shared memory segment
    if ((shmid = shmget(key, SHM_SIZE, 0644 | IPC_CREAT)) == -1) {
        perror("shmget");
        exit(1);
    }

    // attach shared memory segment
    if ((shm = shmat(shmid, NULL, 0)) == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    // start child process
    switch(pid = fork()) {
        case -1:  // error
            perror("fork");
            exit(1);
            break;
        case 0:  // child process
            strcat(strcat(strcat(strcat(strcat(shm, str1), " "), str3), " "), str5);  // write to shared memory
            exit(0);
            break;
        default:  // parent process
            wait(&status);
            if (WIFEXITED(status)) {  // check if child exited normally
                for (s = shm; *s != '\0'; s++)  // read from shared memory
                    putchar(*s);
                putchar('\n');
                shmdt(shm);  // detach shared memory segment
                shmctl(shmid, IPC_RMID, NULL);  // delete shared memory segment
            }
            break;
    }

    return 0;
}