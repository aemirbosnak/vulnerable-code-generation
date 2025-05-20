//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/wait.h>
#include <sys/utsname.h>

#define MAX_PROCESSES 100
#define MAX_COMMAND_LENGTH 1024

typedef struct {
    pid_t pid;
    char command[MAX_COMMAND_LENGTH];
    int status;
} process_t;

process_t processes[MAX_PROCESSES];
int num_processes = 0;

void update_processes() {
    DIR *dir;
    struct dirent *ent;
    char path[1024];
    sprintf(path, "/proc");
    dir = opendir(path);

    if (dir!= NULL) {
        while ((ent = readdir(dir))!= NULL) {
            if (ent->d_type == DT_DIR) {
                int pid = atoi(ent->d_name);
                if (pid > 0 && pid <= MAX_PROCESSES) {
                    snprintf(processes[pid].command, MAX_COMMAND_LENGTH, "Process %d", pid);
                    processes[pid].pid = pid;
                    processes[pid].status = -1;
                    num_processes++;
                }
            }
        }
        closedir(dir);
    }
}

void *monitor_processes(void *arg) {
    while (1) {
        update_processes();
        sleep(5);
    }
    return NULL;
}

int main(int argc, char **argv) {
    pthread_t thread_id;
    pthread_create(&thread_id, NULL, monitor_processes, NULL);

    while (1) {
        system("clear");
        printf("Process Viewer\n");
        for (int i = 0; i < num_processes; i++) {
            printf("%d. %s (%d)\n", i+1, processes[i].command, processes[i].pid);
        }
        printf("\n");
        sleep(1);
    }

    return 0;
}