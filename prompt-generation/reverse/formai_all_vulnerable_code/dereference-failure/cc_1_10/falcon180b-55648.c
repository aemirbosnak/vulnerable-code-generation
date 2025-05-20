//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>
#include <errno.h>
#include <sys/wait.h>

#define MAX_PROCESSES 100
#define MAX_COMMAND_LENGTH 80

struct process {
    int pid;
    char command[MAX_COMMAND_LENGTH];
};

void print_processes(struct process *processes, int num_processes) {
    printf("PID\tCommand\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%d\t%s\n", processes[i].pid, processes[i].command);
    }
}

int main() {
    char *proc_file = "/proc";
    DIR *dir;
    struct dirent *ent;
    int num_processes = 0;
    struct process processes[MAX_PROCESSES];

    dir = opendir(proc_file);
    if (dir == NULL) {
        printf("Error opening /proc directory\n");
        exit(1);
    }

    while ((ent = readdir(dir))!= NULL) {
        if (ent->d_type == DT_DIR) {
            int pid = atoi(ent->d_name);
            if (pid > 0 && pid <= getpid()) {
                char command_file[20];
                sprintf(command_file, "/proc/%d/cmdline", pid);
                FILE *fp = fopen(command_file, "r");
                if (fp!= NULL) {
                    fgets(processes[num_processes].command, MAX_COMMAND_LENGTH, fp);
                    fclose(fp);
                    processes[num_processes].pid = pid;
                    num_processes++;
                }
            }
        }
    }

    print_processes(processes, num_processes);

    return 0;
}