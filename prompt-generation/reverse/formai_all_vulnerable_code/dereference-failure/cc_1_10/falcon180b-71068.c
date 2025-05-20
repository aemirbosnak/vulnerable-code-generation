//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include <dirent.h>

#define MAX_PROCESSES 100
#define MAX_LINE_LENGTH 2048

typedef struct {
    int pid;
    char name[MAX_LINE_LENGTH];
} process_t;

void print_processes(process_t *processes, int num_processes) {
    printf("PID\tName\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%d\t%s\n", processes[i].pid, processes[i].name);
    }
}

int read_processes(process_t *processes, int max_processes) {
    char line[MAX_LINE_LENGTH];
    FILE *proc_file = fopen("/proc/self/task", "r");
    if (proc_file == NULL) {
        printf("Error reading /proc/self/task\n");
        return -1;
    }

    int num_processes = 0;
    while (fgets(line, MAX_LINE_LENGTH, proc_file)!= NULL) {
        if (num_processes >= max_processes) {
            break;
        }
        char *pid_str = strtok(line, " ");
        int pid = atoi(pid_str);
        char *name = strtok(NULL, " ");
        if (name!= NULL && strlen(name) > 0) {
            strcpy(processes[num_processes].name, name);
        }
        processes[num_processes].pid = pid;
        num_processes++;
    }

    fclose(proc_file);
    return num_processes;
}

int main() {
    process_t processes[MAX_PROCESSES];
    int num_processes = read_processes(processes, MAX_PROCESSES);
    if (num_processes < 0) {
        return -1;
    }

    print_processes(processes, num_processes);

    return 0;
}