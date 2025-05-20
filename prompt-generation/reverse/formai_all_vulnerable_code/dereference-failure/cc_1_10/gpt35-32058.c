//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

void analyze_directory(char* path);
void analyze_file(char* path);

int main(int argc, char *argv[])
{
    if(argc < 2)
    {
        printf("Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    analyze_directory(argv[1]);

    return 0;
}

void analyze_directory(char* path)
{
    DIR* directory;
    struct dirent* dir_entry;

    if((directory = opendir(path)) != NULL)
    {
        while((dir_entry = readdir(directory)) != NULL)
        {
            char entry_path[1024];
            sprintf(entry_path, "%s/%s", path, dir_entry->d_name);

            if(dir_entry->d_type == DT_DIR)
            {
                if(strcmp(dir_entry->d_name, ".") == 0 || strcmp(dir_entry->d_name, "..") == 0)
                {
                    continue;
                }

                analyze_directory(entry_path);
            }
            else
            {
                analyze_file(entry_path);
            }
        }

        closedir(directory);
    }
    else
    {
        perror("Error opening directory");
    }
}

void analyze_file(char* path)
{
    struct stat file_stats;

    if(stat(path, &file_stats) == 0)
    {
        printf("%s: %lld bytes\n", path, file_stats.st_size);
    }
    else
    {
        perror("Error getting file stats");
    }
}