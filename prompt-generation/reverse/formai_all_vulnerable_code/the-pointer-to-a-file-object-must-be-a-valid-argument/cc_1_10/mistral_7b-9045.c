//MISTRAL-7B DATASET v1.0 Category: System process viewer ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_PROCS 50

typedef struct {
    pid_t pid;
    char cmd[256];
} Process;

void print_process(Process p) {
    printf("%5d %s\n", p.pid, p.cmd);
}

int main() {
    Process procs[MAX_PROCS];
    int num_procs = 0;

    char command[256];
    snprintf(command, sizeof(command), "ps aux --no-headers --format='%d %s' | tr -s '/' '\n' | sed 's/[^0-9]*//g' | head -n %d", MAX_PROCS);

    FILE *pipe = popen(command, "r");

    char line[128];
    int i = 0;
    while (fgets(line, sizeof(line), pipe) != NULL) {
        Process p;
        sscanf(line, "%d %s", &p.pid, p.cmd);

        if (num_procs >= MAX_PROCS) {
            printf("Maximum number of processes reached.\n");
            break;
        }

        procs[num_procs++] = p;
    }

    pclose(pipe);

    if (num_procs > 0) {
        printf("\n Process List:\n");
        for (int i = 0; i < num_procs; ++i) {
            print_process(procs[i]);
        }
    }

    return 0;
}