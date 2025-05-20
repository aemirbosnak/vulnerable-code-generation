//LLAMA2-13B DATASET v1.0 Category: Interprocess communication ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_KEY 0xdeadbeef
#define MSG_LEN 1024

struct message {
    char *data;
    int len;
};

int main() {
    key_t shm_key = SHM_KEY;
    int shmid = shmget(shm_key, sizeof(struct message), IPC_CREAT | 0666);
    if (shmid < 0) {
        perror("shmget() failed");
        return 1;
    }

    // Create a shared memory segment
    struct message *shm = shmat(shmid, NULL, 0);
    if (shm == NULL) {
        perror("shmat() failed");
        return 1;
    }

    // Fill the shared memory with some data
    char *data = "Hello, world!";
    shm->data = data;
    shm->len = strlen(data);

    // Create a pipe for communication
    int fd[2];
    pipe(fd);

    // Fork a child process to read from the pipe
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork() failed");
        return 1;
    }
    if (pid == 0) {
        close(fd[0]);
        read(fd[1], shm, MSG_LEN);
        close(fd[1]);
        printf("%s\n", shm->data);
        exit(0);
    }

    // In the parent process, write to the pipe and then wait for the child to read it
    close(fd[1]);
    write(fd[0], shm, MSG_LEN);
    wait(NULL);

    // Clean up
    shmctl(shmid, IPC_RMID, 0);
    return 0;
}