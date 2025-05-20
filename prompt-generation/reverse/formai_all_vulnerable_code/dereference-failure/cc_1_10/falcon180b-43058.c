//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include <dirent.h>
#include <sys/wait.h>
#include <sys/resource.h>

#define MAX_PROCESS_NAME_LENGTH 1024

typedef struct {
    pid_t pid;
    char name[MAX_PROCESS_NAME_LENGTH];
    int status;
} Process;

void print_processes(Process *processes, int num_processes) {
    printf("PID\tName\tStatus\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%d\t%s\t%d\n", processes[i].pid, processes[i].name, processes[i].status);
    }
}

void monitor_processes(Process *processes, int num_processes) {
    while (1) {
        int status;
        waitpid(0, &status, WNOHANG);

        for (int i = 0; i < num_processes; i++) {
            if (processes[i].status == 0) {
                if (WIFEXITED(status)) {
                    processes[i].status = WEXITSTATUS(status);
                } else if (WIFSIGNALED(status)) {
                    processes[i].status = WTERMSIG(status);
                }
            }
        }

        print_processes(processes, num_processes);
    }
}

int main() {
    DIR *dir;
    struct dirent *ent;
    Process *processes = NULL;
    int num_processes = 0;

    if ((dir = opendir("/proc"))!= NULL) {
        while ((ent = readdir(dir))!= NULL) {
            if (ent->d_type == DT_DIR) {
                int pid = atoi(ent->d_name);

                char name[MAX_PROCESS_NAME_LENGTH];
                snprintf(name, MAX_PROCESS_NAME_LENGTH, "/proc/%d/comm", pid);

                FILE *file = fopen(name, "r");
                if (file!= NULL) {
                    fgets(name, MAX_PROCESS_NAME_LENGTH, file);
                    name[strcspn(name, "\n")] = '\0'; // Remove newline character

                    processes = realloc(processes, sizeof(Process) * ++num_processes);
                    processes[num_processes - 1].pid = pid;
                    strncpy(processes[num_processes - 1].name, name, MAX_PROCESS_NAME_LENGTH);
                }

                fclose(file);
            }
        }

        closedir(dir);
    }

    monitor_processes(processes, num_processes);

    return 0;
}