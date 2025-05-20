//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <dirent.h>

#define MAX_PROCESSES 100
#define MAX_COMMAND_LENGTH 1024

struct process {
    char command[MAX_COMMAND_LENGTH];
    int pid;
    int status;
};

void print_processes(struct process processes[], int num_processes) {
    for (int i = 0; i < num_processes; i++) {
        printf("%s (%d)\n", processes[i].command, processes[i].pid);
    }
}

int main() {
    struct process processes[MAX_PROCESSES];
    int num_processes = 0;

    DIR *dir;
    struct dirent *ent;

    if ((dir = opendir("/proc"))!= NULL) {
        while ((ent = readdir(dir))!= NULL) {
            if (ent->d_type == DT_DIR) {
                char path[100];
                sprintf(path, "/proc/%s/cmdline", ent->d_name);

                int fd = open(path, O_RDONLY);
                if (fd >= 0) {
                    char command[MAX_COMMAND_LENGTH];
                    int bytes_read = read(fd, command, MAX_COMMAND_LENGTH - 1);
                    close(fd);

                    if (bytes_read > 0 && command[bytes_read - 1] == '\0') {
                        processes[num_processes].command[bytes_read] = '\0';
                        strncpy(processes[num_processes].command, command, MAX_COMMAND_LENGTH - 1);
                        processes[num_processes].pid = atoi(ent->d_name);
                        processes[num_processes].status = -1;
                        num_processes++;
                    }
                }
            }
        }
        closedir(dir);
    }

    while (1) {
        print_processes(processes, num_processes);

        for (int i = 0; i < num_processes; i++) {
            if (processes[i].status == -1) {
                processes[i].status = waitpid(processes[i].pid, NULL, WNOHANG);
            }
        }

        sleep(1);
    }

    return 0;
}