//GEMINI-pro DATASET v1.0 Category: Metadata Extractor ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *filename = argv[1];

    // Get file information
    struct stat file_info;
    if (stat(filename, &file_info) != 0)
    {
        perror("stat");
        return EXIT_FAILURE;
    }

    // Print file metadata
    printf("File: %s\n", filename);
    printf("Size: %ld bytes\n", file_info.st_size);
    printf("Permissions: %o\n", file_info.st_mode);
    printf("Owner: %d\n", file_info.st_uid);
    printf("Group: %d\n", file_info.st_gid);
    printf("Last modified: %s", ctime(&file_info.st_mtime));

    // Get file extension
    char *extension = strrchr(filename, '.');
    if (extension != NULL)
    {
        printf("Extension: %s\n", extension + 1);
    }

    // Check if file is a regular file
    if (!S_ISREG(file_info.st_mode))
    {
        fprintf(stderr, "%s is not a regular file.\n", filename);
        return EXIT_FAILURE;
    }

    // Open file
    FILE *fp = fopen(filename, "r");
    if (fp == NULL)
    {
        perror("fopen");
        return EXIT_FAILURE;
    }

    // Read first 100 bytes of file
    char buffer[101];
    size_t bytes_read = fread(buffer, 1, 100, fp);
    fclose(fp);

    // Check if file contains any text
    int contains_text = 0;
    for (size_t i = 0; i < bytes_read; i++)
    {
        if (isprint(buffer[i]))
        {
            contains_text = 1;
            break;
        }
    }

    if (contains_text)
    {
        printf("File contains text.\n");
    }
    else
    {
        printf("File does not contain any text.\n");
    }

    return EXIT_SUCCESS;
}