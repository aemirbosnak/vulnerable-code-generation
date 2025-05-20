//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

#define BUFFER_SIZE 256

void get_process_info(const char *pid) {
    char path[BUFFER_SIZE];
    snprintf(path, sizeof(path), "/proc/%s/stat", pid);
    
    FILE *file = fopen(path, "r");
    if (!file) {
        return; // Unable to open process file
    }
    
    char buffer[BUFFER_SIZE];
    fgets(buffer, sizeof(buffer), file);
    
    // Split by spaces
    char *tokens[10];
    char *token = strtok(buffer, " ");
    int index = 0;

    while (token != NULL && index < 10) {
        tokens[index++] = token;
        token = strtok(NULL, " ");
    }

    // Basic info
    printf("PID: %s\n", pid);
    printf("Process Name: %s\n", tokens[1]);
    printf("State: %s\n", tokens[3]);
    printf("Parent PID: %s\n\n", tokens[4]);

    fclose(file);
}

void list_processes() {
    DIR *dir = opendir("/proc");
    struct dirent *entry;

    if (!dir) {
        perror("Could not open /proc directory");
        return;
    }

    printf("Process Viewer\n");
    printf("=====================\n");

    while ((entry = readdir(dir)) != NULL) {
        // Only process directories that represent PIDs
        if (entry->d_type == DT_DIR && atoi(entry->d_name) > 0) {
            get_process_info(entry->d_name);
        }
    }

    closedir(dir);
}

int main() {
    list_processes();
    return 0;
}