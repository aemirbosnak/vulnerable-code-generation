//FormAI DATASET v1.0 Category: System process viewer ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>

#define PATH "/proc/"

// Function declarations
void printProcessInfo(unsigned int pid);
void printHeader();

int main() {
    DIR *dir;
    struct dirent *entry;

    // Print header
    printHeader();

    // Open the directory 
    if ((dir = opendir(PATH)) == NULL) {
        perror("opendir() error");
        exit(EXIT_FAILURE);
    }

    // Loop through each entry in the directory
    while ((entry = readdir(dir)) != NULL) {
        // Check if entry is a directory and contains only digits
        if (isdigit(entry->d_name[0])) {
            // Convert directory name to integer
            unsigned int pid = (unsigned int)strtol(entry->d_name, NULL, 10);
            // Print process info
            printProcessInfo(pid);
        }
    }

    // Close the directory
    closedir(dir);

    return 0;
}

// Function to print header
void printHeader() {
    printf("%-10s %-20s %-10s %-10s %-20s\n", "PID", "NAME", "STATE", "PPID", "USER");
    printf("---------------------------------------------------------------\n");
}

// Function to print process information based on pid
void printProcessInfo(unsigned int pid) {
    char path[50];
    char buffer[1024];
    char name[50], state[50], user[50];
    unsigned int ppid;

    // Get process status file path
    sprintf(path, "/proc/%d/status", pid);

    // Open process status file
    FILE *file = fopen(path, "r");
    if (file == NULL) {
        perror("fopen() error");
        exit(EXIT_FAILURE);
    }

    // Loop through each line in the file
    while (fgets(buffer, sizeof(buffer), file)) {
        // Get process name
        if (strncmp(buffer, "Name:", 5) == 0) {
            sscanf(buffer + 5, "%s", name);
        }
        // Get process state
        else if (strncmp(buffer, "State:", 6) == 0) {
            sscanf(buffer + 6, "%s", state);
        }
        // Get process parent pid
        else if (strncmp(buffer, "PPid:", 5) == 0) {
            sscanf(buffer + 5, "%u", &ppid);
        }
        // Get process user
        else if (strncmp(buffer, "Uid:", 4) == 0) {
            unsigned int uid;
            sscanf(buffer + 4, "%u", &uid);
            // Get user name based on uid
            sprintf(path, "getent passwd %u | cut -d: -f1", uid);
            FILE *cmd = popen(path, "r");
            fgets(user, sizeof(user), cmd);
            pclose(cmd);
            // Remove \n from user name
            user[strlen(user) - 1] = '\0';
        }
    }

    // Close process status file
    fclose(file);

    // Print process info
    printf("%-10u %-20s %-10s %-10u %-20s\n", pid, name, state, ppid, user);
}