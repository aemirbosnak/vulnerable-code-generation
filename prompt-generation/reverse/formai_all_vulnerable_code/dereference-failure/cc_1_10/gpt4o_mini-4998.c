//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

// Function to check for a virus signature in a file
int check_for_signature(const char *file_path, const char *signature) {
    FILE *file = fopen(file_path, "r");
    if (file == NULL) {
        perror("Error opening file");
        return 0; // Return 0 if file could not be opened
    }

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, signature) != NULL) {
            fclose(file);
            return 1; // Return 1 if signature found
        }
    }

    fclose(file);
    return 0; // Return 0 if signature not found
}

// Function to scan a directory for files
void scan_directory(const char *dir_path, const char *signature) {
    DIR *dir;
    struct dirent *ent;

    dir = opendir(dir_path);
    if (dir == NULL) {
        perror("Could not open directory");
        return;
    }

    while ((ent = readdir(dir)) != NULL) {
        if (ent->d_type == DT_REG) { // Check if it is a regular file
            char file_path[512];
            snprintf(file_path, sizeof(file_path), "%s/%s", dir_path, ent->d_name);
            
            if (check_for_signature(file_path, signature)) {
                printf("Warning: Virus signature found in file: %s\n", file_path);
            } else {
                printf("No virus signature in file: %s\n", file_path);
            }
        }
    }

    closedir(dir);
}

// Function to get the signature to search for
void get_signature(char *signature, size_t size) {
    printf("Enter the virus signature to search for: ");
    fgets(signature, size, stdin);
    signature[strcspn(signature, "\n")] = 0; // Remove newline character from input
}

// Main function to run the antivirus scanner
int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char signature[256];
    get_signature(signature, sizeof(signature));

    printf("Scanning directory: %s\n", argv[1]);
    scan_directory(argv[1], signature);

    printf("Scanning complete.\n");
    return EXIT_SUCCESS;
}