//LLAMA2-13B DATASET v1.0 Category: Interprocess communication ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_KEY 0xdeadbeef
#define SHM_SIZE 1024

void* shm_create(void) {
    int shmid = shmget(SHM_KEY, SHM_SIZE, IPC_CREAT | 0644);
    if (shmid < 0) {
        perror("shmget");
        exit(EXIT_FAILURE);
    }
    void* shm = mmap(NULL, SHM_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shmid, 0);
    if (shm == MAP_FAILED) {
        perror("mmap");
        exit(EXIT_FAILURE);
    }
    return shm;
}

void shm_send(void* shm, char* message) {
    int len = strlen(message);
    char* shm_ptr = shm;
    for (int i = 0; i < len; i++) {
        *(shm_ptr + i) = message[i];
    }
}

char* shm_recv(void* shm) {
    char* shm_ptr = shm;
    char message[1024];
    int len = 0;
    while (len < 1024) {
        char c = *(shm_ptr + len);
        if (c == '\0') {
            break;
        }
        message[len++] = c;
    }
    return message;
}

int main() {
    pid_t pid;
    pid = fork();
    if (pid == 0) {
        // Child process
        void* shm = shm_create();
        char* message = "Hello, parent!";
        shm_send(shm, message);
        printf("Child: Sent message %s\n", message);
        exit(EXIT_SUCCESS);
    } else {
        // Parent process
        void* shm = shm_create();
        char* message = shm_recv(shm);
        printf("Parent: Received message %s\n", message);
        exit(EXIT_SUCCESS);
    }
    return 0;
}