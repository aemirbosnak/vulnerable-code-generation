//Gemma-7B DATASET v1.0 Category: File Synchronizer ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

#define MAX_FILES 10

int main()
{
    int i, j, files_count = 0;
    char **files_list = NULL;
    FILE **file_handles = NULL;
    struct stat file_stats[MAX_FILES];

    files_list = malloc(MAX_FILES * sizeof(char *));
    file_handles = malloc(MAX_FILES * sizeof(FILE *));

    for (i = 0; i < MAX_FILES; i++)
    {
        files_list[i] = NULL;
        file_handles[i] = NULL;
    }

    while (files_count < MAX_FILES)
    {
        printf("Enter file name: ");
        files_list[files_count] = malloc(256);
        scanf("%s", files_list[files_count]);

        file_handles[files_count] = fopen(files_list[files_count], "r");

        if (file_handles[files_count] == NULL)
        {
            printf("Error opening file.\n");
            exit(1);
        }

        stat(files_list[files_count], &file_stats[files_count]);

        files_count++;
    }

    printf("File list:\n");
    for (i = 0; i < files_count; i++)
    {
        printf("%s (size: %d bytes)\n", files_list[i], file_stats[i].st_size);
    }

    for (i = 0; i < files_count; i++)
    {
        fclose(file_handles[i]);
        free(files_list[i]);
    }

    free(files_list);
    free(file_handles);

    return 0;
}