//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>
#include <unistd.h>

#define PROC_DIR "/proc"
#define MAX_BUFFER_SIZE 256

// Function to read a specific file and return its content as a string
char *read_file(const char *filepath) {
    FILE *file = fopen(filepath, "r");
    if (!file) {
        perror("Failed to open file");
        return NULL;
    }
    
    char *buffer = malloc(MAX_BUFFER_SIZE);
    if (!buffer) {
        perror("Failed to allocate memory");
        fclose(file);
        return NULL;
    }
    
    if (fgets(buffer, MAX_BUFFER_SIZE, file) == NULL) {
        free(buffer);
        fclose(file);
        return NULL;
    }

    fclose(file);
    return buffer;
}

// Function to check if a string is a number (valid PID)
int is_number(const char *str) {
    while (*str) {
        if (!isdigit(*str)) {
            return 0;
        }
        str++;
    }
    return 1;
}

// Function to display process details given a PID
void display_process_details(const char *pid) {
    char filepath[MAX_BUFFER_SIZE];
    snprintf(filepath, sizeof(filepath), "%s/%s/stat", PROC_DIR, pid);
    
    char *content = read_file(filepath);
    if (content) {
        char comm[MAX_BUFFER_SIZE];
        int state;
        sscanf(content, "%*d %s %*c %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %d",
               comm, &state);
        printf("PID: %s\nCommand: %s\nState: %d\n", pid, comm, state);
        free(content);
    } else {
        printf("Failed to read details for PID: %s\n", pid);
    }
}

// Function to list all processes
void list_processes() {
    DIR *proc_dir = opendir(PROC_DIR);
    struct dirent *entry;

    if (!proc_dir) {
        perror("Failed to open /proc directory");
        return;
    }

    printf("%-10s %-20s %-10s\n", "PID", "Command", "State");
    printf("%-10s %-20s %-10s\n", "----", "-------", "-----");

    while ((entry = readdir(proc_dir)) != NULL) {
        if (is_number(entry->d_name)) {
            display_process_details(entry->d_name);
        }
    }

    closedir(proc_dir);
}

// Main function to execute the program
int main(int argc, char *argv[]) {
    if (argc > 1) {
        if (is_number(argv[1])) {
            display_process_details(argv[1]);
        } else {
            fprintf(stderr, "Invalid PID entered: %s\n", argv[1]);
            return EXIT_FAILURE;
        }
    } else {
        list_processes();
    }
    return EXIT_SUCCESS;
}