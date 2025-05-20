//GEMINI-pro DATASET v1.0 Category: System process viewer ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <dirent.h>

int main()
{
    DIR *dp;
    struct dirent *dirp;
    char path[] = "/proc";
    int pid;
    char stat_file[50];
    char state;

    // Open the /proc directory
    if ((dp = opendir(path)) == NULL) {
        perror("opendir");
        exit(EXIT_FAILURE);
    }

    // Read each entry in the directory
    while ((dirp = readdir(dp)) != NULL) {
        // Check if the entry is a directory
        if (dirp->d_type == DT_DIR) {
            // Convert the directory name to a process ID
            pid = atoi(dirp->d_name);

            // Check if the process ID is valid
            if (pid > 0) {
                // Create the path to the stat file
                sprintf(stat_file, "/proc/%d/stat", pid);

                // Open the stat file
                FILE *fp = fopen(stat_file, "r");
                if (fp == NULL) {
                    perror("fopen");
                    exit(EXIT_FAILURE);
                }

                // Read the state of the process
                fscanf(fp, "%*d %*s %c", &state);

                // Print the process ID, state, and command name
                printf("%d %c %s\n", pid, state, dirp->d_name);

                // Close the stat file
                fclose(fp);
            }
        }
    }

    // Close the /proc directory
    closedir(dp);
    return 0;
}