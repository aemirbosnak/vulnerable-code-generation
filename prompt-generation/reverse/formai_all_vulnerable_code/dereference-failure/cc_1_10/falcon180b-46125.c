//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>

#define MAX_PROCESSES 100
#define MAX_COMMAND_LENGTH 80

typedef struct {
    int pid;
    char command[MAX_COMMAND_LENGTH];
} process_t;

void print_processes(process_t* processes, int num_processes) {
    printf("PID\tCommand\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%d\t%s\n", processes[i].pid, processes[i].command);
    }
}

int main() {
    DIR* dir;
    struct dirent* ent;
    int num_processes = 0;
    process_t processes[MAX_PROCESSES];

    if ((dir = opendir("/proc"))!= NULL) {
        while ((ent = readdir(dir))!= NULL) {
            if (ent->d_type == DT_DIR) {
                int pid = atoi(ent->d_name);
                if (num_processes < MAX_PROCESSES) {
                    processes[num_processes].pid = pid;
                    snprintf(processes[num_processes].command, MAX_COMMAND_LENGTH, "Process %d", pid);
                    num_processes++;
                }
            }
        }
        closedir(dir);
    } else {
        perror("");
        return 1;
    }

    print_processes(processes, num_processes);

    return 0;
}