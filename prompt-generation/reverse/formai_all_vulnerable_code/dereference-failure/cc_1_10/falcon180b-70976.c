//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <dirent.h>

#define MAX_PROCESSES 100
#define MAX_COMMAND_LENGTH 1024

typedef struct process {
    char command[MAX_COMMAND_LENGTH];
    pid_t pid;
    int status;
} Process;

void print_processes(Process processes[], int num_processes) {
    for (int i = 0; i < num_processes; i++) {
        printf("%s (PID %d)\n", processes[i].command, processes[i].pid);
    }
}

int main() {
    Process processes[MAX_PROCESSES];
    int num_processes = 0;

    DIR *dir;
    struct dirent *ent;

    if ((dir = opendir("/proc"))!= NULL) {
        while ((ent = readdir(dir))!= NULL) {
            if (ent->d_type == DT_DIR) {
                char pid_str[16];
                snprintf(pid_str, sizeof(pid_str), "%d", ent->d_name[0] - '0');
                int pid = atoi(pid_str);

                Process process;
                strncpy(process.command, ent->d_name, sizeof(process.command) - 1);
                process.command[sizeof(process.command) - 1] = '\0';
                process.pid = pid;

                processes[num_processes++] = process;

                if (num_processes >= MAX_PROCESSES) {
                    break;
                }
            }
        }

        closedir(dir);
    }

    print_processes(processes, num_processes);

    return 0;
}