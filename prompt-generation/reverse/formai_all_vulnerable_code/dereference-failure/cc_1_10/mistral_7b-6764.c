//MISTRAL-7B DATASET v1.0 Category: Pattern printing ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define ROWS 10
#define COLS 10
#define BUF_SIZE 100
#define SHM_KEY 1234

typedef struct {
    int row;
    int col;
    char pattern[BUF_SIZE];
} pattern_t;

void print_pattern(int row, int col, char *pattern) {
    int i, j;

    printf("\nRow %d, Col %d: %s\n", row, col, pattern);
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            putchar(pattern[i * col + j]);
        }
        putchar('\n');
    }
}

int main() {
    int shmid;
    pattern_t *shm;
    int pid;
    int i, j;

    shmid = shmget(SHM_KEY, sizeof(pattern_t) * ROWS, 0666 | IPC_CREAT);
    if (shmid < 0) {
        perror("shmget");
        exit(1);
    }

    shm = (pattern_t *) shmat(shmid, NULL, 0);
    if (shm == (void *) -1) {
        perror("shmat");
        exit(1);
    }

    for (i = 0; i < ROWS; i++) {
        pid = fork();
        if (pid < 0) {
            perror("fork");
            exit(1);
        }
        if (pid > 0) {
            strcpy(shm[i].pattern, "X");
            shm[i].row = i + 1;
            shm[i].col = COLS;
            continue;
        }

        print_pattern(shm[i].row, shm[i].col, shm[i].pattern);
        exit(0);
    }

    for (i = 0; i < ROWS; i++) {
        wait(NULL);
    }

    shmdt(shm);
    shmctl(shmid, IPC_RMID, 0);

    return 0;
}