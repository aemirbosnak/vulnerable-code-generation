//FormAI DATASET v1.0 Category: System process viewer ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

#define BUFFER_SIZE 512
#define MAX_PID_LENGTH 10

// Function to check if a given string represents a valid integer
int is_valid_number(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isdigit(str[i]))
            return 0;
    }
    return 1;
}

// Function to read the status file of a process and return its name
char *get_process_name(char *pid) {
    char path[BUFFER_SIZE];
    FILE *fp;
    sprintf(path, "/proc/%s/status", pid);
    fp = fopen(path, "r");
    if (fp == NULL) {
        printf("Error reading process status file.\n");
        return NULL;
    }
    char buffer[BUFFER_SIZE];
    while (fgets(buffer, BUFFER_SIZE, fp)) {
        if (strncmp(buffer, "Name:", 5) == 0) {
            char *name = strdup(buffer + 6);
            name[strlen(name) - 1] = '\0'; // remove trailing newline
            fclose(fp);
            return name;
        }
    }
    fclose(fp);
    return NULL;
}

// Function to print the process table
void print_processes() {
    DIR *proc_dir;
    struct dirent *dir_entry;
    printf("%-10s %-20s %s\n", "PID", "NAME", "STATE");
    proc_dir = opendir("/proc");
    if (proc_dir == NULL) {
        printf("Error opening /proc directory.\n");
        return;
    }
    char *pid;
    char buffer[BUFFER_SIZE];
    while ((dir_entry = readdir(proc_dir)) != NULL) {
        if (is_valid_number(dir_entry->d_name)) {
            pid = dir_entry->d_name;
            char path[BUFFER_SIZE];
            sprintf(path, "/proc/%s/stat", pid);
            FILE *fp = fopen(path, "r");
            if (fp == NULL)
                continue;
            fgets(buffer, BUFFER_SIZE, fp);
            fclose(fp);
            char *tokens[52];
            int num_tokens = 0;
            char *token = strtok(buffer, " ");
            while (token != NULL) {
                tokens[num_tokens] = token;
                num_tokens++;
                token = strtok(NULL, " ");
            }
            if (num_tokens < 3)
                continue;
            char *name = get_process_name(pid);
            if (name == NULL)
                continue;
            printf("%-10s %-20s %s\n", pid, name, tokens[2]);
            free(name);
        }
    }
    closedir(proc_dir);
}

// Main function
int main() {
    print_processes();
    return 0;
}