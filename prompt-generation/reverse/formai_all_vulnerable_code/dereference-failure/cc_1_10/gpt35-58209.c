//FormAI DATASET v1.0 Category: File Backup System ; Style: brave
// Brave style File Backup System Example program in C

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFFER_SIZE 512

int main(int argc, char *argv[])
{
    char src_path[BUFFER_SIZE];
    char dst_path[BUFFER_SIZE];
    char copy_command[BUFFER_SIZE];
    FILE *src_file;
    FILE *dst_file;

    // get source and destination paths from command line arguments
    if (argc != 3) {
        printf("Usage: %s source_file destination_file\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // copy source path to src_path variable
    strcpy(src_path, argv[1]);

    // copy destination path to dst_path variable
    strcpy(dst_path, argv[2]);

    // open source file
    src_file = fopen(src_path, "r");
    if (src_file == NULL) {
        printf("Error opening source file\n");
        exit(EXIT_FAILURE);
    }

    // open destination file for writing
    dst_file = fopen(dst_path, "w");
    if (dst_file == NULL) {
        printf("Error opening destination file\n");
        exit(EXIT_FAILURE);
    }

    // read source file and write to destination
    int read_count;
    char buffer[BUFFER_SIZE];
    while ((read_count = fread(buffer, 1, BUFFER_SIZE, src_file)) > 0) {
        fwrite(buffer, 1, read_count, dst_file);
    }

    // close files
    fclose(src_file);
    fclose(dst_file);

    // print success message
    printf("File backup successful!\n");

    // exit program
    exit(EXIT_SUCCESS);
}