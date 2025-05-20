//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <ctype.h>

#define MAX_PATH 256
#define BUFFER_SIZE 1024

void list_processes() {
    DIR *proc_dir;
    struct dirent *entry;

    if ((proc_dir = opendir("/proc")) == NULL) {
        perror("Failed to open /proc directory");
        return;
    }

    printf("%-10s %-25s %-10s %-10s\n", "PID", "Process Name", "State", "Memory");

    while ((entry = readdir(proc_dir)) != NULL) {
        // Check if the entry is a directory and if it is a number (a PID)
        if (isdigit(entry->d_name[0])) {
            char path[MAX_PATH];
            snprintf(path, sizeof(path), "/proc/%s/stat", entry->d_name);
            FILE *stat_file = fopen(path, "r");

            if (!stat_file) continue;

            int pid, ppid, state;
            char comm[BUFFER_SIZE];
            size_t mem_size;
            
            // Read the relevant fields from the /proc/pid/stat
            fscanf(stat_file, "%d %s %*s %d", &pid, comm, &state);
            fclose(stat_file);

            // Read memory usage
            snprintf(path, sizeof(path), "/proc/%s/status", entry->d_name);
            FILE *status_file = fopen(path, "r");
            if (status_file) {
                char line[BUFFER_SIZE];
                while (fgets(line, sizeof(line), status_file) != NULL) {
                    if (strncmp(line, "VmSize:", 7) == 0) {
                        sscanf(line + 7, "%zu", &mem_size);
                        break;
                    }
                }
                fclose(status_file);
            } else {
                mem_size = 0; // if we can't access status, default to 0
            }

            // Format the output appropriately
            printf("%-10d %-25s %-10d %-10zu KB\n", pid, comm, state, mem_size);
        }
    }
    closedir(proc_dir);
}

int main(void) {
    while (1) {
        printf("\n--- Process Viewer ---\n");
        list_processes();
        printf("--- Refreshing in 2 seconds... ---\n");
        sleep(2); // refresh every 2 seconds
    }
    return 0;
}