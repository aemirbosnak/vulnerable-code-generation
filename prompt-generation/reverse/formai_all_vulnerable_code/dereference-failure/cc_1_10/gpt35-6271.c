//FormAI DATASET v1.0 Category: System process viewer ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <ctype.h>

#define BUF_SIZE 1024

struct Process {
    char pid[BUF_SIZE];
    char name[BUF_SIZE];
    char mem[BUF_SIZE];
};

void printProcesses(struct Process *processes, int num_processes);

int main() {
    DIR *dir;
    struct dirent *ent;
    char path[BUF_SIZE];

    // Create array to hold all processes
    struct Process *processes = malloc(sizeof(struct Process) * BUF_SIZE);
    int num_processes = 0;

    // Open directory "/proc" to obtain all processes
    dir = opendir("/proc");
    if (dir == NULL) {
        perror("Failed to open /proc directory");
        exit(EXIT_FAILURE);
    }

    // Iterate through all directories in "/proc" to obtain processes
    while ((ent = readdir(dir)) != NULL) {
        if (isdigit(*ent->d_name)) {
            snprintf(path, sizeof(path), "/proc/%s/stat", ent->d_name);
            FILE *file = fopen(path, "r");
            if (file != NULL) {
                int pid;
                char comm[BUF_SIZE], state, ppid;
                fscanf(file, "%d %s %c %d", &pid, comm, &state, &ppid);

                // File contains process name in parenthesis
                char *start = strrchr(comm, '(');
                if (start != NULL) {
                    char *end = strrchr(start + 1, ')');
                    if (end != NULL) {
                        *end = '\0';
                        strcpy(processes[num_processes].name, start + 1);
                    }
                }

                // Obtain process memory from "/proc/[pid]/status"
                snprintf(path, sizeof(path), "/proc/%d/status", pid);
                file = fopen(path, "r");
                if (file != NULL) {
                    char line[BUF_SIZE];
                    while (fgets(line, BUF_SIZE, file) != NULL) {
                        if (strncmp(line, "VmSize:", 7) == 0) {
                            // Remove newline character
                            char *ptr = strchr(line, '\n');
                            if (ptr != NULL) {
                                *ptr = '\0';
                            }

                            // Obtain memory amount
                            ptr = line + 7;
                            while (*ptr == ' ') {
                                ptr++;
                            }
                            strcpy(processes[num_processes].mem, ptr);
                            break;
                        }
                    }
                }

                // Obtain process id
                snprintf(processes[num_processes].pid, sizeof(processes[num_processes].pid), "%d", pid);
                num_processes++;
                fclose(file);
            }
        }
    }

    closedir(dir);

    // Print all processes
    printProcesses(processes, num_processes);

    free(processes);
    return 0;
}

void printProcesses(struct Process *processes, int num_processes) {
    printf("PID      NAME                          MEM\n");
    printf("-----------------------------------------\n");

    for (int i = 0; i < num_processes; i++) {
        printf("%-8s%-31s%s\n", processes[i].pid, processes[i].name, processes[i].mem);
    }

    printf("-----------------------------------------\n");
    printf("Total processes: %d\n", num_processes);
}