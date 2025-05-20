//FormAI DATASET v1.0 Category: System process viewer ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>

#define MAX_LINE_LENGTH 100

// This function checks if a directory entry represents a directory
int is_directory(const char *path) {
    DIR *d = opendir(path);
    if (d == NULL) return 0; // Not a directory
    closedir(d);
    return 1;
}

int main() {
    char line[MAX_LINE_LENGTH];
    FILE *fp;

    char path[MAX_LINE_LENGTH];
    sprintf(path, "/proc");

    DIR *d = opendir(path);
    if (d == NULL) {
        printf("Unable to open directory %s\n", path);
        return 1;
    }

    struct dirent *dir;
    while ((dir = readdir(d)) != NULL) {
        // Ignore all non-directory entries and the current and parent directories
        if(!is_directory(dir->d_name) || strcmp(dir->d_name,".") == 0 || strcmp(dir->d_name,"..") == 0) continue;

        // Convert the directory name to a process ID
        int pid = atoi(dir->d_name);
        if (pid == 0) continue; // Invalid process ID

        // Read the command line of the process
        char cmdline_path[MAX_LINE_LENGTH];
        sprintf(cmdline_path, "/proc/%d/cmdline", pid);

        fp = fopen(cmdline_path, "r");
        if (fp == NULL) {
            printf("Unable to open file %s\n", cmdline_path);
            continue;
        }

        fgets(line, MAX_LINE_LENGTH, fp);
        fclose(fp);

        // Print the process ID and command line
        printf("%5d %s\n", pid, line);
    }

    closedir(d);
    return 0;
}