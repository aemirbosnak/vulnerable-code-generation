//GPT-4o-mini DATASET v1.0 Category: Intrusion detection system ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <time.h>
#include <errno.h>

#define LOG_FILE "intrusion_log.txt"
#define MONITOR_DIR "/path/to/monitor"
#define MAX_PATH_LENGTH 256
#define MAX_LOG_ENTRY_LENGTH 512

void log_entry(const char *entry) {
    FILE *log_file = fopen(LOG_FILE, "a");
    if (log_file == NULL) {
        perror("Failed to open log file");
        return;
    }
    fprintf(log_file, "%s\n", entry);
    fclose(log_file);
}

void check_file(const char *file_path, const struct stat *file_stat) {
    static time_t last_mod_time = 0;
    
    if (last_mod_time != file_stat->st_mtime) {
        char log_msg[MAX_LOG_ENTRY_LENGTH];
        snprintf(log_msg, sizeof(log_msg), "File changed: %s at %s", file_path, ctime(&file_stat->st_mtime));
        log_entry(log_msg);
        last_mod_time = file_stat->st_mtime;
    }
}

void scan_directory(const char *dir_path) {
    DIR *dir;
    struct dirent *entry;
    char file_path[MAX_PATH_LENGTH];
    struct stat file_stat;

    dir = opendir(dir_path);
    if (dir == NULL) {
        perror("Could not open directory");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_name[0] == '.') {
            continue; // Skip hidden files and directories
        }

        snprintf(file_path, sizeof(file_path), "%s/%s", dir_path, entry->d_name);
        
        if (stat(file_path, &file_stat) == -1) {
            perror("Stat failed");
            continue;
        }

        if (S_ISREG(file_stat.st_mode)) {
            check_file(file_path, &file_stat);
        } else if (S_ISDIR(file_stat.st_mode)) {
            scan_directory(file_path); // Recursive checking of directories
        }
    }

    closedir(dir);
}

void monitor_directory() {
    while (1) {
        scan_directory(MONITOR_DIR);
        sleep(10); // Check every 10 seconds
    }
}

int main() {
    printf("Starting Intrusion Detection System...\n");
    
    log_entry("Intrusion Detection System started");
    
    monitor_directory();

    return 0;
}