//MISTRAL-7B DATASET v1.0 Category: Interprocess communication ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define PIPE_SIZE 100
#define SHM_KEY 12345

struct Message {
    pid_t pid;
    char message[PIPE_SIZE];
};

int main(void) {
    int fd[2];
    pid_t pid;
    struct Message my_msg;
    int shmid;

    // Creating pipe
    if (pipe(fd) < 0) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    // Creating shared memory
    shmid = shmget(SHM_KEY, sizeof(struct Message), 0666 | IPC_CREAT);
    if (shmid < 0) {
        perror("shmget");
        exit(EXIT_FAILURE);
    }

    // Attaching shared memory to data segment
    my_msg = *((struct Message *) shmat(shmid, NULL, 0));

    pid = fork();

    if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid > 0) { // He
        close(fd[0]);

        while (1) {
            memset(my_msg.message, 0, PIPE_SIZE);
            printf("He: ");
            fgets(my_msg.message, PIPE_SIZE, stdin);

            write(fd[1], &my_msg, sizeof(struct Message));
            read(fd[1], &my_msg, sizeof(struct Message));
            printf("He received: %s\n", my_msg.message);

            if (strcmp(my_msg.message, "End of conversation") == 0)
                break;
        }

        close(fd[1]);
        shmdt(&my_msg);
        shmctl(shmid, IPC_RMID, 0);
        exit(EXIT_SUCCESS);
    } else { // She
        close(fd[1]);

        while (1) {
            read(fd[0], &my_msg, sizeof(struct Message));
            printf("She received: %s\n", my_msg.message);

            memset(my_msg.message, 0, PIPE_SIZE);
            printf("She: ");
            fgets(my_msg.message, PIPE_SIZE, stdin);

            write(fd[1], &my_msg, sizeof(struct Message));

            if (strcmp(my_msg.message, "End of conversation") == 0)
                break;
        }

        close(fd[0]);
        shmdt(&my_msg);
        shmctl(shmid, IPC_RMID, 0);
        exit(EXIT_SUCCESS);
    }
}