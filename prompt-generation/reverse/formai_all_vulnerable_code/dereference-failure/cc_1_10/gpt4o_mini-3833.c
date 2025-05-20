//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>

#define MAX_PROCESSES 1024
#define MAX_LINE_LENGTH 256

typedef struct {
    pid_t pid;
    char name[MAX_LINE_LENGTH];
} Process;

void fetch_processes(Process processes[], int *count) {
    DIR *dir;
    struct dirent *entry;

    if ((dir = opendir("/proc")) == NULL) {
        perror("Could not open /proc directory");
        exit(EXIT_FAILURE);
    }

    *count = 0;
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_DIR) {
            pid_t pid = atoi(entry->d_name);
            if (pid > 0) {
                char comm[MAX_LINE_LENGTH];
                snprintf(comm, sizeof(comm), "/proc/%d/comm", pid);
                
                FILE *fp = fopen(comm, "r");
                if (fp != NULL) {
                    fgets(processes[*count].name, MAX_LINE_LENGTH, fp);
                    processes[*count].name[strcspn(processes[*count].name, "\n")] = 0; // Remove newline
                    processes[*count].pid = pid;
                    (*count)++;
                    fclose(fp);
                }
            }
        }
    }
    closedir(dir);
}

void display_processes(Process processes[], int count) {
    printf("\n============================= Process Viewer =============================\n");
    printf("| %-6s | %-25s |\n", "PID", "Process Name");
    printf("---------------------------------------------------------------------------\n");

    for (int i = 0; i < count; ++i) {
        printf("| %-6d | %-25s |\n", processes[i].pid, processes[i].name);
    }

    printf("---------------------------------------------------------------------------\n");
    printf("Total Processes: %d\n", count);
    printf("===========================================================================\n");
}

int main() {
    printf("Welcome to the Lively Process Viewer!\n");
    printf("Let’s dig into the processes running on your system...\n");

    Process processes[MAX_PROCESSES];
    int process_count = 0;

    fetch_processes(processes, &process_count);
    display_processes(processes, process_count);

    printf("Thank you for using the Lively Process Viewer. Keep exploring!\n");
    return EXIT_SUCCESS;
}