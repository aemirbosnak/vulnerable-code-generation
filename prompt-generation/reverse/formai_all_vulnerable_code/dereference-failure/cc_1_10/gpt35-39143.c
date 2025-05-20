//FormAI DATASET v1.0 Category: System process viewer ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <ctype.h>

#define BUFFER_SIZE 512

// Function to get a process' name from it's pid
char* get_proc_name(char* pid) {
    char* name = NULL;
    char* path = (char*)malloc(sizeof(char) * (strlen(pid) + 20)); // Path to the /proc/$pid/stat file
    sprintf(path, "/proc/%s/stat", pid);
    FILE* f = fopen(path, "r");
    if (f) {
        char buffer[BUFFER_SIZE];
        fgets(buffer, BUFFER_SIZE, f);
        fclose(f);
        char* start = strchr(buffer, '(') + 1;
        char* end = strchr(buffer, ')');
        int len = end - start;
        name = (char*)malloc(sizeof(char) * (len + 1));
        strncpy(name, start, len);
        name[len] = '\0';
    }
    free(path);
    return name;
}

// Function to get the status of a process from it's pid
char* get_proc_status(char* pid) {
    char* status = NULL;
    char* path = (char*)malloc(sizeof(char) * (strlen(pid) + 20)); // Path to the /proc/$pid/status file
    sprintf(path, "/proc/%s/status", pid);
    FILE* f = fopen(path, "r");
    if (f) {
        char buffer[BUFFER_SIZE];
        while (fgets(buffer, BUFFER_SIZE, f)) {
            // Search for the "State" line
            if (strncmp(buffer, "State:", 6) == 0) {
                status = strdup(buffer + 7);
                break;
            }
        }
        fclose(f);
    }
    free(path);
    return status;
}

int main() {
    printf("PID   PPID NAME               STATUS\n"); // Header
    DIR* dir = opendir("/proc"); // Open the /proc directory
    if (dir) {
        struct dirent* entry;
        while ((entry = readdir(dir))) { // Iterate through each directory in /proc
            if (isdigit(*entry->d_name)) { // Ignore directories that aren't PIDs
                char* pid = entry->d_name;
                char* pname = get_proc_name(pid);
                char* status = get_proc_status(pid);
                printf("%-5s %-5s %-18s %s\n", pid, "0", pname ? pname : "<unknown>", status ? status : "<unknown>");
                free(pname);
                free(status);
            }
        }
        closedir(dir);
    } else {
        perror("Couldn't open the /proc directory");
        return 1;
    }
    return 0;
}