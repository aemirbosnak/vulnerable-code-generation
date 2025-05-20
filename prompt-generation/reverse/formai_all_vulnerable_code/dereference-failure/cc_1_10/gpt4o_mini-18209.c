//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>

#define MAX_BUFFER 256
#define PROC_DIR "/proc"
#define STAT_FILE_SIZE 1024

void print_process_info(const char *pid) {
    char stat_file_path[MAX_BUFFER];
    snprintf(stat_file_path, sizeof(stat_file_path), "%s/%s/stat", PROC_DIR, pid);

    FILE *stat_file = fopen(stat_file_path, "r");
    if (stat_file == NULL) {
        perror("Error opening stat file");
        return;
    }
    
    char buffer[STAT_FILE_SIZE];
    if (fgets(buffer, sizeof(buffer), stat_file) == NULL) {
        perror("Error reading stat file");
        fclose(stat_file);
        return;
    }

    // Now we will parse the stat file output
    char *fields[52]; // There are more than 52 fields but we'll extract only the necessary ones
    char *token = strtok(buffer, " ");
    int i = 0;

    while (token != NULL && i < 52) {
        fields[i++] = token;
        token = strtok(NULL, " ");
    }

    if (i >= 52) {
        printf("Process ID: %s\n", fields[0]);
        printf("Process Name: %s\n", fields[1]);
        printf("Process State: %s\n", fields[3]);
        printf("Parent Process ID: %s\n", fields[4]);
        printf("Memory Usage: %s\n", fields[22]);
        printf("Virtual Memory Size: %s\n", fields[23]);
        printf("CPU Time: %s\n", fields[14]);
        printf("User Time: %s\n", fields[13]);
    } else {
        printf("Could not fetch enough fields for PID %s\n", pid);
    }

    fclose(stat_file);
}

void list_processes() {
    DIR *proc_dir = opendir(PROC_DIR);
    if (proc_dir == NULL) {
        perror("Cannot open /proc directory");
        return;
    }

    struct dirent *entry;
    while ((entry = readdir(proc_dir)) != NULL) {
        // Check if the entry is a number (i.e., a process ID)
        if (entry->d_type == DT_DIR) {
            int pid = atoi(entry->d_name);
            if (pid > 0) {
                print_process_info(entry->d_name);
                printf("\n---\n");
            }
        }
    }

    closedir(proc_dir);
}

int main() {
    printf("Welcome to the C Process Viewer!\n");
    printf("Fetching information about running processes...\n\n");
    
    list_processes();
    
    printf("Process viewing completed. Thank you!\n");
    return 0;
}