//FormAI DATASET v1.0 Category: Interprocess communication ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE 1024

int main(void) {
    int shmid;
    char *shm, *s;

    key_t key = ftok("shmfile", 'R');
    if (key == -1) {
        perror("ftok");
        exit(EXIT_FAILURE);
    }

    shmid = shmget(key, SHM_SIZE, 0666 | IPC_CREAT);
    if (shmid == -1) {
        perror("shmget");
        exit(EXIT_FAILURE);
    }

    shm = shmat(shmid, NULL, 0);
    if (shm == (char *)-1) {
        perror("shmat");
        exit(EXIT_FAILURE);
    }

    s = shm;

    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        /* Child process */
        for (s = shm; *s != '\0'; s++)
            putchar(toupper(*s));
        putchar('\n');

        *shm = '*';

        exit(EXIT_SUCCESS);
    } else {
        /* Parent process */
        printf("Enter some text: ");
        fgets(s, SHM_SIZE, stdin);

        *shm = '!';

        wait(NULL);

        printf("Result: ");
        for (s = shm; *s != '\0'; s++)
            putchar(*s);
        putchar('\n');

        if (shmdt(shm) == -1) {
            perror("shmdt");
            exit(EXIT_FAILURE);
        }

        if (shmctl(shmid, IPC_RMID, NULL) == -1) {
            perror("shmctl");
            exit(EXIT_FAILURE);
        }

        exit(EXIT_SUCCESS);
    }
}