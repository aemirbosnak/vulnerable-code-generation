//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <dirent.h>
#include <string.h>
#include <errno.h>

#define MAX_PROCESSES 1024
#define MAX_COMMAND_LENGTH 1024
#define MAX_PID_LENGTH 8

typedef struct {
    pid_t pid;
    char command[MAX_COMMAND_LENGTH];
    int status;
} process_t;

void print_processes(process_t processes[], int count) {
    printf("PID\tCOMMAND\tSTATUS\n");
    for (int i = 0; i < count; i++) {
        printf("%-8d", processes[i].pid);
        printf("%-16s", processes[i].command);
        printf("%-8d", processes[i].status);
        printf("\n");
    }
}

int main() {
    process_t processes[MAX_PROCESSES];
    int count = 0;
    DIR *dir;
    struct dirent *ent;
    char path[MAX_COMMAND_LENGTH];

    if ((dir = opendir("/proc"))!= NULL) {
        while ((ent = readdir(dir))!= NULL) {
            if (ent->d_type == DT_DIR) {
                snprintf(path, MAX_COMMAND_LENGTH, "/proc/%s/cmdline", ent->d_name);
                FILE *file = fopen(path, "r");
                if (file!= NULL) {
                    fgets(processes[count].command, MAX_COMMAND_LENGTH, file);
                    fclose(file);
                    processes[count].pid = atoi(ent->d_name);
                    processes[count].status = 0;
                    count++;
                }
            }
        }
        closedir(dir);
    }

    while (1) {
        print_processes(processes, count);
        sleep(1);
    }

    return 0;
}