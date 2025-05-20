//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>

#define MAX_PROCESSES 1024
#define MAX_COMMAND_LENGTH 1024

typedef struct {
    pid_t pid;
    char command[MAX_COMMAND_LENGTH];
} process_t;

process_t processes[MAX_PROCESSES];
int num_processes = 0;

void add_process(pid_t pid) {
    process_t *new_process = &processes[num_processes++];
    new_process->pid = pid;
    new_process->command[0] = '\0';
}

void update_process_command(pid_t pid, char *command) {
    int i;
    for (i = 0; i < num_processes; i++) {
        if (processes[i].pid == pid) {
            strncpy(processes[i].command, command, MAX_COMMAND_LENGTH);
            processes[i].command[MAX_COMMAND_LENGTH - 1] = '\0';
            break;
        }
    }
}

int main() {
    DIR *proc_dir;
    struct dirent *dirent;
    char path[MAX_COMMAND_LENGTH];
    proc_dir = opendir("/proc");

    if (proc_dir == NULL) {
        perror("opendir");
        exit(EXIT_FAILURE);
    }

    while ((dirent = readdir(proc_dir))!= NULL) {
        if (dirent->d_type == DT_DIR) {
            snprintf(path, MAX_COMMAND_LENGTH, "/proc/%s/cmdline", dirent->d_name);
            FILE *file = fopen(path, "r");

            if (file!= NULL) {
                char cmdline[MAX_COMMAND_LENGTH];
                fgets(cmdline, MAX_COMMAND_LENGTH, file);
                fclose(file);

                add_process(atoi(dirent->d_name));
                update_process_command(atoi(dirent->d_name), cmdline);
            }
        }
    }

    closedir(proc_dir);

    printf("PID\tCommand\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%d\t%s\n", processes[i].pid, processes[i].command);
    }

    return 0;
}