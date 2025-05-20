//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>

#define MAX_SIGNATURES 5
#define MAX_FILENAME_LEN 256
#define MAX_PATH_LEN 512

// Example malware signatures (for demonstration purposes)
const char *malware_signatures[MAX_SIGNATURES] = {
    "malware_1_signature",
    "malware_2_signature",
    "malware_3_signature",
    "malware_4_signature",
    "malware_5_signature"
};

int check_for_malware(const char *file_path) {
    FILE *file = fopen(file_path, "r");
    if (!file) {
        perror("Could not open file");
        return 0; // File did not open, cannot check for malware
    }

    char buffer[256];
    while (fgets(buffer, sizeof(buffer), file)) {
        for (int i = 0; i < MAX_SIGNATURES; i++) {
            if (strstr(buffer, malware_signatures[i]) != NULL) {
                fclose(file);
                return 1; // Malware signature found
            }
        }
    }
    
    fclose(file);
    return 0; // No signatures found
}

void scan_directory(const char *directory_path) {
    struct dirent *entry;
    struct stat file_stat;
    DIR *dir = opendir(directory_path);

    if (!dir) {
        perror("Could not open directory");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        // Ignore the special entries "." and ".."
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char full_path[MAX_PATH_LEN];
        snprintf(full_path, sizeof(full_path), "%s/%s", directory_path, entry->d_name);

        // Check if it's a file
        if (stat(full_path, &file_stat) == 0 && S_ISREG(file_stat.st_mode)) {
            printf("Scanning file: %s\n", full_path);
            if (check_for_malware(full_path)) {
                printf("WARNING: Malware detected in file: %s\n", full_path);
            } else {
                printf("No malware detected in file: %s\n", full_path);
            }
        }
    }

    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory-path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Scan the specified directory for malware
    scan_directory(argv[1]);

    return EXIT_SUCCESS;
}