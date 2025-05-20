//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>

void display_process_info(const char *pid) {
    char path[256];
    sprintf(path, "/proc/%s/status", pid);
    FILE *file = fopen(path, "r");
    if (!file) {
        printf("Could not open status file for PID: %s\n", pid);
        return;
    }

    char line[256];
    printf("Observing the mysterious process with PID: %s\n", pid);
    while (fgets(line, sizeof(line), file)) {
        if (strncmp(line, "Name:", 5) == 0 || strncmp(line, "State:", 6) == 0 || 
            strncmp(line, "Uid:", 4) == 0 || strncmp(line, "Gid:", 4) == 0) {
            printf("%s", line);
        }
    }
    fclose(file);
}

void list_all_processes() {
    DIR *proc_dir = opendir("/proc");
    struct dirent *entry;

    if (!proc_dir) {
        printf("Could not open /proc directory.\n");
        return;
    }

    printf("The elusive agents of our operating system lie beneath... \n");

    while ((entry = readdir(proc_dir)) != NULL) {
        if (isdigit(entry->d_name[0])) { // Check if the directory name is a PID
            display_process_info(entry->d_name);
        }
    }

    closedir(proc_dir);
}

void search_process_by_name(const char *target_name) {
    DIR *proc_dir = opendir("/proc");
    struct dirent *entry;

    if (!proc_dir) {
        printf("Could not open /proc directory.\n");
        return;
    }

    printf("In pursuit of the shadowy process named '%s'...\n", target_name);

    while ((entry = readdir(proc_dir)) != NULL) {
        if (isdigit(entry->d_name[0])) { // Check if it's a PID
            char path[256];
            sprintf(path, "/proc/%s/comm", entry->d_name);
            FILE *comm_file = fopen(path, "r");
            if (comm_file) {
                char process_name[256];
                fgets(process_name, sizeof(process_name), comm_file);
                process_name[strcspn(process_name, "\n")] = 0; // Remove newline

                if (strcmp(process_name, target_name) == 0) {
                    printf("Found the target process: PID: %s, Name: %s\n", entry->d_name, process_name);
                    fclose(comm_file);
                    display_process_info(entry->d_name);
                }
                fclose(comm_file);
            }
        }
    }

    closedir(proc_dir);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <process_name or 'all'>\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[1], "all") == 0) {
        list_all_processes();
    } else {
        search_process_by_name(argv[1]);
    }

    return 0;
}