//Falcon2-11B DATASET v1.0 Category: File Synchronizer ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 100

int main(int argc, char **argv)
{
    char src_file[MAX_FILE_NAME_LENGTH];
    char dest_file[MAX_FILE_NAME_LENGTH];
    FILE *src_file_ptr, *dest_file_ptr;

    if (argc!= 3)
    {
        printf("Usage: %s <source file> <destination file>\n", argv[0]);
        return 1;
    }

    strcpy(src_file, argv[1]);
    strcpy(dest_file, argv[2]);

    src_file_ptr = fopen(src_file, "r");
    if (src_file_ptr == NULL)
    {
        printf("Error opening source file: %s\n", src_file);
        return 1;
    }

    dest_file_ptr = fopen(dest_file, "w");
    if (dest_file_ptr == NULL)
    {
        printf("Error opening destination file: %s\n", dest_file);
        fclose(src_file_ptr);
        return 1;
    }

    char buffer[MAX_FILE_NAME_LENGTH];
    while (!feof(src_file_ptr))
    {
        fgets(buffer, MAX_FILE_NAME_LENGTH, src_file_ptr);
        fputs(buffer, dest_file_ptr);
    }

    fclose(src_file_ptr);
    fclose(dest_file_ptr);

    printf("File synchronization completed successfully.\n");

    return 0;
}