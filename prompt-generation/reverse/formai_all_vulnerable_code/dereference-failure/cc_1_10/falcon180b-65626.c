//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>

#define BUFFER_SIZE 1024

typedef struct process {
    int pid;
    char name[BUFFER_SIZE];
    int status;
} Process;

void read_processes(Process *processes, int count) {
    char path[BUFFER_SIZE];
    snprintf(path, BUFFER_SIZE, "/proc/%d/cmdline", processes[0].pid);
    FILE *file = fopen(path, "r");
    if (file!= NULL) {
        char cmdline[BUFFER_SIZE];
        fgets(cmdline, BUFFER_SIZE, file);
        fclose(file);
        strncpy(processes[0].name, cmdline, BUFFER_SIZE - 1);
    } else {
        strcpy(processes[0].name, "unknown");
    }
}

void print_processes(Process *processes, int count) {
    printf("PID\tName\tStatus\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%s\t%d\n", processes[i].pid, processes[i].name, processes[i].status);
    }
}

int main() {
    DIR *dir;
    struct dirent *ent;
    int count = 0;
    Process processes[1024];

    if ((dir = opendir("/proc"))!= NULL) {
        while ((ent = readdir(dir))!= NULL) {
            int pid = atoi(ent->d_name);
            if (count >= 1024) {
                break;
            }
            processes[count].pid = pid;
            count++;
        }
        closedir(dir);
    }

    for (int i = 0; i < count; i++) {
        read_processes(processes, count);
    }

    print_processes(processes, count);

    return 0;
}