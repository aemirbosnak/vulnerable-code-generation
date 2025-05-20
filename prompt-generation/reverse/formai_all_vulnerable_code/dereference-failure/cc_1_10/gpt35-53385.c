//FormAI DATASET v1.0 Category: File Synchronizer ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

void synchronize(const char* source, const char* destination) {
    DIR* source_dir = opendir(source);
    if (source_dir == NULL) {
        printf("Failed to open source directory %s", source);
        return;
    }

    DIR* dest_dir = opendir(destination);
    if (dest_dir == NULL) {
        printf("Failed to open destination directory %s", destination);
        return;
    }

    struct dirent* source_ent;
    struct dirent* dest_ent;
    while ((source_ent = readdir(source_dir)) != NULL) {
        char* source_name = source_ent->d_name;
        char source_path[strlen(source) + strlen(source_name) + 2];
        sprintf(source_path, "%s/%s", source, source_name);

        struct stat source_stats;
        if (stat(source_path, &source_stats) < 0) {
            printf("Failed to stat source file %s\n", source_path);
            continue;
        }

        if (S_ISDIR(source_stats.st_mode)) {
            if (strcmp(source_name, ".") == 0 || strcmp(source_name, "..") == 0) {
                continue;
            }

            char dest_path[strlen(destination) + strlen(source_name) + 2];
            sprintf(dest_path, "%s/%s", destination, source_name);

            struct stat dest_stats;
            if (stat(dest_path, &dest_stats) < 0) {
                mkdir(dest_path, source_stats.st_mode);
                if (stat(dest_path, &dest_stats) < 0) {
                    printf("Failed to create destination directory %s\n", dest_path);
                    continue;
                }
            }

            synchronize(source_path, dest_path);
        } else {
            if (strncmp(source_name, ".", 1) == 0) {
                continue;
            }

            dest_ent = NULL;
            rewinddir(dest_dir);
            while ((dest_ent = readdir(dest_dir)) != NULL) {
                if (strcmp(dest_ent->d_name, source_name) == 0) {
                    break;
                }
            }

            char dest_path[strlen(destination) + strlen(source_name) + 2];
            sprintf(dest_path, "%s/%s", destination, source_name);

            struct stat dest_stats;
            if (stat(dest_path, &dest_stats) < 0) {
                FILE* source_file = fopen(source_path, "r");
                FILE* dest_file = fopen(dest_path, "w");
                char buffer[4096];
                size_t read_count = 0;

                while ((read_count = fread(buffer, 1, 4096, source_file)) > 0) {
                    fwrite(buffer, 1, read_count, dest_file);
                }

                fclose(source_file);
                fclose(dest_file);

                printf("Created file %s\n", dest_path);
            } else {
                if (source_stats.st_mtime > dest_stats.st_mtime) {
                    FILE* source_file = fopen(source_path, "r");
                    FILE* dest_file = fopen(dest_path, "w");
                    char buffer[4096];
                    size_t read_count = 0;

                    while ((read_count = fread(buffer, 1, 4096, source_file)) > 0) {
                        fwrite(buffer, 1, read_count, dest_file);
                    }

                    fclose(source_file);
                    fclose(dest_file);

                    printf("Modified file %s\n", dest_path);
                } else {
                    printf("No changes needed for file %s\n", dest_path);
                }
            }
        }
    }

    closedir(source_dir);
    closedir(dest_dir);
}

int main(int argc, char** argv) {
    if (argc < 3) {
        printf("Usage: %s SOURCE_DIR DESTINATION_DIR\n", argv[0]);
        return 1;
    }

    synchronize(argv[1], argv[2]);

    return 0;
}