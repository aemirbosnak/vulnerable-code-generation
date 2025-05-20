//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <errno.h>
#include <signal.h>
#include <sys/wait.h>

#define MAX_PROCESSES 1024
#define MAX_COMMAND_LENGTH 1024

typedef struct {
    pid_t pid;
    char command[MAX_COMMAND_LENGTH];
    int status;
} Process;

void sigchld_handler(int signum) {
    while (waitpid(-1, NULL, WNOHANG) > 0) {
        // Do nothing
    }
}

int main() {
    int i, status;
    DIR *proc_dir;
    struct dirent *dirent;
    char path[MAX_COMMAND_LENGTH];
    Process processes[MAX_PROCESSES];
    int num_processes = 0;

    signal(SIGCHLD, sigchld_handler);

    proc_dir = opendir("/proc");
    if (proc_dir == NULL) {
        printf("Error opening /proc directory\n");
        exit(1);
    }

    while ((dirent = readdir(proc_dir))!= NULL) {
        if (dirent->d_type == DT_DIR && dirent->d_name[0] >= '0' && dirent->d_name[0] <= '9') {
            snprintf(path, MAX_COMMAND_LENGTH, "/proc/%s/cmdline", dirent->d_name);
            if (access(path, R_OK) == 0) {
                FILE *fp = fopen(path, "r");
                if (fp!= NULL) {
                    fgets(processes[num_processes].command, MAX_COMMAND_LENGTH, fp);
                    fclose(fp);
                    processes[num_processes].pid = atoi(dirent->d_name);
                    processes[num_processes].status = -1;
                    num_processes++;
                }
            }
        }
    }

    closedir(proc_dir);

    while (1) {
        printf("\n");
        for (i = 0; i < num_processes; i++) {
            printf("%-8d %-40s ", processes[i].pid, processes[i].command);
            if (processes[i].status == -1) {
                printf("Running\n");
            } else {
                printf("Exited with status %d\n", processes[i].status);
            }
        }
        fflush(stdout);
        sleep(1);
    }

    return 0;
}