//GPT-4o-mini DATASET v1.0 Category: Metadata Extractor ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_PATH 1024

typedef struct {
    int function_count;
    int comment_count;
    int line_count;
} MetaData;

MetaData extract_metadata(const char* filepath) {
    FILE* file = fopen(filepath, "r");
    MetaData data = {0, 0, 0};
    if (!file) {
        perror("Error opening file");
        return data;
    }

    char line[256];
    int in_multiline_comment = 0;
    while (fgets(line, sizeof(line), file)) {
        data.line_count++;
        
        // Check for single-line comments
        if (strstr(line, "//")) {
            data.comment_count++;
        }
        
        // Check for multi-line comments
        if (in_multiline_comment) {
            data.comment_count++;
            if (strstr(line, "*/")) {
                in_multiline_comment = 0;
            }
        } else if (strstr(line, "/*")) {
            in_multiline_comment = 1;
            data.comment_count++;
        }

        // Count function definitions (simple heuristic)
        if (strchr(line, '(') && strchr(line, ')') && (strchr(line, '{'))) {
            data.function_count++;
        }
    }

    fclose(file);
    return data;
}

void process_directory(const char* dir_path) {
    struct dirent* dir_entry;
    DIR* dir = opendir(dir_path);

    if (!dir) {
        perror("Could not open directory");
        return;
    }

    while ((dir_entry = readdir(dir)) != NULL) {
        if (strcmp(dir_entry->d_name, ".") != 0 && strcmp(dir_entry->d_name, "..") != 0) {
            char full_path[MAX_PATH];
            snprintf(full_path, sizeof(full_path), "%s/%s", dir_path, dir_entry->d_name);

            struct stat entry_stat;
            if (stat(full_path, &entry_stat) == 0) {
                if (S_ISDIR(entry_stat.st_mode)) {
                    process_directory(full_path); // Recurse into subdirectory
                } else if (S_ISREG(entry_stat.st_mode) && strstr(dir_entry->d_name, ".c")) {
                    MetaData metadata = extract_metadata(full_path);
                    printf("File: %s\n", full_path);
                    printf("  Functions: %d\n", metadata.function_count);
                    printf("  Comments: %d\n", metadata.comment_count);
                    printf("  Lines: %d\n", metadata.line_count);
                    printf("-----------------------\n");
                }
            }
        }
    }

    closedir(dir);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory_path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    process_directory(argv[1]);
    return EXIT_SUCCESS;
}