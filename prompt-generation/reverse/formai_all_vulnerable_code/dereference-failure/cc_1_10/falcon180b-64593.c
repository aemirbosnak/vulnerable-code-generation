//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>

#define MAX_PROCESSES 1024
#define MAX_COMMAND_LENGTH 1024

struct process {
    int pid;
    char command[MAX_COMMAND_LENGTH];
};

int num_processes = 0;
struct process processes[MAX_PROCESSES];

void read_processes() {
    DIR *dir;
    struct dirent *ent;
    char path[1024];

    if ((dir = opendir("/proc"))!= NULL) {
        while ((ent = readdir(dir))!= NULL) {
            if (ent->d_type == DT_DIR && isdigit(ent->d_name[0])) {
                snprintf(path, sizeof(path), "/proc/%s/cmdline", ent->d_name);
                FILE *file = fopen(path, "r");
                if (file!= NULL) {
                    char command[MAX_COMMAND_LENGTH];
                    if (fgets(command, sizeof(command), file)!= NULL) {
                        processes[num_processes].pid = atoi(ent->d_name);
                        strncpy(processes[num_processes].command, command, MAX_COMMAND_LENGTH - 1);
                        processes[num_processes].command[MAX_COMMAND_LENGTH - 1] = '\0';
                        num_processes++;
                    }
                    fclose(file);
                }
            }
        }
        closedir(dir);
    }
}

void print_processes() {
    for (int i = 0; i < num_processes; i++) {
        printf("%d - %s\n", processes[i].pid, processes[i].command);
    }
}

int main() {
    read_processes();
    print_processes();

    return 0;
}