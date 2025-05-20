//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: Linus Torvalds
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

typedef struct {
    pid_t pid;
    char command[MAX_COMMAND_LENGTH];
} process_t;

void print_processes(process_t processes[], int num_processes) {
    for (int i = 0; i < num_processes; i++) {
        printf("%d: %s\n", processes[i].pid, processes[i].command);
    }
}

void sigchld_handler(int signum) {
    while (waitpid(-1, NULL, WNOHANG) > 0) {
        // Do nothing
    }
}

int main() {
    signal(SIGCHLD, sigchld_handler);

    DIR *proc_dir = opendir("/proc");
    if (proc_dir == NULL) {
        perror("opendir");
        return 1;
    }

    process_t processes[MAX_PROCESSES];
    int num_processes = 0;

    struct dirent *dirent;
    while ((dirent = readdir(proc_dir))!= NULL) {
        if (dirent->d_type!= DT_DIR) {
            continue;
        }

        pid_t pid = atoi(dirent->d_name);
        char path[20];
        snprintf(path, sizeof(path), "/proc/%d/cmdline", pid);

        FILE *cmdline_file = fopen(path, "r");
        if (cmdline_file == NULL) {
            perror("fopen");
            continue;
        }

        char command[MAX_COMMAND_LENGTH];
        if (fgets(command, sizeof(command), cmdline_file) == NULL) {
            perror("fgets");
            fclose(cmdline_file);
            continue;
        }

        processes[num_processes].pid = pid;
        strncpy(processes[num_processes].command, command, MAX_COMMAND_LENGTH - 1);
        processes[num_processes].command[MAX_COMMAND_LENGTH - 1] = '\0';

        fclose(cmdline_file);
        num_processes++;

        if (num_processes >= MAX_PROCESSES) {
            break;
        }
    }

    closedir(proc_dir);

    print_processes(processes, num_processes);

    return 0;
}