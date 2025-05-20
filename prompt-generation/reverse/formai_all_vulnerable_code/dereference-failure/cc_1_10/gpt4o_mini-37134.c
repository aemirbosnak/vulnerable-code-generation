//GPT-4o-mini DATASET v1.0 Category: Intrusion detection system ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

#define MAX_FILES 100
#define DIR_PATH "./monitor_dir"

typedef struct {
    char name[256];
    time_t last_mod;
} FileInfo;

FileInfo files[MAX_FILES];
int file_count = 0;

void check_existing_files() {
    DIR *dir;
    struct dirent *entry;
    struct stat file_stat;

    if ((dir = opendir(DIR_PATH)) == NULL) {
        perror("opendir");
        exit(EXIT_FAILURE);
    }

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_name[0] != '.') {
            char path[512];
            snprintf(path, sizeof(path), "%s/%s", DIR_PATH, entry->d_name);
            
            if (stat(path, &file_stat) == 0) {
                strcpy(files[file_count].name, entry->d_name);
                files[file_count].last_mod = file_stat.st_mtime;
                file_count++;
            }
        }
    }
    closedir(dir);
}

void detect_changes() {
    DIR *dir;
    struct dirent *entry;
    struct stat file_stat;

    if ((dir = opendir(DIR_PATH)) == NULL) {
        perror("opendir");
        exit(EXIT_FAILURE);
    }

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_name[0] != '.') {
            char path[512];
            snprintf(path, sizeof(path), "%s/%s", DIR_PATH, entry->d_name);
            
            if (stat(path, &file_stat) == 0) {
                int found = 0;
                for (int i = 0; i < file_count; i++) {
                    if (strcmp(files[i].name, entry->d_name) == 0) {
                        found = 1;
                        if (files[i].last_mod != file_stat.st_mtime) {
                            printf("File modified: %s\n", entry->d_name);
                            files[i].last_mod = file_stat.st_mtime; // update last modified time
                        }
                        break;
                    }
                }
                if (!found) {
                    printf("New file created: %s\n", entry->d_name);
                    strcpy(files[file_count].name, entry->d_name);
                    files[file_count].last_mod = file_stat.st_mtime;
                    file_count++;
                }
            }
        }
    }
    closedir(dir);
}

int main() {
    printf("Welcome to the Simple Intrusion Detection System (IDS)!\n");
    
    // Check existing files at the start
    check_existing_files();
    printf("Monitoring directory: %s\n", DIR_PATH);
    
    while (1) {
        // Sleep for a while to avoid excessive CPU usage
        sleep(5);
        // Detect changes 
        detect_changes();
    }

    return 0;
}