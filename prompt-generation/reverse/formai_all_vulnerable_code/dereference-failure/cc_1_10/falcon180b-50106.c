//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <sys/wait.h>

#define MAX_LINE 1024
#define MAX_PROCESSES 1024

struct process {
    int pid;
    char name[MAX_LINE];
};

void print_processes(struct process *processes, int count) {
    for (int i = 0; i < count; ++i) {
        printf("%d\t%s\n", processes[i].pid, processes[i].name);
    }
}

int get_processes(struct process *processes, int max_count) {
    DIR *dir = opendir("/proc");
    if (dir == NULL) {
        return -1;
    }

    int count = 0;
    struct dirent *ent;
    while ((ent = readdir(dir))!= NULL) {
        if (ent->d_name[0] >= '0' && ent->d_name[0] <= '9') {
            char path[MAX_LINE];
            snprintf(path, MAX_LINE, "/proc/%s/cmdline", ent->d_name);
            FILE *file = fopen(path, "r");
            if (file!= NULL) {
                char line[MAX_LINE];
                if (fgets(line, MAX_LINE, file)!= NULL) {
                    line[strcspn(line, "\n")] = '\0';
                    if (count < max_count) {
                        processes[count].pid = atoi(ent->d_name);
                        strncpy(processes[count].name, line, MAX_LINE - 1);
                        processes[count].name[MAX_LINE - 1] = '\0';
                        ++count;
                    }
                }
                fclose(file);
            }
        }
    }

    closedir(dir);
    return count;
}

int main() {
    struct process processes[MAX_PROCESSES];
    int count = get_processes(processes, MAX_PROCESSES);
    if (count <= 0) {
        printf("Error getting processes\n");
        return 1;
    }

    print_processes(processes, count);
    return 0;
}