//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include <dirent.h>

#define MAX_PROCESSES 1024
#define MAX_COMMAND_LENGTH 1024

typedef struct process {
    int pid;
    char command[MAX_COMMAND_LENGTH];
} process_t;

int get_processes(process_t *processes) {
    DIR *dir;
    struct dirent *ent;
    int count = 0;

    if ((dir = opendir("/proc"))!= NULL) {
        while ((ent = readdir(dir))!= NULL) {
            if (ent->d_type == DT_DIR && isdigit(ent->d_name[0])) {
                snprintf(processes[count].command, MAX_COMMAND_LENGTH, "cat /proc/%s/cmdline", ent->d_name);
                processes[count].pid = atoi(ent->d_name);
                count++;
            }
        }
        closedir(dir);
    }

    return count;
}

void print_processes(process_t *processes, int num_processes) {
    for (int i = 0; i < num_processes; i++) {
        printf("%d: %s\n", processes[i].pid, processes[i].command);
    }
}

int main() {
    process_t processes[MAX_PROCESSES];
    int num_processes = get_processes(processes);
    print_processes(processes, num_processes);

    return 0;
}