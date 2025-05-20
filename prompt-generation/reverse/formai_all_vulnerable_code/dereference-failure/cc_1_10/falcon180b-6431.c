//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <errno.h>

#define MAX_PROCESSES 100
#define MAX_PROCESS_NAME 50

typedef struct {
    int pid;
    char name[MAX_PROCESS_NAME];
} Process;

int get_processes(Process *processes) {
    DIR *dir;
    struct dirent *ent;
    int count = 0;

    if ((dir = opendir("/proc"))!= NULL) {
        while ((ent = readdir(dir))!= NULL) {
            if (ent->d_type == DT_DIR) {
                int pid = atoi(ent->d_name);
                if (count < MAX_PROCESSES) {
                    snprintf(processes[count].name, MAX_PROCESS_NAME, "%d", pid);
                    processes[count].pid = pid;
                    count++;
                }
            }
        }
        closedir(dir);
    } else {
        perror("");
        return -1;
    }

    return count;
}

void print_processes(Process *processes, int count) {
    printf("PID\tName\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%s\n", processes[i].pid, processes[i].name);
    }
}

int main() {
    Process processes[MAX_PROCESSES];
    int count = get_processes(processes);

    if (count > 0) {
        print_processes(processes, count);
    } else {
        printf("No processes found.\n");
    }

    return 0;
}