//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>

#define MAX_LINE_LENGTH 256
#define MAX_PROCESSES 100

void print_process_info(const char *pid);
void colorize(const char *text, const char *color_code);

int main() {
    DIR *dir;
    struct dirent *entry;

    printf("🎉 Welcome to the Amazing Linux Process Viewer! 🎉\n");
    printf("=============================================\n");

    // Open the "/proc" directory to read process IDs
    if ((dir = opendir("/proc")) == NULL) {
        perror("Failed to open /proc directory");
        return EXIT_FAILURE;
    }

    // Loop through all entries in the /proc directory
    while ((entry = readdir(dir)) != NULL) {
        // Check if the entry is a directory and an actual PID
        if (entry->d_type == DT_DIR && atoi(entry->d_name) > 0) {
            print_process_info(entry->d_name);
        }
    }

    closedir(dir);
    printf("=============================================\n");
    printf("🎉 Thank you for using the Amazing Linux Process Viewer! 🎉\n");
    return EXIT_SUCCESS;
}

void print_process_info(const char *pid) {
    char path[MAX_LINE_LENGTH], line[MAX_LINE_LENGTH];
    FILE *status_file;
    char name[50];

    // Construct the path to the status file
    snprintf(path, sizeof(path), "/proc/%s/status", pid);

    // Open the status file for reading
    status_file = fopen(path, "r");
    if (status_file == NULL) {
        return;
    }

    // Read the name and status from the status file
    while (fgets(line, sizeof(line), status_file) != NULL) {
        if (strncmp(line, "Name:", 5) == 0) {
            sscanf(line + 6, "%s", name);
            break;
        }
    }

    // Output the process details using color
    colorize("PID: ", "\033[1;34m"); // Blue for PID
    printf("%s ", pid);
    colorize("Name: ", "\033[1;32m"); // Green for name
    printf("%s\n", name); // Print the name

    fclose(status_file);
}

void colorize(const char *text, const char *color_code) {
    printf("%s%s\033[0m", color_code, text); // Reset to default after text
}