//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SIZE 10

int shmid;
int shmaddr;
int semid;
int semnum;

struct data {
    int count;
    char message[80];
};

void handler(int signum) {
    if (signum == SIGUSR1) {
        printf("Received signal 1\n");
        shmctl(shmid, IPC_RMID, NULL);
        exit(0);
    }
}

int main() {
    int fd[2];
    pid_t pid;
    struct data *data;
    int i;

    if (pipe(fd) == -1) {
        perror("Pipe failed");
        exit(1);
    }

    if ((pid = fork()) == -1) {
        perror("Fork failed");
        exit(1);
    } else if (pid == 0) {
        // Child process
        close(fd[0]);
        data = (struct data *)shmat(shmid, NULL, 0);
        if (data == (void *)-1) {
            perror("shmat failed");
            exit(1);
        }
        data->count = 0;
        data->message[0] = '\0';
        for (i = 0; i < SIZE; i++) {
            write(fd[1], &data->message[i], 1);
        }
        close(fd[1]);
        exit(0);
    } else {
        // Parent process
        close(fd[1]);
        data = (struct data *)shmat(shmid, NULL, 0);
        if (data == (void *)-1) {
            perror("shmat failed");
            exit(1);
        }
        signal(SIGUSR1, handler);
        while (data->count < SIZE) {
            read(fd[0], &data->message[data->count], 1);
            data->count++;
        }
        close(fd[0]);
        printf("Received message: %s\n", data->message);
        shmdt(data);
        shmctl(shmid, IPC_RMID, NULL);
        exit(0);
    }
}