//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/statvfs.h>
#include <unistd.h>

#define MAX_PATH_LENGTH 256

void get_disk_space(const char *path) {
    struct statvfs disk_info;

    if (statvfs(path, &disk_info) != 0) {
        perror("Could not get disk information");
        return;
    }

    unsigned long total_space = disk_info.f_blocks * disk_info.f_frsize;
    unsigned long free_space = disk_info.f_bfree * disk_info.f_frsize;
    unsigned long used_space = total_space - free_space;

    printf("Disk Space for '%s':\n", path);
    printf("Total Space: %.2f GB\n", total_space / (1024.0 * 1024 * 1024));
    printf("Used Space: %.2f GB\n", used_space / (1024.0 * 1024 * 1024));
    printf("Free Space: %.2f GB\n", free_space / (1024.0 * 1024 * 1024));
}

// Function to display help information
void display_help() {
    printf("Disk Space Analyzer Help:\n");
    printf("Usage:\n");
    printf("  ./disk_space_analyzer [path]\n");
    printf("  If no path is provided, it defaults to the current working directory.\n");
    printf("Example:\n");
    printf("  ./disk_space_analyzer /home/user\n");
}

int main(int argc, char *argv[]) {
    char path[MAX_PATH_LENGTH];

    // Check if a command line argument is provided
    if (argc > 2) {
        printf("Too many arguments! Use --help for usage information.\n");
        return 1;
    }
    
    // Check if the help command is requested
    if (argc == 2 && strcmp(argv[1], "--help") == 0) {
        display_help();
        return 0;
    }

    // Determine the path to analyze
    if (argc == 1) {
        // Use the current directory if no argument is given
        if (getcwd(path, sizeof(path)) != NULL) {
            printf("Analyzing current directory: %s\n", path);
        } else {
            perror("getcwd() error");
            return 1;
        }
    } else {
        // User-provided path
        strncpy(path, argv[1], MAX_PATH_LENGTH - 1);
        path[MAX_PATH_LENGTH - 1] = '\0'; // Ensure null-termination
    }

    // Analyze the disk space
    get_disk_space(path);

    // Ask user if they want to analyze another path
    char choice;
    do {
        printf("Would you like to analyze another directory? (y/n): ");
        scanf(" %c", &choice);
        if (choice == 'y' || choice == 'Y') {
            printf("Enter path to analyze: ");
            scanf("%s", path);
            get_disk_space(path);
        }
    } while (choice == 'y' || choice == 'Y');

    printf("Thank you for using the Disk Space Analyzer! Have a great day!\n");
    return 0;
}