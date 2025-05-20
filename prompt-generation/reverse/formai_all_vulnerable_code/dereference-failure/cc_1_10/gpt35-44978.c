//FormAI DATASET v1.0 Category: System process viewer ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>

#define MAX_PID_LENGTH 32
#define MAX_LINE_LENGTH 256

// Function to get the process name from the process ID
char *get_process_name(const char *pid) {
    char *line = NULL;
    size_t len = 0;

    char *proc_path = (char *) malloc(strlen("/proc/") + strlen(pid) + strlen("/status") + 1);
    sprintf(proc_path, "/proc/%s/status", pid);

    FILE *fp = fopen(proc_path, "r");
    if (fp == NULL) {
        fprintf(stderr, "%s: ", proc_path);
        perror("");
        free(proc_path);
        exit(1);
    }

    while (getline(&line, &len, fp) != -1) {
        if (strncmp(line, "Name:", strlen("Name:")) == 0) {
            char *name = (char *) calloc(strlen(line) - strlen("Name:") + 1, sizeof(char));
            sscanf(line, "Name: %s", name);
            free(line);
            fclose(fp);
            free(proc_path);
            return name;
        }
    }

    free(line);
    fclose(fp);
    free(proc_path);
    return NULL;
}

int main() {
    DIR *proc_dir;
    struct dirent *proc_entry;
    char *pid_list[MAX_LINE_LENGTH];
    int pid_count = 0;

    // Open the /proc directory
    proc_dir = opendir("/proc");
    if (proc_dir == NULL) {
        perror("Unable to open /proc directory");
        exit(1);
    }

    // Iterate through the directory entries
    while ((proc_entry = readdir(proc_dir)) != NULL) {
        // Check if the directory entry is a valid process ID
        if (atoi(proc_entry->d_name) != 0) {
            pid_list[pid_count++] = strdup(proc_entry->d_name);
        }
    }

    // Sort the list of process IDs 
    for (int i = 0; i < pid_count; i++) {
        for (int j = i+1; j < pid_count; j++) {
            if (atoi(pid_list[i]) > atoi(pid_list[j])) {
                char *temp = pid_list[i];
                pid_list[i] = pid_list[j];
                pid_list[j] = temp;
            }
        }
    }

    // Print the header
    printf("%-10s %-20s %-10s\n", "PID", "COMMAND", "STATE");

    // Iterate through the sorted list of process IDs and print the details
    for (int i = 0; i < pid_count; i++) {
        char *pid = pid_list[i];
        char proc_status_path[MAX_LINE_LENGTH];
        snprintf(proc_status_path, sizeof(proc_status_path), "/proc/%s/status", pid);

        char *process_name = get_process_name(pid);
        if (process_name == NULL) {
            continue;
        }

        FILE *proc_status = fopen(proc_status_path, "r");

        char line[MAX_LINE_LENGTH];
        char state[MAX_LINE_LENGTH];
        while (fgets(line, MAX_LINE_LENGTH, proc_status) != NULL) {
            if (strncmp(line, "State", 5) == 0) {
                sscanf(line, "%*s %s", state);
            }
        }

        printf("%-10s %-20s %-10s\n", pid, process_name, state);

        fclose(proc_status);
        free(process_name);
    }

    // Close the /proc directory
    closedir(proc_dir);

    return 0;
}