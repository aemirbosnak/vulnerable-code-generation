//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <libgen.h>
#include <sys/wait.h>

#define MAX_PROCESSES 100
#define MAX_COMMAND_LENGTH 1024

typedef struct process {
    char command[MAX_COMMAND_LENGTH];
    pid_t pid;
    int status;
} Process;

void print_process(Process* p) {
    printf("PID: %d\n", p->pid);
    printf("Command: %s\n", p->command);
    printf("Status: %d\n", p->status);
    printf("\n");
}

int main() {
    DIR* dir;
    struct dirent* ent;
    Process processes[MAX_PROCESSES];
    int num_processes = 0;

    dir = opendir("/proc");

    if (dir == NULL) {
        printf("Error opening /proc directory.\n");
        return 1;
    }

    while ((ent = readdir(dir))!= NULL) {
        if (ent->d_type == DT_DIR) {
            char path[MAX_COMMAND_LENGTH];
            snprintf(path, MAX_COMMAND_LENGTH, "/proc/%s/cmdline", ent->d_name);

            FILE* file = fopen(path, "r");

            if (file == NULL) {
                continue;
            }

            Process* p = &processes[num_processes];
            strcpy(p->command, "");

            char buffer[MAX_COMMAND_LENGTH];
            while (fgets(buffer, MAX_COMMAND_LENGTH, file)!= NULL) {
                strcat(p->command, buffer);
            }

            fclose(file);
            p->pid = atoi(ent->d_name);
            p->status = 0;

            num_processes++;
        }
    }

    closedir(dir);

    while (1) {
        system("clear");

        printf("PID\tCommand\tStatus\n");

        for (int i = 0; i < num_processes; i++) {
            print_process(&processes[i]);
        }

        sleep(1);
    }

    return 0;
}