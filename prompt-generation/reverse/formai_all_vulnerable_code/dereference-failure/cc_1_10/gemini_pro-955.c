//GEMINI-pro DATASET v1.0 Category: System process viewer ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>

int main(int argc, char *argv[]) {
    // Open the /proc directory
    DIR *proc_dir = opendir("/proc");
    if (proc_dir == NULL) {
        perror("opendir");
        exit(EXIT_FAILURE);
    }

    // Loop through the entries in the /proc directory
    struct dirent *entry;
    while ((entry = readdir(proc_dir)) != NULL) {
        // Skip any non-numeric entries
        if (!isdigit(entry->d_name[0])) {
            continue;
        }

        // Open the procfs file for the process
        char procfs_path[64];
        snprintf(procfs_path, sizeof(procfs_path), "/proc/%s/status", entry->d_name);
        int procfs_fd = open(procfs_path, O_RDONLY);
        if (procfs_fd == -1) {
            perror("open");
            continue;
        }

        // Read the procfs file
        char buf[1024];
        int bytes_read = read(procfs_fd, buf, sizeof(buf));
        if (bytes_read == -1) {
            perror("read");
            close(procfs_fd);
            continue;
        }

        // Parse the procfs file
        char *line;
        while ((line = strsep(&buf, "\n")) != NULL) {
            // Parse the Name/Value pair
            char *name = strtok(line, ":");
            char *value = strtok(NULL, ":");
            if (name == NULL || value == NULL) {
                continue;
            }

            // Print the Name/Value pair
            printf("%s: %s\n", name, value);
        }

        // Close the procfs file
        close(procfs_fd);
    }

    // Close the /proc directory
    closedir(proc_dir);

    return EXIT_SUCCESS;
}