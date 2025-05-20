//FormAI DATASET v1.0 Category: System process viewer ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

// Define constants
#define MAX_PATH_LENGTH 1024
#define MAX_PROCESS_NAME_LENGTH 1024
#define MAX_USERNAME_LENGTH 1024
#define MAX_NUM_PROCESSES 1024

// Define struct for storing process information
struct process_info {
    char process_name[MAX_PROCESS_NAME_LENGTH];
    char username[MAX_USERNAME_LENGTH];
    int pid;
    int ppid;
    int rss;
    long int utime;
};

// Function to check if a string contains only digits
int is_digit(char *str) {
    int i;
    for (i = 0; i < strlen(str); i++) {
        if (!isdigit(str[i])) {
            return 0;
        }
    }
    return 1;
}

// Function to parse process information from a file
void parse_process_info(char *filename, struct process_info *info) {
    // Open file for reading
    char filepath[MAX_PATH_LENGTH];
    snprintf(filepath, sizeof(filepath), "/proc/%s/stat", filename);
    FILE *fp = fopen(filepath, "r");

    // Read data from file
    char *line = NULL;
    size_t len = 0;
    getline(&line, &len, fp);

    // Parse data
    char *token = strtok(line, " ");
    int i = 0;
    while (token != NULL) {
        switch (i) {
            case 1:
                // Process name
                strcpy(info->process_name, token + 1);
                info->process_name[strlen(info->process_name) - 1] = '\0'; // Remove trailing ")"
                break;
            case 3:
                // PID
                info->pid = atoi(token);
                break;
            case 4:
                // Parent PID
                info->ppid = atoi(token);
                break;
            case 5:
                // RSS
                info->rss = atoi(token);
                break;
            case 13:
                // User time
                info->utime = atol(token);
                break;
        }
        i++;
        token = strtok(NULL, " ");
    }

    // Close file
    fclose(fp);

    // Get username from UID
    snprintf(filepath, sizeof(filepath), "/proc/%s/status", filename);
    fp = fopen(filepath, "r");
    while (getline(&line, &len, fp) != -1) {
        if (strncmp(line, "Uid:", 4) == 0) {
            token = strtok(line, "\t");
            token = strtok(NULL, "\t");
            char command[MAX_PATH_LENGTH];
            snprintf(command, sizeof(command), "getent passwd %s | cut -d: -f1", token);
            FILE *pipe = popen(command, "r");
            fgets(info->username, MAX_USERNAME_LENGTH, pipe);
            pclose(pipe);
            info->username[strlen(info->username) - 1] = '\0'; // Remove newline character
        }
    }
    fclose(fp);
}

int main(int argc, char **argv) {
    // Open directory /proc
    DIR *dir = opendir("/proc");
    if (dir == NULL) {
        printf("Failed to open directory /proc\n");
        return 1;
    }

    // Read directory and get list of processes
    struct dirent *ent;
    int num_processes = 0;
    struct process_info processes[MAX_NUM_PROCESSES];
    while ((ent = readdir(dir)) != NULL) {
        if (is_digit(ent->d_name)) {
            // File name is a number (PID)
            parse_process_info(ent->d_name, &processes[num_processes]);
            num_processes++;
        }
    }

    // Close directory
    closedir(dir);

    // Sort processes by RSS
    for (int i = 0; i < num_processes; i++) {
        for (int j = i + 1; j < num_processes; j++) {
            if (processes[i].rss < processes[j].rss) {
                struct process_info tmp = processes[i];
                processes[i] = processes[j];
                processes[j] = tmp;
            }
        }
    }

    // Print result
    printf("%-15s %-10s %-10s %-10s %-10s\n", "Process Name", "PID", "PPID", "RSS (kB)", "User Time");
    for (int i = 0; i < num_processes; i++) {
        printf("%-15s %-10d %-10d %-10d %-10ld\n", processes[i].process_name, processes[i].pid, processes[i].ppid, processes[i].rss, processes[i].utime);
    }

    return 0;
}