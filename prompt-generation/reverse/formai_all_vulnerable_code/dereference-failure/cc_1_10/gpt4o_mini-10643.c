//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PATH 1024
#define MAX_SIGNATURES 100
#define SIGNATURE_LENGTH 32

// Virus signature definitions
const char *virus_signatures[MAX_SIGNATURES] = {
    "malicious_code_1", 
    "malicious_code_2", 
    "trojan_code_1",
    "virus_code_1",
    "worm_code_1",
    "adware_code_1"
};

int signature_count = 6;

// Function prototypes
void scan_file(const char *file_path);
void scan_directory(const char *dir_path);
int contains_signature(const char *buffer, size_t size);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <directory_path>\n", argv[0]);
        return 1;
    }

    printf("Scanning directory: %s\n", argv[1]);
    scan_directory(argv[1]);
    printf("Scan completed.\n");
    
    return 0;
}

void scan_directory(const char *dir_path) {
    DIR *dir;
    struct dirent *entry;

    if (!(dir = opendir(dir_path))) {
        perror("Unable to read directory");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_DIR) {
            // Skip the special entries '.' and '..'
            if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
                char sub_dir_path[MAX_PATH];
                snprintf(sub_dir_path, sizeof(sub_dir_path), "%s/%s", dir_path, entry->d_name);
                scan_directory(sub_dir_path); // Recursive call for subdirectories
            }
        } else if (entry->d_type == DT_REG) {
            char file_path[MAX_PATH];
            snprintf(file_path, sizeof(file_path), "%s/%s", dir_path, entry->d_name);
            scan_file(file_path); // Scan the regular file
        }
    }

    closedir(dir);
}

void scan_file(const char *file_path) {
    FILE *file = fopen(file_path, "rb");
    if (!file) {
        perror("Error opening file");
        return;
    }

    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *buffer = (char *)malloc(file_size);
    fread(buffer, 1, file_size, file);
    fclose(file);

    if (contains_signature(buffer, file_size)) {
        printf("ALERT: Virus detected in file: %s\n", file_path);
    }

    free(buffer);
}

int contains_signature(const char *buffer, size_t size) {
    for (int i = 0; i < signature_count; i++) {
        const char *signature = virus_signatures[i];
        size_t sig_len = strlen(signature);

        for (size_t j = 0; j <= size - sig_len; j++) {
            if (memcmp(&buffer[j], signature, sig_len) == 0) {
                return 1; // Signature found
            }
        }
    }
    return 0; // No signatures found
}