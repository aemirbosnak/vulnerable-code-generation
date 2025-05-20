//FormAI DATASET v1.0 Category: File Backup System ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main(int argc, char **argv)
{
    FILE *source_file_ptr, *backup_file_ptr;
    char *source_file_path, *backup_file_path;
    char buffer[BUFFER_SIZE];
    size_t read_size;

    // check for valid command line arguments
    if (argc < 3) {
        fprintf(stderr, "Usage: %s source_file_path backup_file_path\n", argv[0]);
        exit(EXIT_FAILURE);
    } else {
        source_file_path = argv[1];
        backup_file_path = argv[2];
    }

    // open source file for reading
    source_file_ptr = fopen(source_file_path, "rb");
    if (source_file_ptr == NULL) {
        perror("Failed to open source file");
        exit(EXIT_FAILURE);
    }

    // open backup file for writing
    backup_file_ptr = fopen(backup_file_path, "wb");
    if (backup_file_ptr == NULL) {
        perror("Failed to open backup file");
        exit(EXIT_FAILURE);
    }

    // read from source file and write to backup file
    while ((read_size = fread(buffer, 1, BUFFER_SIZE, source_file_ptr)) > 0) {
        fwrite(buffer, 1, read_size, backup_file_ptr);
    }

    // close files
    fclose(source_file_ptr);
    fclose(backup_file_ptr);

    // print success message
    printf("File backup complete. The source file has been saved to '%s'.\n", backup_file_path);

    return 0;
}