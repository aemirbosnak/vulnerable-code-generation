//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <sys/wait.h>

#define MAX_PROCESSES 100
#define MAX_LINE 1024

struct process {
    int pid;
    char name[MAX_LINE];
};

int get_processes(struct process* processes, int max_processes) {
    DIR* dir = opendir("/proc");
    if (dir == NULL) {
        printf("Error: could not open /proc directory\n");
        return -1;
    }

    int count = 0;
    struct dirent* entry;
    while ((entry = readdir(dir))!= NULL && count < max_processes) {
        if (isdigit(entry->d_name[0])) {
            int pid = atoi(entry->d_name);
            char path[MAX_LINE];
            snprintf(path, MAX_LINE, "/proc/%d/cmdline", pid);
            FILE* file = fopen(path, "r");
            if (file!= NULL) {
                char name[MAX_LINE];
                if (fgets(name, MAX_LINE, file)!= NULL) {
                    name[strcspn(name, "\n")] = '\0';
                    strcpy(processes[count].name, name);
                    processes[count].pid = pid;
                    count++;
                }
                fclose(file);
            }
        }
    }

    closedir(dir);
    return count;
}

void print_processes(struct process* processes, int count) {
    printf("PID\tName\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%s\n", processes[i].pid, processes[i].name);
    }
}

int main() {
    struct process processes[MAX_PROCESSES];
    int count = get_processes(processes, MAX_PROCESSES);
    if (count > 0) {
        print_processes(processes, count);
    } else {
        printf("No processes found\n");
    }

    return 0;
}