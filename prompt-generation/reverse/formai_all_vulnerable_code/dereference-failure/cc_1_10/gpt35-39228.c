//FormAI DATASET v1.0 Category: File Synchronizer ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

int sync_dir(char *source_dir, char *target_dir);

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        printf("Please specify source and target directories.\n");
        return 1;
    }

    char *source_dir = argv[1];
    char *target_dir = argv[2];

    int result = sync_dir(source_dir, target_dir);

    if (result == 0)
    {
        printf("Synchronization complete.\n");
    }
    else
    {
        printf("Synchronization failed.\n");
    }

    return 0;
}

int sync_dir(char *source_dir, char *target_dir)
{
    DIR *source_dp, *target_dp;
    struct dirent *source_entry, *target_entry;

    // Open source and target directories
    source_dp = opendir(source_dir);
    if (source_dp == NULL)
    {
        printf("Error: Unable to open source directory '%s'\n", source_dir);
        return 1;
    }

    target_dp = opendir(target_dir);
    if (target_dp == NULL)
    {
        printf("Error: Unable to open target directory '%s'\n", target_dir);
        return 1;
    }

    // Loop through all source entries and synchronize them
    while ((source_entry = readdir(source_dp)) != NULL)
    {
        // Ignore . and .. entries
        if (strcmp(source_entry->d_name, ".") == 0 ||
            strcmp(source_entry->d_name, "..") == 0)
        {
            continue;
        }

        char source_path[1024];
        char target_path[1024];
        struct stat source_st, target_st;

        // Create source and target paths
        snprintf(source_path, sizeof(source_path), "%s/%s", source_dir, source_entry->d_name);
        snprintf(target_path, sizeof(target_path), "%s/%s", target_dir, source_entry->d_name);

        // Get source and target stats
        stat(source_path, &source_st);
        stat(target_path, &target_st);

        if (S_ISDIR(source_st.st_mode))
        {
            // Create target directory if it doesn't exist
            if (S_ISDIR(target_st.st_mode))
            {
                sync_dir(source_path, target_path);
            }
            else
            {
                mkdir(target_path, source_st.st_mode);
                sync_dir(source_path, target_path);
            }
        }
        else
        {
            // Copy file if it doesn't exist or is different size
            if (!S_ISREG(target_st.st_mode) || source_st.st_size != target_st.st_size)
            {
                FILE *source_fp, *target_fp;

                source_fp = fopen(source_path, "rb");
                target_fp = fopen(target_path, "wb");

                if (source_fp == NULL || target_fp == NULL)
                {
                    printf("Error: Unable to open file '%s' or '%s'\n", source_path, target_path);
                    continue;
                }

                char buffer[1024];
                size_t bytes_read;

                while ((bytes_read = fread(buffer, 1, sizeof(buffer), source_fp)) > 0)
                {
                    fwrite(buffer, 1, bytes_read, target_fp);
                }

                fclose(source_fp);
                fclose(target_fp);
            }
        }
    }

    // Close directories
    closedir(source_dp);
    closedir(target_dp);

    return 0;
}