//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>

#define PROC_PATH "/proc/"

void display_process_info(const char *pid) {
    char path[256];
    snprintf(path, sizeof(path), PROC_PATH "%s/status", pid);

    FILE *fp = fopen(path, "r");
    if (fp == NULL) {
        return;
    }

    char line[256];
    printf("=== Process ID: %s ===\n", pid);
    while (fgets(line, sizeof(line), fp)) {
        if (strstr(line, "Name:") || strstr(line, "State:") || strstr(line, "Uid:") 
            || strstr(line, "Gid:") || strstr(line, "VmSize:")) {
            printf("%s", line);
        }
    }
    printf("=========================\n\n");
    fclose(fp);
}

void list_processes() {
    struct dirent *entry;
    DIR *dp = opendir(PROC_PATH);

    if (dp == NULL) {
        perror("Couldn't open /proc directory");
        return;
    }

    printf("Surprise! Here's a list of all current processes:\n\n");
    
    while ((entry = readdir(dp))) {
        // Check if the entry is a digit (process id)
        if (isdigit(entry->d_name[0])) {
            display_process_info(entry->d_name);
        }
    }

    closedir(dp);
}

void show_usage() {
    printf("Usage: process_viewer\n");
    printf("Displays the current processes running on the system!\n");
}

int main(int argc, char *argv[]) {
    printf("✨ Welcome to the Surprise Process Viewer! ✨\n\n");

    if (argc > 1) {
        show_usage();
        return 1; // Exit if command line argument provided
    }

    list_processes();
    
    printf("✨ That's it! Your processes have been displayed! ✨\n");
    return 0;
}