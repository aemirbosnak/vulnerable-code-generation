//FormAI DATASET v1.0 Category: Interprocess communication ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

#define SIZE 20

int main() {

    int shmid;
    key_t key;
    char *shm, *s;

    key = ftok(".", 'S');
    shmid = shmget(key, SIZE, IPC_CREAT | 0666);

    if(shmid < 0) {
        perror("shmget error");
        exit(1);
    }

    shm = shmat(shmid, NULL, 0);

    if(shm == (char*)-1) {
        perror("shmat error");
        exit(1);
    }

    printf("Enter a message: ");
    fgets(shm, SIZE, stdin);

    pid_t pid = fork();

    if(pid == -1) {
        perror("fork error");
        exit(1);
    }
    else if(pid == 0) { // Child process
        sleep(1);
        printf("\nChild Process:\n");
        printf("Received Message: ");
        for(s = shm; *s != '\0'; s++) {
            putchar(*s);
        }
        putchar('\n');
        printf("Changing Message...\n");
        for(s = shm; *s != '\0'; s++) {
            *s = toupper(*s);
        }
        printf("Changed Message: %s\n", shm);
        _exit(0);
    }
    else { // Parent process
        wait(NULL);
        printf("\nParent Process:\n");
        printf("Received Message: ");
        for(s = shm; *s != '\0'; s++) {
            putchar(*s);
        }
        putchar('\n');
    }

    shmdt(shm);

    return 0;
}