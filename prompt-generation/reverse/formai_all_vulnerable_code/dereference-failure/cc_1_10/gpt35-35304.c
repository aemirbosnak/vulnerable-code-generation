//FormAI DATASET v1.0 Category: System process viewer ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>

struct process_info {
    int pid;
    char name[100];
};

int main() {
    DIR *dir;
    struct dirent *entry;
    FILE *fp;
    char path[100];
    char buffer[1000];
    int pid;
    int count = 0;
    struct process_info processes[100];

    printf("PID\t\tProcess Name\n");

    dir = opendir("/proc");
    if (dir == NULL) {
        printf("Error opening /proc directory");
        return 1;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_DIR) {
            pid = atoi(entry->d_name);
            if (pid != 0) {
                sprintf(path, "/proc/%d/cmdline", pid);
                fp = fopen(path, "r");
                if (fp != NULL) {
                    fgets(buffer, sizeof(buffer), fp);
                    fclose(fp);
                    strcpy(processes[count].name, buffer);
                    processes[count].pid = pid;
                    count++;
                }
            }
        }
    }

    closedir(dir);

    struct process_info temp;

    for (int i = 0; i < count; i++) {
        for (int j = i + 1; j < count; j++) {
            if (strcmp(processes[i].name, processes[j].name) > 0) {
                temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
        printf("%d\t\t%s", processes[i].pid, processes[i].name);
    }

    return 0;
}