//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

// Defining the Virus Signature
#define SIGNATURE "VIRUS_SIGNATURE"

void scan_file(const char *file_path);
void scan_directory(const char *dir_path);
int is_virus_found(const char *file_content);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <directory_path>\n", argv[0]);
        return EXIT_FAILURE;
    }
    
    // Start scanning the directory
    scan_directory(argv[1]);
    return EXIT_SUCCESS;
}

void scan_file(const char *file_path) {
    FILE *file = fopen(file_path, "r");
    if (!file) {
        perror("Could not open file");
        return;
    }
    
    // Read the file content
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *file_content = (char *)malloc(file_size + 1);
    if (!file_content) {
        perror("Memory allocation failed");
        fclose(file);
        return;
    }

    fread(file_content, 1, file_size, file);
    file_content[file_size] = '\0'; // Null-terminate the string

    // Scan for virus signature
    if (is_virus_found(file_content)) {
        printf("Virus found in: %s\n", file_path);
    } else {
        printf("No virus in: %s\n", file_path);
    }

    // Clean up
    free(file_content);
    fclose(file);
}

void scan_directory(const char *dir_path) {
    struct dirent *entry;
    DIR *dp = opendir(dir_path);
    if (dp == NULL) {
        perror("Could not open directory");
        return;
    }

    // Scan each file and directory entry
    while ((entry = readdir(dp))) {
        if (entry->d_type == DT_REG) { // Regular file
            char file_path[1024];
            snprintf(file_path, sizeof(file_path), "%s/%s", dir_path, entry->d_name);
            scan_file(file_path);
        } else if (entry->d_type == DT_DIR) { // Directory
            if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
                char sub_dir_path[1024];
                snprintf(sub_dir_path, sizeof(sub_dir_path), "%s/%s", dir_path, entry->d_name);
                scan_directory(sub_dir_path); // Recursively scan sub-directory
            }
        }
    }

    closedir(dp);
}

int is_virus_found(const char *file_content) {
    // Check if the file contains the signature
    return strstr(file_content, SIGNATURE) != NULL;
}