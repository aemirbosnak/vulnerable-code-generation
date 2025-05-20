//FormAI DATASET v1.0 Category: System process viewer ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <dirent.h>
#include <string.h>
#include <ctype.h>

int main() {
    DIR* proc = opendir("/proc"); // Open the directory where the processes are stored
    struct dirent* dir_entry;

    if (!proc) {
        perror("Failed to open /proc");
        exit(errno);
    }

    printf("PID\tName\n");

    while ((dir_entry = readdir(proc))) { // Loop through the contents of /proc
        int pid = atoi(dir_entry->d_name); // Get the PID from the directory name

        if (pid == 0) { // Skip over non-numeric directory names
            continue;
        }

        char cmd_file[256];
        sprintf(cmd_file, "/proc/%d/cmdline", pid); // Create the path to the cmdline file
        FILE* cmd_stream = fopen(cmd_file, "r");

        if (cmd_stream) {
            char cmd[256];
            int len = 0;

            while ((len = fread(cmd, 1, 256, cmd_stream))) { // Read the command line from the file
                for (int i = 0; i < len; i++) {
                    if (isspace(cmd[i])) { // Replace spaces with underscores
                        cmd[i] = '_';
                    }
                }

                cmd[len] = '\0';

                printf("%d\t%s\n", pid, cmd); // Print the PID and command line
            }

            fclose(cmd_stream);
        }
    }

    closedir(proc);

    return 0;
}