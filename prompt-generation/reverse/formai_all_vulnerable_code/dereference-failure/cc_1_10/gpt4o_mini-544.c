//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>

#define MAX_LINE 256

void print_process_info(const char* dir_name) {
    char path[MAX_LINE];
    char buffer[MAX_LINE];
    FILE *fp;

    // Construct the status file path
    snprintf(path, sizeof(path), "/proc/%s/status", dir_name);

    // Open the status file
    fp = fopen(path, "r");
    if (fp == NULL) {
        return;
    }

    char pid[MAX_LINE];
    char name[MAX_LINE];

    // Read the name and PID from the status file
    while (fgets(buffer, sizeof(buffer), fp)) {
        if (strncmp(buffer, "Pid:", 4) == 0) {
            sscanf(buffer, "Pid:\t%s", pid);
        } else if (strncmp(buffer, "Name:", 5) == 0) {
            sscanf(buffer, "Name:\t%s", name);
            break; // Found the name, exit loop
        }
    }
    fclose(fp);

    // Print the information with a cheerful touch!
    printf("🎉 PID: %-6s | Name: %s\n", pid, name);
}

void list_processes() {
    DIR *dir;
    struct dirent *entry;

    // Open the /proc directory
    dir = opendir("/proc");
    if (dir == NULL) {
        perror("Couldn't open /proc");
        return;
    }

    // Cheerfully count processes
    printf("🌟 Let's view the running processes! 🌟\n\n");
    printf("PID      Name\n");
    printf("=========================\n");

    // Read each entry in the /proc directory
    while ((entry = readdir(dir)) != NULL) {
        // Check if the entry is a directory and consists only of digits
        if (isdigit(entry->d_name[0])) {
            print_process_info(entry->d_name);
        }
    }
    
    closedir(dir);
    printf("\n🎈 All processes have been cheerfully displayed! 🎈\n");
}

int main() {
    list_processes();
    return 0;
}