//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/statvfs.h>
#include <sys/types.h>
#include <dirent.h>

void checkDiskSpace(const char *path) {
    struct statvfs stats;
    if (statvfs(path, &stats) != 0) {
        perror("statvfs error");
        return;
    }
    
    unsigned long total = stats.f_frsize * stats.f_blocks;
    unsigned long free = stats.f_frsize * stats.f_bfree;
    unsigned long used = total - free;
    
    printf("\n--- Disk Space Info for %s ---\n", path);
    printf("Total: %lu bytes\n", total);
    printf("Used: %lu bytes\n", used);
    printf("Free: %lu bytes\n", free);
    printf("-------------------------------\n");
}

void listProcesses() {
    DIR *dir;
    struct dirent *ent;
    
    if ((dir = opendir("/proc")) != NULL) {
        printf("\n--- Running Processes ---\n");
        while ((ent = readdir(dir)) != NULL) {
            if (atoi(ent->d_name) > 0) { // Check for valid PID
                char path[256];
                snprintf(path, sizeof(path), "/proc/%s/stat", ent->d_name);
                FILE *file = fopen(path, "r");
                if (file) {
                    int pid;
                    char comm[256];
                    fscanf(file, "%d %s", &pid, comm);
                    printf("PID: %d, Command: %s\n", pid, comm);
                    fclose(file);
                }
            }
        }
        closedir(dir);
    } else {
        perror("Could not open /proc directory");
    }
}

void generateReport() {
    FILE *file = fopen("system_report.txt", "w");
    if (file) {
        fprintf(file, "=== System Report ===\n");
        fprintf(file, "Generated on: %s", __DATE__ " " __TIME__);
        fprintf(file, "\nList of running processes:\n");
        
        DIR *dir;
        if ((dir = opendir("/proc")) != NULL) {
            struct dirent *ent;
            while ((ent = readdir(dir)) != NULL) {
                if (atoi(ent->d_name) > 0) {
                    fprintf(file, "PID: %s\n", ent->d_name);
                }
            }
            closedir(dir);
        }
        
        fprintf(file, "=====================\n");
        fclose(file);
        printf("Report saved to 'system_report.txt'\n");
    } else {
        perror("Failed to create report file");
    }
}

int main() {
    printf("=== Welcome to the System Admin Utility! ===\n");
    
    // Check disk space of the root directory
    checkDiskSpace("/");
    
    // List current running processes
    listProcesses();
    
    // Generate a system report
    generateReport();
    
    printf("=== Utility tasks completed! ===\n");
    return 0;
}