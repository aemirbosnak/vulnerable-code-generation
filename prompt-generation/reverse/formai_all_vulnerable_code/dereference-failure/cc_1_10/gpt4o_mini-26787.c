//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>

#define PROC_DIR "/proc"
#define COMMAND_PATH_MAX 256

void get_process_info(int pid) {
    char path[COMMAND_PATH_MAX];
    snprintf(path, sizeof(path), "%s/%d/status", PROC_DIR, pid);

    FILE *status_file = fopen(path, "r");
    if (status_file == NULL) {
        return; // Process may have terminated
    }

    char line[256];
    char process_name[256] = "Unknown";
    int vm_size = -1;

    while (fgets(line, sizeof(line), status_file)) {
        if (strncmp(line, "Name:", 5) == 0) {
            sscanf(line, "Name:\t%s", process_name);
        }
        if (strncmp(line, "VmSize:", 7) == 0) {
            sscanf(line, "VmSize:\t%d", &vm_size);
        }
    }

    fclose(status_file);

    // Print process information
    if (vm_size != -1) {
        printf("PID: %d\tName: %s\tMemory: %d KB\n", pid, process_name, vm_size);
    }
}

void list_processes() {
    DIR *dir = opendir(PROC_DIR);
    if (dir == NULL) {
        perror("Could not open /proc directory");
        return;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        // Check if the directory name is a number
        int pid = atoi(entry->d_name);
        if (pid > 0) {
            get_process_info(pid);
        }
    }
    
    closedir(dir);
}

void print_usage() {
    printf("Usage: process_viewer\n");
    printf("Displays currently running processes and their memory usage.\n");
}

int main(int argc, char *argv[]) {
    if (argc > 1) {
        print_usage();
        return EXIT_FAILURE;    
    }

    printf("Process Viewer  v1.0\n");
    printf("=======================\n");
    list_processes();

    return EXIT_SUCCESS;
}