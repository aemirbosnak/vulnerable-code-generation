//GEMINI-pro DATASET v1.0 Category: System process viewer ; Style: secure
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>

int main() {
    // Open the /proc directory
    DIR *proc = opendir("/proc");
    if (proc == NULL) {
        perror("opendir");
        return EXIT_FAILURE;
    }

    // Iterate over the entries in the /proc directory
    struct dirent *entry;
    while ((entry = readdir(proc)) != NULL) {
        // Check if the entry is a directory
        if (entry->d_type != DT_DIR) {
            continue;
        }

        // Check if the entry is a numeric directory
        int pid;
        if (sscanf(entry->d_name, "%d", &pid) != 1) {
            continue;
        }

        // Print the process information
        char path[1024];
        snprintf(path, sizeof(path), "/proc/%d/status", pid);
        FILE *status = fopen(path, "r");
        if (status == NULL) {
            perror("fopen");
            continue;
        }

        char line[1024];
        while (fgets(line, sizeof(line), status) != NULL) {
            // Parse the line to extract the process information
            char name[1024];
            int state;
            if (sscanf(line, "Name:\t%s", name) == 1) {
                printf("Name:\t%s\n", name);
            } else if (sscanf(line, "State:\t%c", &state) == 1) {
                printf("State:\t%c\n", state);
            }
        }

        fclose(status);
    }

    // Close the /proc directory
    closedir(proc);

    return EXIT_SUCCESS;
}