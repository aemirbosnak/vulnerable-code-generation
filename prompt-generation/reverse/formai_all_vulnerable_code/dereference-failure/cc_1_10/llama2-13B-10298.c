//LLAMA2-13B DATASET v1.0 Category: Interprocess communication ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>

#define SHM_SIZE 1024
#define SHM_NAME "my_shm"

typedef struct {
    int num_messages;
    char messages[10];
} shared_data_t;

void *shm_create(void) {
    key_t key = IPC_PRIVATE;
    shared_data_t *shm;

    if ((shm = mmap(NULL, SHM_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, -1, 0)) == MAP_FAILED) {
        perror("mmap() failed");
        exit(EXIT_FAILURE);
    }

    if (shm_open(shm, O_RDWR, 0) != 0) {
        perror("shm_open() failed");
        munmap(shm, SHM_SIZE);
        exit(EXIT_FAILURE);
    }

    return shm;
}

void shm_send(int fd, const char *message) {
    shared_data_t *shm = (shared_data_t *) mmap(NULL, SHM_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (shm == MAP_FAILED) {
        perror("mmap() failed");
        exit(EXIT_FAILURE);
    }

    shm->num_messages++;
    strcpy(shm->messages, message);

    munmap(shm, SHM_SIZE);
}

int shm_recv(int fd, char *message) {
    shared_data_t *shm = (shared_data_t *) mmap(NULL, SHM_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (shm == MAP_FAILED) {
        perror("mmap() failed");
        exit(EXIT_FAILURE);
    }

    if (shm->num_messages > 0) {
        strcpy(message, shm->messages[0]);
        shm->num_messages--;
    }

    munmap(shm, SHM_SIZE);
    return shm->num_messages;
}

int main(int argc, char *argv[]) {
    int fd;
    shared_data_t *shm;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <message>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if ((fd = shm_create()) == -1) {
        perror("shm_create() failed");
        exit(EXIT_FAILURE);
    }

    shm = (shared_data_t *) mmap(NULL, SHM_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (shm == MAP_FAILED) {
        perror("mmap() failed");
        exit(EXIT_FAILURE);
    }

    printf("Received message: %s\n", shm->messages[0]);

    // Exit the parent process
    kill(getppid(), SIGKILL);

    return 0;
}