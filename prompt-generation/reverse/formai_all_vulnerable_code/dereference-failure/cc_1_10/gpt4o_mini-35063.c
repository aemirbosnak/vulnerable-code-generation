//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

// Define some "virus signatures"
#define SIG1 "VIRUS_SIGNATURE_1"
#define SIG2 "VIRUS_SIGNATURE_2"
#define SIG3 "VIRUS_SIGNATURE_3"

void scan_file(const char *filepath);
int check_signature(const char *buffer, size_t size);
void scan_directory(const char *dirpath);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory_to_scan>\n", argv[0]);
        return EXIT_FAILURE;
    }

    scan_directory(argv[1]);
    return EXIT_SUCCESS;
}

void scan_directory(const char *dirpath) {
    struct dirent *entry;
    DIR *dp = opendir(dirpath);
    
    if (dp == NULL) {
        perror("opendir");
        exit(EXIT_FAILURE);
    }

    while ((entry = readdir(dp)) != NULL) {
        if (entry->d_type == DT_REG) {  // Regular file
            char filepath[1024];
            snprintf(filepath, sizeof(filepath), "%s/%s", dirpath, entry->d_name);
            scan_file(filepath);
        } else if (entry->d_type == DT_DIR) {  // Directory
            if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
                char subdirpath[1024];
                snprintf(subdirpath, sizeof(subdirpath), "%s/%s", dirpath, entry->d_name);
                scan_directory(subdirpath);
            }
        }
    }

    closedir(dp);
}

void scan_file(const char *filepath) {
    FILE *file = fopen(filepath, "rb");
    char buffer[1024];
    size_t bytesRead;
    
    if (file == NULL) {
        perror("fopen");
        return;
    }

    printf("Scanning file: %s\n", filepath);
    
    while ((bytesRead = fread(buffer, 1, sizeof(buffer), file)) > 0) {
        if (check_signature(buffer, bytesRead)) {
            printf("Virus detected in file: %s\n", filepath);
            fclose(file);
            return;
        }
    }

    fclose(file);
    printf("File scanned successfully: %s - No virus found.\n", filepath);
}

int check_signature(const char *buffer, size_t size) {
    if (memmem(buffer, size, SIG1, strlen(SIG1)) != NULL) {
        return 1;  // Virus detected
    }
    if (memmem(buffer, size, SIG2, strlen(SIG2)) != NULL) {
        return 1;  // Virus detected
    }
    if (memmem(buffer, size, SIG3, strlen(SIG3)) != NULL) {
        return 1;  // Virus detected
    }
    return 0;  // No virus found
}