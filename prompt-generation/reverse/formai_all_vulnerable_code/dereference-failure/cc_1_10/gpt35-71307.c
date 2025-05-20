//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: Linus Torvalds
#include <stdio.h>
#include <dirent.h>
#include <string.h>

void countDirectory(const char *dirname, int depth);

int main()
{
    printf("C Disk Space Analyzer\n\n");
    countDirectory("/", 0);
    return 0;
}

void countDirectory(const char *dirname, int depth)
{
    DIR *dir;
    struct dirent *entry;
    int total_bytes = 0, num_files = 0, num_dirs = 0;

    if (!(dir = opendir(dirname)))
    {
        fprintf(stderr, "Cannot open directory '%s'\n", dirname);
        return;
    }

    while ((entry = readdir(dir)) != NULL)
    {
        if (entry->d_type == DT_DIR)
        {
            char path[1024];
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
                continue;
            snprintf(path, sizeof(path), "%s/%s", dirname, entry->d_name);
            countDirectory(path, depth + 1);
            num_dirs++;
        }
        else
        {
            char path[1024];
            snprintf(path, sizeof(path), "%s/%s", dirname, entry->d_name);
            FILE *file = fopen(path, "rb");
            if (file)
            {
                fseek(file, 0L, SEEK_END);
                int file_size = ftell(file);
                total_bytes += file_size;
                num_files++;
                fclose(file);
            }
        }
    }

    closedir(dir);

    if (depth == 0)
    {
        printf("%-50s %10s %15s %15s\n", "Directory", "# of Files", "# of Directories", "Total Bytes");
        printf("%-50s %10s %15s %15s\n", "---------", "----------", "---------------", "-----------");
    }

    printf("%-50s %10d %15d %15d\n", dirname, num_files, num_dirs, total_bytes);
}