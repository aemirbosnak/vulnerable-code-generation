//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_PROCESSES 1024
#define MAX_LINE_LENGTH 100
#define MAX_COMMAND_LENGTH 1000

typedef struct {
    pid_t pid;
    int status;
    char command[MAX_COMMAND_LENGTH];
} Process;

void sigchld_handler(int signum) {
    while (waitpid(-1, NULL, WNOHANG) > 0) {
        printf("Child process terminated.\n");
    }
}

void print_process(Process *process) {
    printf("PID: %d\n", process->pid);
    printf("Status: %d\n", process->status);
    printf("Command: %s\n\n", process->command);
}

int main() {
    signal(SIGCHLD, sigchld_handler);

    DIR *proc_dir = opendir("/proc");
    if (proc_dir == NULL) {
        printf("Failed to open /proc directory.\n");
        return 1;
    }

    Process processes[MAX_PROCESSES];
    int num_processes = 0;

    struct dirent *dirent;
    while ((dirent = readdir(proc_dir))!= NULL) {
        if (dirent->d_type == DT_DIR && dirent->d_name[0] >= '0' && dirent->d_name[0] <= '9') {
            char path[100];
            sprintf(path, "/proc/%s/cmdline", dirent->d_name);

            FILE *file = fopen(path, "r");
            if (file!= NULL) {
                char command[MAX_LINE_LENGTH];
                if (fgets(command, MAX_LINE_LENGTH, file)!= NULL) {
                    processes[num_processes].pid = atoi(dirent->d_name);
                    strcpy(processes[num_processes].command, command);
                    num_processes++;
                }
                fclose(file);
            }
        }
    }

    closedir(proc_dir);

    if (num_processes == 0) {
        printf("No running processes found.\n");
        return 1;
    }

    printf("Running processes:\n");
    for (int i = 0; i < num_processes; i++) {
        print_process(&processes[i]);
    }

    return 0;
}