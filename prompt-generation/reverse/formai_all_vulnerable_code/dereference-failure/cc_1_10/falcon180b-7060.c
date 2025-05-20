//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <sys/wait.h>

#define MAX_LINE 1024
#define MAX_PROCESSES 1024

typedef struct process {
    int pid;
    char name[MAX_LINE];
} process_t;

int compare_processes(const void *a, const void *b) {
    const process_t *process1 = a;
    const process_t *process2 = b;

    return strcmp(process1->name, process2->name);
}

int main() {
    DIR *dir;
    struct dirent *ent;
    char proc_path[MAX_LINE];
    char cmdline_path[MAX_LINE];
    char buf[MAX_LINE];
    FILE *fp;
    int i = 0;
    int num_processes = 0;
    process_t *processes = NULL;

    dir = opendir("/proc");
    if (dir == NULL) {
        printf("Error opening /proc directory.\n");
        exit(1);
    }

    while ((ent = readdir(dir))!= NULL) {
        if (ent->d_type == DT_DIR && ent->d_name[0] >= '0' && ent->d_name[0] <= '9') {
            sprintf(proc_path, "/proc/%s/cmdline", ent->d_name);
            fp = fopen(proc_path, "r");
            if (fp == NULL) {
                continue;
            }

            fgets(buf, MAX_LINE, fp);
            fclose(fp);

            if (num_processes >= MAX_PROCESSES) {
                printf("Maximum number of processes reached.\n");
                break;
            }

            processes = realloc(processes, sizeof(process_t) * (num_processes + 1));
            strcpy(processes[num_processes].name, buf);
            processes[num_processes].pid = atoi(ent->d_name);
            num_processes++;
        }
    }

    closedir(dir);

    qsort(processes, num_processes, sizeof(process_t), compare_processes);

    for (i = 0; i < num_processes; i++) {
        printf("%d: %s\n", processes[i].pid, processes[i].name);
    }

    free(processes);
    return 0;
}