//GEMINI-pro DATASET v1.0 Category: System process viewer ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>

// Function to print process information
void print_process_info(pid_t pid, char *name) {
    FILE *f;
    char path[256];
    char line[1024];

    // Open the process status file
    sprintf(path, "/proc/%d/status", pid);
    f = fopen(path, "r");
    if (f == NULL) {
        perror("fopen");
        return;
    }

    // Read the first line of the status file, which contains the process name
    fgets(line, sizeof(line), f);
    printf("%s (%s\n", name, line);

    // Read the rest of the status file, printing out selected information
    while (fgets(line, sizeof(line), f)) {
        if (strstr(line, "State:") != NULL) {
            printf("    State: %s", line);
        } else if (strstr(line, "Pid:") != NULL) {
            printf("    Pid: %s", line);
        } else if (strstr(line, "VmPeak:") != NULL) {
            printf("    VmPeak: %s", line);
        } else if (strstr(line, "VmHWM:") != NULL) {
            printf("    VmHWM: %s", line);
        }
    }

    // Close the status file
    fclose(f);
}

// Main function
int main(int argc, char **argv) {
    DIR *dir;
    struct dirent *entry;
    pid_t pid;
    char name[256];

    // Open the /proc directory
    dir = opendir("/proc");
    if (dir == NULL) {
        perror("opendir");
        return EXIT_FAILURE;
    }

    // Iterate over the entries in the /proc directory
    while ((entry = readdir(dir)) != NULL) {
        // Check if the entry is a directory
        if (entry->d_type != DT_DIR) {
            continue;
        }

        // Convert the entry name to a PID
        pid = atoi(entry->d_name);
        if (pid == 0) {
            continue;
        }

        // Open the process name file
        sprintf(name, "/proc/%d/comm", pid);
        FILE *f = fopen(name, "r");
        if (f == NULL) {
            perror("fopen");
            continue;
        }

        // Read the process name
        fgets(name, sizeof(name), f);
        name[strlen(name) - 1] = '\0'; // Remove the newline character

        // Close the process name file
        fclose(f);

        // Print the process information
        print_process_info(pid, name);
    }

    // Close the /proc directory
    closedir(dir);

    return EXIT_SUCCESS;
}