//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/wait.h>
#include <sys/resource.h>
#include <sys/time.h>
#include <sys/utsname.h>
#include <errno.h>

#define MAX_PROCESSES 100
#define MAX_COMMAND_LENGTH 1024

typedef struct process {
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

int get_processes(process_t *processes) {
    DIR *dir;
    struct dirent *ent;
    char path[MAX_COMMAND_LENGTH];
    int num_processes = 0;

    if ((dir = opendir("/proc"))!= NULL) {
        while ((ent = readdir(dir))!= NULL) {
            if (ent->d_type == DT_DIR) {
                snprintf(path, MAX_COMMAND_LENGTH, "/proc/%s/cmdline", ent->d_name);
                FILE *file = fopen(path, "r");
                if (file!= NULL) {
                    fgets(processes[num_processes].command, MAX_COMMAND_LENGTH, file);
                    fclose(file);
                    processes[num_processes].pid = atoi(ent->d_name);
                    processes[num_processes].status = -1;
                    num_processes++;
                }
            }
        }
        closedir(dir);
    }

    return num_processes;
}

int main() {
    process_t processes[MAX_PROCESSES];
    int num_processes;

    num_processes = get_processes(processes);
    print_processes(processes, num_processes);

    while (1) {
        sleep(1);
        num_processes = get_processes(processes);
        print_processes(processes, num_processes);
    }

    return 0;
}