//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PATH_LENGTH 1024
#define MAX_SIGNATURES 10

// Struct to hold virus signatures
typedef struct {
    char *name;
    char *signature;
} VirusSignature;

// Array of virus signatures
VirusSignature signatures[MAX_SIGNATURES] = {
    { "EICAR_test_file", "X5O!P%@AP[4\\PZX54(P^)7CC)7}" },
    { "Generic Virus", "SomeGenericSignature123456" },
    { "Trojan", "TrojanSignature123" },
    // Add additional signatures here!
};

void scan_file(const char *file_path) {
    FILE *file = fopen(file_path, "rb");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    char buffer[1024];
    size_t bytes_read;
    while ((bytes_read = fread(buffer, 1, sizeof(buffer), file)) > 0) {
        for (int i = 0; i < MAX_SIGNATURES; i++) {
            if (strstr(buffer, signatures[i].signature) != NULL) {
                printf("\033[31m[WARNING]\033[0m Virus detected in file: %s (Virus: %s)\n", file_path, signatures[i].name);
                fclose(file);
                return; // Virus found, no need to check further
            }
        }
    }

    printf("\033[32m[SAFE]\033[0m File is safe: %s\n", file_path);
    fclose(file);
}

void scan_directory(const char *dir_path) {
    struct dirent *entry;
    DIR *dp = opendir(dir_path);

    if (dp == NULL) {
        perror("Error opening directory");
        return;
    }

    while ((entry = readdir(dp)) != NULL) {
        if (entry->d_name[0] == '.') {
            continue; // Skip hidden files
        }

        char full_path[MAX_PATH_LENGTH];
        snprintf(full_path, sizeof(full_path), "%s/%s", dir_path, entry->d_name);
        struct stat path_stat;
        stat(full_path, &path_stat);

        if (S_ISREG(path_stat.st_mode)) {
            scan_file(full_path); // Regular file
        } else if (S_ISDIR(path_stat.st_mode)) {
            scan_directory(full_path); // Recursively scan subdirectories
        }
    }

    closedir(dp);
}

void print_welcome_message() {
    printf("=====================================\n");
    printf("         C Antivirus Scanner         \n");
    printf("           By Your Name              \n");
    printf("=====================================\n");
    printf("Starting the scan... Hold tight!\n");
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory_to_scan>\n", argv[0]);
        return EXIT_FAILURE;
    }

    print_welcome_message();
    scan_directory(argv[1]);

    printf("Scan complete! Stay safe out there!\n");
    return EXIT_SUCCESS;
}