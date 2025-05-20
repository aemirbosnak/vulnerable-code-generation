//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <stdbool.h>

#define MAX_SIZE 1024

bool is_regular_file(const char *path)
{
    struct stat path_stat;
    stat(path, &path_stat);
    return S_ISREG(path_stat.st_mode);
}

long long int get_directory_size(const char *path)
{
    long long int size = 0;
    DIR *dir;
    struct dirent *entry;

    dir = opendir(path);
    if (dir == NULL)
    {
        printf("Error: Unable to open directory %s\n", path);
        return 0;
    }

    while ((entry = readdir(dir)) != NULL)
    {
        char *fullpath = NULL;
        fullpath = (char *)malloc(strlen(path) + strlen(entry->d_name) + 2);
        if (fullpath != NULL)
        {
            sprintf(fullpath, "%s/%s", path, entry->d_name);
            if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0)
            {
                if (is_regular_file(fullpath))
                {
                    struct stat st;
                    if (stat(fullpath, &st) == 0)
                    {
                        size += st.st_size;
                    }
                }
                else if (entry->d_type == DT_DIR)
                {
                    size += get_directory_size(fullpath);
                }
            }
            free(fullpath);
        }
    }

    closedir(dir);

    return size;
}

char *format_size(long long int size)
{
    char *formatted = NULL;
    int unit = 0;
    char *units[] = {"B", "KB", "MB", "GB", "TB"};

    while (size > 1024 && unit < 4)
    {
        size /= 1024;
        unit++;
    }

    formatted = (char *)malloc(MAX_SIZE);
    sprintf(formatted, "%lld %s", size, units[unit]);

    return formatted;
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s <Directory Path>\n", argv[0]);
        return 0;
    }

    long long int size = get_directory_size(argv[1]);
    char *formatted_size = format_size(size);

    printf("%s\n", formatted_size);

    free(formatted_size);

    return 0;
}