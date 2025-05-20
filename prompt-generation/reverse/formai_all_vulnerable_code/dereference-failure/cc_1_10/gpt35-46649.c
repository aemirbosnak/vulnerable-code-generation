//FormAI DATASET v1.0 Category: File Synchronizer ; Style: curious
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

void sync_files(const char* source_dir, const char* dest_dir) {
    DIR* source_dp = opendir(source_dir);
    DIR* dest_dp = opendir(dest_dir);

    if (!source_dp) {
        printf("Error: cannot open source directory %s\n", source_dir);
        return;
    }

    if (!dest_dp) {
        printf("Error: cannot open destination directory %s\n", dest_dir);
        closedir(source_dp);
        return;
    }

    struct dirent* source_dent;
    while ((source_dent = readdir(source_dp))) {
        if (source_dent->d_type != DT_REG) {
            continue;
        }

        char source_path[PATH_MAX];
        sprintf(source_path, "%s/%s", source_dir, source_dent->d_name);

        struct stat source_stats;
        if (stat(source_path, &source_stats) < 0) {
            printf("Error: cannot stat %s\n", source_path);
            continue;
        }

        struct dirent* dest_dent;
        while ((dest_dent = readdir(dest_dp))) {
            if (dest_dent->d_type != DT_REG) {
                continue;
            }

            char dest_path[PATH_MAX];
            sprintf(dest_path, "%s/%s", dest_dir, dest_dent->d_name);

            struct stat dest_stats;
            if (stat(dest_path, &dest_stats) < 0) {
                printf("Error: cannot stat %s\n", dest_path);
                continue;
            }

            if (strcmp(source_dent->d_name, dest_dent->d_name) == 0) {
                if (source_stats.st_mtime > dest_stats.st_mtime) {
                    printf("Copying %s to %s...\n", source_path, dest_path);
                    FILE* source_file = fopen(source_path, "rb");
                    FILE* dest_file = fopen(dest_path, "wb");
                    char buffer[1024];
                    int n;
                    while ((n = fread(buffer, 1, sizeof(buffer), source_file)) > 0) {
                        fwrite(buffer, 1, n, dest_file);
                    }
                    fclose(source_file);
                    fclose(dest_file);
                }
            }
        }

        rewinddir(dest_dp);
    }

    closedir(source_dp);
    closedir(dest_dp);

    printf("Done synchronizing!\n");
}

int main(int argc, char** argv) {
    if (argc < 3) {
        printf("Usage: %s source_dir dest_dir\n", argv[0]);
        return 1;
    }

    const char* source_dir = argv[1];
    const char* dest_dir = argv[2];

    sync_files(source_dir, dest_dir);

    return 0;
}