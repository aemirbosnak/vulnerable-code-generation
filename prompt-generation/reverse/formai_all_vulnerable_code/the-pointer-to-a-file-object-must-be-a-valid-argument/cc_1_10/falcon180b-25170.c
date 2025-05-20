//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/mman.h>
#include <sys/ptrace.h>
#include <sys/user.h>
#include <sys/reg.h>

#define PAGE_SIZE 4096
#define MAX_PIDS 1000

typedef struct {
    int pid;
    char name[16];
    char state;
} process;

void get_processes(process* procs, int count) {
    FILE* fp = fopen("/proc/self/task/", "r");
    char line[1024];
    int i = 0;

    while (fgets(line, sizeof(line), fp)!= NULL) {
        if (i >= count) {
            break;
        }

        int pid = atoi(line);
        snprintf(procs[i].name, sizeof(procs[i].name), "%d", pid);
        procs[i].pid = pid;
        procs[i].state = 'R';
        i++;
    }

    fclose(fp);
}

void print_processes(process* procs, int count) {
    printf("PID\tName\tState\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%s\t%c\n", procs[i].pid, procs[i].name, procs[i].state);
    }
}

int main() {
    process procs[MAX_PIDS];
    int count = 0;

    get_processes(procs, MAX_PIDS);
    print_processes(procs, count);

    return 0;
}