//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PATH 1024
#define HASH_SIZE 1024

typedef struct {
    char *filename;
    unsigned long hash;
} VirusSignature;

VirusSignature signatures[] = {
    {"badware.exe", 0x8B9D687B},
    {"malware.scr", 0x5A63E3BD},
    {"toxicfile.dll", 0x7C9F6D4E},
    {"ransomware.txt", 0x4F2A5F1C}
};

unsigned long hash_file(const char *filename) {
    unsigned long hash = 5381;
    int c;
    FILE *file = fopen(filename, "rb");
    if (!file) {
        return 0; // Error opening file
    }
    
    while ((c = fgetc(file)) != EOF) {
        hash = ((hash << 5) + hash) + c; // hash * 33 + c
    }
    fclose(file);
    return hash;
}

int is_in_signature(const char *filename, unsigned long file_hash) {
    for (size_t i = 0; i < sizeof(signatures) / sizeof(signatures[0]); i++) {
        if (strcmp(filename, signatures[i].filename) == 0) {
            if (file_hash == signatures[i].hash) {
                return 1; // Found a match
            }
        }
    }
    return 0; // No match found
}

void scan_directory(const char *directory) {
    struct dirent *entry;
    struct stat file_stat;
    char full_path[MAX_PATH];
    DIR *dp = opendir(directory);
    
    if (dp == NULL) {
        perror("opendir");
        return;
    }
    
    while ((entry = readdir(dp)) != NULL) {
        // Ignore the "." and ".." entries
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            snprintf(full_path, sizeof(full_path), "%s/%s", directory, entry->d_name);
            if (stat(full_path, &file_stat) == 0) {
                if (S_ISDIR(file_stat.st_mode)) {
                    // Recursively scan directories
                    scan_directory(full_path);
                } else {
                    // Check the file for viruses
                    unsigned long file_hash = hash_file(full_path);
                    if (file_hash != 0 && is_in_signature(entry->d_name, file_hash)) {
                        printf("Virus detected: %s\n", full_path);
                    }
                }
            } else {
                perror("stat");
            }
        }
    }
    closedir(dp);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <directory_to_scan>\n", argv[0]);
        return 1;
    }

    printf("Scanning directory: %s\n", argv[1]);
    scan_directory(argv[1]);
    printf("Scanning completed.\n");

    return 0;
}