//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

#define MAX_PATH 1024
#define SIGNATURE "LOVE_VIRUS"

// Function prototypes
void scan_directory(const char *path);
void scan_file(const char *file_path);
void report_infection(const char *file_path);

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Oh dearest user, you forgot to provide a path!\n");
        printf("Usage: ./antivirus <directory_path>\n");
        return 1;
    }

    printf("With love in every byte...\n");
    scan_directory(argv[1]);
    printf("Scanning completed, my sweet companion.\n");
    return 0;
}

void scan_directory(const char *path) {
    DIR *dir;
    struct dirent *entry;

    if (!(dir = opendir(path))) {
        fprintf(stderr, "Oh sorrowful fate! Unable to open the directory: %s\n", path);
        return;
    }

    printf("Entering the realm of %s, where shadows may hide...\n", path);
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_DIR) {
            if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
                char new_path[MAX_PATH];
                snprintf(new_path, sizeof(new_path), "%s/%s", path, entry->d_name);
                scan_directory(new_path);  // Recursively scan subdirectories
            }
        } else {
            char file_path[MAX_PATH];
            snprintf(file_path, sizeof(file_path), "%s/%s", path, entry->d_name);
            scan_file(file_path);  // Scan the file
        }
    }
    closedir(dir);
}

void scan_file(const char *file_path) {
    FILE *file;
    char *buffer;
    long file_size;

    file = fopen(file_path, "rb");
    if (!file) {
        fprintf(stderr, "Alas! Could not open file: %s\n", file_path);
        return;
    }

    fseek(file, 0, SEEK_END);
    file_size = ftell(file);
    rewind(file);

    buffer = (char *)malloc(file_size + 1);
    fread(buffer, 1, file_size, file);
    buffer[file_size] = '\0';  // Null-terminate for string search

    if (strstr(buffer, SIGNATURE) != NULL) {
        report_infection(file_path);
    }

    free(buffer);
    fclose(file);
}

void report_infection(const char *file_path) {
    printf("Oh, the betrayal! The heart weeps for %s, tainted by the love virus!\n", file_path);
    printf("Fear not, dear user, for with your wisdom, we shall cleanse this sin.\n");
}