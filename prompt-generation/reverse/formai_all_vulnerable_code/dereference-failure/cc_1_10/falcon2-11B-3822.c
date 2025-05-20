//Falcon2-11B DATASET v1.0 Category: Metadata Extractor ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

int main()
{
    DIR *dirp;
    struct dirent *entry;
    struct stat file_stat;
    char *file_path;
    char *metadata;
    int file_size;

    dirp = opendir(".");
    if (dirp == NULL)
    {
        printf("Error: Could not open the current directory.\n");
        return 1;
    }

    while ((entry = readdir(dirp))!= NULL)
    {
        if (entry->d_type == DT_REG)
        {
            file_path = malloc(sizeof(char) * 256);
            strncpy(file_path, entry->d_name, 256);
            stat(file_path, &file_stat);
            if (S_ISREG(file_stat.st_mode))
            {
                file_size = (int) file_stat.st_size;
                metadata = malloc(file_size + 1);
                metadata[file_size] = '\0';
                if (read(file_stat.st_dev, metadata, file_size) < 0)
                {
                    printf("Error: Could not read the file.\n");
                    free(metadata);
                    free(file_path);
                    return 1;
                }
                printf("File: %s\n", file_path);
                printf("Size: %d bytes\n", file_size);
                printf("Metadata: %s\n", metadata);
                free(metadata);
                free(file_path);
            }
        }
    }

    closedir(dirp);
    return 0;
}