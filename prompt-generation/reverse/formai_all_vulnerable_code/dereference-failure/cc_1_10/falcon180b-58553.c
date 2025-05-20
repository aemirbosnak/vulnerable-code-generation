//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include <dirent.h>

#define MAX_PROCESSES 100
#define BUFFER_SIZE 1024

typedef struct {
    char name[32];
    int pid;
    int ppid;
    int status;
    char command[80];
} Process;

void get_processes(Process* processes, int num_processes) {
    DIR* dir = opendir("/proc");
    if (!dir) {
        printf("Error opening /proc directory\n");
        exit(1);
    }

    int num_found = 0;
    struct dirent* entry;
    while ((entry = readdir(dir))!= NULL) {
        if (entry->d_type == DT_DIR) {
            int pid = atoi(entry->d_name);
            if (num_found < num_processes) {
                processes[num_found].pid = pid;
                sprintf(processes[num_found].name, "%d", pid);
                sprintf(processes[num_found].command, "cat /proc/%d/cmdline", pid);
                num_found++;
            }
        }
    }

    closedir(dir);
}

void print_processes(Process* processes, int num_processes) {
    printf("Name\tPID\tPPID\tStatus\tCommand\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%-32s %d %d %d %s\n", processes[i].name, processes[i].pid, processes[i].ppid, processes[i].status, processes[i].command);
    }
}

int main() {
    Process processes[MAX_PROCESSES];
    int num_processes = 0;

    get_processes(processes, MAX_PROCESSES);
    print_processes(processes, num_processes);

    return 0;
}