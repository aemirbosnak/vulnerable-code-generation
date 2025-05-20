//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <errno.h>
#include <dirent.h>

#define MAX_PROCESSES 1024
#define MAX_COMMAND_LENGTH 1024

typedef struct {
    pid_t pid;
    char command[MAX_COMMAND_LENGTH];
} process_t;

void print_processes(process_t processes[], int num_processes) {
    printf("PID\tCOMMAND\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%d\t%s\n", processes[i].pid, processes[i].command);
    }
}

int main() {
    process_t processes[MAX_PROCESSES];
    int num_processes = 0;

    DIR *dir;
    struct dirent *ent;

    if ((dir = opendir("/proc"))!= NULL) {
        while ((ent = readdir(dir))!= NULL) {
            if (ent->d_type == DT_DIR) {
                int pid = ent->d_name[0] - '0';

                if (pid > 0 && pid <= MAX_PROCESSES) {
                    sprintf(processes[num_processes].command, "cat /proc/%d/cmdline", pid);
                    processes[num_processes].pid = pid;
                    num_processes++;
                }
            }
        }
        closedir(dir);
    }

    for (int i = 0; i < num_processes; i++) {
        FILE *fp;
        char buffer[MAX_COMMAND_LENGTH];

        if ((fp = popen(processes[i].command, "r"))!= NULL) {
            while (fgets(buffer, MAX_COMMAND_LENGTH, fp)!= NULL) {
                strcat(processes[i].command, buffer);
            }
            pclose(fp);
        }
    }

    print_processes(processes, num_processes);

    return 0;
}