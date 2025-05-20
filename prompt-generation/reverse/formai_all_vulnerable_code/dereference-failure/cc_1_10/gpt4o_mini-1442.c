//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>

#define MAX_PATH 256
#define BUFFER_SIZE 256

void trim_whitespace(char* str) {
    char *end;

    while (isspace((unsigned char)*str)) str++;

    if (*str == 0) return;

    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) end--;

    *(end + 1) = 0;
}

void read_process_info(const char* pid) {
    char path[MAX_PATH];
    snprintf(path, sizeof(path), "/proc/%s/status", pid);
    
    FILE *file = fopen(path, "r");
    if (!file) {
        perror("Failed to open status file");
        return;
    }

    char line[BUFFER_SIZE];
    printf("Process ID: %s\n", pid);
    while (fgets(line, sizeof(line), file) != NULL) {
        trim_whitespace(line);
        if (strncmp(line, "Name:", 5) == 0 || 
            strncmp(line, "State:", 6) == 0 ||
            strncmp(line, "Pid:", 4) == 0 ||
            strncmp(line, "PPid:", 5) == 0 ||
            strncmp(line, "Uid:", 4) == 0) {
            printf("%s\n", line);
        }
    }
    
    fclose(file);
    printf("\n");
}

void list_processes() {
    DIR *proc_dir = opendir("/proc");
    if (!proc_dir) {
        perror("Failed to open /proc directory");
        return;
    }

    struct dirent *entry;
    while ((entry = readdir(proc_dir)) != NULL) {
        if (isdigit(entry->d_name[0])) {
            read_process_info(entry->d_name);
        }
    }

    closedir(proc_dir);
}

int main() {
    printf("Process Viewer\n");
    printf("=====================\n");
    list_processes();
    return 0;
}