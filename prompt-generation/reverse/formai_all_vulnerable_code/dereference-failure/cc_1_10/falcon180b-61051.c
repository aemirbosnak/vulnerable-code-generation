//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <libgen.h>

#define MAX_PROCESSES 1024
#define MAX_COMMAND_LENGTH 1024
#define MAX_USER_LENGTH 32

typedef struct {
    int pid;
    char command[MAX_COMMAND_LENGTH];
    char user[MAX_USER_LENGTH];
} process_t;

int main(int argc, char **argv) {
    if (argc!= 2) {
        printf("Usage: %s <process-id>\n", argv[0]);
        exit(1);
    }

    int pid = atoi(argv[1]);
    char proc_path[64];
    snprintf(proc_path, sizeof(proc_path), "/proc/%d", pid);

    FILE *fp = fopen(proc_path, "r");
    if (fp == NULL) {
        printf("Cannot open process with PID %d\n", pid);
        exit(1);
    }

    process_t processes[MAX_PROCESSES];
    int num_processes = 0;

    while (fgets(processes[num_processes].command, MAX_COMMAND_LENGTH, fp)!= NULL) {
        processes[num_processes++].pid = pid;
        processes[num_processes - 1].command[strcspn(processes[num_processes - 1].command, "\n")] = '\0';
        char *user_name = basename(processes[num_processes - 1].command);
        strncpy(processes[num_processes - 1].user, user_name, MAX_USER_LENGTH);
    }

    fclose(fp);

    printf("Processes for PID %d:\n", pid);
    for (int i = 0; i < num_processes; i++) {
        printf("%d: %s (%s)\n", processes[i].pid, processes[i].command, processes[i].user);
    }

    return 0;
}