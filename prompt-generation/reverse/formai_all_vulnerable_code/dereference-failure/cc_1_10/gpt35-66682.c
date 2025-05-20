//FormAI DATASET v1.0 Category: System process viewer ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>

#define MAX_PATH 100

// Function to check whether a string represents an integer or not
int isInteger(char *str) {
    int i;
    for (i = 0; str[i] != '\0'; i++) {
        if (!isdigit(str[i])) {
            return 0;
        }
    }
    return 1;
}

int main() {
    DIR *d; // directory pointer
    struct dirent *dir; // directory entry structure
    int pid; // process id
    char path[MAX_PATH], command[100], state[10];
    long unsigned int utime, stime;

    printf("PID\tCommand\t\tState\tUTime\t\tSTime\n");

    // Open the /proc directory
    d = opendir("/proc");

    // Loop through each directory entry in /proc directory
    while ((dir = readdir(d)) != NULL) {
        // Check if the directory entry represents a process id
        if (isInteger(dir->d_name)) {
            pid = atoi(dir->d_name);

            // Open the /proc/[pid]/stat file
            sprintf(path, "/proc/%d/stat", pid);
            FILE *statFile = fopen(path, "r");

            if (statFile == NULL) {
                continue; // if can't open file, skip to next directory entry
            }

            // Read the process information from the /proc/[pid]/stat file
            fscanf(statFile, "%d %s %s %*s %*s %*s %*s %*s %*s %*s %*s %*s %lu %lu", 
                &pid, command, state, &utime, &stime);

            fclose(statFile);

            // print the process information
            printf("%d\t%s\t\t%s\t%lu\t%lu\n", pid, command, state, utime, stime);
        }
    }

    closedir(d); // Close the /proc directory
    return 0;
}