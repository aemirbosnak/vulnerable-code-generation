//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: ephemeral
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>

#define PROC_PATH "/proc/"
#define BUFFER_SIZE 256

void display_process_info(pid_t pid) {
    char path[BUFFER_SIZE];
    char line[BUFFER_SIZE];
    sprintf(path, "%s%d/stat", PROC_PATH, pid);

    FILE *stat_file = fopen(path, "r");
    if (stat_file == NULL) {
        perror("Could not open stat file");
        return;
    }

    fgets(line, sizeof(line), stat_file);
    fclose(stat_file);

    char *token = strtok(line, " ");
    int token_count = 0;
    char *process_name = NULL;

    // Traverse the tokens to extract process name and state
    while (token != NULL) {
        if (token_count == 1) {
            process_name = token;
        }
        if (token_count == 2) {
            printf("Process ID: %d\n", pid);
            printf("Process Name: %s\n", process_name);
            printf("Process State: %s\n", token);
        }
        token = strtok(NULL, " ");
        token_count++;
    }
}

void print_header() {
    printf("-----------------------------\n");
    printf(" Process Viewer\n");
    printf("-----------------------------\n");
    printf(" PID\tProcess Name\tState\n");
    printf("-----------------------------\n");
}

void list_processes() {
    DIR *proc_dir = opendir(PROC_PATH);
    struct dirent *entry;

    if (proc_dir == NULL) {
        perror("Could not open /proc directory");
        return;
    }

    while ((entry = readdir(proc_dir)) != NULL) {
        if (isdigit(entry->d_name[0])) {
            pid_t pid = atoi(entry->d_name);
            display_process_info(pid);
            printf("-----------------------------\n");
        }
    }
    
    closedir(proc_dir);
}

void display_usage(const char *program_name) {
    printf("Usage: %s\n", program_name);
    printf("Displays a list of current processes on the system.\n");
}

int main(int argc, char *argv[]) {
    // Check for usage
    if (argc > 1) {
        display_usage(argv[0]);
        return 1;
    }

    print_header();
    list_processes();

    return 0;
}