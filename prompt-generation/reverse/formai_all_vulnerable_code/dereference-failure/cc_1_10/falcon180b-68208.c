//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_PROCESSES 100
#define MAX_COMMAND_LEN 1024

typedef struct {
    pid_t pid;
    char command[MAX_COMMAND_LEN];
    int status;
} process_t;

void print_processes(process_t *processes, int num_processes) {
    printf("PID\tCommand\tStatus\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%d\t%s\t%d\n", processes[i].pid, processes[i].command, processes[i].status);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s [interval]\n", argv[0]);
        return 1;
    }

    int interval = atoi(argv[1]);
    if (interval <= 0) {
        printf("Invalid interval\n");
        return 1;
    }

    process_t processes[MAX_PROCESSES];
    int num_processes = 0;

    while (1) {
        num_processes = 0;

        FILE *fp = fopen("/proc/self/status", "r");
        if (fp == NULL) {
            perror("fopen");
            continue;
        }

        char line[MAX_COMMAND_LEN];
        while (fgets(line, MAX_COMMAND_LEN, fp)!= NULL) {
            if (strncmp(line, "Name:", 5) == 0) {
                strtok(line, ":");
                strtok(NULL, ":");
                strcpy(processes[num_processes].command, line);
            }
        }

        fclose(fp);

        for (int i = 0; i < num_processes; i++) {
            printf("Watching process: %s\n", processes[i].command);
        }

        sleep(interval);
    }

    return 0;
}