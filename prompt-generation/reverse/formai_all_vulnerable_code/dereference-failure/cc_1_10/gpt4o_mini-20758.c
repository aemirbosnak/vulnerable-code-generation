//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>

#define MAX_PROCESSES 1024
#define BUFFER_SIZE 256

typedef struct {
    int pid;
    char name[BUFFER_SIZE];
    long memory;
} ProcessInfo;

int is_number(const char *str) {
    while (*str) {
        if (!isdigit(*str)) return 0;
        str++;
    }
    return 1;
}

void get_process_info(const char *pid, ProcessInfo *process) {
    char path[BUFFER_SIZE];
    snprintf(path, sizeof(path), "/proc/%s/stat", pid);
    
    FILE *fp = fopen(path, "r");
    if (fp == NULL) {
        fprintf(stderr, "Could not open file: %s\n", path);
        return;
    }
    
    fscanf(fp, "%d %s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %lld", 
            &process->pid, process->name, &process->memory);
    
    // Clean the name
    memmove(process->name, process->name + 1, strlen(process->name));
    process->name[strlen(process->name) - 1] = '\0'; // Remove trailing parenthesis
    
    fclose(fp);
}

void list_processes() {
    DIR *directory;
    struct dirent *entry;
    ProcessInfo processes[MAX_PROCESSES];
    int count = 0;

    directory = opendir("/proc");
    if (directory == NULL) {
        perror("Could not open /proc directory");
        return;
    }

    while ((entry = readdir(directory)) != NULL) {
        if (is_number(entry->d_name)) {
            ProcessInfo process;
            get_process_info(entry->d_name, &process);
            processes[count++] = process;
        }
    }

    closedir(directory);

    // Output the gathered information
    printf("%-10s %-40s %-10s\n", "PID", "NAME", "MEMORY (KB)");
    printf("-------------------------------------------------------\n");
    
    for (int i = 0; i < count; i++) {
        printf("%-10d %-40s %-10ld\n", processes[i].pid, processes[i].name, processes[i].memory);
    }
}

int main() {
    printf("Welcome to the Linux Process Viewer!\n");
    printf("Here is a list of the currently running processes:\n");
    
    list_processes();
    return 0;
}