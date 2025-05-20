//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

// Define some virus signatures for demonstration
const char *virus_signatures[] = {
    "VIRUS_SIGNATURE_1",
    "VIRUS_SIGNATURE_2",
    "MALWARE_CODE_XYZ",
    NULL
};

// Function to check if a file is infected based on virus signatures
int check_for_virus(const char *file_path) {
    FILE *file = fopen(file_path, "r");
    if (!file) {
        perror("Error opening file");
        return -1; // Error opening the file
    }

    // Read file content and search for virus signatures
    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), file)) {
        for (const char **signature = virus_signatures; *signature != NULL; signature++) {
            if (strstr(buffer, *signature) != NULL) {
                fclose(file);
                return 1; // Virus found
            }
        }
    }

    fclose(file);
    return 0; // No virus found
}

// Function to scan a directory for files
void scan_directory(const char *dir_path) {
    struct dirent *entry;
    DIR *dp = opendir(dir_path);
    if (dp == NULL) {
        perror("Error opening directory");
        return; // Error opening directory
    }

    while ((entry = readdir(dp))) {
        // Ignore '.' and '..'
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            char file_path[1024];
            snprintf(file_path, sizeof(file_path), "%s/%s", dir_path, entry->d_name);
            
            struct stat file_stat;
            if (stat(file_path, &file_stat) == 0) {
                // Only scan regular files
                if (S_ISREG(file_stat.st_mode)) {
                    int result = check_for_virus(file_path);
                    if (result == 1) {
                        printf("Infected File Found: %s\n", file_path);
                    } else if (result == 0) {
                        printf("File Safe: %s\n", file_path);
                    }
                }
            }
        }
    }
    closedir(dp);
}

// Main function
int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory_to_scan>\n", argv[0]);
        return EXIT_FAILURE;
    }

    scan_directory(argv[1]);
    return EXIT_SUCCESS;
}