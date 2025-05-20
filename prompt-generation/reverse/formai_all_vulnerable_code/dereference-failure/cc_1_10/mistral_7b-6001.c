//MISTRAL-7B DATASET v1.0 Category: Automated Fortune Teller ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <fcntl.h>

#define FIFO_READ "/tmp/fortune_read.fifo"
#define FIFO_WRITE "/tmp/fortune_write.fifo"

#define SHM_SIZE 1024

key_t shm_key;
int shm_id;
char *shm_str;

void fortune_teller(int pid1, int pid2) {
    char message[100];
    char *fortune;

    mkfifo(FIFO_WRITE, 0666);
    mkfifo(FIFO_READ, 0666);

    shm_key = ftok("fortune.c", 65);
    shm_id = shmget(shm_key, SHM_SIZE, IPC_CREAT | 0666);
    shm_str = shmget(shm_key, SHM_SIZE, 0);

    sprintf(message, "%d %s", pid1, "entered the room");
    write(pid2, message, strlen(message) + 1);

    read(FIFO_READ, message, 100);
    fortune = strtok(message, " ");
    sprintf(shm_str, "Your fortune is: %s", fortune);

    write(pid1, "Your fortune has been told!", strlen("Your fortune has been told!"));

    shmctl(shm_id, IPC_RMID, NULL);
    shmctl(shm_key, IPC_RMID, NULL);
    unlink(FIFO_WRITE);
    unlink(FIFO_READ);
}

int main() {
    int pid1, pid2;

    pid1 = fork();

    if (pid1 < 0) {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    }

    if (pid1 > 0) { // Parent process
        pid2 = fork();

        if (pid2 < 0) {
            perror("Fork failed");
            exit(EXIT_FAILURE);
        }

        if (pid2 > 0) { // Grandparent process
            int status;
            waitpid(pid1, &status, 0);
            waitpid(pid2, NULL, 0);
            fortune_teller(pid1, pid2);
            exit(EXIT_SUCCESS);
        }

        close(0);
        dup2(atoi(getenv("O_RDONLY")), 0);

        execlp("./client.out", "client.out", NULL);
    }

    close(1);
    dup2(atoi(getenv("O_WRONLY")), 1);

    execlp("./server.out", "server.out", NULL);
}