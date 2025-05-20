//FormAI DATASET v1.0 Category: System process viewer ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

#define BUFFER_SIZE 256

// Function to check if the given string is a number
int is_number(const char* str) {
    int i;
    for (i = 0; str[i] != '\0'; i++) {
        if (!isdigit(str[i]))
            return 0;
    }
    return 1;
}

// Function to get the parent process id
int get_parent_pid(const int pid) {
    int parent_pid = -1;
    char path[BUFFER_SIZE];
    snprintf(path, BUFFER_SIZE, "/proc/%d/stat", pid);
    FILE* fp = fopen(path, "r");
    if (fp == NULL) {
        perror("Error opening file");
        return -1;
    }
    char buff[BUFFER_SIZE];
    fgets(buff, BUFFER_SIZE, fp);
    char* token = strtok(buff, " ");
    int i = 0;
    while (token != NULL) {
        i++;
        if (i == 4) {
            parent_pid = atoi(token);
            break;
        }
        token = strtok(NULL, " ");
    }
    fclose(fp);
    return parent_pid;
}

// Function to get the command name of a process
void get_command_name(const int pid, char* command_name) {
    char path[BUFFER_SIZE];
    snprintf(path, BUFFER_SIZE, "/proc/%d/cmdline", pid);
    FILE* fp = fopen(path, "r");
    if (fp == NULL) {
        perror("Error opening file");
        return;
    }
    fgets(command_name, BUFFER_SIZE, fp);
    fclose(fp);
}

int main() {
    DIR* proc = opendir("/proc");
    if (proc == NULL) {
        perror("Error opening directory");
        return EXIT_FAILURE;
    }
    printf("%-8s %-10s %-10s %s\n", "PID", "COMMAND", "PPID", "STATUS");
    struct dirent* file;
    while ((file = readdir(proc)) != NULL) {
        if (is_number(file->d_name)) {
            int pid = atoi(file->d_name);
            int parent_pid = get_parent_pid(pid);
            char command_name[BUFFER_SIZE];
            get_command_name(pid, command_name);
            printf("%-8d %-10s ", pid, command_name);
            if (parent_pid == -1) {
                printf("%-10s ", "N/A");
            }
            else {
                printf("%-10d ", parent_pid);
            }
            char path[BUFFER_SIZE];
            snprintf(path, BUFFER_SIZE, "/proc/%d/status", pid);
            FILE* fp = fopen(path, "r");
            if (fp == NULL) {
                perror("Error opening file");
                printf("N/A\n");
                continue;
            }
            char buff[BUFFER_SIZE];
            while (fgets(buff, BUFFER_SIZE, fp)) {
                if (strncmp(buff, "State:", 6) == 0) {
                    char* token = strtok(buff + 7, " ");
                    printf("%s\n", token);
                    break;
                }
            }
            fclose(fp);
        }
    }
    closedir(proc);
    return EXIT_SUCCESS;
}