//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <dirent.h>

#define MAX_PROCESSES 100

typedef struct {
    int pid;
    char name[100];
    int status;
} process;

void print_processes(process *processes, int num_processes) {
    for (int i = 0; i < num_processes; i++) {
        printf("%d\t%s\t%d\n", processes[i].pid, processes[i].name, processes[i].status);
    }
}

int get_processes(process *processes, int max_processes) {
    DIR *dir = opendir("/proc");
    struct dirent *ent;
    int num_processes = 0;

    while ((ent = readdir(dir))!= NULL) {
        if (ent->d_type == DT_DIR && strcmp(ent->d_name, ".")!= 0 && strcmp(ent->d_name, "..")!= 0) {
            if (num_processes >= max_processes) {
                closedir(dir);
                return num_processes;
            }

            char path[100];
            sprintf(path, "/proc/%s/cmdline", ent->d_name);

            int fd = open(path, O_RDONLY);

            if (fd!= -1) {
                char *cmdline = NULL;
                ssize_t len = read(fd, &cmdline, 100);

                if (len > 0) {
                    cmdline[len - 1] = '\0';
                    strncpy(processes[num_processes].name, cmdline, 100);
                } else {
                    strcpy(processes[num_processes].name, "Unknown");
                }

                close(fd);
            } else {
                strcpy(processes[num_processes].name, "Unknown");
            }

            processes[num_processes].pid = atoi(ent->d_name);
            processes[num_processes].status = 0;

            num_processes++;
        }
    }

    closedir(dir);

    return num_processes;
}

int main() {
    process processes[MAX_PROCESSES];
    int num_processes = get_processes(processes, MAX_PROCESSES);

    printf("PID\tName\tStatus\n");
    print_processes(processes, num_processes);

    return 0;
}