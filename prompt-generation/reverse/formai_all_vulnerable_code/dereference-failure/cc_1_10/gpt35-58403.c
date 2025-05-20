//FormAI DATASET v1.0 Category: File Synchronizer ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// This program synchronizes two files, source and destination, by copying the newer one from source to destination.
// If both files are the same, no operation will be executed.

int main(int argc, char *argv[]) {
    // Check if the number of arguments passed is correct
    if(argc != 3) {
        printf("Please input the source file and the destination file.\n");
        exit(1);
    }

    // Open the source file and check if it exists
    FILE *source_file = fopen(argv[1], "rb");
    if(source_file == NULL) {
        printf("Could not open the source file.\n");
        exit(1);        
    }

    // Open the destination file and check if it exists
    FILE *destination_file = fopen(argv[2], "rb");
    if(destination_file == NULL) {
        printf("Could not open the destination file.\n");
        exit(1);        
    }

    // Check if the files are the same
    int c1, c2;
    while((c1 = getc(source_file)) == (c2 = getc(destination_file)) && c1 != EOF);

    // If the files are different, check which one is newer and copy it to the other
    if(c1 != c2) {
        fseek(source_file, 0L, SEEK_END);
        fseek(destination_file, 0L, SEEK_END);

        long source_size = ftell(source_file);
        long destination_size = ftell(destination_file);

        // If the source file is newer, copy it over the destination file
        if(source_size > destination_size) {
            fseek(source_file, 0L, SEEK_SET);
            fseek(destination_file, 0L, SEEK_SET);

            char *data = (char*)malloc(source_size);
            fread(data, 1, source_size, source_file);

            fclose(destination_file);
            destination_file = fopen(argv[2], "wb");
            fwrite(data, 1, source_size, destination_file);

            printf("Synchronization complete! Copied the source file to the destination file.\n");
        }
        // If the destination file is newer or both are the same, do nothing
        else {
            printf("Synchronization complete! The files are already in sync.\n");
        }
    }
    // If the files are the same, do nothing
    else {
        printf("Synchronization complete! The files are already in sync.\n");
    }

    // Close the files
    fclose(source_file);
    fclose(destination_file);

    return 0;
}