//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <unistd.h>
#include <ctype.h>

// Function to retrieve process information from /proc filesystem
void get_process_info(int pid, char *name, int *ppid) {
    char path[40], buffer[1000];
    FILE *status_file;

    // Construct the path to the status file
    snprintf(path, sizeof(path), "/proc/%d/status", pid);
    status_file = fopen(path, "r");
    if (status_file != NULL) {
        while (fgets(buffer, sizeof(buffer), status_file) != NULL) {
            if (sscanf(buffer, "Name:\t%s", name) == 1)
                ;
            else if (sscanf(buffer, "PPid:\t%d", ppid) == 1)
                ;
        }
        fclose(status_file);
    } else {
        strcpy(name, "Unknown");
        *ppid = -1;
    }
}

// Function to print the header for the process list
void print_header() {
    printf("%-8s %-25s %-8s\n", "PID", "Process Name", "Parent PID");
    printf("%-8s %-25s %-8s\n", "--------", "-------------------------", "--------");
}

// Function to display all processes
void display_processes() {
    struct dirent *entry;
    DIR *proc_dir = opendir("/proc");

    if (proc_dir == NULL) {
        perror("Unable to open /proc directory");
        exit(EXIT_FAILURE);
    }

    print_header();
    
    while ((entry = readdir(proc_dir)) != NULL) {
        if (isdigit(entry->d_name[0])) { // Check if the directory name is a number (i.e., a PID)
            int pid = atoi(entry->d_name);
            char name[256];
            int ppid;

            get_process_info(pid, name, &ppid);
            printf("%-8d %-25s %-8d\n", pid, name, ppid);
        }
    }
    
    closedir(proc_dir);
}

// Function to filter processes by name
void filter_processes_by_name(const char *keyword) {
    struct dirent *entry;
    DIR *proc_dir = opendir("/proc");
    
    if (proc_dir == NULL) {
        perror("Unable to open /proc directory");
        exit(EXIT_FAILURE);
    }

    printf("\nProcesses matching '%s':\n", keyword);
    print_header();

    while ((entry = readdir(proc_dir)) != NULL) {
        if (isdigit(entry->d_name[0])) { // Only consider directories named by PID
            int pid = atoi(entry->d_name);
            char name[256];
            int ppid;

            get_process_info(pid, name, &ppid);
            if (strstr(name, keyword) != NULL) { // Check if process name contains the keyword
                printf("%-8d %-25s %-8d\n", pid, name, ppid);
            }
        }
    }
    
    closedir(proc_dir);
}

int main(int argc, char *argv[]) {
    if (argc > 1) {
        // Filter by process name given as command line argument
        filter_processes_by_name(argv[1]);
    } else {
        // Display all processes
        display_processes();
    }

    return 0;
}