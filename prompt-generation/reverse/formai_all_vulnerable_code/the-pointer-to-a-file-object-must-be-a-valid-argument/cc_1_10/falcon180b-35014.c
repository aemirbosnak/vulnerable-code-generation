//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/sysinfo.h>

typedef struct {
    char *name;
    int id;
    int rss;
} process_t;

int main() {
    int num_processes = 0;
    process_t *processes = NULL;
    struct sysinfo info;

    if (sysinfo(&info) < 0) {
        fprintf(stderr, "Error getting system information.\n");
        return 1;
    }

    num_processes = info.procs;
    processes = (process_t *) malloc(num_processes * sizeof(process_t));

    if (processes == NULL) {
        fprintf(stderr, "Error allocating memory for processes.\n");
        return 1;
    }

    for (int i = 0; i < num_processes; i++) {
        sprintf(processes[i].name, "Process %d", i);
        processes[i].id = i;
        processes[i].rss = 0;
    }

    while (1) {
        for (int i = 0; i < num_processes; i++) {
            sprintf(processes[i].name, "Process %d", i);
            FILE *fp = fopen("/proc/self/status", "r");
            char line[256];

            while (fgets(line, sizeof(line), fp)!= NULL) {
                if (strncmp(line, "VmRSS:", 7) == 0) {
                    sscanf(line, "VmRSS: %d kB", &processes[i].rss);
                    break;
                }
            }

            fclose(fp);
        }

        sleep(5);
    }

    free(processes);
    return 0;
}