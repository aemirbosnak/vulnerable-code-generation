//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/time.h>
#include <time.h>
#include <signal.h>

#define MAX_PROCESSES 1000
#define MAX_ARGS 1000

typedef struct {
    int pid;
    int status;
    char name[MAX_ARGS];
} process_t;

void print_processes(process_t *processes, int num_processes) {
    for (int i = 0; i < num_processes; i++) {
        printf("%d %s\n", processes[i].pid, processes[i].name);
    }
}

int main(int argc, char **argv) {
    int num_processes = 0;
    process_t processes[MAX_PROCESSES];

    while (num_processes < MAX_PROCESSES) {
        char line[MAX_ARGS];
        if (fgets(line, MAX_ARGS, stdin) == NULL) {
            break;
        }
        if (line[0] == 'q') {
            break;
        }
        char *token = strtok(line, " ");
        int pid = atoi(token);
        token = strtok(NULL, " ");
        strcpy(processes[num_processes].name, token);
        processes[num_processes].pid = pid;
        num_processes++;
    }

    printf("Processes:\n");
    print_processes(processes, num_processes);

    for (int i = 0; i < num_processes; i++) {
        int status;
        waitpid(processes[i].pid, &status, WUNTRACED);
        processes[i].status = status;
    }

    printf("\n");
    print_processes(processes, num_processes);

    return 0;
}