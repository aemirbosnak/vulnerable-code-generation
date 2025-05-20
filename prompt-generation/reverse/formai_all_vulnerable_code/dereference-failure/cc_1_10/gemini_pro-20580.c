//GEMINI-pro DATASET v1.0 Category: System administration ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>

// A complex C program that performs various system administration tasks
int main() {
    // Open the /proc directory
    DIR *procdir = opendir("/proc");
    if (procdir == NULL) {
        perror("opendir");
        return EXIT_FAILURE;
    }

    // Read the contents of the /proc directory
    struct dirent *procdirent;
    while ((procdirent = readdir(procdir)) != NULL) {
        // Check if the current entry is a directory
        if (procdirent->d_type == DT_DIR) {
            // Get the process ID from the directory name
            char *pid = procdirent->d_name;

            // Open the /proc/[pid]/status file
            char statusfile[128];
            sprintf(statusfile, "/proc/%s/status", pid);
            FILE *statusfp = fopen(statusfile, "r");
            if (statusfp == NULL) {
                perror("fopen");
                return EXIT_FAILURE;
            }

            // Read the contents of the /proc/[pid]/status file
            char line[1024];
            while (fgets(line, sizeof(line), statusfp) != NULL) {
                // Check if the current line contains the State: field
                if (strncmp(line, "State:", 6) == 0) {
                    // Get the state of the process
                    char state = line[7];

                    // Print the process ID and state
                    printf("%s: %c\n", pid, state);

                    // Close the /proc/[pid]/status file
                    fclose(statusfp);
                    break;
                }
            }
        }
    }

    // Close the /proc directory
    closedir(procdir);

    return EXIT_SUCCESS;
}