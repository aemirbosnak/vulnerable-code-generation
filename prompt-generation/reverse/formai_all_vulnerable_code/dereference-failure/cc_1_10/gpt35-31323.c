//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Welcome to the Cheerful C Disk Space Analyzer!\n");

    char c, *filename;
    long long int file_size = 0, total_size = 0, dir_count = 0, file_count = 0;

    printf("Please enter the file or directory name to analyze: ");
    scanf("%ms", &filename);

    FILE *fp = fopen(filename, "r");

    if (fp == NULL)
    {
        printf("Oops! Cannot open file '%s'\n", filename);
        return 1;
    }

    while ((c = fgetc(fp)) != EOF)
    {
        if (c == '/')
        {
            dir_count++;
        }
        else if (c == '\n')
        {
            file_count++;
            total_size += file_size;
            file_size = 0;
        }
        else
        {
            file_size++;
        }
    }

    fclose(fp);
    free(filename);

    printf("\nAnalysis of '%s':\n", filename);
    printf("- Total Directories: %lld\n", dir_count);
    printf("- Total Files: %lld\n", file_count);
    printf("- Total File Size: %lld bytes\n", total_size);

    printf("\nThank you for using the Cheerful C Disk Space Analyzer! Have a nice day!\n");

    return 0;
}