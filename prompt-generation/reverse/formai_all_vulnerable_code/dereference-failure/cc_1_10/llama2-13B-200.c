//LLAMA2-13B DATASET v1.0 Category: Interprocess communication ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/shm.h>
#include <fcntl.h>

#define SHM_KEY 0xdeadbeef
#define SHM_SIZE 1024

void* shm_create(void) {
    int shmid = shmget(SHM_KEY, SHM_SIZE, IPC_CREAT | 0644);
    if (shmid < 0) {
        perror("shmget");
        return NULL;
    }
    void* shm = mmap(NULL, SHM_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shmid, 0);
    if (shm == MAP_FAILED) {
        perror("mmap");
        shmctl(shmid, IPC_RMID, 0);
        return NULL;
    }
    return shm;
}

void shm_write(void* shm, char* message) {
    size_t len = strlen(message);
    memcpy(shm, message, len);
}

char* shm_read(void* shm) {
    char* message = NULL;
    size_t len = 0;
    memcpy(&message, shm, len);
    return message;
}

int main() {
    void* shm = shm_create();
    if (!shm) {
        perror("shm_create");
        return 1;
    }
    char* message = "Hello, world!";
    shm_write(shm, message);
    message = shm_read(shm);
    if (message == NULL) {
        perror("shm_read");
        return 2;
    }
    printf("%s\n", message);
    return 0;
}