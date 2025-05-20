//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <ctype.h>

#define MAX_PATH 1024
#define PROC_DIR "/proc"

void list_processes();
void print_process_info(pid_t pid);
void print_usage();

int main(int argc, char *argv[]) {
    if (argc > 1) { 
        pid_t pid = atoi(argv[1]);
        if (pid > 0) {
            print_process_info(pid);
        } else {
            print_usage();
        }
    } else {
        list_processes();
    }
    return 0;
}

void list_processes() {
    DIR *dir;
    struct dirent *entry;
    char path[MAX_PATH];

    if ((dir = opendir(PROC_DIR)) == NULL) {
        perror("opendir");
        exit(EXIT_FAILURE);
    }

    printf("%-10s %-25s %-10s\n", "PID", "COMMAND", "STATE");
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_DIR) {
            pid_t pid = atoi(entry->d_name);
            if (pid > 0) {
                snprintf(path, sizeof(path), PROC_DIR"/%s/stat", entry->d_name);
                FILE *file = fopen(path, "r");
                if (file) {
                    char command[256];
                    char state;
                    fscanf(file, "%*d %s %*c %c", command, &state);
                    fclose(file);
                    command[strcspn(command, ")]")] = 0;  // Remove trailing ')' or ']'
                    printf("%-10d %-25s %-10c\n", pid, command, state);
                }
            }
        }
    }
    closedir(dir);
}

void print_process_info(pid_t pid) {
    char path[MAX_PATH];
    snprintf(path, sizeof(path), PROC_DIR"/%d/stat", pid);
    FILE *file = fopen(path, "r");

    if (!file) {
        perror("fopen");
        return;
    }

    pid_t ppid;
    char state;
    unsigned long vsize, rss;
    char comm[256];
    
    fscanf(file, "%d %s %*c %d %*d %*d %*d %*d %*u %*u %*u %lu %lu %*d %*d %*d %*u %*u %*u %*u %*u", &pid, comm, &ppid, &vsize, &rss);
    fclose(file);
    
    comm[strcspn(comm, ")]")] = 0; // Clean up command string

    printf("Process ID: %d\n", pid);
    printf("Command: %s\n", comm);
    printf("Parent Process ID: %d\n", ppid);
    printf("State: %c\n", state);
    printf("Virtual Memory Size: %lu KB\n", vsize / 1024);
    printf("Resident Set Size: %lu KB\n", rss / 1024);

    // Getting CPU usage
    snprintf(path, sizeof(path), PROC_DIR"/%d/statm", pid);
    file = fopen(path, "r");
    
    if (file) {
        unsigned long size, resident, shared, text, lib, data, dt;
        fscanf(file, "%lu %lu %lu %lu %lu %lu %lu", &size, &resident, &shared, &text, &lib, &data, &dt);
        fclose(file);
        printf("Memory Size: %lu\n", size);
    }
}

void print_usage() {
    printf("Usage:\n");
    printf("  To list all processes: ./process_viewer\n");
    printf("  To get info about a specific process: ./process_viewer <PID>\n");
}