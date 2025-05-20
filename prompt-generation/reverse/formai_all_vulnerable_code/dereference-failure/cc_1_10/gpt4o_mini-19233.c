//GPT-4o-mini DATASET v1.0 Category: Intrusion detection system ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <time.h>

// Define maximum length of filepath
#define MAX_PATH 1024
#define LOG_FILE "intrusion_detection.log"

// Structure to hold system file information
typedef struct {
    char filepath[MAX_PATH];
    time_t last_modified_time;
} FileInfo;

// Function prototypes
void log_event(const char* message);
void monitor_directory(const char* dir_path);
void check_file_changes(const char* dir_path, FileInfo* file_info, int file_count);
void initialize_file_info(FileInfo* file_info, const char* dir_path, int* file_count);
void report_modification(const char* filepath, time_t old_time, time_t new_time);
void print_current_time();

// Entry point of the program
int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory_to_monitor>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Monitor specified directory
    monitor_directory(argv[1]);

    return EXIT_SUCCESS;
}

// Function to log messages to a file
void log_event(const char* message) {
    FILE* log_file = fopen(LOG_FILE, "a");
    if (log_file != NULL) {
        fprintf(log_file, "[%s] %s\n", (char*)ctime(&(time_t){time(NULL)}), message);
        fclose(log_file);
    }
}

// Function to monitor the specified directory
void monitor_directory(const char* dir_path) {
    FileInfo file_info[100];
    int file_count = 0;
    
    initialize_file_info(file_info, dir_path, &file_count);
    
    while (1) {
        sleep(5); // Check every 5 seconds
        check_file_changes(dir_path, file_info, file_count);
    }
}

// Initialize file information for all files in the directory
void initialize_file_info(FileInfo* file_info, const char* dir_path, int* file_count) {
    DIR* dir = opendir(dir_path);
    struct dirent* entry;

    if (dir == NULL) {
        perror("Failed to open directory");
        exit(EXIT_FAILURE);
    }

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG) { // Only regular files
            snprintf(file_info[*file_count].filepath, MAX_PATH, "%s/%s", dir_path, entry->d_name);
            struct stat st;
            if (stat(file_info[*file_count].filepath, &st) == 0) {
                file_info[*file_count].last_modified_time = st.st_mtime;
                (*file_count)++;
            }
        }
    }
    closedir(dir);
}

// Function to check for file changes
void check_file_changes(const char* dir_path, FileInfo* file_info, int file_count) {
    struct stat st;
    for (int i = 0; i < file_count; i++) {
        if (stat(file_info[i].filepath, &st) == 0) {
            if (st.st_mtime != file_info[i].last_modified_time) {
                report_modification(file_info[i].filepath, file_info[i].last_modified_time, st.st_mtime);
                file_info[i].last_modified_time = st.st_mtime; // Update the last modified time
            }
        } else {
            log_event("File deleted or inaccessible");
        }
    }
}

// Function to report a modification event
void report_modification(const char* filepath, time_t old_time, time_t new_time) {
    log_event("Modification detected in file:");
    printf("Modification detected in file: %s\n", filepath);
    print_current_time();
}

// Print the current time with formatted output
void print_current_time() {
    time_t now = time(NULL);
    char* time_str = ctime(&now);
    printf("Current Time: %s", time_str);
}