//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <ctype.h>

#define PROC_PATH "/proc"
#define BUF_SIZE 1024

// Function to check if a string represents a number
int is_number(const char* str) {
    while (*str) {
        if (!isdigit(*str)) {
            return 0;
        }
        str++;
    }
    return 1;
}

// Function to read process information
void read_process_info(int pid) {
    char path[BUF_SIZE];
    FILE *status_file;
    snprintf(path, sizeof(path), "%s/%d/status", PROC_PATH, pid);
    status_file = fopen(path, "r");

    if (status_file) {
        char buffer[BUF_SIZE];
        printf("\nProcess ID: %d\n", pid);
        while (fgets(buffer, sizeof(buffer), status_file)) {
            if (strncmp(buffer, "Name:", 5) == 0 || strncmp(buffer, "State:", 6) == 0 || strncmp(buffer, "Pid:", 4) == 0) {
                printf("%s", buffer);
            }
            if (strncmp(buffer, "VmSize:", 7) == 0) {
                printf("%s", buffer);
            }
        }
        fclose(status_file);
    }
}

// Function to list all running processes
void list_processes() {
    DIR *proc_dir;
    struct dirent *entry;
    proc_dir = opendir(PROC_PATH);

    if (proc_dir) {
        while ((entry = readdir(proc_dir)) != NULL) {
            if (is_number(entry->d_name)) {
                int pid = atoi(entry->d_name);
                read_process_info(pid);
            }
        }
        closedir(proc_dir);
    } else {
        perror("Failed to open /proc directory");
    }
}

// Function to print the usage of the command
void print_usage(const char *program_name) {
    printf("Usage: %s [options]\n", program_name);
    printf("Options:\n");
    printf("  -h, --help      Display this help message\n");
    printf("  -l, --list      List all running processes\n");
}

// The main function
int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Error: No options provided.\n");
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0) {
        print_usage(argv[0]);
        return EXIT_SUCCESS;
    }
    
    if (strcmp(argv[1], "-l") == 0 || strcmp(argv[1], "--list") == 0) {
        printf("Listing all running processes:\n");
        list_processes();
        return EXIT_SUCCESS;
    }

    fprintf(stderr, "Error: Invalid option '%s'.\n", argv[1]);
    print_usage(argv[0]);
    return EXIT_FAILURE;
}