//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>

#define MAX_PROCESSES 1024
#define MAX_COMMAND_LENGTH 1024

typedef struct process {
    int pid;
    char command[MAX_COMMAND_LENGTH];
} Process;

void print_processes(Process *processes, int num_processes) {
    printf("PID\tCommand\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%d\t%s\n", processes[i].pid, processes[i].command);
    }
}

int get_processes(Process *processes, int max_processes) {
    DIR *dir;
    struct dirent *ent;
    int num_processes = 0;

    if ((dir = opendir("/proc"))!= NULL) {
        while ((ent = readdir(dir))!= NULL) {
            if (ent->d_type == DT_DIR) {
                snprintf(processes[num_processes].command, MAX_COMMAND_LENGTH, "%s", ent->d_name);
                processes[num_processes].pid = atoi(ent->d_name);
                num_processes++;
            }
            if (num_processes >= max_processes) {
                break;
            }
        }
        closedir(dir);
    }

    return num_processes;
}

int main() {
    Process processes[MAX_PROCESSES];
    int num_processes = get_processes(processes, MAX_PROCESSES);

    printf("Total processes: %d\n", num_processes);
    print_processes(processes, num_processes);

    return 0;
}