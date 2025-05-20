//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <time.h>

#define MAX_PATH_LENGTH 1024
#define LOG_FILE "sysadmin.log"

// Function to log messages to a log file
void log_message(const char *message) {
    FILE *log_fp = fopen(LOG_FILE, "a");
    if (log_fp != NULL) {
        time_t now = time(NULL);
        fprintf(log_fp, "[%s] %s\n", ctime(&now), message);
        fclose(log_fp);
    }
}

// Function to check if a directory exists
int dir_exists(const char *path) {
    struct stat statbuf;
    return (stat(path, &statbuf) == 0 && S_ISDIR(statbuf.st_mode));
}

// Function to create a directory with a given path
void create_directory(const char *path) {
    if (mkdir(path, 0755) == 0) {
        char message[100];
        snprintf(message, sizeof(message), "Directory created: %s", path);
        log_message(message);
        printf("Created directory: %s\n", path);
    } else {
        log_message("Failed to create directory.");
        perror("mkdir");
    }
}

// Function to clean and organize files in the specified directory
void clean_directory(const char *dir_path) {
    struct dirent *entry;
    DIR *dp = opendir(dir_path);
    
    if (dp == NULL) {
        perror("opendir");
        return;
    }

    while ((entry = readdir(dp)) != NULL) {
        if (entry->d_type == DT_REG) {
            char old_path[MAX_PATH_LENGTH];
            char new_path[MAX_PATH_LENGTH];

            snprintf(old_path, sizeof(old_path), "%s/%s", dir_path, entry->d_name);
            snprintf(new_path, sizeof(new_path), "%s/cleaned/%s", dir_path, entry->d_name);
            
            // Create a "cleaned" directory if it doesn't exist
            if (!dir_exists("cleaned")) {
                create_directory("cleaned");
            }

            // Move the file to cleaned directory
            if (rename(old_path, new_path) == 0) {
                char message[100];
                snprintf(message, sizeof(message), "Moved: %s to cleaned/%s", old_path, entry->d_name);
                log_message(message);
                printf("Moved: %s to cleaned/%s\n", old_path, entry->d_name);
            } else {
                log_message("Failed to move file.");
                perror("rename");
            }
        }
    }
    closedir(dp);
}

// Function to display system information
void display_system_info() {
    log_message("Displaying system information.");
    printf("System Information:\n");
    printf("====================\n");
    printf("Operating System: %s\n", getenv("OS"));
    printf("Architecture: %s\n", (sizeof(void*) == 8) ? "64-bit" : "32-bit");
    printf("User: %s\n", getenv("USER"));
    printf("Home Directory: %s\n", getenv("HOME"));
}

// Main function - entry point of the program
int main() {
    printf("Welcome to the Imaginative System Administration Tool!\n");
    log_message("System Admin Tool started.");

    // Display system information
    display_system_info();

    // Clean a specified directory
    char directory[MAX_PATH_LENGTH];
    printf("Enter a directory path to clean (e.g. ./mydir): ");
    fgets(directory, sizeof(directory), stdin);
    directory[strcspn(directory, "\n")] = 0; // Remove newline character

    // Clean the provided directory
    clean_directory(directory);

    printf("System maintenance completed. Check the log file for details: %s\n", LOG_FILE);
    return 0;
}