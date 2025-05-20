//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_PATH 1024
#define MAX_SIGNATURE 256

typedef struct {
    char name[MAX_SIGNATURE]; // virus name
    char signature[MAX_SIGNATURE]; // virus signature
} Virus;

Virus viruses[] = {
    {"EICAR", "X5O!P%@AP[4|A]$EICAR-STANDARD-ANTIVIRUS-TEST-FILE!$H+H*"},
    {"TestVirus", "SomeMaliciousSignature12345"}
};
int virus_count = sizeof(viruses) / sizeof(viruses[0]);

void scan_file(const char* file_path);
void scan_directory(const char* dir_path);
void display_usage(const char* program_name);

int main(int argc, char* argv[]) {
    if (argc != 2) {
        display_usage(argv[0]);
        return EXIT_FAILURE;
    }
    
    struct stat file_info;
    if (stat(argv[1], &file_info) != 0) {
        perror("Error accessing file/director");
        return EXIT_FAILURE;
    }
    
    if (S_ISDIR(file_info.st_mode)) {
        printf("Scanning directory: %s\n", argv[1]);
        scan_directory(argv[1]);
    } else if (S_ISREG(file_info.st_mode)) {
        printf("Scanning file: %s\n", argv[1]);
        scan_file(argv[1]);
    } else {
        fprintf(stderr, "Error: %s is neither a file nor a directory.\n", argv[1]);
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

void display_usage(const char* program_name) {
    printf("Usage: %s <file or directory to scan>\n", program_name);
}

void scan_file(const char* file_path) {
    FILE* file = fopen(file_path, "rb");
    if (!file) {
        perror("Error opening file");
        return;
    }
    
    char buffer[1024];
    size_t bytes_read;
    int found_virus = 0;

    while ((bytes_read = fread(buffer, 1, sizeof(buffer), file)) > 0) {
        for (int i = 0; i < virus_count; i++) {
            if (memmem(buffer, bytes_read, viruses[i].signature, strlen(viruses[i].signature)) != NULL) {
                printf("Virus detected: %s in file: %s\n", viruses[i].name, file_path);
                found_virus = 1;
            }
        }
    }
    
    if (!found_virus) {
        printf("No viruses found in the file: %s\n", file_path);
    }
    
    fclose(file);
}

void scan_directory(const char* dir_path) {
    DIR* dir = opendir(dir_path);
    if (!dir) {
        perror("Error opening directory");
        return;
    }

    struct dirent* entry;
    char full_path[MAX_PATH];

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_name[0] == '.') {
            // Skip hidden files and directories
            continue;
        }
        
        snprintf(full_path, sizeof(full_path), "%s/%s", dir_path, entry->d_name);
        
        struct stat file_info;
        if (stat(full_path, &file_info) != 0) {
            perror("Error accessing file");
            continue;
        }
        
        if (S_ISREG(file_info.st_mode)) {
            scan_file(full_path);
        } else if (S_ISDIR(file_info.st_mode)) {
            printf("Entering directory: %s\n", full_path);
            scan_directory(full_path);
        }
    }
    
    closedir(dir);
}