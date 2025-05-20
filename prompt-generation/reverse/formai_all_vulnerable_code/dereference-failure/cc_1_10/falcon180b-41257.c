//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <dirent.h>

#define MAX_PROCESSES 1024
#define MAX_PROCESS_NAME_LEN 1024

struct process {
    int pid;
    char name[MAX_PROCESS_NAME_LEN];
};

int get_processes(struct process *processes, int max_processes) {
    DIR *dir;
    struct dirent *ent;
    char path[1024];
    int count = 0;

    snprintf(path, sizeof(path), "/proc");
    dir = opendir(path);
    if (!dir) {
        return -1;
    }

    while ((ent = readdir(dir))!= NULL && count < max_processes) {
        int len;
        snprintf(path, sizeof(path), "/proc/%s", ent->d_name);
        len = readlink(path, processes[count].name, MAX_PROCESS_NAME_LEN - 1);
        if (len > 0) {
            processes[count].name[len] = '\0';
            processes[count].pid = atoi(ent->d_name);
            count++;
        }
    }

    closedir(dir);
    return count;
}

void print_processes(struct process *processes, int num_processes) {
    int i;

    for (i = 0; i < num_processes; i++) {
        printf("%d: %s\n", processes[i].pid, processes[i].name);
    }
}

int main(int argc, char *argv[]) {
    struct process processes[MAX_PROCESSES];
    int num_processes;

    num_processes = get_processes(processes, MAX_PROCESSES);
    if (num_processes < 0) {
        fprintf(stderr, "Error getting processes\n");
        return 1;
    }

    print_processes(processes, num_processes);

    return 0;
}