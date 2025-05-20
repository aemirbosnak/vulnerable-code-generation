//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>

#define MAX_PATH 256
#define MAX_LINE_LENGTH 1024

void get_process_info(const char* pid) {
    char path[MAX_PATH];
    snprintf(path, sizeof(path), "/proc/%s/stat", pid); // Prepare path to the stat file
    FILE *file = fopen(path, "r"); // Open the stat file

    if (file) {
        char line[MAX_LINE_LENGTH];
        fgets(line, sizeof(line), file); // Read line from stat file
        
        // Process the line into fields
        char *fields[52]; 
        char *token = strtok(line, " ");
        int i = 0;
        while (token != NULL && i < 52) {
            fields[i++] = token;
            token = strtok(NULL, " ");
        }

        // Process fields to extract relevant info
        printf("PID: %s\n", fields[0]);
        printf("Command: %s\n", fields[1]);
        printf("State: %s\n", fields[2]);
        printf("PPID: %s\n", fields[3]);
        printf("Priority: %s\n", fields[17]);
        printf("Nice: %s\n\n", fields[18]);

        fclose(file);
    } else {
        perror("Could not open process stat file");
    }
}

void list_processes() {
    DIR *dir;
    struct dirent *entry;

    // Open the /proc directory
    if ((dir = opendir("/proc")) == NULL) {
        perror("Could not open /proc directory");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (isdigit(entry->d_name[0])) { // Check if the entry is a PID
            get_process_info(entry->d_name); // Get process info for the PID
        }
    }

    closedir(dir);
}

int main() {
    printf("Decentralized Process Viewer\n");
    printf("===========================\n");
    list_processes(); // List all processes

    return 0;
}