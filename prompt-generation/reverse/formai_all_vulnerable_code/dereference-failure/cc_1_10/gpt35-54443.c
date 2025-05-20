//FormAI DATASET v1.0 Category: System process viewer ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

#define MAX_PATH 1024

void print_process_info(char* pid) {
    // Open the process status file
    char proc_file[MAX_PATH];
    sprintf(proc_file, "/proc/%s/status", pid);
    FILE* fp = fopen(proc_file, "r");

    // Read the process name and print it
    char line[MAX_PATH];
    char* name = NULL;
    while (fgets(line, MAX_PATH, fp)) {
        if (strncmp(line, "Name:", 5) == 0) {
            name = strdup(line + 6);
            name[strcspn(name, "\r\n")] = 0;
            break;
        }
    }
    printf("%s (%s)\n", name, pid);
    free(name);

    // Close the file
    fclose(fp);
}

void process_dir(const char* dir_path) {
    DIR* dir = opendir(dir_path);
    if (!dir) {
        return;
    }

    // Loop through all entries in the directory
    struct dirent* entry;
    while ((entry = readdir(dir)) != NULL) {
        // Skip entries that are not directories or cannot be converted to integers
        if (entry->d_type != DT_DIR) {
            continue;
        }
        int pid = atoi(entry->d_name);
        if (pid <= 0) {
            continue;
        }

        // Print information about the current process
        print_process_info(entry->d_name);

        // Recursively process the subdirectory
        char sub_dir[MAX_PATH];
        sprintf(sub_dir, "%s/%s", dir_path, entry->d_name);
        process_dir(sub_dir);
    }

    // Close the directory
    closedir(dir);
}

int main() {
    printf("The following processes are running on the system:\n");
    process_dir("/proc");
    return 0;
}