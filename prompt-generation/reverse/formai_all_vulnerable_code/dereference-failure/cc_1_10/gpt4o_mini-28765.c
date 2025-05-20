//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

#define MAX_SIG_LENGTH 256
#define MAX_FILE_SIZE 1024 * 1024 // 1MB
#define MAX_BUFF_SIZE 4096
#define MAX_PATH_LENGTH 512

// List of virus signatures
const char* virus_signatures[] = {
    "VIRUS1_SIGNATURE",
    "VIRUS2_SIGNATURE",
    "MALWARE_SIGNATURE",
    NULL // End of list marker
};

// Function to check if the file contains any virus signatures
int scan_file(const char *filepath) {
    FILE *file = fopen(filepath, "rb");
    
    if (!file) {
        printf("Unable to open file: %s\n", filepath);
        return -1;
    }

    char buffer[MAX_BUFF_SIZE];
    while (fread(buffer, sizeof(char), sizeof(buffer), file) > 0) {
        for (int i = 0; virus_signatures[i] != NULL; i++) {
            if (strstr(buffer, virus_signatures[i]) != NULL) {
                fclose(file);
                return 1; // File is infected
            }
        }
    }
    fclose(file);
    return 0; // File is clean
}

// Function to scan all files in a directory
void scan_directory(const char *dirpath) {
    struct dirent *entry;
    DIR *dir = opendir(dirpath);
    
    if (!dir) {
        printf("Could not open directory: %s\n", dirpath);
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        // Ignore "." and ".." entries
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            char filepath[MAX_PATH_LENGTH];
            snprintf(filepath, sizeof(filepath), "%s/%s", dirpath, entry->d_name);
            
            if (entry->d_type == DT_DIR) {
                printf("Scanning directory: %s...\n", filepath);
                scan_directory(filepath); // Recursively scan subdirectories
            } else {
                printf("Scanning file: %s...\n", filepath);
                int result = scan_file(filepath);
                if (result == 1) {
                    printf("!Warning: Infected file found: %s\n", filepath);
                } else if (result == 0) {
                    printf("File is clean: %s\n", filepath);
                }
            }
        }
    }
    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: ./antivirus_scanner <directory>\n");
        exit(1);
    }

    printf("👀 Starting the antivirus scanner! 🚀\n");
    printf("Scanning the directory: %s\n", argv[1]);

    scan_directory(argv[1]);
    
    printf("✅ Scanning completed! 🎉\n");
    return 0;
}