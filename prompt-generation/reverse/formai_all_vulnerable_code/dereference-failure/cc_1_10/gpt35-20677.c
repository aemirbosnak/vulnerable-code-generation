//FormAI DATASET v1.0 Category: System process viewer ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <ctype.h>

// Function declarations
char *get_process_name(long pid);
int check_is_number(char *str);
char *get_process_status(long pid);

// Main function
int main() {
    DIR *dirp;
    struct dirent *direntp;
    printf("%-10s %-30s %-20s\n", "PID", "Process Name", "Status");
    dirp = opendir("/proc");

    // Loop through all directories in /proc
    while ((direntp = readdir(dirp)) != NULL) {
        char *dir_name = direntp->d_name;

        // Check if directory name only contains numbers
        if (check_is_number(dir_name)) {
            long pid = atol(dir_name);
            char *process_name = get_process_name(pid);
            char *process_status = get_process_status(pid);
            printf("%-10ld %-30s %-20s\n", pid, process_name, process_status);
            free(process_name);
            free(process_status);
        }
    }

    closedir(dirp);
    return 0;
}

char *get_process_name(long pid) {
    char *process_name = malloc(1024);
    sprintf(process_name, "/proc/%ld/cmdline", pid);
    FILE *file = fopen(process_name, "r");

    // Read process name from cmdline file
    int character;
    int i = 0;
    while ((character = fgetc(file)) != EOF) {
        if (character == '\0') {
            process_name[i] = ' ';
        } else {
            process_name[i] = (char) character;
        }
        i++;
    }
    fclose(file);
    return process_name;
}

int check_is_number(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isdigit(str[i])) {
            return 0;
        }
    }
    return 1;
}

char *get_process_status(long pid) {
    char *process_status = malloc(1024);
    char path[1024];

    // Create path to process status file
    sprintf(path, "/proc/%ld/status", pid);

    FILE *file = fopen(path, "r");
    char line[1024];

    // Read status file line by line
    while (fgets(line, sizeof(line), file)) {
        char *token = strtok(line, ":");
        if (token != NULL) {
            if (strcmp(token, "State") == 0) {
                token = strtok(NULL, ":");
                if (token != NULL) {
                    strcpy(process_status, token);
                    break;
                }
            }
        }
    }

    fclose(file);
    return process_status;
}