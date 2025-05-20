//FormAI DATASET v1.0 Category: File Backup System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main(int argc, char **argv) {
    // check if file names are provided
    if(argc < 3) {
        printf("Usage: backup <source-file> <destination-file>\n");
        return 1;
    }

    // open source file
    FILE *source_file = fopen(argv[1], "rb");
    if(source_file == NULL) {
        printf("Error: could not open file %s\n", argv[1]);
        return 1;
    }

    // open destination file
    FILE *destination_file = fopen(argv[2], "wb");
    if(destination_file == NULL) {
        printf("Error: could not create file %s\n", argv[2]);
        return 1;
    }

    // create buffer for copying
    char buffer[BUFFER_SIZE];

    // copy contents from source to destination
    size_t read_count, write_count;
    while((read_count = fread(buffer, 1, BUFFER_SIZE, source_file)) > 0) {
        write_count = fwrite(buffer, 1, read_count, destination_file);

        // check for write errors
        if(write_count != read_count) {
            printf("Error: could not write to file %s\n", argv[2]);
            fclose(source_file);
            fclose(destination_file);
            return 1;
        }
    }

    // close files
    fclose(source_file);
    fclose(destination_file);

    printf("Backup successful!\n");
    return 0;
}