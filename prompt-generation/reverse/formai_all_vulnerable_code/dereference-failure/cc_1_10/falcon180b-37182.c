//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
#include <dirent.h>

#define MAX_PROCESS_NAME_LENGTH 256
#define MAX_PROCESS_ID_LENGTH 16

struct process {
    char name[MAX_PROCESS_NAME_LENGTH];
    char id[MAX_PROCESS_ID_LENGTH];
    int pid;
};

void print_processes(struct process *processes, int num_processes) {
    for (int i = 0; i < num_processes; i++) {
        printf("%s (%s)\n", processes[i].name, processes[i].id);
    }
}

struct process *get_processes(int *num_processes) {
    DIR *dir;
    struct dirent *ent;
    dir = opendir("/proc");
    if (dir == NULL) {
        printf("Error opening /proc directory\n");
        exit(1);
    }
    struct process *processes = (struct process *) malloc(sizeof(struct process) * 100);
    int count = 0;
    while ((ent = readdir(dir))!= NULL) {
        if (ent->d_type == DT_DIR) {
            char id[MAX_PROCESS_ID_LENGTH];
            snprintf(id, MAX_PROCESS_ID_LENGTH, "%d", ent->d_ino);
            strncpy(processes[count].name, ent->d_name, MAX_PROCESS_NAME_LENGTH - 1);
            strncpy(processes[count].id, id, MAX_PROCESS_ID_LENGTH - 1);
            processes[count].pid = fork();
            if (processes[count].pid == 0) {
                execlp("ps", "ps", "-p", id, NULL);
                exit(1);
            } else {
                waitpid(processes[count].pid, NULL, 0);
            }
            count++;
        }
    }
    closedir(dir);
    *num_processes = count;
    return processes;
}

int main() {
    int num_processes;
    struct process *processes = get_processes(&num_processes);
    print_processes(processes, num_processes);
    return 0;
}