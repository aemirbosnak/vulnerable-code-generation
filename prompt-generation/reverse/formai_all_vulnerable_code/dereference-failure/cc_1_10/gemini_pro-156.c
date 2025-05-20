//GEMINI-pro DATASET v1.0 Category: Interprocess communication ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#include <signal.h>
#include <errno.h>

#define SHM_SIZE 1024
#define SHM_KEY 0x12345678

static volatile int shm_id = -1;
static volatile void *shm_addr = NULL;
static volatile int shm_size = 0;

static void cleanup() {
    if (shm_id != -1) {
        if (shmdt(shm_addr) == -1) {
            perror("shmdt");
        }
        shm_addr = NULL;
        if (shmctl(shm_id, IPC_RMID, NULL) == -1) {
            perror("shmctl");
        }
        shm_id = -1;
    }
}

static void sighandler(int signum) {
    cleanup();
    exit(EXIT_SUCCESS);
}

int main(int argc, char **argv) {
    signal(SIGINT, sighandler);
    signal(SIGTERM, sighandler);
    signal(SIGQUIT, sighandler);
    signal(SIGABRT, sighandler);
    signal(SIGSEGV, sighandler);
    signal(SIGBUS, sighandler);
    signal(SIGILL, sighandler);
    signal(SIGFPE, sighandler);
    signal(SIGPIPE, sighandler);
    signal(SIGALRM, sighandler);

    shm_id = shmget(SHM_KEY, SHM_SIZE, IPC_CREAT | IPC_EXCL | 0600);
    if (shm_id == -1) {
        perror("shmget");
        return EXIT_FAILURE;
    }

    shm_addr = shmat(shm_id, NULL, 0);
    if (shm_addr == (void *)-1) {
        perror("shmat");
        return EXIT_FAILURE;
    }

    shm_size = SHM_SIZE;

    while (1) {
        memset(shm_addr, 0, shm_size);
        if (snprintf(shm_addr, shm_size, "Hello from process %d!", getpid()) < 0) {
            perror("snprintf");
            return EXIT_FAILURE;
        }
        sleep(1);
    }

    cleanup();
    return EXIT_SUCCESS;
}