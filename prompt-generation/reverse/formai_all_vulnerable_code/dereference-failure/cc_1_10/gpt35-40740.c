//FormAI DATASET v1.0 Category: System process viewer ; Style: puzzling
#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

// Function to check if a process ID exists
int isProcessValid(char* pid) {
    char path[50];
    sprintf(path, "/proc/%s", pid);
    struct stat buffer;
    if (stat(path, &buffer) == 0) {
        return 1;
    } else {
        return 0;
    }
}

// Function to get the command line arguments
char* getCmdline(char* pid) {
    char path[50];
    sprintf(path, "/proc/%s/cmdline", pid);
    char cmdline[1024];
    FILE* f = fopen(path, "r");
    if (f == NULL) {
        return "Unknown Process";
    } else {
        fgets(cmdline, 1024, f);
        fclose(f);
        return cmdline;
    }
}

// Function to get the parent process ID
char* getParentPID(char* pid) {
    char path[50];
    sprintf(path, "/proc/%s/stat", pid);
    FILE* f = fopen(path, "r");
    if (f == NULL) {
        return "-1";
    } else {
        char statLine[1024];
        fgets(statLine, 1024, f);
        fclose(f);
        
        // Split the stat line by space
        char* token = strtok(statLine, " ");
        int count = 0;
        while (token != NULL) {
            if (count == 3) {
                return token;
            }
            token = strtok(NULL, " ");
            count++;
        }
        return "-1";
    }
}

// Function to get the process state
char* getState(char* pid) {
    char path[50];
    sprintf(path, "/proc/%s/stat", pid);
    FILE* f = fopen(path, "r");
    if (f == NULL) {
        return "Unknown";
    } else {
        char statLine[1024];
        fgets(statLine, 1024, f);
        fclose(f);
        
        // Split the stat line by space
        char* token = strtok(statLine, " ");
        int count = 0;
        while (token != NULL) {
            if (count == 2) {
                return token;
            }
            token = strtok(NULL, " ");
            count++;
        }
        return "Unknown";
    }
}

// Function to get the process memory usage
long int getMemoryUsage(char* pid) {
    char path[50];
    sprintf(path, "/proc/%s/statm", pid);
    FILE *f = fopen(path, "r");
    if (f == NULL) {
        return -1;
    }
    long int size, resident, share, text, lib, data, dt;
    fscanf(f, "%ld %ld %ld %ld %ld %ld %ld", &size, &resident, &share, &text, &lib, &data, &dt);
    fclose(f);
    return resident;
}

// Function to check if a string is a number
int isNumber(char* str) {
    for (int i=0; i<strlen(str); i++) {
        if (!isdigit(str[i])) {
            return 0;
        }
    }
    return 1;
}

int main(int argc, char* argv[]) {
    // Check if a PID is given as an argument
    if (argc != 2 || !isNumber(argv[1])) {
        printf("Please enter a valid process ID\n");
        return 0;
    }

    // Check if the given PID exists
    if (!isProcessValid(argv[1])) {
        printf("Process with PID %s does not exist\n", argv[1]);
        return 0;
    }

    // Get the command line arguments
    char* cmdline = getCmdline(argv[1]);

    // Get the parent process ID
    char* parentPID = getParentPID(argv[1]);

    // Get the process state
    char* state = getState(argv[1]);

    // Get the memory usage
    long int memory = getMemoryUsage(argv[1]);

    // Output process details
    printf("PID: %s\n", argv[1]);
    printf("Command Line Arguments: %s\n", cmdline);
    printf("Parent Process ID: %s\n", parentPID);
    printf("State: %s\n", state);
    printf("Memory Usage: %ld KB\n", memory);

    return 0;
}