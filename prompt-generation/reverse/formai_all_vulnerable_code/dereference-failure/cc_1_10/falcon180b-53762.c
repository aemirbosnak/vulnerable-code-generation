//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <sys/wait.h>
#include <sys/resource.h>

#define MAX_PROCESSES 100
#define MAX_COMMAND_LEN 1024

struct process {
    pid_t pid;
    char command[MAX_COMMAND_LEN];
};

void print_processes(struct process *processes, int num_processes) {
    printf("PID\tCOMMAND\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%d\t%s\n", processes[i].pid, processes[i].command);
    }
}

int main() {
    struct process processes[MAX_PROCESSES];
    int num_processes = 0;

    DIR *dir;
    struct dirent *ent;

    if ((dir = opendir("/proc"))!= NULL) {
        while ((ent = readdir(dir))!= NULL) {
            if (ent->d_type == DT_DIR) {
                snprintf(processes[num_processes].command, MAX_COMMAND_LEN, "%d", ent->d_ino);
                processes[num_processes].pid = atoi(processes[num_processes].command);
                num_processes++;
            }
        }
        closedir(dir);
    } else {
        perror("");
        exit(EXIT_FAILURE);
    }

    print_processes(processes, num_processes);

    return 0;
}