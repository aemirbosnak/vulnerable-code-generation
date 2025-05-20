//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <ctype.h>

#define BUFFER_SIZE 256
#define MAX_PROCESSES 1024

typedef struct {
    int pid;
    char command[BUFFER_SIZE];
    float cpu_usage;
} ProcessInfo;

float get_cpu_usage(int pid) {
    char path[BUFFER_SIZE];
    FILE *file;
    float cpu_usage = 0.0;

    snprintf(path, sizeof(path), "/proc/%d/stat", pid);
    file = fopen(path, "r");
    if (file) {
        int utime, stime;
        fscanf(file, "%*d %*s %*c %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %d %d", &utime, &stime);
        cpu_usage = (float)(utime + stime);
        fclose(file);
    }
    return cpu_usage;
}

void list_processes(const char *filter) {
    DIR *proc_dir;
    struct dirent *entry;
    ProcessInfo processes[MAX_PROCESSES];
    int count = 0;

    proc_dir = opendir("/proc");
    if (!proc_dir) {
        perror("opendir");
        return;
    }

    while ((entry = readdir(proc_dir)) != NULL) {
        if (isdigit(entry->d_name[0])) {
            int pid = atoi(entry->d_name);
            char path[BUFFER_SIZE];
            snprintf(path, sizeof(path), "/proc/%d/comm", pid);
            FILE *comm_file = fopen(path, "r");
            if (comm_file) {
                char command[BUFFER_SIZE];
                fgets(command, sizeof(command), comm_file);
                command[strcspn(command, "\n")] = 0; // Remove newline character

                if (strstr(command, filter) != NULL) {
                    processes[count].pid = pid;
                    strncpy(processes[count].command, command, sizeof(processes[count].command));
                    processes[count].cpu_usage = get_cpu_usage(pid);
                    count++;
                }
                fclose(comm_file);
            }
        }
    }
    closedir(proc_dir);

    printf("PID\tCPU Usage\tCommand\n");
    printf("-------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%.2f\t\t%s\n", processes[i].pid, processes[i].cpu_usage, processes[i].command);
    }
}

int main() {
    char filter[BUFFER_SIZE];

    printf("Enter a string to filter processes by command name: ");
    fgets(filter, sizeof(filter), stdin);
    filter[strcspn(filter, "\n")] = 0; // Remove newline character

    list_processes(filter);
    return 0;
}