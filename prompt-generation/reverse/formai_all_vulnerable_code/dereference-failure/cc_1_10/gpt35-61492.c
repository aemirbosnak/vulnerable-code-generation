//FormAI DATASET v1.0 Category: File Synchronizer ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_FILENAME_LENGTH 256
#define MAX_BUFFER_LENGTH 1024

void sync_files(char *src_path, char *dst_path);
bool is_directory(const char *path);
bool file_exists(const char *path);
bool copy_file(const char *src_path, const char *dst_path);
void copy_directory(const char *src_path, const char *dst_path);

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Usage: file_sync <source_path> <destination_path>\n");
        return 1;
    }

    sync_files(argv[1], argv[2]);

    printf("File synchronization complete!\n");

    return 0;
}

void sync_files(char *src_path, char *dst_path)
{
    DIR *dir;

    if (!(dir = opendir(src_path)))
    {
        printf("Unable to open source directory %s: %s\n", src_path, strerror(errno));
        return;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL)
    {
        if (entry->d_type == DT_DIR)
        {
            // Skip "." and ".." directories
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            {
                continue;
            }

            // Recursively copy subdirectory
            char src_subdir[MAX_FILENAME_LENGTH], dst_subdir[MAX_FILENAME_LENGTH];
            snprintf(src_subdir, sizeof(src_subdir), "%s/%s", src_path, entry->d_name);
            snprintf(dst_subdir, sizeof(dst_subdir), "%s/%s", dst_path, entry->d_name);

            if (!is_directory(dst_subdir))
            {
                if (file_exists(dst_subdir))
                {
                    printf("%s is not a directory\n");
                    return;
                }

                // Create destination directory if it doesn't exist
                if (mkdir(dst_subdir, 0755) == -1)
                {
                    printf("Unable to create destination directory %s: %s\n", dst_subdir, strerror(errno));
                    return;
                }
            }

            // Recursively copy subdirectory
            copy_directory(src_subdir, dst_subdir);
        }
        else
        {
            // Copy regular file
            char src_file[MAX_FILENAME_LENGTH], dst_file[MAX_FILENAME_LENGTH];
            snprintf(src_file, sizeof(src_file), "%s/%s", src_path, entry->d_name);
            snprintf(dst_file, sizeof(dst_file), "%s/%s", dst_path, entry->d_name);

            copy_file(src_file, dst_file);
        }
    }

    closedir(dir);
}

bool is_directory(const char *path)
{
    struct stat st;
    if (stat(path, &st) == -1)
    {
        return false;
    }

    return S_ISDIR(st.st_mode);
}

bool file_exists(const char *path)
{
    return access(path, F_OK) != -1;
}

bool copy_file(const char *src_path, const char *dst_path)
{
    FILE *src = fopen(src_path, "r");
    if (!src)
    {
        printf("Unable to open source file %s: %s\n", src_path, strerror(errno));
        return false;
    }

    FILE *dst = fopen(dst_path, "w");
    if (!dst)
    {
        printf("Unable to create destination file %s: %s\n", dst_path, strerror(errno));
        fclose(src);
        return false;
    }

    char buffer[MAX_BUFFER_LENGTH];
    size_t bytes;

    while ((bytes = fread(buffer, sizeof(char), sizeof(buffer), src)) > 0)
    {
        fwrite(buffer, sizeof(char), bytes, dst);
    }

    fclose(dst);
    fclose(src);

    return true;
}

void copy_directory(const char *src_path, const char *dst_path)
{
    DIR *dir;
    if (!(dir = opendir(src_path)))
    {
        printf("Unable to open source directory %s: %s\n", src_path, strerror(errno));
        return;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL)
    {
        if (entry->d_type == DT_DIR)
        {
            // Skip "." and ".." directories
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            {
                continue;
            }

            char src_subdir[MAX_FILENAME_LENGTH], dst_subdir[MAX_FILENAME_LENGTH];
            snprintf(src_subdir, sizeof(src_subdir), "%s/%s", src_path, entry->d_name);
            snprintf(dst_subdir, sizeof(dst_subdir), "%s/%s", dst_path, entry->d_name);

            if (!is_directory(dst_subdir))
            {
                if (file_exists(dst_subdir))
                {
                    printf("%s is not a directory\n");
                    return;
                }

                // Create destination directory if it doesn't exist
                if (mkdir(dst_subdir, 0755) == -1)
                {
                    printf("Unable to create destination directory %s: %s\n", dst_subdir, strerror(errno));
                    return;
                }
            }

            copy_directory(src_subdir, dst_subdir);
        }
        else
        {
            // Copy regular file
            char src_file[MAX_FILENAME_LENGTH], dst_file[MAX_FILENAME_LENGTH];
            snprintf(src_file, sizeof(src_file), "%s/%s", src_path, entry->d_name);
            snprintf(dst_file, sizeof(dst_file), "%s/%s", dst_path, entry->d_name);

            copy_file(src_file, dst_file);
        }
    }

    closedir(dir);
}