//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>

#define BUFFER_SIZE 256

void list_processes() {
    DIR *dir;
    struct dirent *entry;
    char path[BUFFER_SIZE];
    char cmdline[BUFFER_SIZE];
    FILE *fp;

    // Open the /proc directory
    dir = opendir("/proc");
    if (dir == NULL) {
        perror("Failed to open /proc directory");
        return;
    }

    printf("🚀 Listing Processes... 🐍\n");
    printf("%-10s %-8s %-30s\n", "PID", "State", "Command");

    // Reading entries in /proc
    while ((entry = readdir(dir)) != NULL) {
        if (isdigit(*entry->d_name)) {  // Only process directories
            snprintf(path, sizeof(path), "/proc/%s/stat", entry->d_name);
            fp = fopen(path, "r");
            if (fp) {
                int pid;
                char state;
                char comm[BUFFER_SIZE];
                
                // Read process info from the stat file
                fscanf(fp, "%d %s %*c %c", &pid, comm, &state);
                fclose(fp);

                // Store and format command
                comm[strcspn(comm, ")]")] = 0;  // Remove trailing brackets
                snprintf(cmdline, sizeof(cmdline), "/proc/%s/cmdline", entry->d_name);
                
                FILE *cmd_fp = fopen(cmdline, "r");
                if (cmd_fp) {
                    fgets(comm, sizeof(comm), cmd_fp);
                    fclose(cmd_fp);
                }

                printf("%-10d %-8c %-30s\n", pid, state, comm);
            }
        }
    }
    closedir(dir);
    printf("🌟 End of Process List 🌟\n");
}

int main() {
    printf("👁️ Simple C Process Viewer 😎\n");
    list_processes();
    return 0;
}