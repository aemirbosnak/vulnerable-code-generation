//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_FILE_NAME_LENGTH 256
#define MAX_SCAN_DEPTH 5

typedef struct {
    char *pattern;
    int count;
} VirusSignature;

VirusSignature known_viruses[] = {
    {"VIRUS1", 0},
    {"VIRUS2", 0},
    {"WORM1", 0},
    {NULL, 0} // Sentinel to mark the end of the array
};

// Function declarations
void scan_directory(const char *dir_path, int depth);
int check_for_viruses(const char *file_path);
void report_viruses(const char *file_path, int match_count);

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory_to_scan>\n", argv[0]);
        return EXIT_FAILURE;
    }

    printf("Sherlock Holmes Antivirus Scanner Initializing...\n");
    
    scan_directory(argv[1], 0);

    printf("Scan complete. Analyzing results...\n\n");
    for (int i = 0; known_viruses[i].pattern != NULL; i++) {
        if (known_viruses[i].count > 0) {
            printf("Detected %d instance(s) of virus: %s\n", known_viruses[i].count, known_viruses[i].pattern);
        }
    }

    return EXIT_SUCCESS;
}

void scan_directory(const char *dir_path, int depth) {
    if (depth > MAX_SCAN_DEPTH) {
        printf("Reached maximum scan depth (%d). Skipping further exploration.\n", MAX_SCAN_DEPTH);
        return;
    }

    DIR *dir = opendir(dir_path);
    if (dir == NULL) {
        perror("Error opening directory");
        return;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_DIR) {
            // Skip directories '.' and '..'
            if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
                char new_dir_path[MAX_FILE_NAME_LENGTH];
                snprintf(new_dir_path, sizeof(new_dir_path), "%s/%s", dir_path, entry->d_name);
                printf("Exploring directory: %s\n", new_dir_path);
                scan_directory(new_dir_path, depth + 1);
            }
        } else if (entry->d_type == DT_REG) {
            char file_path[MAX_FILE_NAME_LENGTH];
            snprintf(file_path, sizeof(file_path), "%s/%s", dir_path, entry->d_name);
            printf("Scanning file: %s\n", file_path);
            int match_count = check_for_viruses(file_path);
            if (match_count > 0) {
                report_viruses(file_path, match_count);
            }
        }
    }
    closedir(dir);
}

int check_for_viruses(const char *file_path) {
    FILE *file = fopen(file_path, "rb");
    if (!file) {
        perror("Unable to open file");
        return 0;
    }

    char buffer[1024];
    size_t bytes_read;
    int match_count = 0;

    while ((bytes_read = fread(buffer, 1, sizeof(buffer), file)) > 0) {
        for (int i = 0; known_viruses[i].pattern != NULL; i++) {
            if (memmem(buffer, bytes_read, known_viruses[i].pattern, strlen(known_viruses[i].pattern))) {
                known_viruses[i].count++;
                match_count++;
            }
        }
    }

    fclose(file);
    return match_count;
}

void report_viruses(const char *file_path, int match_count) {
    printf("ALERT! Found potential virus in %s. Matches detected: %d\n", file_path, match_count);
}