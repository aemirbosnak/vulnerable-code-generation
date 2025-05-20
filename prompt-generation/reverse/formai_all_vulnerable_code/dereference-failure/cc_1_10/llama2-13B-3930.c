//LLAMA2-13B DATASET v1.0 Category: Interprocess communication ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <unistd.h>

#define MESSAGE_SIZE 1024
#define SHM_KEY 0xdeadbeef

void *shm_create(void) {
    key_t key = SHM_KEY;
    int shmid = shmget(key, MESSAGE_SIZE, IPC_CREAT | 0644);
    if (shmid < 0) {
        perror("shmget");
        exit(EXIT_FAILURE);
    }
    void *shm = mmap(NULL, MESSAGE_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shmid, 0);
    if (shm == MAP_FAILED) {
        perror("mmap");
        exit(EXIT_FAILURE);
    }
    return shm;
}

void shm_send(void *shm, const char *message) {
    char *ptr = (char *)shm;
    memcpy(ptr, message, strlen(message));
}

char *shm_recv(void *shm) {
    char *ptr = (char *)shm;
    return ptr;
}

int main() {
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    if (pid == 0) {
        // Child process
        void *shm = shm_create();
        char message[] = "Hello, brave world!";
        shm_send(shm, message);
        exit(EXIT_SUCCESS);
    } else {
        // Parent process
        void *shm = shm_create();
        char *message = shm_recv(shm);
        printf("%s\n", message);
        exit(EXIT_SUCCESS);
    }
    return 0;
}