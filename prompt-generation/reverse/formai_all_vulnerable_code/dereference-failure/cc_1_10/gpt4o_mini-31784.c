//GPT-4o-mini DATASET v1.0 Category: Data recovery tool ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define RECOVERY_DIR "recovered_files"

// Function to create a directory for recovered files
void create_recovery_directory() {
    if (mkdir(RECOVERY_DIR, 0755) == -1) {
        perror("Failed to create recovery directory");
        exit(EXIT_FAILURE);
    }
}

// Function to check if a file is a regular file
int is_regular_file(const struct dirent *entry) {
    return entry->d_type == DT_REG; // Regular file type
}

// Function to recover a simple text file
void recover_file(const char *filename) {
    FILE *original_file = fopen(filename, "r");
    if (original_file == NULL) {
        fprintf(stderr, "Could not open file: %s\n", filename);
        return;
    }

    char buffer[BUFFER_SIZE];
    char recovered_filename[BUFFER_SIZE];
    snprintf(recovered_filename, sizeof(recovered_filename), "%s/recovered_%s", RECOVERY_DIR, filename);

    FILE *recovered_file = fopen(recovered_filename, "w");
    if (recovered_file == NULL) {
        fprintf(stderr, "Could not create file: %s\n", recovered_filename);
        fclose(original_file);
        return;
    }

    while (fgets(buffer, sizeof(buffer), original_file)) {
        fputs(buffer, recovered_file);
    }

    fclose(original_file);
    fclose(recovered_file);
    printf("Recovered: %s -> %s\n", filename, recovered_filename);
}

// Function to scan a directory and recover files
void scan_and_recover_directory(const char *directory) {
    struct dirent **namelist;
    int n = scandir(directory, &namelist, is_regular_file, alphasort);
    if (n < 0) {
        perror("scandir");
        return;
    }

    for (int i = 0; i < n; i++) {
        char *filename = namelist[i]->d_name;
        recover_file(filename);
        free(namelist[i]);
    }
    free(namelist);
}

// Main function
int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory_to_scan>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Create recovery directory
    create_recovery_directory();

    // Scan the specified directory and recover files
    scan_and_recover_directory(argv[1]);

    printf("Recovery Process Completed\n");
    return 0;
}