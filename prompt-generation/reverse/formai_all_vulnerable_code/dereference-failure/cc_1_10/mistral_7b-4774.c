//MISTRAL-7B DATASET v1.0 Category: Interprocess communication ; Style: Ken Thompson
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_KEY 1234
#define MESSAGE_SIZE 100

struct shared_data {
    int pid;
    char message[MESSAGE_SIZE];
};

int main() {
    key_t shm_key = ftok("shm.txt", SHM_KEY);
    int shmid = shmget(shm_key, sizeof(struct shared_data), 0666 | IPC_CREAT);
    struct shared_data *data = shmat(shmid, NULL, 0);

    data->pid = getpid();
    printf("PID: %d\n", data->pid);

    pid_t child_pid = fork();
    if (child_pid < 0) {
        perror("Error forking process");
        exit(EXIT_FAILURE);
    } else if (child_pid > 0) {
        printf("Parent process sending message to child process: %s\n", "Hello from parent!");
        strcpy(data->message, "Hello from parent!");
        shmdt(data);
        shmctl(shmid, IPC_RMID, NULL);
        waitpid(child_pid, NULL, 0);
    } else {
        close(STDOUT_FILENO); // Redirect stdout to pipe
        int pipefd[2];
        pipe(pipefd);

        dup2(pipefd[1], STDOUT_FILENO); // Make pipe the new stdout

        char received_message[MESSAGE_SIZE];
        read(pipefd[0], received_message, MESSAGE_SIZE);
        printf("Child process received message: %s\n", received_message);
        close(pipefd[0]);
        close(pipefd[1]);

        exit(EXIT_SUCCESS);
    }

    return EXIT_SUCCESS;
}