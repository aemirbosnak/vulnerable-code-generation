//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <dirent.h>
#include <libgen.h>
#include <sys/wait.h>

#define MAX_PROCESSES 100
#define MAX_LINE_LENGTH 1024

typedef struct {
    char name[MAX_LINE_LENGTH];
    pid_t pid;
} Process;

void display_processes(Process *processes, int count) {
    printf("Name\tPID\n");
    for (int i = 0; i < count; i++) {
        printf("%s\t%d\n", processes[i].name, processes[i].pid);
    }
}

int main() {
    char command[MAX_LINE_LENGTH];
    char *args[MAX_LINE_LENGTH/2];
    pid_t pid;
    int status;
    int i;
    char cwd[MAX_LINE_LENGTH];
    DIR *dir;
    struct dirent *ent;
    Process processes[MAX_PROCESSES];
    int count = 0;

    // Get the current working directory
    if (getcwd(cwd, MAX_LINE_LENGTH) == NULL) {
        printf("Error: Failed to get current working directory.\n");
        return 1;
    }

    // Open the directory and read the contents
    dir = opendir(cwd);
    if (dir == NULL) {
        printf("Error: Failed to open directory.\n");
        return 1;
    }

    while ((ent = readdir(dir))!= NULL) {
        if (ent->d_type == DT_DIR) {
            continue;
        }

        snprintf(command, MAX_LINE_LENGTH, "ps -p %d -o name=", ent->d_ino);
        if (system(command) == -1) {
            printf("Error: Failed to execute command.\n");
            return 1;
        }

        if (waitpid(pid, &status, WUNTRACED) == -1) {
            printf("Error: Failed to wait for process.\n");
            return 1;
        }

        if (WIFEXITED(status)) {
            strcpy(processes[count].name, basename(ent->d_name));
            processes[count].pid = WEXITSTATUS(status);
            count++;

            if (count >= MAX_PROCESSES) {
                break;
            }
        }
    }

    closedir(dir);

    display_processes(processes, count);

    return 0;
}