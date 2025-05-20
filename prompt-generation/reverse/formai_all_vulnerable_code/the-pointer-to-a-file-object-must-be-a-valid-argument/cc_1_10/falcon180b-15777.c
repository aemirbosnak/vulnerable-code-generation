//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

// Function to display system processes
void display_processes() {
    FILE* fp;
    char line[1024];
    char *token;
    pid_t pid;

    // Open the /proc directory
    fp = fopen("/proc", "r");
    if (fp == NULL) {
        printf("Error: Could not open /proc directory.\n");
        exit(1);
    }

    // Iterate through each process
    while (fgets(line, sizeof(line), fp)!= NULL) {
        // Extract the process ID from the directory name
        pid = atoi(line);

        // Open the process status file
        sprintf(line, "/proc/%d/status", pid);
        fp = fopen(line, "r");
        if (fp == NULL) {
            printf("Error: Could not open status file for process %d.\n", pid);
            continue;
        }

        // Read the name of the process
        fgets(line, sizeof(line), fp);
        token = strtok(line, " ");
        printf("%d: %s\n", pid, token);

        // Close the status file
        fclose(fp);
    }

    // Close the /proc directory
    fclose(fp);
}

int main() {
    display_processes();
    return 0;
}