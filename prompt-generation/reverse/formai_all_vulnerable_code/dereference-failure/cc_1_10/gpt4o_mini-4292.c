//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 256
#define PROC_DIR "/proc"

void trim_whitespace(char *str) {
    char *end;

    // Trim leading space
    while(isspace((unsigned char)*str)) str++;

    // Trim trailing space
    end = str + strlen(str) - 1;
    while(end > str && isspace((unsigned char)*end)) end--;

    // Null terminate string after last non-space
    *(end + 1) = '\0';
}

void print_process_info(int pid) {
    char path[MAX_LEN], line[MAX_LEN], status[MAX_LEN];
    FILE *status_file;

    snprintf(path, sizeof(path), PROC_DIR "/%d/status", pid);
    status_file = fopen(path, "r");
    if (!status_file) return;

    printf("PID: %d\n", pid);
    
    // Read and parse status file
    while (fgets(line, sizeof(line), status_file)) {
        if (strstr(line, "Name:") || strstr(line, "State:")) {
            trim_whitespace(line);
            printf("%s\n", line);
        }
    }
    printf("\n");

    fclose(status_file);
}

void list_processes() {
    struct dirent *entry;
    DIR *dp;

    dp = opendir(PROC_DIR);
    if (dp == NULL) {
        perror("opendir");
        return;
    }

    printf("Processes:\n");
    while ((entry = readdir(dp))) {
        if (entry->d_type == DT_DIR) {
            int pid = atoi(entry->d_name);
            if (pid > 0) {
                print_process_info(pid);
            }
        }
    }

    closedir(dp);
}

void display_help() {
    printf("Usage: procview [options]\n");
    printf("Options:\n");
    printf("  -h or --help      Display this help message\n");
    printf("  -l or --list      List all current processes\n");
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        display_help();
        return 1;
    }

    if (strcmp(argv[1], "-l") == 0 || strcmp(argv[1], "--list") == 0) {
        list_processes();
    } else if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0) {
        display_help();
    } else {
        printf("Invalid option: %s\n", argv[1]);
        display_help();
        return 1;
    }

    return 0;
}