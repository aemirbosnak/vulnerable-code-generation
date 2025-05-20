//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/statvfs.h>

#define MAX_PATH_LENGTH 256
#define MAX_DRIVES 10
#define BUFFER_SIZE 512

void print_disk_space(const char *path) {
    struct statvfs stat;

    if (statvfs(path, &stat) != 0) { 
        printf("Could not retrieve information for path: %s\n", path);
        return;
    }

    unsigned long total = stat.f_blocks * stat.f_frsize;
    unsigned long free = stat.f_bfree * stat.f_frsize;
    unsigned long used = total - free;

    printf("Disk usage for: %s\n", path);
    printf("Total: %lu bytes\n", total);
    printf("Used: %lu bytes\n", used);
    printf("Free: %lu bytes\n", free);
    printf("---------\n");
}

void display_drive_information() {
    printf("Available drives in the system:\n");

    FILE *fp;
    char path[BUFFER_SIZE];

    fp = popen("df -h | awk '{if(NR>1)print $6}'", "r");
    if (fp == NULL) {
        printf("Failed to run command to get drives\n");
        return;
    }

    while (fgets(path, sizeof(path), fp) != NULL) {
        path[strcspn(path, "\n")] = 0; // Remove newline
        print_disk_space(path);
    }

    pclose(fp);
}

void show_help() {
    printf("Usage: disk_space_analyzer [options]\n");
    printf("Options:\n");
    printf("  -h, --help        Show this help message and exit\n");
    printf("  -d, --drive       Specify a specific drive path (e.g., /, /home)\n");
}

int main(int argc, char *argv[]) {
    char specific_drive[MAX_PATH_LENGTH] = "";

    if (argc > 1) {
        if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0) {
            show_help();
            return 0;
        }
        else if (strcmp(argv[1], "-d") == 0 && argc > 2) {
            strncpy(specific_drive, argv[2], MAX_PATH_LENGTH - 1);
            specific_drive[MAX_PATH_LENGTH - 1] = '\0'; // null terminate
        } else {
            printf("Invalid option. Use -h or --help for usage.\n");
            return 1;
        }
    }

    if (strlen(specific_drive) > 0) {
        print_disk_space(specific_drive);
    } else {
        display_drive_information();
    }

    return 0;
}