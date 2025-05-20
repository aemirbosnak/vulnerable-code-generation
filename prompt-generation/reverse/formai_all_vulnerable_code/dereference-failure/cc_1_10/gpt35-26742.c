//FormAI DATASET v1.0 Category: File Synchronizer ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
* This program synchronizes the contents of two files and makes sure that they are identical.
* It reads the contents of the two files and compares them byte by byte.
* If any differences are found, the program updates the second file to match the first one.
*/

int main(int argc, char** argv){

    if(argc != 3){
        printf("Please specify two file names to synchronize!\n");
        return 1;
    }

    FILE *file1, *file2; // Declare file pointers
    int byte1, byte2; // Variables to store bytes read from files
    long diff_count = 0; // Counter for number of bytes that differ
    long file_size1, file_size2; // Variables for storing file sizes

    // Open file1 in read mode
    file1 = fopen(argv[1], "rb");
    if(file1 == NULL){
        printf("Error opening %s for reading!\n", argv[1]);
        return 1;
    }

    // Open file2 in read/write mode
    file2 = fopen(argv[2], "r+b");
    if(file2 == NULL){
        printf("Error opening %s for read/write!\n", argv[2]);
        return 1;
    }

    // Get the size of file1
    fseek(file1, 0, SEEK_END);
    file_size1 = ftell(file1);
    fseek(file1, 0, SEEK_SET);

    // Get the size of file2
    fseek(file2, 0, SEEK_END);
    file_size2 = ftell(file2);
    fseek(file2, 0, SEEK_SET);

    // If the files are not the same size, exit the program
    if(file_size1 != file_size2) {
        printf("The two files are not the same size!\n");
        return 1;
    }

    // Loop through the files and compare byte by byte
    while((byte1 = getc(file1)) != EOF && (byte2 = getc(file2)) != EOF){
        if(byte1 != byte2){
            diff_count++;
            // Update file2 to match file1
            fseek(file2, -1, SEEK_CUR);
            putc(byte1, file2);
        }
    }

    // Close the files
    fclose(file1);
    fclose(file2);

    // Print a summary of the synchronization process
    if(diff_count > 0){
        printf("%ld bytes differed between the two files. Synchronization complete!\n", diff_count);
    } else {
        printf("The two files are already synchronized!\n");
    }

    return 0;
}