//FormAI DATASET v1.0 Category: File Synchronizer ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

void sync_files(char* src_dir, char* dest_dir);

int main(int argc, char** argv) {
    if (argc != 3) {
        printf("Usage: %s <src_directory> <dest_directory>\n", argv[0]);
        exit(1);
    }

    printf("Starting file synchronization...\n");
    sync_files(argv[1], argv[2]);
    printf("File synchronization complete!\n");

    return 0;
}

void sync_files(char* src_dir, char* dest_dir) {
    DIR* dp = opendir(src_dir);
    if (dp == NULL) {
        printf("Error: could not open source directory %s\n", src_dir);
        exit(1);
    }

    struct dirent* entry;
    while ((entry = readdir(dp)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char src_path[1000];
        sprintf(src_path, "%s/%s", src_dir, entry->d_name);

        char dest_path[1000];
        sprintf(dest_path, "%s/%s", dest_dir, entry->d_name);

        if (entry->d_type == DT_DIR) {
            sync_files(src_path, dest_path);
        } else {
            FILE* src_file = fopen(src_path, "rb");
            if (src_file == NULL) {
                printf("Error: could not open source file %s\n", src_path);
                continue;
            }

            FILE* dest_file = fopen(dest_path, "rb");
            if (dest_file != NULL) {
                fclose(dest_file);

                int choice;
                printf("File %s already exists in destination directory, do you want to overwrite it? (1 = Yes, 0 = No): ", entry->d_name);
                scanf("%d", &choice);

                if (choice == 0) {
                    fclose(src_file);
                    continue;
                }
            }

            dest_file = fopen(dest_path, "wb");
            if (dest_file == NULL) {
                printf("Error: could not create destination file %s\n", dest_path);
                fclose(src_file);
                continue;
            }

            char buffer[4096];
            size_t nread;
            while ((nread = fread(buffer, 1, sizeof(buffer), src_file)) > 0) {
                fwrite(buffer, 1, nread, dest_file);
            }

            fclose(src_file);
            fclose(dest_file);
            printf("Copied file %s from %s to %s\n", entry->d_name, src_dir, dest_dir);
        }
    }

    closedir(dp);
}