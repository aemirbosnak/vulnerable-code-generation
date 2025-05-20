//FormAI DATASET v1.0 Category: System process viewer ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>

#define MAX_PATH 1024

int main() {
    DIR *dir;
    struct dirent *entry;
    char path[MAX_PATH];

    printf("Process ID\tProcess Name\n");

    // Open directory /proc
    dir = opendir("/proc");
    if (dir == NULL) {
        perror("Error: Unable to open directory");
        exit(EXIT_FAILURE);
    }

    while ((entry = readdir(dir)) != NULL) {
        // Check if the directory entry is a process directory
        if ((entry->d_type == DT_DIR) && (strcmp(entry->d_name, ".") != 0) && (strcmp(entry->d_name, "..") != 0) && (isdigit(entry->d_name[0]))) {
            // Construct the path to the process status file
            snprintf(path, MAX_PATH, "/proc/%s/status", entry->d_name);
            
            // Open the process status file
            FILE *fp = fopen(path, "r");
            if (fp == NULL) {
                fprintf(stderr, "Warning: Unable to open file %s\n", path);
                continue;
            }

            // Parse the process status file to get the process name
            char line[MAX_PATH];
            char *name = "Unknown";
            while (fgets(line, MAX_PATH, fp)) {
                if (strncmp(line, "Name:", 5) == 0) {
                    name = line + 6;
                    break;
                }
            }

            // Close the process status file
            fclose(fp);

            // Print the process ID and name
            printf("%s\t%s", entry->d_name, name);
        }
    }

    // Close the /proc directory
    closedir(dir);

    return 0;
}