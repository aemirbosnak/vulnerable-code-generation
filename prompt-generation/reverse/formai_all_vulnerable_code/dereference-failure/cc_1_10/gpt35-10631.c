//FormAI DATASET v1.0 Category: File Synchronizer ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

/* Function Prototype Declarations */
int is_dir(const char *file_path);
void synchronize(const char *source_dir, const char *target_dir, int force);

/* Main Function */
int main(int argc, char *argv[]) {
    // Check if source and target directories were provided
    if (argc < 3) {
        printf("Error: Source and target directories are required!\n");
        return 1;
    }

    // Check if force flag was provided
    int force = 0;
    if (argc == 4 && strcmp(argv[3], "-f") == 0) {
        force = 1;
    }

    // Synchronize directories
    synchronize(argv[1], argv[2], force);

    printf("Synchronization complete!\n");
    return 0;
}

/* Function Definitions */
int is_dir(const char *file_path) {
    struct stat path_stat;
    stat(file_path, &path_stat);
    return S_ISDIR(path_stat.st_mode);
}

void synchronize(const char *source_dir, const char *target_dir, int force) {
    struct dirent *entry;
    DIR *dir = opendir(source_dir);

    // Check if source directory could be opened
    if (dir == NULL) {
        printf("Error: Cannot open source directory %s\n", source_dir);
        return;
    }

    // Create target directory if it doesn't exist
    if (access(target_dir, F_OK) == -1) {
        mkdir(target_dir, 0755);
    }

    // Synchronize each file in the source directory
    while ((entry = readdir(dir)) != NULL) {
        char source_path[512];
        char target_path[512];
        sprintf(source_path, "%s/%s", source_dir, entry->d_name);
        sprintf(target_path, "%s/%s", target_dir, entry->d_name);

        // Ignore "." and ".." directories
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        // Synchronize a directory recursively
        if (is_dir(source_path)) {
            // Check if target directory already exists
            if (access(target_path, F_OK) == -1) {
                if (!force) {
                    printf("Error: Target directory %s does not exist!\n", target_path);
                    continue;
                }
            }

            // Recursively synchronize the directories
            synchronize(source_path, target_path, force);
            continue;
        }

        // Copy file to target directory if it doesn't exist or force flag is set
        if (access(target_path, F_OK) == -1 || force) {
            printf("Copying %s to %s\n", source_path, target_path);
            FILE *source_file = fopen(source_path, "rb");
            FILE *target_file = fopen(target_path, "wb");
            unsigned char buffer[4096];
            int n;
            while ((n = fread(buffer, sizeof(unsigned char), sizeof(buffer), source_file)) > 0) {
                fwrite(buffer, sizeof(unsigned char), n, target_file);
            }
            fclose(source_file);
            fclose(target_file);
        }
    }

    closedir(dir);
}