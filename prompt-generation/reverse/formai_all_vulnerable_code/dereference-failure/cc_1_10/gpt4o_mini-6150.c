//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>

#define PROC_DIR "/proc/"
#define STAT_FILE "stat"
#define BUF_SIZE 128

void print_process_info(const char *pid) {
    char stat_path[BUF_SIZE];
    snprintf(stat_path, sizeof(stat_path), "%s%s/%s", PROC_DIR, pid, STAT_FILE);
    
    FILE *file = fopen(stat_path, "r");
    if (file) {
        char buffer[1024];
        fgets(buffer, sizeof(buffer), file);
        
        char *token = strtok(buffer, " ");
        int index = 0;
        char *proc_info[52];  // The stat file usually has 52 columns
        while (token != NULL && index < 52) {
            proc_info[index++] = token;
            token = strtok(NULL, " ");
        }
        
        printf("PID: %s\n", proc_info[0]);
        printf("Comm: %s\n", proc_info[1]);
        printf("State: %s\n", proc_info[3]);
        printf("PPID: %s\n", proc_info[4]);
        printf("RSS: %s\n", proc_info[23]);
        printf("CPU: %s\n", proc_info[13]);
        printf("--------------------------------------\n");
        
        fclose(file);
    } else {
        perror("Could not read the stat file");
    }
}

void list_processes() {
    DIR *dir = opendir(PROC_DIR);
    if (!dir) {
        perror("Could not open /proc directory");
        return;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_DIR) {
            // Check if the directory name is numeric (valid PID).
            if (atoi(entry->d_name) > 0) {
                print_process_info(entry->d_name);
            }
        }
    }
    
    closedir(dir);
}

int main() {
    printf("Welcome to the Immersive Linux Process Viewer!\n");
    printf("Fetching process information...\n");
    printf("--------------------------------------\n");

    list_processes();

    printf("Process listing complete! Exiting...\n");
    return 0;
}