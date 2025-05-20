//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>

#define MAX_PROCESSES 256
#define MAX_COMMAND_LENGTH 1024

typedef struct process {
    int pid;
    char command[MAX_COMMAND_LENGTH];
} process_t;

void read_processes(process_t processes[], int *count) {
    DIR *dir;
    struct dirent *ent;
    char path[MAX_COMMAND_LENGTH];

    snprintf(path, sizeof(path), "/proc");
    dir = opendir(path);

    if (dir == NULL) {
        fprintf(stderr, "Error: Unable to open /proc directory.\n");
        exit(1);
    }

    int i = 0;
    while ((ent = readdir(dir))!= NULL) {
        if (ent->d_type == DT_DIR && ent->d_name[0] >= '0' && ent->d_name[0] <= '9') {
            snprintf(path, sizeof(path), "/proc/%s/cmdline", ent->d_name);
            FILE *file = fopen(path, "r");

            if (file == NULL) {
                fprintf(stderr, "Error: Unable to read process command line for PID %s.\n", ent->d_name);
                continue;
            }

            fgets(processes[i].command, MAX_COMMAND_LENGTH, file);
            processes[i].command[strcspn(processes[i].command, "\n")] = '\0';
            processes[i].pid = atoi(ent->d_name);

            fclose(file);
            i++;
        }
    }

    *count = i;
    closedir(dir);
}

void print_processes(process_t processes[], int count) {
    printf("PID\tCommand\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%s\n", processes[i].pid, processes[i].command);
    }
}

int main() {
    process_t processes[MAX_PROCESSES];
    int count;

    read_processes(processes, &count);
    print_processes(processes, count);

    return 0;
}