//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>
#include <unistd.h>

#define MAX_PATH 256

typedef struct Process {
    int pid;
    int ppid;
    char name[256];
} Process;

void view_processes(int ppid, int level) {
    DIR *dir;
    struct dirent *entry;

    if (!(dir = opendir("/proc"))) {
        perror("opendir");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (isdigit(entry->d_name[0])) {
            Process proc;
            char path[MAX_PATH];
            FILE *fp;

            proc.pid = atoi(entry->d_name);
            snprintf(proc.name, sizeof(proc.name), "%s", entry->d_name);
            snprintf(path, sizeof(path), "/proc/%s/stat", entry->d_name);

            fp = fopen(path, "r");
            if (fp) {
                fscanf(fp, "%d %s %*c %d", &proc.pid, proc.name, &proc.ppid);
                fclose(fp);

                // Check the parent process id
                if (proc.ppid == ppid) {
                    // Print current process with indentation based on the recursion level
                    for (int i = 0; i < level; ++i) {
                        printf("    ");
                    }
                    printf("PID: %d, PPID: %d, Name: %s\n", proc.pid, proc.ppid, proc.name);

                    // Recursively view child processes
                    view_processes(proc.pid, level + 1);
                }
            }
        }
    }
    closedir(dir);
}

int main() {
    printf("Process Viewer\n");
    printf("===============\n");
    printf("Displaying process hierarchy starting from PPID 1 (init process)\n\n");
    view_processes(1, 0);
    return 0;
}