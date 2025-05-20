//GEMINI-pro DATASET v1.0 Category: System process viewer ; Style: unmistakable
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/sysinfo.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    pid_t pid;
    char *name;
    int state;
} process_t;

int main() {
    struct sysinfo info;
    if (sysinfo(&info) == -1) {
        perror("sysinfo");
        return 1;
    }

    process_t *processes = malloc(sizeof(process_t) * info.procs);
    if (processes == NULL) {
        perror("malloc");
        return 1;
    }

    FILE *f = fopen("/proc", "r");
    if (f == NULL) {
        perror("fopen");
        return 1;
    }

    char line[1024];
    while (fgets(line, sizeof(line), f) != NULL) {
        if (line[0] == '0') {
            continue;
        }

        char *name = malloc(1024);
        if (name == NULL) {
            perror("malloc");
            return 1;
        }

        int pid = atoi(line);

        char state;
        if (fscanf(f, "Name: %s\nState: %c\n", name, &state) != 2) {
            perror("fscanf");
            return 1;
        }

        processes[pid].pid = pid;
        processes[pid].name = name;
        processes[pid].state = state;
    }

    fclose(f);

    qsort(processes, info.procs, sizeof(process_t), (int (*)(const void *, const void *))strcmp);

    for (int i = 0; i < info.procs; i++) {
        printf("%d\t%s\t%c\n", processes[i].pid, processes[i].name, processes[i].state);
    }

    free(processes);

    return 0;
}