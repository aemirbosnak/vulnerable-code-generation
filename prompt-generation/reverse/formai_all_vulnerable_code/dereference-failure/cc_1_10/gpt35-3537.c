//FormAI DATASET v1.0 Category: System process viewer ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>
#include <unistd.h>
#include <fcntl.h>

#define MAX_PID 32768  // Maximum size of pid

int count = 0;        // Count the number of running processes
int sleeping = 0;     // Count the number of sleeping processes
int running = 0;      // Count the number of running processes

// Function to check if a string is numeric
int isNumeric(char *str) {
    for(int i=0; i<strlen(str); i++) {
        if (!isdigit(str[i])) {
            return 0;
        }
    }
    return 1;
}

// Function to print the process information
void printProcInfo(int pid, char *status, char *name) {
    char path[256];
    char buf[256];
    int fd, n;

    // Get the process command line information
    sprintf(path, "/proc/%d/cmdline", pid);
    fd = open(path, O_RDONLY);
    n = read(fd, buf, 256);
    close(fd);

    // Print the process information
    printf("%-7d %-12s %-20s %s\n", pid, status, name, buf);
}

// Main function
int main() {
    DIR *dir;
    struct dirent *ent;
    char *pid;
    char path[256];
    char buf[256];

    // Print the header
    printf("%-7s %-12s %-20s %s\n", "PID", "STATUS", "NAME", "COMMAND");

    // Open the /proc directory
    dir = opendir("/proc");
    if (dir == NULL) {
        perror("Unable to open /proc directory");
        return EXIT_FAILURE;
    }

    // Iterate through each directory in the /proc directory
    while ((ent = readdir(dir)) != NULL) {
        pid = ent->d_name;
        // Check if the name of the directory is a process id number
        if (isNumeric(pid)) {
            strcpy(path, "/proc/");
            strcat(path, pid);
            strcat(path, "/stat");
            // Open the /proc/<pid>/stat file
            FILE *fp = fopen(path, "r");
            if (fp == NULL) {
                perror("Unable to open stat file");
                continue;
            }
            // Read the /proc/<pid>/stat file
            fscanf(fp, "%d %s %s", &pid, buf, buf);
            fclose(fp);
            // Get the process status information
            if (strcmp(buf, "R") == 0) {
                printProcInfo(pid, "Running", ent->d_name);
                running++;
            } else if (strcmp(buf, "S") == 0) {
                printProcInfo(pid, "Sleeping", ent->d_name);
                sleeping++;
            } else {
                printProcInfo(pid, "Unknown", ent->d_name);
            }
            count++;
        }
    }

    // Print the statistics
    printf("\nTotal number of processes: %d\n", count);
    printf("Number of running processes: %d\n", running);
    printf("Number of sleeping processes: %d\n", sleeping);

    // Close the /proc directory
    closedir(dir);

    return EXIT_SUCCESS;
}