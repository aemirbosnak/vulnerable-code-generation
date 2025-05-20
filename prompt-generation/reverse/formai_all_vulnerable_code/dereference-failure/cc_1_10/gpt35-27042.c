//FormAI DATASET v1.0 Category: System process viewer ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <ctype.h>

#define MAX_PROCESS_NAME 256
#define MAX_PATH_LENGTH 1024

int main() {
    DIR* proc_dir = opendir("/proc");
    if (proc_dir == NULL) {
        perror("Failed to open /proc directory");
        exit(1);
    }

    printf("==============================================\n");
    printf(" Welcome to the Post-Apocalyptic System Viewer\n");
    printf("==============================================\n\n");

    struct dirent* proc_entry;
    while ((proc_entry = readdir(proc_dir)) != NULL) {
        if (isdigit(proc_entry->d_name[0])) {

            // Fetch process name
            char process_name[MAX_PROCESS_NAME] = {'\0'};
            char process_status_path[MAX_PATH_LENGTH] = {'\0'};
            char status_line[MAX_PATH_LENGTH] = {'\0'};

            // Append process ID and "/status" to proc path
            snprintf(process_status_path, MAX_PATH_LENGTH, "/proc/%s/status", proc_entry->d_name);

            // Open the status file
            FILE* status_file = fopen(process_status_path, "r");
            if (status_file == NULL) {
                continue;
            }

            // Read each line in the file and parse output
            while (fgets(status_line, MAX_PATH_LENGTH, status_file) != NULL) {
                if (strncmp(status_line, "Name:", 5) == 0) {
                    char* name_start = status_line + 6;
                    strncpy(process_name, name_start, MAX_PROCESS_NAME);
                    process_name[strcspn(process_name, "\r\n")] = '\0'; // Remove trailing new line
                }
            }
            fclose(status_file);

            // Fetch process memory usage
            char process_mem_path[MAX_PATH_LENGTH] = {'\0'};
            char mem_line[MAX_PATH_LENGTH] = {'\0'};
            long vmrss = 0;

            // Append process ID and "/status" to proc path
            snprintf(process_mem_path, MAX_PATH_LENGTH, "/proc/%s/status", proc_entry->d_name);

            // Open the status file
            FILE* mem_file = fopen(process_mem_path, "r");
            if (mem_file == NULL) {
                continue;
            }

            // Read each line in the file and parse output
            while (fgets(mem_line, MAX_PATH_LENGTH, mem_file) != NULL) {
                if (strncmp(mem_line, "VmRSS:", 6) == 0) {
                    char* rss_start = mem_line + 7;
                    char* rss_end;
                    vmrss = strtol(rss_start, &rss_end, 10) * 1024; // Convert KB to bytes
                }
            }
            fclose(mem_file);

            // Print process info
            printf("Process ID: %s\n", proc_entry->d_name);
            printf("Process Name: %s\n", process_name);
            printf("Memory Usage: %ld bytes\n", vmrss);
            printf("----------------------------------------------\n");
        }
    }

    closedir(proc_dir);
    return 0;
}