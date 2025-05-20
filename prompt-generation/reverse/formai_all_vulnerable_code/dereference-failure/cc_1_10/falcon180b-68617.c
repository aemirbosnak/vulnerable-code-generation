//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>

#define MAX_PROCESSES 1024

struct process {
    char name[32];
    int pid;
    int ppid;
    char state;
    int utime;
    int stime;
    float cpu;
    int priority;
    int nice;
};

void read_processes(struct process *processes) {
    DIR *dir;
    struct dirent *ent;
    char path[1024];
    sprintf(path, "/proc");
    dir = opendir(path);

    if (dir!= NULL) {
        while ((ent = readdir(dir))!= NULL) {
            if (ent->d_type == DT_DIR) {
                int pid = atoi(ent->d_name);
                char cmdline_path[64];
                sprintf(cmdline_path, "/proc/%d/cmdline", pid);
                FILE *fp = fopen(cmdline_path, "r");
                if (fp!= NULL) {
                    fgets(processes[pid].name, 32, fp);
                    fclose(fp);
                } else {
                    strcpy(processes[pid].name, "unknown");
                }
            }
        }
        closedir(dir);
    }
}

void print_processes(struct process *processes, int num_processes) {
    printf("PID\tPPID\tName\tState\tCPU\tPriority\tNice\n");
    for (int i = 0; i < num_processes; i++) {
        if (processes[i].ppid == 1) {
            printf("%d\t%d\t%s\t%c\t%.2f\t%d\t%d\n", processes[i].pid, processes[i].ppid, processes[i].name, processes[i].state, processes[i].cpu, processes[i].priority, processes[i].nice);
        }
    }
}

int main() {
    struct process processes[MAX_PROCESSES];
    int num_processes = 0;

    read_processes(processes);
    print_processes(processes, num_processes);

    return 0;
}