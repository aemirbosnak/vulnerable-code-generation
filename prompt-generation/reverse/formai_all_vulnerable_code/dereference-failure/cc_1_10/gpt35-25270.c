//FormAI DATASET v1.0 Category: System process viewer ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

#define MAX_PID_LEN 10

/**
 * This program will print out the list of running processes on the system with their respective 
 * Process ID (PID), Name and Memory Size.
 */

/**
 * This function checks if the given string represents a number.
 */
int is_number(char* str) {
    for (int i = 0; i < strlen(str); i++) {
        if (!isdigit(str[i])) {
            return 0;
        }
    }
    return 1;
}

/**
 * This function returns the size of the memory used by the given process identified by its PID.
 * It reads from the /proc/${PID}/status file to find the VmSize field.
 */
long get_memory_size(char* pid) {
    char path[50];
    sprintf(path, "/proc/%s/status", pid);

    FILE* fp = fopen(path, "r");
    if (fp == NULL) {
        return -1;
    }

    char* line = NULL;
    size_t len = 0;
    ssize_t read;

    long memory_size = -1;

    while ((read = getline(&line, &len, fp)) != -1) {
        if (strncmp(line, "VmSize:", 7) == 0) {
            char* value = strtok(line + 7, " ");
            if (is_number(value)) {
                memory_size = strtol(value, NULL, 10);
            }
            break;
        }
    }

    fclose(fp);
    if (line) {
        free(line);
    }

    return memory_size;
}

/**
 * This function returns the name of the given process identified by its PID.
 * It reads from the /proc/${PID}/comm file to find the name.
 */
char* get_process_name(char* pid) {
    char path[50];
    sprintf(path, "/proc/%s/comm", pid);

    FILE* fp = fopen(path, "r");
    if (fp == NULL) {
        return NULL;
    }

    char* line = NULL;
    size_t len = 0;
    ssize_t read;

    char* name = NULL;
    if ((read = getline(&line, &len, fp)) != -1) {
        name = malloc(sizeof(char) * (strlen(line) + 1));
        strcpy(name, line);
    }

    fclose(fp);
    if (line) {
        free(line);
    }

    return name;
}

/**
 * This function prints out the list of running processes on the system with their respective 
 * Process ID (PID), Name and Memory Size.
 */
void print_process_list() {
    DIR* dir = opendir("/proc");
    if (dir == NULL) {
        printf("Error: could not open /proc directory\n");
        return;
    }

    printf("%-10s %-50s %s\n", "PID", "Name", "Memory Size (KB)");

    struct dirent* entry;

    while ((entry = readdir(dir)) != NULL) {
        if (is_number(entry->d_name)) {
            char* pid = entry->d_name;
            long memory_size = get_memory_size(pid);
            char* process_name = get_process_name(pid);

            if (memory_size != -1 && process_name != NULL) {
                printf("%-10s %-50s %ld\n", pid, process_name, memory_size);
                free(process_name);
            }
        }
    }

    closedir(dir);
}

int main() {
    print_process_list();
    return 0;
}