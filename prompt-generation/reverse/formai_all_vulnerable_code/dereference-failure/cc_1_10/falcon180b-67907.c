//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/mman.h>
#include <errno.h>

#define PROC_PID_LIST "/proc/self/task"
#define MAX_LINE_LEN 1024
#define MAX_PROC_PID 50

typedef struct {
    int pid;
    int status;
    char comm[16];
} proc_t;

int main() {
    FILE *fp;
    char line[MAX_LINE_LEN];
    char *token;
    int count = 0;
    proc_t procs[MAX_PROC_PID];

    fp = fopen(PROC_PID_LIST, "r");

    if (fp == NULL) {
        printf("Error: %s\n", strerror(errno));
        return 1;
    }

    while (fgets(line, MAX_LINE_LEN, fp)!= NULL) {
        token = strtok(line, " ");
        sscanf(token, "%d", &procs[count].pid);
        procs[count].status = 0;
        strcpy(procs[count].comm, "");
        count++;
    }

    fclose(fp);

    printf("PID\tStatus\tCommand\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%d\t%s\n", procs[i].pid, procs[i].status, procs[i].comm);
    }

    return 0;
}