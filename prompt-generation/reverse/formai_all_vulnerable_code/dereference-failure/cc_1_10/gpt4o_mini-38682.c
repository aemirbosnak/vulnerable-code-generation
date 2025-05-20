//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>

#define PROC_DIR "/proc"
#define BUFFER_SIZE 256

void print_process_info(const char *pid) {
    char path[BUFFER_SIZE];
    FILE *fp;
    char line[BUFFER_SIZE];

    // Construct the path to the stat file of the process
    snprintf(path, sizeof(path), "%s/%s/stat", PROC_DIR, pid);
    
    // Open the stat file for reading
    fp = fopen(path, "r");
    if (fp == NULL) {
        perror("Could not open process file");
        return;
    }

    // Read process information from the stat file
    if (fgets(line, sizeof(line), fp) != NULL) {
        // Split the line into tokens
        char *token = strtok(line, " ");
        int count = 0;
        char *info[50];

        while (token != NULL) {
            info[count++] = token;
            token = strtok(NULL, " ");
        }

        // Display important process information
        if (count > 24) {
            printf("PID: %s, Command: %s, State: %s, User time: %s, System time: %s\n",
                   info[0], info[1], info[2], info[13], info[14]);
        }
    }

    fclose(fp);
}

void list_processes() {
    DIR *proc_dir;
    struct dirent *entry;

    // Open the /proc directory
    proc_dir = opendir(PROC_DIR);
    if (proc_dir == NULL) {
        perror("Could not open /proc directory");
        return;
    }

    // Iterate through the directory entries
    while ((entry = readdir(proc_dir)) != NULL) {
        // Check if the entry is a number (which corresponds to a PID)
        if (isdigit(entry->d_name[0])) {
            print_process_info(entry->d_name);
        }
    }

    closedir(proc_dir);
}

int main() {
    printf("=== Process Viewer ===\n");
    list_processes();
    printf("======================\n");
    return 0;
}