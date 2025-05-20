//FormAI DATASET v1.0 Category: System process viewer ; Style: detailed
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 512

void printProcessInfo(const char *pid) {
    char filePath[BUFFER_SIZE] = {0};
    char name[BUFFER_SIZE] = {0};
    char state[BUFFER_SIZE] = {0};
    int ppid = 0;

    // Set the file path of the status file for the given PID
    sprintf(filePath, "/proc/%s/status", pid);

    // Open the status file
    FILE *fp = fopen(filePath, "r");
    if(fp != NULL) {
        // Parse the file to extract the required information
        char buffer[BUFFER_SIZE] = {0};
        while(fgets(buffer, BUFFER_SIZE - 1, fp)) {
            if(sscanf(buffer, "Name:\t%s", name) == 1) {
                continue;
            }
            if(sscanf(buffer, "State:\t%s", state) == 1) {
                continue;
            }
            if(sscanf(buffer, "PPid:\t%d", &ppid) == 1) {
                continue;
            }
        }

        // Close the file
        fclose(fp);

        // Print the extracted information
        printf("%-10s%-20s%-10s%d\n", pid, name, state, ppid);
    }
}

int main() {
    printf("%-10s%-20s%-10s%s\n", "PID", "NAME", "STATE", "PPID");

    // Open the /proc directory
    DIR *dir = opendir("/proc");
    if(dir != NULL) {
        // Read the directory entries
        struct dirent *entry;
        while((entry = readdir(dir)) != NULL) {
            // Check if the entry is a directory and its name consists of only numerical characters
            if(entry->d_type == DT_DIR && strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0 && atoi(entry->d_name) != 0) {
                printProcessInfo(entry->d_name);
            }
        }

        // Close the directory
        closedir(dir);
    }

    return 0;
}