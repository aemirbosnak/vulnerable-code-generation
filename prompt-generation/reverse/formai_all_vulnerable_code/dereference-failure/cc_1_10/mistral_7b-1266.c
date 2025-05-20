//MISTRAL-7B DATASET v1.0 Category: System process viewer ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_KEY 1234
#define BUFFER_SIZE 256

typedef struct {
    pid_t pid;
    char name[BUFFER_SIZE];
} ProcessInfo;

void print_process_info(ProcessInfo process) {
    char cmd[BUFFER_SIZE];
    snprintf(cmd, sizeof(cmd), "ps -p %ld -o comm=", process.pid);
    FILE *ps = popen(cmd, "r");
    if (ps) {
        fgets(process.name, sizeof(process.name), ps);
        pclose(ps);
        process.name[strcspn(process.name, "\n")] = '\0';
    }
    printf("PID: %ld, Name: %s\n", process.pid, process.name);
}

int main() {
    int shm_id;
    ProcessInfo *process_info_shm;
    key_t shm_key_temp = SHM_KEY;

    if ((shm_id = shmget(shm_key_temp, sizeof(ProcessInfo), IPC_CREAT | 0666)) < 0) {
        perror("shmget failed");
        return 1;
    }

    process_info_shm = shmat(shm_id, NULL, 0);
    if (process_info_shm == (void *)-1) {
        perror("shmat failed");
        return 1;
    }

    while (1) {
        pid_t child_pid = fork();
        if (child_pid < 0) {
            perror("fork failed");
            exit(1);
        } else if (child_pid > 0) {
            wait(NULL);
            close(shm_id);
            shmdt(process_info_shm);
            print_process_info(*process_info_shm);
            exit(0);
        } else {
            getcwd(process_info_shm->name, sizeof(process_info_shm->name));
            strcat(process_info_shm->name, "/ShannonProcessViewer");
            execlp("./ShannonProcessViewer", "ShannonProcessViewer", NULL);
            perror("execlp failed");
            exit(1);
        }
    }

    return 0;
}