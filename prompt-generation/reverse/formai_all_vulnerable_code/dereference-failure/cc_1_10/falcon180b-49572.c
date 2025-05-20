//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_PROCESSES 100
#define MAX_COMMAND_LENGTH 1024

typedef struct process_info {
    pid_t pid;
    char command[MAX_COMMAND_LENGTH];
} ProcessInfo;

void print_processes(ProcessInfo *processes, int num_processes) {
    printf("PID\tCommand\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%d\t%s\n", processes[i].pid, processes[i].command);
    }
}

int main() {
    int num_processes = 0;
    ProcessInfo *processes = malloc(MAX_PROCESSES * sizeof(ProcessInfo));
    DIR *dir = opendir("/proc");
    if (dir == NULL) {
        printf("Error opening /proc directory\n");
        exit(1);
    }
    struct dirent *entry;
    while ((entry = readdir(dir))!= NULL) {
        if (entry->d_type == DT_DIR && isdigit(entry->d_name[0])) {
            pid_t pid = atoi(entry->d_name);
            char path[32];
            sprintf(path, "/proc/%d/cmdline", pid);
            FILE *file = fopen(path, "r");
            if (file!= NULL) {
                fgets(processes[num_processes].command, MAX_COMMAND_LENGTH, file);
                fclose(file);
                processes[num_processes].pid = pid;
                num_processes++;
            }
        }
    }
    closedir(dir);
    print_processes(processes, num_processes);
    free(processes);
    return 0;
}