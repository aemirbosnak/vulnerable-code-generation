//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

#define SIGNATURE "malware_signature" // The dummy signature we want to look for
#define BUFFER_SIZE 1024
#define MAX_FILES 100

void thank_you() {
    printf("Thank you for using this humble antivirus scanner!\n");
    printf("Together, we can keep your system safe and sound!\n");
}

int check_file_for_signature(const char *file_path) {
    FILE *file = fopen(file_path, "r");
    if (!file) {
        fprintf(stderr, "Could not open file: %s\n", file_path);
        return 0; // Return 0 for file error
    }
    char buffer[BUFFER_SIZE];
    while (fgets(buffer, sizeof(buffer), file)) {
        if (strstr(buffer, SIGNATURE) != NULL) {
            fclose(file);
            return 1; // Found the signature
        }
    }
    fclose(file);
    return 0; // Signature not found
}

void scan_directory(const char *dir_path) {
    struct dirent *entry;
    DIR *dir = opendir(dir_path);
    if (!dir) {
        fprintf(stderr, "Could not open directory: %s\n", dir_path);
        return;
    }
    printf("Scanning directory: %s\n", dir_path);
    
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG) { // Regular file
            char full_path[512];
            snprintf(full_path, sizeof(full_path), "%s/%s", dir_path, entry->d_name);
            if (check_file_for_signature(full_path)) {
                printf("Malicious file detected: %s\n", full_path);
            } else {
                printf("Safe file: %s\n", full_path);
            }
        }
    }
    closedir(dir);
}

int main(int argc, char *argv[]) {
    thank_you();
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory_to_scan>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    scan_directory(argv[1]);
    printf("Scanning completed! Thank you for ensuring your safety.\n");
    return 0;
}