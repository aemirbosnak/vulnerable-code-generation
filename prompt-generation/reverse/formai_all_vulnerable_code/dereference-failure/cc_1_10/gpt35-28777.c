//FormAI DATASET v1.0 Category: System process viewer ; Style: Ken Thompson
#include <stdio.h>
#include <dirent.h>
#include <string.h>

int main() {

    DIR *dir;
    struct dirent *entry;

    // Open the directory "/proc"
    dir = opendir("/proc");

    // Loop through each entry in the directory
    while ((entry = readdir(dir)) != NULL) {

        // Check if the entry is a directory and if its name is a number
        if (entry->d_type == DT_DIR && isdigit(entry->d_name[0])) {

            // Open the status file for this process
            char status_path[100];
            sprintf(status_path, "/proc/%s/status", entry->d_name);
            FILE *status_file = fopen(status_path, "r");

            // Read the process name from the status file
            char line[100];
            char *name = NULL;
            while (fgets(line, sizeof(line), status_file)) {
                if (strncmp(line, "Name:", 5) == 0) {
                    name = strdup(line + 6);
                    break;
                }
            }

            // Open the stat file for this process
            char stat_path[100];
            sprintf(stat_path, "/proc/%s/stat", entry->d_name);
            FILE *stat_file = fopen(stat_path, "r");

            // Read the process PID, PPID, and CPU usage from the stat file
            int pid, ppid;
            float cpu_usage;
            fscanf(stat_file, "%d %*s %*c %d %*c %*c %*c %*c %*c %*c %*c %*c %*c %*c %f", &pid, &ppid, &cpu_usage);

            // Print the process information
            printf("PID: %d, Name: %s, PPID: %d, CPU Usage: %.2f%%\n", pid, name, ppid, cpu_usage);

            // Clean up
            free(name);
            fclose(status_file);
            fclose(stat_file);
        }
    }

    // Clean up
    closedir(dir);

    return 0;
}