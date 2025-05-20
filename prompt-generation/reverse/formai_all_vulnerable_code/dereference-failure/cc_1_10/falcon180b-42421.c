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

#define MAX_PROCESSES 100
#define MAX_COMMAND_LEN 1024

typedef struct process {
    int pid;
    char command[MAX_COMMAND_LEN];
} Process;

void print_processes(Process *processes, int num_processes) {
    printf("PID\tCommand\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%d\t%s\n", processes[i].pid, processes[i].command);
    }
}

int main() {
    Process processes[MAX_PROCESSES];
    int num_processes = 0;

    DIR *dir;
    struct dirent *ent;
    if ((dir = opendir("/proc"))!= NULL) {
        while ((ent = readdir(dir))!= NULL) {
            if (ent->d_type == DT_DIR) {
                int pid = atoi(ent->d_name);
                if (pid > 0 && pid <= 9999) {
                    char command[MAX_COMMAND_LEN];
                    sprintf(command, "/proc/%d/cmdline", pid);
                    FILE *fp = fopen(command, "r");
                    if (fp!= NULL) {
                        fgets(command, MAX_COMMAND_LEN, fp);
                        fclose(fp);

                        strtok(command, "\n");
                        strcpy(processes[num_processes].command, command);
                        processes[num_processes].pid = pid;
                        num_processes++;
                    }
                }
            }
        }
        closedir(dir);
    }

    print_processes(processes, num_processes);

    return 0;
}