//GPT-4o-mini DATASET v1.0 Category: Data recovery tool ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define SIGNATURE_SIZE 3

// Function to read a file's content and check for a specific signature
int check_file_for_signature(const char *file_path, const char *signature, char *buffer) {
    FILE *file = fopen(file_path, "rb");
    if (!file) {
        return 0;
    }

    size_t bytesRead = fread(buffer, 1, BUFFER_SIZE, file);
    fclose(file);

    return bytesRead > 0 && memcmp(buffer, signature, SIGNATURE_SIZE) == 0;
}

// Function to recover "deleted" files based on signature scanning
void recover_files(const char *directory, const char *signature) {
    struct dirent *entry;
    struct stat file_stat;
    char file_path[BUFFER_SIZE];
    char buffer[BUFFER_SIZE];

    DIR *dir = opendir(directory);
    if (!dir) {
        perror("Could not open directory");
        return;
    }

    int recovered_count = 0;
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG) { // Only check regular files
            snprintf(file_path, sizeof(file_path), "%s/%s", directory, entry->d_name);
            if (check_file_for_signature(file_path, signature, buffer)) {
                printf("Recovered file: %s\n", entry->d_name);
                recovered_count++;
            }
        }
    }
    closedir(dir);

    if (recovered_count == 0) {
        printf("No files recovered with signature: %s\n", signature);
    } else {
        printf("Total recovered files: %d\n", recovered_count);
    }
}

// Main function to run the recovery tool
int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <directory> <signature>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *directory = argv[1];
    const char *signature = argv[2];

    // Ensure the signature length is reasonable
    if (strlen(signature) < SIGNATURE_SIZE) {
        fprintf(stderr, "Signature must be at least %d characters long.\n", SIGNATURE_SIZE);
        return EXIT_FAILURE;
    }

    printf("Scanning directory: %s for signature: %s\n", directory, signature);
    recover_files(directory, signature);
    printf("Data recovery process complete! Who knew scavenging could be so much fun?\n");

    return EXIT_SUCCESS;
}