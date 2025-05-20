//FormAI DATASET v1.0 Category: File Synchronizer ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PATH_LEN 1024 // Define the maximum path length

/**
 * This function returns a boolean value indicating whether the given path is a directory or not.
 */
int is_directory(const char *path)
{
    struct stat buffer;
    if (stat(path, &buffer) == 0)
    {
        return S_ISDIR(buffer.st_mode);
    }
    return 0;
}

/**
 * This function synchronizes two directories by copying newer/changed files from the source directory to the destination directory.
 */
void synchronize_directories(const char *src_path, const char *dst_path)
{
    DIR *src_dir, *dst_dir;
    struct dirent *src_ent, *dst_ent;
    struct stat src_ent_stat, dst_ent_stat;

    if ((src_dir = opendir(src_path)) == NULL)
    {
        printf("Error: cannot open source directory '%s'\n", src_path);
        return;
    }

    if ((dst_dir = opendir(dst_path)) == NULL)
    {
        printf("Error: cannot open destination directory '%s'\n", dst_path);
        closedir(src_dir);
        return;
    }

    while ((src_ent = readdir(src_dir)) != NULL)
    {
        if (strcmp(src_ent->d_name, ".") == 0 || strcmp(src_ent->d_name, "..") == 0)
        {
            continue;
        }

        char src_ent_path[MAX_PATH_LEN];
        strcpy(src_ent_path, src_path);
        strcat(src_ent_path, "/");
        strcat(src_ent_path, src_ent->d_name);

        if (is_directory(src_ent_path)) // If the source entry is a directory, recursively call this function with the corresponding destination directory path, else proceed to syncing
        {
            char dst_ent_path[MAX_PATH_LEN];
            strcpy(dst_ent_path, dst_path);
            strcat(dst_ent_path, "/");
            strcat(dst_ent_path, src_ent->d_name);
            synchronize_directories(src_ent_path, dst_ent_path);
        }
        else
        {
            int src_ent_mtime = stat(src_ent_path, &src_ent_stat) == 0 ? src_ent_stat.st_mtime : 0; // Get the modification time of the source entry
            int dst_ent_mtime = 0;

            while ((dst_ent = readdir(dst_dir)) != NULL) // Search for a matching destination entry in the destination directory
            {
                if (strcmp(dst_ent->d_name, ".") == 0 || strcmp(dst_ent->d_name, "..") == 0)
                {
                    continue;
                }

                char dst_ent_path[MAX_PATH_LEN];
                strcpy(dst_ent_path, dst_path);
                strcat(dst_ent_path, "/");
                strcat(dst_ent_path, dst_ent->d_name);

                if (strcmp(src_ent->d_name, dst_ent->d_name) == 0)
                {
                    dst_ent_mtime = fstat(dirfd(dst_dir), &dst_ent_stat) == 0 ? dst_ent_stat.st_mtime : 0; // Get the modification time of the matching destination entry
                    break;
                }
            }

            if (dst_ent == NULL || src_ent_mtime > dst_ent_mtime) // If a matching destination entry doesn't exist or the source entry is newer/changed, copy the source entry to the destination directory
            {
                char dst_ent_path[MAX_PATH_LEN];
                strcpy(dst_ent_path, dst_path);
                strcat(dst_ent_path, "/");
                strcat(dst_ent_path, src_ent->d_name);

                FILE *src_file = fopen(src_ent_path, "rb");
                FILE *dst_file = fopen(dst_ent_path, "wb");

                if (src_file == NULL || dst_file == NULL)
                {
                    printf("Error: cannot open file for copying\n");
                    closedir(src_dir);
                    closedir(dst_dir);
                    return;
                }

                char buffer[1024];
                size_t read_size = fread(buffer, 1, sizeof(buffer), src_file);
                while (read_size > 0)
                {
                    fwrite(buffer, 1, read_size, dst_file);
                    read_size = fread(buffer, 1, sizeof(buffer), src_file);
                }

                fclose(src_file);
                fclose(dst_file);

                printf("Copied file from '%s' to '%s'\n", src_ent_path, dst_ent_path);
            }
        }
    }

    closedir(src_dir);
    closedir(dst_dir);
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Usage: %s <source_directory> <destination_directory>\n", argv[0]);
        return 1;
    }

    synchronize_directories(argv[1], argv[2]);

    return 0;
}