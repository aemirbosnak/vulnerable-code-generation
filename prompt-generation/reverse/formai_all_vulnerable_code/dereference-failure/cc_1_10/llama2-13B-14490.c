//LLAMA2-13B DATASET v1.0 Category: Interprocess communication ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_KEY 0xdeadbeef
#define MSG_LEN 1024

typedef struct {
    int id;
    char message[MSG_LEN];
} message_t;

int main(void) {
    key_t shm_key = SHM_KEY;
    int shmid = shmget(shm_key, sizeof(message_t), IPC_CREAT | 0644);
    if (shmid == -1) {
        perror("shmget() failed");
        return 1;
    }

    // Create a shared memory object
    message_t *shm = shmat(shmid, NULL, 0);
    if (shm == (message_t *) -1) {
        perror("shmat() failed");
        return 1;
    }

    // Fork a child process
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork() failed");
        return 1;
    }
    if (pid == 0) {
        // Child process
        char *message = "Hello from the child!";
        int len = strlen(message);
        if (shm->id != 0) {
            // Send message to the parent process
            if (shmdt(shm) == -1) {
                perror("shmdt() failed");
                return 1;
            }
            if (msgsnd(shmid, message, len, 0) == -1) {
                perror("msgsnd() failed");
                return 1;
            }
        }
        // Exit the child process
        exit(0);
    } else {
        // Parent process
        while (1) {
            // Receive message from the child process
            message_t message;
            if (msgrcv(shmid, &message, sizeof(message), 0, 0) == -1) {
                perror("msgrcv() failed");
                return 1;
            }
            printf("Received message from child: %s\n", message.message);
        }
    }

    return 0;
}