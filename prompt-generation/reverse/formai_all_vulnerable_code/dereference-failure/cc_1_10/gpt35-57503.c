//FormAI DATASET v1.0 Category: System process viewer ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <ctype.h>

int is_number(const char* str) {
    // Checks if a string is a number
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isdigit(str[i])) {
            return 0;
        }
    }
    return 1;
}

void print_process_info(const char* pid, const char* name, const char* state) {
    // Prints the process information
    printf("-- Process Information --\n");
    printf("PID: %s\n", pid);
    printf("Name: %s\n", name);
    printf("State: %s\n", state);
}

void read_process_info(const char* pid) {
    // Reads the process information from the /proc file system
    char filename[512];
    snprintf(filename, sizeof(filename), "/proc/%s/stat", pid);

    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        return;
    }

    char line[1024];
    if (fgets(line, sizeof(line), fp)) {
        char* p = strtok(line, " ");
        char* name = strtok(NULL, " ");
        char* state = strtok(NULL, " ");
        print_process_info(pid, name, state);
    }

    fclose(fp);
}

void process_list() {
    // Lists all the processes on the system using the /proc file system
    DIR* dir = opendir("/proc");
    if (dir == NULL) {
        printf("Unable to open /proc directory\n");
        return;
    }

    struct dirent* entry;
    while ((entry = readdir(dir)) != NULL) {
        if (is_number(entry->d_name)) {
            read_process_info(entry->d_name);
        }
    }

    closedir(dir);
}

int main() {
    printf("=== C System Process Viewer Example ===\n");

    while (1) {
        // User input menu
        printf("\nEnter an option:\n");
        printf("1. List all processes\n");
        printf("2. Get process information\n");
        printf("3. Quit\n");

        char option[2];
        fgets(option, sizeof(option), stdin);

        if (option[0] == '1') {
            printf("\n--- Process List ---\n");
            process_list();
        } else if (option[0] == '2') {
            printf("\n--- Get Process Information ---\n");
            printf("Enter the PID: ");
            char pid[10];
            fgets(pid, sizeof(pid), stdin);
            read_process_info(pid);
        } else if (option[0] == '3') {
            printf("Exiting program\n");
            break;
        } else {
            printf("Invalid option\n");
        }
    }

    return 0;
}