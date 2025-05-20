//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <ctype.h>
#include <sys/types.h>

#define PROC_PATH "/proc/"

void print_process_info(const char *pid) {
    char path[256];
    FILE *status_file;
    char name[256], line[256];
    uid_t uid;

    // Construct the path to the status file
    snprintf(path, sizeof(path), "%s%s/status", PROC_PATH, pid);

    // Open the status file for reading
    status_file = fopen(path, "r");
    if (status_file == NULL) {
        return;
    }

    // Read the name and UID from the status file
    while (fgets(line, sizeof(line), status_file)) {
        if (sscanf(line, "Name:\t%s", name) == 1) {
            // Found process name
        } else if (sscanf(line, "Uid:\t%d", (int*)&uid) == 1) {
            // Found user ID
        }
    }

    fclose(status_file);

    // Print the process information
    printf("%-10s %-10d %-20s\n", pid, uid, name);
}

int main(void) {
    DIR *proc_dir;
    struct dirent *entry;

    // Open the /proc directory to list processes
    proc_dir = opendir(PROC_PATH);
    if (proc_dir == NULL) {
        perror("Failed to open /proc directory");
        return EXIT_FAILURE;
    }

    printf("%-10s %-10s %-20s\n", "PID", "UID", "Process Name");
    printf("---------------------------------------------------------\n");

    // Iterate through entries in the /proc directory
    while ((entry = readdir(proc_dir)) != NULL) {
        // Check if the entry is a directory and consists of digits only
        if (entry->d_type == DT_DIR && isdigit(entry->d_name[0])) {
            // Print process information
            print_process_info(entry->d_name);
        }
    }

    closedir(proc_dir);
    return EXIT_SUCCESS;
}