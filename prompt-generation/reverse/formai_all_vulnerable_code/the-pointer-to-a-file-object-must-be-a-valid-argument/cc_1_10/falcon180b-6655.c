//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_LINE_SIZE 1024
#define MAX_PROCESSES 100

typedef struct {
    int pid;
    char name[MAX_LINE_SIZE];
    int status;
} process_t;

void get_processes(process_t *processes, int max_processes) {
    FILE *fp;
    char line[MAX_LINE_SIZE];
    int count = 0;

    fp = fopen("/proc/self/status", "r");

    while (fgets(line, MAX_LINE_SIZE, fp)!= NULL) {
        if (count >= max_processes) {
            break;
        }

        sscanf(line, "Name:\t%s", processes[count].name);
        processes[count].pid = getpid();
        processes[count].status = 1;
        count++;
    }

    fclose(fp);
}

void print_processes(process_t *processes, int num_processes) {
    int i;

    for (i = 0; i < num_processes; i++) {
        printf("%d: %s\n", processes[i].pid, processes[i].name);
    }
}

int main() {
    process_t processes[MAX_PROCESSES];
    int num_processes = 0;

    get_processes(processes, MAX_PROCESSES);
    print_processes(processes, num_processes);

    return 0;
}