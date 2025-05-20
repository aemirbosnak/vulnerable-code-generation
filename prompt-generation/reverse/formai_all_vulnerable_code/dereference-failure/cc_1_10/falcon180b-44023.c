//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <errno.h>
#include <ctype.h>
#include <dirent.h>

#define MAX_PROCESSES 100
#define BUFFER_SIZE 4096

typedef struct process {
    pid_t pid;
    char name[128];
    int status;
    int ppid;
    int pri;
} Process;

void read_proc(int fd, Process *processes) {
    char buffer[BUFFER_SIZE];
    char *line = NULL;
    size_t len = 0;
    Process *p = processes;
    while ((getline(&line, &len, fd))!= -1) {
        if (strlen(line) > 0) {
            sscanf(line, "%d %s %d %d %d", &p->pid, p->name, &p->ppid, &p->pri, &p->status);
            p++;
            if (p - processes >= MAX_PROCESSES) {
                break;
            }
        }
    }
}

void print_processes(Process *processes, int count) {
    printf("PID\tName\tPPID\tPRI\tStatus\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%s\t%d\t%d\t%d\n", processes[i].pid, processes[i].name, processes[i].ppid, processes[i].pri, processes[i].status);
    }
}

int main() {
    DIR *dir;
    struct dirent *ent;
    char path[128];
    int count = 0;
    Process processes[MAX_PROCESSES];

    dir = opendir("/proc");
    if (dir == NULL) {
        perror("opendir");
        exit(1);
    }

    while ((ent = readdir(dir))!= NULL) {
        if (isdigit(ent->d_name[0])) {
            sprintf(path, "/proc/%s/status", ent->d_name);
            int fd = open(path, O_RDONLY);
            if (fd!= -1) {
                read_proc(fd, processes);
                close(fd);
                count++;
            }
        }
    }

    closedir(dir);
    print_processes(processes, count);

    return 0;
}