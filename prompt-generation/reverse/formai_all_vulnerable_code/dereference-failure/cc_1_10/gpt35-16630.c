//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

#define PRINT_HR "--------------------------------------------------------------------------\n"

void analyze_directory(const char* path, unsigned long long* total_size)
{
    struct dirent* dir_entry;
    DIR* dir = opendir(path);

    if (dir == NULL)
    {
        printf("Could not open directory: %s\n", path);
        return;
    }

    while ((dir_entry = readdir(dir)) != NULL)
    {
        char entry_path[1024];
        snprintf(entry_path, 1024, "%s/%s", path, dir_entry->d_name);

        if (dir_entry->d_type == DT_DIR && (strcmp(dir_entry->d_name, ".") != 0 && strcmp(dir_entry->d_name, "..") != 0))
        {
            analyze_directory(entry_path, total_size);
        }
        else
        {
            FILE* file = fopen(entry_path, "rb");

            if (file == NULL)
            {
                printf("Could not open file: %s\n", entry_path);
                continue;
            }

            fseek(file, 0L, SEEK_END);
            unsigned long long file_size = ftell(file);

            (*total_size) += file_size;

            fclose(file);
        }
    }

    closedir(dir);
}

int main(int argc, char** argv)
{
    if (argc < 2)
    {
        printf("Usage: %s path/to/directory\n", argv[0]);
        return 0;
    }

    unsigned long long total_size = 0ULL;

    analyze_directory(argv[1], &total_size);

    printf(PRINT_HR);
    printf("| %-30s | %-20s |\n", "Directory", "Size");
    printf(PRINT_HR);
    printf("| %-30s | %-20llu |\n", argv[1], total_size);
    printf(PRINT_HR);

    return 0;
}