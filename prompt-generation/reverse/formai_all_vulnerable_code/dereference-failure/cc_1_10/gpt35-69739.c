//FormAI DATASET v1.0 Category: System process viewer ; Style: relaxed
/*
 * This is a custom system process viewer program built using the C programming language.
 * The program displays information about currently running processes on a Linux system.
 * The program uses the sysinfo() library function to gather information about each process 
 * that is currently executing, and displays this information on the screen in a tabular format.
 *
 * Author: YourNameHere
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <signal.h>
#include <sys/sysinfo.h>

void print_header();
void print_process_info(char* pid);

int main(int argc, char** argv) {
    // Print header
    print_header();

    // Open directory containing process info
    DIR* dir = opendir("/proc");
    if (dir == NULL) {
        printf("Could not open directory /proc\n");
        return -1;
    }

    // Loop through each directory in /proc
    struct dirent* entry;
    while ((entry = readdir(dir)) != NULL) {
        // Check if it is a directory (i.e. represents a process)
        char* str_pid = entry->d_name;
        int pid = atoi(str_pid);
        if (pid > 0) {
            // Print process info
            print_process_info(str_pid);
        }
    }

    // Close directory
    closedir(dir);

    return 0;
}

void print_header() {
    printf("%-10s%-30s%-10s%-10s%-20s\n", "PID", "Command", "State", "Threads", "Memory Usage");
    printf("------------------------------------------------------------------------\n");
}

void print_process_info(char* pid) {
    // Open file containing information about the process
    char path[50];
    sprintf(path, "/proc/%s/stat", pid);
    FILE* file = fopen(path, "r");
    if (file == NULL) {
        // Process might have terminated during the loop; no need to panic
        return;
    }

    // Read process information
    char command[20];
    char state;
    int num_threads;
    long int utime, stime, cutime, cstime, starttime;
    fscanf(file, "%s %*s %c %*d %*d %*d %*d %*d %*u %*u %*u %*u %lu %lu %lu %lu %*u %lu", 
           command, &state, &num_threads, &utime, &stime, &cutime, &cstime, &starttime);

    // Compute memory usage
    long int memory;
    char mem_path[50];
    sprintf(mem_path, "/proc/%s/statm", pid);
    FILE* mem_file = fopen(mem_path, "r");
    if (mem_file == NULL) {
        // Process might have terminated during the loop; no need to panic
        memory = 0;
    } else {
        fscanf(mem_file, "%ld", &memory);
        fclose(mem_file);
    }
    memory *= 4096;

    // Close file
    fclose(file);

    // Remove name of command from command argument list
    char* p = strchr(command, '/');
    if (p != NULL) {
        strcpy(command, p+1);
    }

    // Print process info
    printf("%-10s%-30s%-10c%-10d%-20ld\n", pid, command, state, num_threads, memory);
}