//FormAI DATASET v1.0 Category: File Synchronizer ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define TRUE 1
#define FALSE 0

void sync_files(char *source, char *dest, char *ext)
{
    DIR *dir;
    struct dirent *entry;

    // Open directory for source files
    if ((dir = opendir(source)) == NULL)
    {
        perror("Error opening source directory.");
        exit(EXIT_FAILURE);
    }

    // Traverse through entries in directory
    while ((entry = readdir(dir)) != NULL)
    {
        char src_path[100], dest_path[100];
        struct stat s;

        // Ignore special directories
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;

        // Construct source and destination paths
        sprintf(src_path, "%s/%s", source, entry->d_name);
        sprintf(dest_path, "%s/%s", dest, entry->d_name);

        // Get file statistics
        if (stat(src_path, &s) == -1)
        {
            perror("Error getting file statistics.");
            exit(EXIT_FAILURE);
        }

        // Recursively sync subdirectories
        if (S_ISDIR(s.st_mode))
        {   
            sync_files(src_path, dest_path, ext);
        }
        else
        {
            // Check file extension
            char *file_ext = strrchr(entry->d_name, '.');
            if (file_ext != NULL && strcmp(file_ext, ext) == 0)
            {
                // Check if files are different
                FILE *f1 = fopen(src_path, "rb");
                FILE *f2 = fopen(dest_path, "rb");

                if (f1 == NULL || f2 == NULL)
                {
                    perror("Error opening files.");
                    exit(EXIT_FAILURE);
                }

                fseek(f1, 0L, SEEK_END);
                int f1_size = ftell(f1);
                fseek(f1, 0L, SEEK_SET);

                fseek(f2, 0L, SEEK_END);
                int f2_size = ftell(f2);
                fseek(f2, 0L, SEEK_SET);

                if (f1_size != f2_size)
                {
                    // Copy file from source to destination
                    FILE *f_dest = fopen(dest_path, "wb");
                    fprintf(f_dest, "%s", "");

                    int c;
                    FILE *f_src = fopen(src_path, "rb");
                    while ((c = fgetc(f_src)) != EOF)
                    {
                        fputc(c, f_dest);
                    }

                    fclose(f_src);
                    fclose(f_dest);

                    printf("%s copied to %s.\n", src_path, dest_path);
                }
                else
                {
                    // Compare contents of source and destination files
                    int same = TRUE;
                    int c1, c2;

                    while ((c1 = fgetc(f1)) != EOF && (c2 = fgetc(f2)) != EOF)
                    {
                        if (c1 != c2)
                        {
                            same = FALSE;
                            break;
                        }
                    }

                    fclose(f1);
                    fclose(f2);

                    if (!same)
                    {
                        // Copy file from source to destination
                        FILE *f_dest = fopen(dest_path, "wb");
                        fprintf(f_dest, "%s", "");

                        int c;
                        FILE *f_src = fopen(src_path, "rb");
                        while ((c = fgetc(f_src)) != EOF)
                        {
                            fputc(c, f_dest);
                        }

                        fclose(f_src);
                        fclose(f_dest);

                        printf("%s synced to %s.\n", src_path, dest_path);
                    }
                }
            }
        }
    }

    closedir(dir);
}

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        printf("Usage: %s [source folder] [destination folder] [file extension]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *source = argv[1];
    char *dest = argv[2];
    char *ext = argv[3];

    sync_files(source, dest, ext);

    printf("Files with extension %s in %s synced with %s.\n", ext, source, dest);

    return 0;
}