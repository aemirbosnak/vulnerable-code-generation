//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/statvfs.h>

void print_disk_usage(const char *path) {
    struct statvfs stat;

    // Retrieve file system statistics
    if (statvfs(path, &stat) != 0) {
        perror("Failed to get filesystem statistics");
        return; // Exit if an error occurred
    }

    // Calculate the total and available space
    unsigned long total_space = stat.f_blocks * stat.f_frsize;
    unsigned long free_space = stat.f_bfree * stat.f_frsize;
    unsigned long used_space = total_space - free_space;

    // Print the results
    printf("Disk Usage for: %s\n", path);
    printf("Total space: %lu bytes\n", total_space);
    printf("Used space: %lu bytes\n", used_space);
    printf("Free space: %lu bytes\n", free_space);
    
    // Calculate and print percentages
    printf("Used percentage: %.2f%%\n", (double)used_space / (double)total_space * 100);
    printf("Free percentage: %.2f%%\n", (double)free_space / (double)total_space * 100);
    printf("====================================\n");
}

void list_files(const char *path) {
    FILE *fp;
    char command[256];

    // Construct a command to list files and their sizes
    snprintf(command, sizeof(command), "du -h --max-depth=1 %s", path);
    
    // Open the command for reading
    if ((fp = popen(command, "r")) == NULL) {
        perror("Failed to run command");
        return; // Exit if an error occurred
    }

    // Read the output a line at a time - output it
    char output[256];
    printf("List of files and their sizes in: %s\n", path);
    while (fgets(output, sizeof(output), fp) != NULL) {
        printf("%s", output);
    }

    // Close the command stream
    if (pclose(fp) == -1) {
        perror("Failed to close command");
    }
}

void display_help() {
    printf("Disk Space Analyzer\n");
    printf("Usage: ./disk_space_analyzer <directory_path>\n");
    printf("This program analyzes disk space usage and lists files in the specified directory.\n");
    printf("If no directory path is provided, it defaults to the current directory.\n");
}

int main(int argc, char *argv[]) {
    // Set the directory path
    const char *dir_path = ".";
    if (argc > 1) {
        dir_path = argv[1];
    }

    // Display helpful information
    if (strcmp(dir_path, "--help") == 0) {
        display_help();
        return 0;
    }

    // Print disk usage
    print_disk_usage(dir_path);

    // List files in the specified directory
    list_files(dir_path);

    // Thank the user for using the program
    printf("Thank you for using the Disk Space Analyzer! All files and statistics are provided with gratitude.\n");

    return 0;
}