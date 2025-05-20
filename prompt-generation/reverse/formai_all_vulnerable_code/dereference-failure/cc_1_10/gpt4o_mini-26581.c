//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PATH_LENGTH 1024
#define HASH_TABLE_SIZE 1000
#define FILE_EXTENSIONS_COUNT 3

const char *blacklist_extensions[FILE_EXTENSIONS_COUNT] = {".exe", ".scr", ".pif"};

typedef struct {
    char filename[MAX_PATH_LENGTH];
    unsigned long hash;
} BlacklistedFile;

BlacklistedFile hash_table[HASH_TABLE_SIZE];
int hash_count = 0;

// Simple hash function for demonstration purposes
unsigned long hash(const char *str) {
    unsigned long hash = 5381;
    int c;

    while ((c = *str++)) {
        hash = ((hash << 5) + hash) + c; 
    }
    return hash;
}

int is_blacklisted(const char *filename) {
    const char *ext = strrchr(filename, '.');
    if (ext != NULL) {
        for (int i = 0; i < FILE_EXTENSIONS_COUNT; i++) {
            if (strcmp(ext, blacklist_extensions[i]) == 0) {
                return 1; // File is blacklisted
            }
        }
    }
    return 0; // File is not blacklisted
}

void scan_file(const char *filepath) {
    struct stat buf;
    if (stat(filepath, &buf) != 0) {
        perror("Stat error");
        return;
    }

    if (S_ISREG(buf.st_mode)) {
        unsigned long file_hash = hash(filepath);
        if (is_blacklisted(filepath)) {
            printf("WARNING: Blacklisted file found: %s (Hash: %lu)\n", filepath, file_hash);
            if (hash_count < HASH_TABLE_SIZE) {
                strcpy(hash_table[hash_count].filename, filepath);
                hash_table[hash_count].hash = file_hash;
                hash_count++;
            } else {
                printf("Hash table full. Unable to store more entries.\n");
            }
        }
    }
}

void traverse_directory(const char *dir_name) {
    DIR *dir = opendir(dir_name);
    struct dirent *entry;

    if (dir == NULL) {
        perror("Failed to open directory");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        char path[MAX_PATH_LENGTH];
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            snprintf(path, sizeof(path), "%s/%s", dir_name, entry->d_name);
            scan_file(path);

            if (entry->d_type == DT_DIR) {
                traverse_directory(path);
            }
        }
    }
    closedir(dir);
}

void print_blacklisted_files() {
    printf("\n=== Blacklisted Files Found ===\n");
    for (int i = 0; i < hash_count; i++) {
        printf("File: %s, Hash: %lu\n", hash_table[i].filename, hash_table[i].hash);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory_to_scan>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *directory_to_scan = argv[1];

    printf("Scanning directory: %s\n", directory_to_scan);
    
    traverse_directory(directory_to_scan);

    print_blacklisted_files();

    return EXIT_SUCCESS;
}