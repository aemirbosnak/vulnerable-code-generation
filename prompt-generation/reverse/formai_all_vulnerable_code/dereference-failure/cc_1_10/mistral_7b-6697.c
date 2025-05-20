//MISTRAL-7B DATASET v1.0 Category: System process viewer ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_PROC_NAME 64
#define SHM_KEY 1234

typedef struct {
    pid_t pid;
    char name[MAX_PROC_NAME];
} proc_info;

volatile sig_atomic_t stop = 0;

void sigint_handler(int signal) {
    stop = 1;
}

int main() {
    struct shmid_ds shm_info;
    int shmid;
    proc_info *proc_list;

    if ((shmid = shmget(SHM_KEY, sizeof(proc_info) * 10, 0666 | IPC_CREAT)) < 0) {
        perror("shmget");
        exit(EXIT_FAILURE);
    }

    if ((proc_list = shmat(shmid, NULL, 0)) == (proc_info *) -1) {
        perror("shmat");
        exit(EXIT_FAILURE);
    }

    signal(SIGINT, sigint_handler);

    while (!stop) {
        for (int i = 0; i < 10; i++) {
            proc_info *p = &proc_list[i];
            p->pid = waitpid(-1, NULL, WNOHANG | WUNTRACED);
            if (p->pid > 0) {
                snprintf(p->name, sizeof(p->name), "%s (%d)", strrchr(strrchr("/proc/self/task/", '/'), '/') + 1, p->pid);
                if (snprintf(p->name + strlen(p->name), sizeof(p->name) - strlen(p->name), "%d", getppid()) >= sizeof(p->name) - strlen(p->name)) {
                    strcpy(p->name, "Unknown");
                }
            }
        }
        sleep(1);
    }

    shmdt(proc_list);
    shmctl(shmid, IPC_RMID, NULL);

    return EXIT_SUCCESS;
}