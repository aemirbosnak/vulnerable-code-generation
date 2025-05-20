//GEMINI-pro DATASET v1.0 Category: System process viewer ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>

// Elementary, my dear Watson!
void view_processes(char *proc_path) {
    DIR *proc_dir;
    struct dirent *proc_entry;
    struct stat proc_stat;
    char proc_name[256];
    char proc_stat_path[256];

    // Open the /proc directory
    proc_dir = opendir(proc_path);
    if (proc_dir == NULL) {
        perror("opendir");
        exit(EXIT_FAILURE);
    }

    // Iterate over the /proc directory
    while ((proc_entry = readdir(proc_dir)) != NULL) {
        // Skip "." and ".."
        if (strcmp(proc_entry->d_name, ".") == 0 || strcmp(proc_entry->d_name, "..") == 0) {
            continue;
        }

        // Check if the entry is a directory
        snprintf(proc_stat_path, sizeof(proc_stat_path), "%s/%s/stat", proc_path, proc_entry->d_name);
        if (stat(proc_stat_path, &proc_stat) == -1) {
            perror("stat");
            continue;
        }

        if (!S_ISDIR(proc_stat.st_mode)) {
            continue;
        }

        // Read the process name
        snprintf(proc_name, sizeof(proc_name), "/proc/%s/cmdline", proc_entry->d_name);
        FILE *proc_cmdline = fopen(proc_name, "r");
        if (proc_cmdline == NULL) {
            perror("fopen");
            continue;
        }
        fgets(proc_name, sizeof(proc_name), proc_cmdline);
        fclose(proc_cmdline);

        // Print the process information
        printf("%s (%s)\n", proc_name, proc_entry->d_name);
    }

    // Close the /proc directory
    closedir(proc_dir);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s proc_path\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    view_processes(argv[1]);

    return EXIT_SUCCESS;
}