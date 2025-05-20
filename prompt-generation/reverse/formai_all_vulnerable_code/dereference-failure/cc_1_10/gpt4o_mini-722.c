//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/sysinfo.h>
#include <sys/statvfs.h>
#include <dirent.h>

// Function to display system information
void display_system_info() {
    struct sysinfo si;
    if (sysinfo(&si) == 0) {
        printf("System Uptime: %ld days, %ld hours, %ld minutes\n", 
               si.uptime / 86400, (si.uptime % 86400) / 3600, 
               (si.uptime % 3600) / 60);
        printf("Total RAM: %ld MB\n", si.totalram / 1024 / 1024);
        printf("Free RAM: %ld MB\n", si.freeram / 1024 / 1024);
        printf("Total Swap: %ld MB\n", si.totalswap / 1024 / 1024);
        printf("Free Swap: %ld MB\n", si.freeswap / 1024 / 1024);
    } else {
        perror("sysinfo");
    }
}

// Function to check disk usage
void check_disk_usage() {
    struct statvfs stat;
    if (statvfs("/", &stat) == 0) {
        unsigned long total = stat.f_blocks * stat.f_frsize / 1024 / 1024; // Total in MB
        unsigned long free = stat.f_bfree * stat.f_frsize / 1024 / 1024; // Free in MB
        unsigned long used = total - free;
        printf("Disk Usage: Total: %lu MB, Used: %lu MB, Free: %lu MB\n", total, used, free);
    } else {
        perror("statvfs");
    }
}

// Function to list running processes
void list_running_processes() {
    DIR *dir;
    struct dirent *entry;
    char path[256];
    FILE *fp;
    char buffer[256];

    dir = opendir("/proc");
    if (dir == NULL) {
        perror("opendir");
        return;
    }

    printf("Running Processes:\n");
    while ((entry = readdir(dir)) != NULL) {
        if (isdigit(*entry->d_name)) {
            snprintf(path, sizeof(path), "/proc/%s/status", entry->d_name);
            fp = fopen(path, "r");
            if (fp) {
                while (fgets(buffer, sizeof(buffer), fp)) {
                    if (strncmp(buffer, "Name:", 5) == 0) {
                        printf("PID %s: %s", entry->d_name, buffer + 6);
                        break;
                    }
                }
                fclose(fp);
            }
        }
    }
    closedir(dir);
}

// Main menu
void display_menu() {
    int choice;
    while (1) {
        printf("\n--- System Administration Utility ---\n");
        printf("1. Display System Information\n");
        printf("2. Check Disk Usage\n");
        printf("3. List Running Processes\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                display_system_info();
                break;
            case 2:
                check_disk_usage();
                break;
            case 3:
                list_running_processes();
                break;
            case 4:
                printf("Exiting...\n");
                return;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

// Entry point of the program
int main() {
    display_menu();
    return 0;
}