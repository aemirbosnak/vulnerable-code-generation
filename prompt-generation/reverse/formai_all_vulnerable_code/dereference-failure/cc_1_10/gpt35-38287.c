//FormAI DATASET v1.0 Category: Interprocess communication ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>

#define SHMKEY 123456
#define SHMSZ 27

int main() {
    pid_t pid;
    char *shm, *s;

    int shmid = shmget(SHMKEY, SHMSZ, IPC_CREAT | 0666);
    if(shmid < 0) {
        perror("shmget error");
        exit(1);
    }

    shm = shmat(shmid, NULL, 0);
    if(shm == (char *) -1) {
        perror("shmat error");
        exit(1);
    }

    s = shm;
    *s = 'a';
    *(s+1) = '\0';

    pid = fork();
    if(pid < 0) {
        perror("fork error");
        exit(1);
    } else if(pid == 0) {
        printf("Child process reads from shared memory: ");
        for(s = shm; *s != '\0'; s++) {
            putchar(*s);
        }
        putchar('\n');

        *shm = '*';
        exit(0);
    } else {
        wait(NULL);

        printf("Parent process writes to shared memory: ");
        for(s = shm; *s != '\0'; s++) {
            putchar(*s);
        }
        putchar('\n');
        
        printf("Parent process reads modified data from shared memory: ");
        for(s = shm; *s != '*'; s++) {
            putchar(*s);
        }
        putchar('\n');

        if(shmdt(shm) == -1) {
            perror("shmdt error");
            exit(1);
        }

        if(shmctl(shmid, IPC_RMID, 0) == -1) {
            perror("shmctl error");
            exit(1);
        }
    }

    return 0;
}