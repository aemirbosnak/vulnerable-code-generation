//Falcon-180B DATASET v1.0 Category: System boot optimizer ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define PAGE_SIZE 4096
#define NUM_PAGES 100
#define NUM_PROCS 4

int shm_id;
char *shm_addr;

void init_shm() {
    int shm_fd;
    shm_fd = shm_open("/shared_memory", O_CREAT | O_RDWR, 0666);
    if (shm_fd == -1) {
        printf("Error: shm_open() failed\n");
        exit(1);
    }
    ftruncate(shm_fd, NUM_PAGES * PAGE_SIZE);
    shm_addr = mmap(NULL, NUM_PAGES * PAGE_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
    if (shm_addr == MAP_FAILED) {
        printf("Error: mmap() failed\n");
        exit(1);
    }
    memset(shm_addr, 0, NUM_PAGES * PAGE_SIZE);
    close(shm_fd);
}

void *child_func(void *arg) {
    int i;
    for (i = 0; i < NUM_PAGES; i++) {
        memset(shm_addr + i * PAGE_SIZE, 0xff, PAGE_SIZE);
    }
    return NULL;
}

int main() {
    int i;
    pid_t pids[NUM_PROCS];

    init_shm();

    for (i = 0; i < NUM_PROCS; i++) {
        pids[i] = fork();
        if (pids[i] == -1) {
            printf("Error: fork() failed\n");
            exit(1);
        } else if (pids[i] == 0) {
            child_func(NULL);
            exit(0);
        }
    }

    for (i = 0; i < NUM_PROCS; i++) {
        wait(NULL);
    }

    printf("Shared memory initialized\n");

    return 0;
}