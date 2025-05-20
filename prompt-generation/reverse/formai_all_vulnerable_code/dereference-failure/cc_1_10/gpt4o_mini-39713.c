//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PATH_LENGTH 1024
#define BUFFER_SIZE 4096

// Struct to represent a scanned file
typedef struct {
    char path[MAX_PATH_LENGTH];
    int infected;
    char *virus_signature;
} ScannedFile;

// Function to read virus signatures from a file
char **read_virus_signatures(const char *signature_file, int *count) {
    FILE *file = fopen(signature_file, "r");
    if (!file) {
        perror("Unable to open signature file");
        exit(EXIT_FAILURE);
    }

    char **signatures = malloc(BUFFER_SIZE * sizeof(char *));
    char buffer[BUFFER_SIZE];
    *count = 0;

    while (fgets(buffer, sizeof(buffer), file)) {
        buffer[strcspn(buffer, "\n")] = 0;  // Remove newline
        signatures[*count] = strdup(buffer);
        (*count)++;
    }

    fclose(file);
    return signatures;
}

// Function to scan a single file for viruses
int scan_file(const char *file_path, char **signatures, int sig_count) {
    FILE *file = fopen(file_path, "rb");
    if (!file) {
        perror("Failed to open file for scanning");
        return -1;
    }

    char buffer[BUFFER_SIZE];
    size_t bytes_read;
    int found_virus = 0;

    while ((bytes_read = fread(buffer, 1, sizeof(buffer), file)) > 0) {
        for (int i = 0; i < sig_count; i++) {
            if (strstr(buffer, signatures[i])) {
                found_virus = 1;
                break;
            }
        }
        if (found_virus) break;
    }

    fclose(file);
    return found_virus;
}

// Function to scan a directory recursively
void scan_directory(const char *directory_path, char **signatures, int sig_count) {
    DIR *dir = opendir(directory_path);
    if (!dir) {
        perror("Failed to open directory");
        return;
    }

    struct dirent *entry;
    struct stat entry_stat;

    while ((entry = readdir(dir)) != NULL) {
        // Skip the current and parent directory entries
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;

        char full_path[MAX_PATH_LENGTH];
        snprintf(full_path, sizeof(full_path), "%s/%s", directory_path, entry->d_name);

        if (stat(full_path, &entry_stat) == -1) {
            perror("Failed to get file stats");
            continue;
        }

        if (S_ISDIR(entry_stat.st_mode)) {
            // Recur into subdirectory
            scan_directory(full_path, signatures, sig_count);
        } else if (S_ISREG(entry_stat.st_mode)) {
            // Scan the file
            if (scan_file(full_path, signatures, sig_count)) {
                printf("Infected file found: %s\n", full_path);
            }
        }
    }

    closedir(dir);
}

// Main function to initialize the scanner
int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <directory_to_scan> <signature_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *directory_to_scan = argv[1];
    const char *signature_file = argv[2];

    int sig_count;
    char **virus_signatures = read_virus_signatures(signature_file, &sig_count);
    
    printf("Initiating antivirus scan...\n");
    scan_directory(directory_to_scan, virus_signatures, sig_count);
    
    // Free memory allocated for virus signatures
    for (int i = 0; i < sig_count; i++) {
        free(virus_signatures[i]);
    }
    free(virus_signatures);

    printf("Scan complete.\n");
    return EXIT_SUCCESS;
}