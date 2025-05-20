//FormAI DATASET v1.0 Category: System administration ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>

void print_directory_contents(const char *path, int indent)
{
    DIR *dir = opendir(path);

    if (dir == NULL)
    {
        perror("Unable to opendir");
        exit(EXIT_FAILURE);
    }

    struct dirent *dir_entry;

    while ((dir_entry = readdir(dir)) != NULL)
    {
        if (dir_entry->d_type == DT_DIR)
        {
            if (strcmp(dir_entry->d_name, ".") == 0 || strcmp(dir_entry->d_name, "..") == 0)
            {
                continue;
            }

            printf("%*s%s/\n", indent, "", dir_entry->d_name);

            char new_path[1024];
            snprintf(new_path, sizeof(new_path), "%s/%s", path, dir_entry->d_name);

            print_directory_contents(new_path, indent + 4);
        }
        else
        {
            printf("%*s%s\n", indent, "", dir_entry->d_name);
        }
    }

    closedir(dir);
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    print_directory_contents(argv[1], 0);

    return EXIT_SUCCESS;
}