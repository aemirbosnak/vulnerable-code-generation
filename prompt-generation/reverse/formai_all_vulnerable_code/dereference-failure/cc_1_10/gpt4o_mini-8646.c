//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>

#define MAX_LINE_LENGTH 256
#define PROC_DIRECTORY "/proc"

void happy_print(const char *message) {
    printf("\033[1;32m%s\033[0m\n", message); // Print in green
}

void display_process_info(const char *pid) {
    char path[MAX_LINE_LENGTH];
    FILE *status_file;
    char line[MAX_LINE_LENGTH];
    char process_name[MAX_LINE_LENGTH];

    // Path to the status file of the process
    snprintf(path, sizeof(path), "%s/%s/status", PROC_DIRECTORY, pid);
    status_file = fopen(path, "r");

    if (status_file) {
        while (fgets(line, sizeof(line), status_file)) {
            if (sscanf(line, "Name:\t%s", process_name) == 1) {
                happy_print(process_name);
                break;
            }
        }
        fclose(status_file);
    } else {
        happy_print("Could not open status file. Maybe this process has ended?");
    }
}

void list_processes() {
    DIR *proc_dir;
    struct dirent *entry;

    happy_print("🌟 Listing all running processes at this moment! 🎉");

    proc_dir = opendir(PROC_DIRECTORY);
    if (!proc_dir) {
        perror("Could not open /proc directory");
        return;
    }

    while ((entry = readdir(proc_dir)) != NULL) {
        // Check if the entry is a directory and contains a number (PID)
        if (entry->d_type == DT_DIR && isdigit(entry->d_name[0])) {
            happy_print("📅 Found a process with PID: ");
            printf("\033[1;34m%s\033[0m\n", entry->d_name); // PID in blue
            display_process_info(entry->d_name);
        }
    }

    closedir(proc_dir);
    happy_print("✨ All processes have been listed! 👏");
}

int main() {
    happy_print("🌈 Welcome to the Happy Process Viewer! 🌈");
    list_processes();
    happy_print("💖 Thank you for using the Happy Process Viewer! 💖");
    return 0;
}