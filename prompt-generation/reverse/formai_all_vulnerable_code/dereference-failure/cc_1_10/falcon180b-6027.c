//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>

#define MAX_PROCESSES 100
#define MAX_COMMAND_LENGTH 80

typedef struct {
    pid_t pid;
    char command[MAX_COMMAND_LENGTH];
    int status;
} process_t;

void print_processes(process_t *processes, int num_processes) {
    printf("PID\tCOMMAND\tSTATUS\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%d\t%s\t%d\n", processes[i].pid, processes[i].command, processes[i].status);
    }
}

int main() {
    process_t processes[MAX_PROCESSES];
    int num_processes = 0;

    DIR *proc_dir = opendir("/proc");
    if (proc_dir == NULL) {
        printf("Error: could not open /proc directory.\n");
        return 1;
    }

    struct dirent *dirent;
    while ((dirent = readdir(proc_dir))!= NULL) {
        if (dirent->d_type == DT_DIR && dirent->d_name[0] >= '0' && dirent->d_name[0] <= '9') {
            // Found a process directory
            pid_t pid = atoi(dirent->d_name);
            char path[50];
            sprintf(path, "/proc/%d/cmdline", pid);

            int fd = open(path, O_RDONLY);
            if (fd == -1) {
                printf("Error: could not open /proc/%d/cmdline.\n", pid);
                continue;
            }

            char command[MAX_COMMAND_LENGTH];
            memset(command, 0, MAX_COMMAND_LENGTH);
            ssize_t bytes_read = read(fd, command, MAX_COMMAND_LENGTH - 1);
            if (bytes_read == -1) {
                printf("Error: could not read /proc/%d/cmdline.\n", pid);
                continue;
            }
            command[bytes_read] = '\0';

            processes[num_processes].pid = pid;
            strncpy(processes[num_processes].command, command, MAX_COMMAND_LENGTH - 1);
            processes[num_processes].command[MAX_COMMAND_LENGTH - 1] = '\0';
            num_processes++;
        }
    }

    closedir(proc_dir);

    print_processes(processes, num_processes);

    return 0;
}