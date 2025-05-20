//FormAI DATASET v1.0 Category: System process viewer ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>

#define MAX_LENGTH 1024

// Function to determine if a given string is a number
int is_number(char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isdigit(str[i])) {
            return 0;
        }
    }
    return 1;
}

// Function to parse the contents of /proc/<pid>/stat file
int parse_stat(char* pid, char** name, char** status, char** memory_size) {
    FILE* file;
    char file_path[MAX_LENGTH];

    // Build the file path to the stat file for the given pid
    sprintf(file_path, "/proc/%s/stat", pid);

    // Open the stat file
    file = fopen(file_path, "r");
    if (file == NULL) {
        return -1;
    }

    // Parse the contents of the stat file
    char buffer[MAX_LENGTH];
    fgets(buffer, MAX_LENGTH, file);

    // Extract the name, status, and memory size from the buffer
    char* ptr = buffer;
    int field_count = 0;

    while (*ptr && field_count < 22) {
        if (field_count == 1) {
            // Extract the process name
            *name = ptr;
            while (*ptr && *ptr != ' ') {
                ptr++;
            }
            *ptr = '\0';
        } else if (field_count == 2) {
            // Extract the process status
            ptr++;
            *status = ptr;
            while (*ptr && *ptr != ' ') {
                ptr++;
            }
            *ptr = '\0';
        } else if (field_count == 22) {
            // Extract the memory size in bytes
            ptr++;
            *memory_size = ptr;
            while (*ptr && *ptr != ' ') {
                ptr++;
            }
            *ptr = '\0';
        } else {
            // Go to the next field separator
            while (*ptr && *ptr != ' ') {
                ptr++;
            }
        }
        field_count++;
        ptr++;
    }

    fclose(file);
    return 0;
}

// Function to parse the contents of /proc/<pid>/status file
int parse_status(char* pid, char** uid, char** gid, char** vmsize) {
    FILE* file;
    char file_path[MAX_LENGTH];

    // Build the file path to the status file for the given pid
    sprintf(file_path, "/proc/%s/status", pid);

    // Open the status file
    file = fopen(file_path, "r");
    if (file == NULL) {
        return -1;
    }

    // Parse the contents of the status file
    char buffer[MAX_LENGTH];
    while (fgets(buffer, MAX_LENGTH, file)) {
        // Extract the Uid line
        if (strncmp(buffer, "Uid:", 4) == 0) {
            *uid = strchr(buffer, '\t') + 1;
            *gid = strchr(*uid, '\t') + 1;
            *vmsize = strchr(*gid, '\t') + 1;
            char* end = strchr(*vmsize, '\n');
            if (end) {
                *end = '\0';
            }
        }
    }

    fclose(file);
    return 0;
}

int main() {
    DIR* directory;
    struct dirent* entry;
    char* pid;
    char* name;
    char* status;
    char* uid;
    char* gid;
    char* vmsize;
    char* memory_size;

    // Print header
    printf("PID\tName\t\tStatus\tUID\tGID\tVMsize\tMemory size\n");

    // Open the /proc directory
    directory = opendir("/proc");
    if (directory == NULL) {
        perror("Error: Unable to open directory /proc");
        exit(EXIT_FAILURE);
    }

    // Loop through all directories in the /proc directory
    while ((entry = readdir(directory)) != NULL) {
        pid = entry->d_name;
        if (!is_number(pid)) {
            continue;
        }

        // Parse stat and status files for the given pid
        if (parse_stat(pid, &name, &status, &memory_size) == 0 &&
            parse_status(pid, &uid, &gid, &vmsize) == 0) {

            // Print process information
            printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\n", pid, name, status, uid, gid, vmsize, memory_size);
        }
    }

    closedir(directory);
    return 0;
}