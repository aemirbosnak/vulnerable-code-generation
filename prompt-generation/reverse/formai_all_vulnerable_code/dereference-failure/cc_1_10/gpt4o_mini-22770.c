//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <ctype.h>

#define BUFFER_SIZE 256
#define STATUS_FILE "/proc/%s/status"

void trim_whitespace(char *str) {
    char *end;

    // Trim leading space
    while (isspace((unsigned char)*str)) str++;

    // Trim trailing space
    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) end--;

    // Null terminate
    end[1] = '\0';
}

void print_process_info(const char *pid) {
    char status_path[BUFFER_SIZE];
    snprintf(status_path, sizeof(status_path), STATUS_FILE, pid);
    
    FILE *file = fopen(status_path, "r");
    if (!file) {
        perror("Failed to open process status file");
        return;
    }

    char line[BUFFER_SIZE];
    while (fgets(line, sizeof(line), file)) {
        if (strncmp(line, "Name:", 5) == 0 || strncmp(line, "Pid:", 4) == 0 ||
            strncmp(line, "State:", 6) == 0 || strncmp(line, "Uid:", 4) == 0 ||
            strncmp(line, "Gid:", 4) == 0) {
            trim_whitespace(line);
            printf("%s\n", line);
        }
    }

    fclose(file);
}

void list_processes() {
    DIR *proc_dir = opendir("/proc");
    if (!proc_dir) {
        perror("Failed to open /proc directory");
        exit(EXIT_FAILURE);
    }

    struct dirent *entry;
    while ((entry = readdir(proc_dir)) != NULL) {
        // check if the name is a number (pid)
        if (isdigit(entry->d_name[0])) {
            print_process_info(entry->d_name);
            printf("-----------------------------\n");
        }
    }
    
    closedir(proc_dir);
}

int main() {
    printf("Simple Process Viewer\n");
    printf("=========================\n");

    list_processes();

    printf("Finished displaying processes.\n");
    return 0;
}