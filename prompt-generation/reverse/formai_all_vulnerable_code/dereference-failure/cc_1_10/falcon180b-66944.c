//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_PROCESSES 1024
#define MAX_COMMAND_LENGTH 1024
#define BUFFER_SIZE 4096

typedef struct {
    char command[MAX_COMMAND_LENGTH];
    int pid;
    int status;
    int exit_code;
} process_t;

process_t processes[MAX_PROCESSES];
int num_processes = 0;

void read_processes() {
    DIR *dir;
    struct dirent *ent;
    char path[MAX_COMMAND_LENGTH];

    if ((dir = opendir("/proc"))!= NULL) {
        while ((ent = readdir(dir))!= NULL) {
            if (ent->d_type == DT_DIR) {
                snprintf(path, MAX_COMMAND_LENGTH, "/proc/%s/cmdline", ent->d_name);
                FILE *file = fopen(path, "r");

                if (file!= NULL) {
                    fgets(processes[num_processes].command, MAX_COMMAND_LENGTH, file);
                    fclose(file);

                    processes[num_processes].pid = atoi(ent->d_name);
                    processes[num_processes].status = 0;
                    processes[num_processes].exit_code = 0;

                    num_processes++;
                }
            }
        }

        closedir(dir);
    }
}

void update_processes() {
    for (int i = 0; i < num_processes; i++) {
        if (waitpid(processes[i].pid, &processes[i].status, WNOHANG) == processes[i].pid) {
            processes[i].exit_code = WEXITSTATUS(processes[i].status);
        }
    }
}

void print_processes() {
    printf("PID\tCommand\tStatus\tExit Code\n");

    for (int i = 0; i < num_processes; i++) {
        printf("%d\t%s\t%d\t%d\n", processes[i].pid, processes[i].command, processes[i].status, processes[i].exit_code);
    }
}

int main() {
    read_processes();

    while (1) {
        update_processes();
        print_processes();
        sleep(1);
    }

    return 0;
}