//GEMINI-pro DATASET v1.0 Category: System process viewer ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>

#define MAX_CMD_LEN 1024

int main(int argc, char **argv)
{
    // Check if a command is provided.
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <command>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Open the "/proc/" directory.
    DIR *proc_dir = opendir("/proc/");
    if (proc_dir == NULL) {
        perror("opendir(\"/proc/\")");
        exit(EXIT_FAILURE);
    }

    // Read the directory entries.
    struct dirent *entry;
    while ((entry = readdir(proc_dir)) != NULL) {
        // Check if the entry is a directory.
        if (entry->d_type != DT_DIR) {
            continue;
        }

        // Get the process ID.
        int pid = atoi(entry->d_name);

        // Open the "/proc/<pid>/cmdline" file.
        char cmdline_path[MAX_CMD_LEN];
        snprintf(cmdline_path, MAX_CMD_LEN, "/proc/%d/cmdline", pid);
        int cmdline_fd = open(cmdline_path, O_RDONLY);
        if (cmdline_fd < 0) {
            perror("open(\"/proc/<pid>/cmdline\")");
            continue;
        }

        // Read the command line.
        char cmdline[MAX_CMD_LEN];
        memset(cmdline, 0, MAX_CMD_LEN);
        if (read(cmdline_fd, cmdline, MAX_CMD_LEN) < 0) {
            perror("read(\"/proc/<pid>/cmdline\")");
            close(cmdline_fd);
            continue;
        }
        close(cmdline_fd);

        // Check if the command line matches the specified command.
        if (strstr(cmdline, argv[1]) != NULL) {
            // Print the process information.
            printf("%d %s\n", pid, cmdline);
        }
    }

    // Close the "/proc/" directory.
    closedir(proc_dir);

    return EXIT_SUCCESS;
}