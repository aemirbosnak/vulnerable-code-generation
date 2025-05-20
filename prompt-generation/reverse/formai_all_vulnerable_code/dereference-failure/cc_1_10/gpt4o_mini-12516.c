//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <ctype.h>

#define BUF_SIZE 256

void print_process_info(const char* pid) {
    char path[BUF_SIZE];
    sprintf(path, "/proc/%s/stat", pid);
    
    FILE *file = fopen(path, "r");
    if (file) {
        char comm[BUF_SIZE];
        char state;
        int ppid;
        unsigned long utime, stime, cutime, cstime;
        
        // Read the required fields from the stat file
        fscanf(file, "%*d %s %c %d %*d %*u %*u %*u %*u %*u %*u %*u %*u %*u %lu %lu %lu %lu",
               comm, &state, &ppid, &utime, &stime, &cutime, &cstime);
        
        // Display process details
        printf("%-10s %-10c %-5d %lu %lu %s\n", pid, state, ppid, utime + stime, cutime + cstime, comm);
        fclose(file);
    }
}

void list_all_processes() {
    DIR *proc_dir = opendir("/proc");
    struct dirent *entry;

    if (proc_dir == NULL) {
        perror("opendir");
        exit(EXIT_FAILURE);
    }

    printf("%-10s %-10s %-5s %-10s  %-10s %s\n", "PID", "STAT", "PPID", "UTIME", "STIME", "COMMAND");
    printf("-----------------------------------------------------------\n");

    // Iterate through all entries in the /proc directory
    while ((entry = readdir(proc_dir)) != NULL) {
        if (isdigit(entry->d_name[0])) {
            // This is a PID directory, process it
            print_process_info(entry->d_name);
        }
    }

    closedir(proc_dir);
}

int main() {
    printf("Simple Process Viewer\n");
    printf("======================\n");
    list_all_processes();
    return 0;
}