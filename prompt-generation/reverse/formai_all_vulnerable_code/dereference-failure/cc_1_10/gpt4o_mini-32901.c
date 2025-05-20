//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_PATH_LEN 1024
#define HASH_LEN 64

char *calculate_hash(const char *file_path) {
    // Dummy hash calculation for demonstration
    // This should be replaced with an actual hash function
    static char hash[HASH_LEN];
    snprintf(hash, HASH_LEN, "%lx", (unsigned long)file_path[0]); // simplistic hash
    return hash;
}

int scan_file(const char *file_path) {
    FILE *file = fopen(file_path, "rb");
    if (!file) return 0;

    // Simple "scan" routine: Check for malicious content
    char buffer[256];
    while (fread(buffer, 1, sizeof(buffer), file) > 0) {
        // Check for dummy malicious signature
        if (strstr(buffer, "MALICIOUS") != NULL) {
            fclose(file);
            return 1; // Detected
        }
    }
    fclose(file);
    return 0; // Clean
}

void scan_directory(const char *dir_path) {
    struct dirent *entry;
    struct stat file_stat;
    char path[MAX_PATH_LEN];

    DIR *dp = opendir(dir_path);
    if (dp == NULL) {
        perror("opendir");
        return;
    }

    while ((entry = readdir(dp)) != NULL) {
        if (entry->d_name[0] == '.') continue; // Skip hidden files
        snprintf(path, sizeof(path), "%s/%s", dir_path, entry->d_name);
        
        if (stat(path, &file_stat) == -1) {
            perror("stat");
            continue;
        }

        if (S_ISDIR(file_stat.st_mode)) {
            scan_directory(path); // Recursive scan
        } else if (S_ISREG(file_stat.st_mode)) {
            printf("Scanning file: %s\n", path);
            if (scan_file(path)) {
                printf("ALERT: Malware detected in %s\n", path);
            }
        }
    }
    closedir(dp);
}

void display_usage(const char *prog_name) {
    printf("Usage: %s <directory>\n", prog_name);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        display_usage(argv[0]);
        exit(EXIT_FAILURE);
    }

    char *target_directory = argv[1];
    struct stat dir_stat;

    if (stat(target_directory, &dir_stat) == -1 || !S_ISDIR(dir_stat.st_mode)) {
        fprintf(stderr, "Invalid directory: %s\n", target_directory);
        exit(EXIT_FAILURE);
    }

    printf("Initiating scan on directory: %s\n", target_directory);
    scan_directory(target_directory);
    printf("Scan completed.\n");

    return 0;
}