//FormAI DATASET v1.0 Category: System process viewer ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

#define MAX_PID_LENGTH 10
#define MAX_COMMAND_LENGTH 1024

// This function retrieves the name of the command from /proc/pid/stat file
void get_command_name(const char* pid, char* command_name) {
    char stat_file_path[256];
    sprintf(stat_file_path, "/proc/%s/stat", pid);
    int fd = open(stat_file_path, O_RDONLY);
    if (fd == -1) {
        perror("Error opening stat file.");
        exit(1);
    }
    char buffer[MAX_COMMAND_LENGTH];
    read(fd, buffer, MAX_COMMAND_LENGTH);
    close(fd);
    char* command_start = strchr(buffer, '(')+1;
    char* command_end = strchr(command_start, ')');
    int command_length = command_end - command_start;
    strncpy(command_name, command_start, command_length); // Copy the command name to the output argument
    command_name[command_length] = '\0'; // Add null character at the end of the string
}

// This function prints the process details for the given PID
void print_process_details(const char* pid) {
    char command_name[MAX_COMMAND_LENGTH];
    get_command_name(pid, command_name);
    printf("%-10s %-20s\n", pid, command_name);
}

// This function prints the header for the process table
void print_process_table_header() {
    printf("%-10s %-20s\n", "PID", "COMMAND");
    printf("----------------------------------\n");
}

int main() {
    int pid;
    DIR* proc_dir = opendir("/proc");
    if (proc_dir == NULL) {
        perror("Error opening /proc directory.");
        return 1;
    }
    print_process_table_header();
    struct dirent* entry;
    while ((entry = readdir(proc_dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }
        // Check if the entry is a directory with a name containing only digits (i.e., a process directory)
        int is_process_directory = 1;
        for (int i = 0; i < strlen(entry->d_name); i++) {
            if (entry->d_name[i] < '0' || entry->d_name[i] > '9') {
                is_process_directory = 0;
                break;
            }
        }
        if (is_process_directory) {
            print_process_details(entry->d_name);
        }
    }
    closedir(proc_dir);
    return 0;
}