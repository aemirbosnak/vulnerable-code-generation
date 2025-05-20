//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

#define SIGNATURE "malicious_code"
#define BUFFER_SIZE 1024

// Function declarations
int check_file(const char *filename);
void scan_directory(const char *directory);
void print_peaceful_message();

int main(int argc, char *argv[]) {
    print_peaceful_message();

    if (argc < 2) {
        printf("Usage: %s <directory_to_scan>\n", argv[0]);
        return 1;
    }

    scan_directory(argv[1]);

    return 0;
}

void print_peaceful_message() {
    printf("Welcome to the Peaceful Antivirus Scanner!\n");
    printf("We strive for harmony between your digital space and safety.\n");
    printf("Scanning in progress, please be patient...\n");
}

void scan_directory(const char *directory) {
    struct dirent *entry;
    DIR *dp = opendir(directory);

    if (dp == NULL) {
        printf("Error: Could not open directory %s\n", directory);
        return;
    }

    while ((entry = readdir(dp))) {
        if (entry->d_type == DT_REG) { // Regular file
            char filepath[256];
            snprintf(filepath, sizeof(filepath), "%s/%s", directory, entry->d_name);
            if (check_file(filepath)) {
                printf("Alert: Malicious code found in %s\n", filepath);
            } else {
                printf("%s is safe.\n", filepath);
            }
        } else if (entry->d_type == DT_DIR && strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            char subdirectory[256];
            snprintf(subdirectory, sizeof(subdirectory), "%s/%s", directory, entry->d_name);
            scan_directory(subdirectory);
        }
    }

    closedir(dp);
}

int check_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Warning: Could not read file %s\n", filename);
        return 0;
    }

    char buffer[BUFFER_SIZE];
    while (fgets(buffer, sizeof(buffer), file)) {
        if (strstr(buffer, SIGNATURE)) {
            fclose(file);
            return 1; // Malicious code found
        }
    }

    fclose(file);
    return 0; // Safe
}