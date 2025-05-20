//FormAI DATASET v1.0 Category: Image compression ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// This program compresses an image using the "squish and squeeze" algorithm

int main() {
    printf("Welcome to the Squish and Squeeze Image Compression Tool!\n");
    printf("Please enter the name of the image you wish to compress: ");

    char filename[50];
    scanf("%s", filename);

    // Let's open the file and check if it exists
    FILE* file_ptr = fopen(filename, "r");
    if (file_ptr == NULL) {
        printf("Oops! The file doesn't exist. Please try again.\n");
        return 0; // Better luck next time
    }

    // First, we need to find out the size of the file
    fseek(file_ptr, 0L, SEEK_END);
    int file_size = ftell(file_ptr);
    rewind(file_ptr);

    // Let's allocate memory dynamically to store the file data
    char* file_data = (char*) malloc(file_size * sizeof(char));
    fread(file_data, sizeof(char), file_size, file_ptr);
    fclose(file_ptr);

    // Now, for the fun part! Let's compress the image!
    // Squish and squeeze algorithm: take any repeated character sequences and replace them with a single character followed by a number indicating the number of times it should be repeated
    
    char compressed_data[2*file_size]; // we'll allocate double the size just to be safe!
    int compressed_index = 0; // the index where the compressed data will be stored

    char current_char = file_data[0];
    int count = 1;

    for (int i = 1; i < file_size; i++) {
        if (file_data[i] == current_char) {
            count++;
        } else {
            compressed_data[compressed_index++] = current_char;
            compressed_data[compressed_index++] = count + '0'; // convert count to ASCII code
            current_char = file_data[i];
            count = 1;
        }
    }

    // Let's not forget the last character sequence
    compressed_data[compressed_index++] = current_char;
    compressed_data[compressed_index++] = count + '0';

    // Time to write the compressed data to a new file
    char new_filename[50];
    strcpy(new_filename, "compressed_");
    strcat(new_filename, filename);

    FILE* new_file_ptr = fopen(new_filename, "w");
    fwrite(compressed_data, sizeof(char), compressed_index, new_file_ptr);
    fclose(new_file_ptr);

    printf("Your image has been successfully compressed and saved as %s\n", new_filename);
    printf("Thank you for using our tool!\n");

    free(file_data);

    return 0;
}