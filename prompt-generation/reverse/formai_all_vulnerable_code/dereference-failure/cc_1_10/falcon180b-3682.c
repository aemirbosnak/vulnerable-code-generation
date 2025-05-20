//Falcon-180B DATASET v1.0 Category: System boot optimizer ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_PROCESSES 100

typedef struct {
    char *name;
    int priority;
    int pid;
} Process;

Process processes[MAX_PROCESSES];
int num_processes = 0;

void add_process(char *name, int priority) {
    if (num_processes >= MAX_PROCESSES) {
        printf("Error: Too many processes\n");
        return;
    }

    Process *p = &processes[num_processes];
    p->name = strdup(name);
    p->priority = priority;
    p->pid = 0;

    num_processes++;
}

int compare_processes(const void *a, const void *b) {
    Process *p1 = (Process *)a;
    Process *p2 = (Process *)b;

    if (p1->priority > p2->priority) {
        return -1;
    } else if (p1->priority < p2->priority) {
        return 1;
    } else {
        return 0;
    }
}

void run_processes() {
    qsort(processes, num_processes, sizeof(Process), compare_processes);

    for (int i = 0; i < num_processes; i++) {
        Process *p = &processes[i];

        if (p->pid == 0) {
            int pid = fork();

            if (pid == 0) {
                p->pid = getpid();

                char *argv[3];
                argv[0] = p->name;
                argv[1] = NULL;

                execvp(p->name, argv);

                printf("Error: Failed to execute process %s\n", p->name);
                exit(1);
            } else {
                p->pid = pid;
            }
        } else {
            int status;
            waitpid(p->pid, &status, WNOHANG);

            if (WIFEXITED(status)) {
                p->pid = 0;
            }
        }
    }
}

int main() {
    add_process("ls", 10);
    add_process("grep foo", 20);
    add_process("sort", 30);

    run_processes();

    return 0;
}