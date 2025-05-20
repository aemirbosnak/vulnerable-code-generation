//FormAI DATASET v1.0 Category: Interprocess communication ; Style: accurate
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHMSIZE 27

int main()
{
    int shmid;
    key_t key;
    char *shm, *s;

    key = 5678;

    if ((shmid = shmget(key, SHMSIZE, IPC_CREAT | 0666)) < 0) {
        perror("shmget");
        exit(1);
    }

    if ((shm = shmat(shmid, NULL, 0)) == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    s = shm;

    for (char c = 'A'; c <= 'Z'; c++) {
        *s++ = c;
    }
    *s = '\0';

    while (*shm != '*') {
        sleep(1);
    }

    for (s = shm; *s != '\0'; s++) {
        putchar(*s);
    }
    putchar('\n');

    *shm = '*';

    if (shmdt(shm) == -1) {
        perror("shmdt");
        exit(1);
    }

    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        perror("shmctl");
        exit(1);
    }

    return 0;
}