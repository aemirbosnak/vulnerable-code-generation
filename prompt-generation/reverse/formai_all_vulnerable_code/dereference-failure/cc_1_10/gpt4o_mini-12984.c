//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>

#define PROC_DIR "/proc"
#define MAX_BUF 256

void print_process_info(const char *pid) {
    char path[MAX_BUF];
    char status_file[MAX_BUF];
    char cmdline_file[MAX_BUF];
    FILE *file;
    char buffer[MAX_BUF];
    
    // Construct the file paths
    snprintf(status_file, sizeof(status_file), "%s/%s/status", PROC_DIR, pid);
    snprintf(cmdline_file, sizeof(cmdline_file), "%s/%s/cmdline", PROC_DIR, pid);
    
    // Open the status file
    file = fopen(status_file, "r");
    if (file) {
        printf("PID: %s\n", pid);
        
        // Read status information
        while (fgets(buffer, sizeof(buffer), file)) {
            if (strstr(buffer, "State:") || strstr(buffer, "Name:")) {
                printf("    %s", buffer);
            }
        }
        fclose(file);
    }

    // Open the cmdline file to get the command line
    file = fopen(cmdline_file, "r");
    if (file) {
        if (fgets(buffer, sizeof(buffer), file)) {
            printf("    Command: %s\n", buffer);
        }
        fclose(file);
    }
    
    printf("\n");
}

void list_processes() {
    struct dirent *entry;
    DIR *dp = opendir(PROC_DIR);
    
    if (dp == NULL) {
        perror("opendir: /proc");
        exit(EXIT_FAILURE);
    }

    // Iterate over the /proc directory
    while ((entry = readdir(dp)) != NULL) {
        // Check if the entry is a number (which indicates a PID)
        if (entry->d_type == DT_DIR) {
            if (strspn(entry->d_name, "0123456789") == strlen(entry->d_name)) {
                print_process_info(entry->d_name);
            }
        }
    }

    closedir(dp);
}

int main(int argc, char *argv[]) {
    printf("Simple Process Viewer\n");
    printf("=====================\n\n");
    
    // List all processes
    list_processes();

    return 0;
}