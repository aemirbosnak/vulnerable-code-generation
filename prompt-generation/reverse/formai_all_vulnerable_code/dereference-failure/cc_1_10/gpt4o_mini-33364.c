//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

#define PATH_MAX 1024
#define FILE_NAME_MAX 256
#define VIRUS_SIGNATURE "LoveVirus"

void serenade_file(const char *file_path) {
    printf("Scanning the heart of the file: %s...\n", file_path);
}

int has_virus(const char *file_path) {
    FILE *file = fopen(file_path, "rb");
    if (!file) {
        perror("Error opening file");
        return 0;
    }

    char buffer[256];
    while (fread(buffer, sizeof(char), sizeof(buffer), file)) {
        if (strstr(buffer, VIRUS_SIGNATURE)) {
            fclose(file);
            return 1; // Virus detected
        }
    }

    fclose(file);
    return 0; // Safe
}

void express_love(const char *file_path) {
    printf("Oh dear file, you are infected with a virus! Don't worry, I shall save you from the clutches of despair!\n");
    printf("We must remove the malicious code and restore your purity...\n");
    // Here, we can choose to "heal" the file by simply simulating its removal
}

void scan_directory(const char *directory_path) {
    DIR *dir = opendir(directory_path);
    struct dirent *entry;

    if (!dir) {
        perror("Could not open directory");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG) { // Check if it's a regular file
            char file_path[PATH_MAX];
            snprintf(file_path, sizeof(file_path), "%s/%s", directory_path, entry->d_name);
            serenade_file(file_path);

            if (has_virus(file_path)) {
                express_love(file_path);
            } else {
                printf("Your heart is pure, dear file: %s. No virus found!\n", file_path);
            }
        } else if (entry->d_type == DT_DIR && strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            char nested_path[PATH_MAX];
            snprintf(nested_path, sizeof(nested_path), "%s/%s", directory_path, entry->d_name);
            scan_directory(nested_path);
        }
    }

    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("My love, please provide a directory path for me to scan!\n");
        return 1;
    }

    const char *directory_to_scan = argv[1];
    printf("Darling, let me scan your precious folder: %s!\n", directory_to_scan);
    scan_directory(directory_to_scan);
    printf("Oh what joy, I have completed my task!\n");

    return 0;
}