//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>

#define MAX_PROC 1024
#define PROC_PATH "/proc/"
#define STATUS_FILE "status"

void display_process_info(const char *pid) {
    char path[256];
    snprintf(path, sizeof(path), "%s%s/%s", PROC_PATH, pid, STATUS_FILE);
    
    FILE *file = fopen(path, "r");
    if (!file) {
        fprintf(stderr, "Could not open file for PID %s\n", pid);
        return;
    }

    char line[256];
    printf("Process ID: %s\n", pid);
    while (fgets(line, sizeof(line), file)) {
        if (strncmp(line, "Name:", 5) == 0 || 
            strncmp(line, "State:", 6) == 0 || 
            strncmp(line, "Uid:", 4) == 0) {
                printf("  %s", line);
        }
    }
    printf("\n");
    fclose(file);
}

void list_processes() {
    struct dirent *entry;
    DIR *dp = opendir(PROC_PATH);

    if (!dp) {
        fprintf(stderr, "Could not open /proc directory\n");
        exit(EXIT_FAILURE);
    }

    while ((entry = readdir(dp))) {
        if (isdigit(entry->d_name[0])) {
            display_process_info(entry->d_name);
        }
    }

    closedir(dp);
}

void print_header() {
    printf("---------------------------------------------------\n");
    printf("               Linux Process Viewer \n");
    printf("---------------------------------------------------\n");
    printf("PID\tName\t\tState\tUID\n");
    printf("---------------------------------------------------\n");
}

int main(void) {
    print_header();
    list_processes();

    return 0;
}