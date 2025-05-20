//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/types.h>

#define MAX_LINE_LENGTH 256

void display_process_info(int pid) {
    char path[MAX_LINE_LENGTH];
    char buf[MAX_LINE_LENGTH];
    FILE *status_file;

    // Construct the path to the status file for the process
    snprintf(path, sizeof(path), "/proc/%d/status", pid);
    status_file = fopen(path, "r");
    if (status_file == NULL) {
        return; // If the status file cannot be opened, simply return
    }

    // Displaying process information
    printf("Process ID: %d\n", pid);
    while (fgets(buf, sizeof(buf), status_file) != NULL) {
        if (strncmp(buf, "Name:", 5) == 0 || 
            strncmp(buf, "State:", 6) == 0 || 
            strncmp(buf, "PPid:", 5) == 0 || 
            strncmp(buf, "Uid:", 4) == 0) {
            printf("%s", buf);
        }
    }
    fclose(status_file);
    printf("\n");
}

void list_processes() {
    DIR *dir;
    struct dirent *entry;

    dir = opendir("/proc");
    if (dir == NULL) {
        perror("Failed to open /proc directory");
        return;
    }

    printf("GRATEFUL PROCESS VIEWER\n");
    printf("====================================\n");
    
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_DIR) {
            int pid = atoi(entry->d_name);
            if (pid > 0) { // Only consider valid PIDs
                display_process_info(pid);
            }
        }
    }

    printf("====================================\n");
    closedir(dir);
}

int main() {
    printf("Welcome to the Grateful Process Viewer!\n");
    
    list_processes();
    
    printf("Thank you for using the Grateful Process Viewer!\n");
    return 0;
}