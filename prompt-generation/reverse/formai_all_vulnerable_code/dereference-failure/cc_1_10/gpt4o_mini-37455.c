//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <errno.h>
#include <unistd.h>

#define MAX_PATH 1024
#define MAX_SIGNATURES 100
#define MAX_SIG_LENGTH 64

typedef struct {
    char signatures[MAX_SIGNATURES][MAX_SIG_LENGTH];
    int count;
} SignatureDatabase;

SignatureDatabase db;

void load_signatures(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Could not open signature file: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    db.count = 0;
    while (fgets(db.signatures[db.count], MAX_SIG_LENGTH, file) != NULL && db.count < MAX_SIGNATURES) {
        db.signatures[db.count][strcspn(db.signatures[db.count], "\n")] = 0; // Remove newline
        db.count++;
    }
    fclose(file);
}

void scan_file(const char *file_path) {
    FILE *file = fopen(file_path, "rb");
    if (!file) {
        fprintf(stderr, "Could not open file %s: %s\n", file_path, strerror(errno));
        return;
    }

    char buffer[4096];
    size_t bytesRead;

    while ((bytesRead = fread(buffer, 1, sizeof(buffer), file)) > 0) {
        for (int i = 0; i < db.count; i++) {
            if (strstr(buffer, db.signatures[i]) != NULL) {
                printf("Virus signature found in file: %s | Signature: %s\n", file_path, db.signatures[i]);
                break; // Stop after first found signature
            }
        }
    }

    fclose(file);
}

void scan_directory(const char *path) {
    struct dirent *entry;
    DIR *dp = opendir(path);

    if (dp == NULL) {
        fprintf(stderr, "Could not open directory %s: %s\n", path, strerror(errno));
        return;
    }

    while ((entry = readdir(dp))) {
        if (entry->d_name[0] == '.') continue; // Skip hidden files
        char full_path[MAX_PATH];
        snprintf(full_path, sizeof(full_path), "%s/%s", path, entry->d_name);

        if (entry->d_type == DT_DIR) {
            scan_directory(full_path); // Recur for subdirectory
        } else if (entry->d_type == DT_REG) {
            scan_file(full_path); // Scan regular file
        }
    }

    closedir(dp);
}

void display_usage(const char *program_name) {
    fprintf(stderr, "Usage: %s <directory_to_scan> <signature_file>\n", program_name);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        display_usage(argv[0]);
        return EXIT_FAILURE;
    }

    const char *directory_to_scan = argv[1];
    const char *signature_file = argv[2];

    load_signatures(signature_file);
    scan_directory(directory_to_scan);

    return EXIT_SUCCESS;
}