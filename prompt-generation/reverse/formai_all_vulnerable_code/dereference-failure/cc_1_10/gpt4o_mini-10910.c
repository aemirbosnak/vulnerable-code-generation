//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>

#define BUFFER_SIZE 256

void display_process_info(const char *pid) {
    char path[BUFFER_SIZE];
    snprintf(path, sizeof(path), "/proc/%s/stat", pid);
    
    FILE *fp = fopen(path, "r");
    if (fp == NULL) {
        return; // Process may have finished, ignoring
    }

    char comm[BUFFER_SIZE];
    char state;
    if (fscanf(fp, "%*d %s %*c %c", comm, &state) == 2) {
        printf("PID: %s | Command: %s | State: %c\n", pid, comm, state);
    }
    fclose(fp);
}

void list_processes() {
    struct dirent *entry;
    DIR *dp = opendir("/proc");

    if (dp == NULL) {
        perror("opendir failed");
        exit(EXIT_FAILURE);
    }

    printf("======= Process Viewer =======\n");
    printf("| PID     | Command         | State \n");
    printf("|---------|-----------------|-------\n");

    while ((entry = readdir(dp)) != NULL) {
        if (isdigit(entry->d_name[0])) {
            display_process_info(entry->d_name);
        }
    }

    closedir(dp);
}

void print_welcome_message() {
    printf("Welcome to the Process Viewer!\n");
    printf("Here you can monitor all running processes on your Linux system.\n");
    printf("Use Ctrl+C to terminate the viewer.\n\n");
}

void print_exit_message() {
    printf("\nThank you for using the Process Viewer. Goodbye!\n");
}

int main() {
    print_welcome_message();
    
    while (1) {
        list_processes();
        printf("\nRefreshing in 2 seconds...\n");
        sleep(2); // Refresh every 2 seconds
        printf("\033[H\033[J"); // ANSI escape code to clear the screen
    }

    print_exit_message();
    return 0;
}