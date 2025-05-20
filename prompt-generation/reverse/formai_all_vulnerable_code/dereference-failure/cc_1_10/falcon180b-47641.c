//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/wait.h>
#include <signal.h>
#include <errno.h>

#define MAX_PROCESSES 100
#define MAX_COMMAND_LENGTH 1024

typedef struct process {
    int pid;
    char command[MAX_COMMAND_LENGTH];
    int status;
} Process;

void sigchld_handler(int signum) {
    while (waitpid(-1, NULL, WNOHANG) > 0) {
        // Do nothing
    }
}

int main() {
    int i = 0;
    Process processes[MAX_PROCESSES];
    DIR *dir;
    struct dirent *ent;

    signal(SIGCHLD, sigchld_handler);

    if ((dir = opendir("/proc"))!= NULL) {
        while ((ent = readdir(dir))!= NULL) {
            if (ent->d_type == DT_DIR && ent->d_name[0] >= '0' && ent->d_name[0] <= '9') {
                snprintf(processes[i].command, MAX_COMMAND_LENGTH, "Process %d", atoi(ent->d_name));
                processes[i].pid = atoi(ent->d_name);
                processes[i].status = 0;
                i++;
            }
        }
        closedir(dir);
    }

    while (1) {
        system("clear");
        for (int j = 0; j < i; j++) {
            printf("%d. %s (%d)\n", j+1, processes[j].command, processes[j].pid);
        }
        sleep(1);
    }

    return 0;
}