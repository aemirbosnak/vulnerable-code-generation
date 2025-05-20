//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <ctype.h>

#define MAX_PATH 256
#define BUFFER_SIZE 1024

void print_process_info(const char *pid) {
    char path[MAX_PATH];
    FILE *status_file;
    char line[BUFFER_SIZE];

    snprintf(path, sizeof(path), "/proc/%s/status", pid);
    status_file = fopen(path, "r");

    if (status_file == NULL) {
        // If we can't open the file, it likely means the process has died in the meantime
        return;
    }

    printf("Process ID: %s\n", pid);
    while (fgets(line, sizeof(line), status_file)) {
        // We will just print some basic information about the process
        if (strncmp(line, "Name:", 5) == 0 || 
            strncmp(line, "Pid:", 4) == 0 || 
            strncmp(line, "Uid:", 4) == 0 || 
            strncmp(line, "State:", 6) == 0) {
            printf("%s", line);
        }
    }
    printf("-----------------------------\n");
    fclose(status_file);
}

int is_numeric(const char *str) {
    while (*str) {
        if (!isdigit(*str)) return 0;
        str++;
    }
    return 1;
}

void list_processes() {
    DIR *proc_dir;
    struct dirent *entry;

    proc_dir = opendir("/proc");
    if (proc_dir == NULL) {
        perror("Unable to open /proc directory");
        exit(EXIT_FAILURE);
    }

    printf("Current Processes in the System:\n");
    printf("===============================\n");

    while ((entry = readdir(proc_dir)) != NULL) {
        if (is_numeric(entry->d_name)) {
            print_process_info(entry->d_name);
        }
    }

    closedir(proc_dir);
}

int main() {
    printf("Welcome to the Linux Process Viewer!\n");
    printf("This tool will help you explore currently running processes.\n\n");

    list_processes();

    printf("Finished displaying process information.\n");
    return 0;
}