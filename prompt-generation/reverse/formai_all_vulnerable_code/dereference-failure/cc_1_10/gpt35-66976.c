//FormAI DATASET v1.0 Category: Compression algorithms ; Style: satisfied
// Welcome to the unique C compression algorithm!
// This program utilizes a combination of ASCII values and bitwise operators to compress text files.

#include <stdio.h>
#include <stdlib.h>

void compress(char *filename) {
    FILE *input = fopen(filename, "r"); // open file for reading
    if (input == NULL) { // check if file exists
        fprintf(stderr, "Error: File does not exist.\n");
        return;
    }
    FILE *output = fopen("compressed.bin", "wb"); // open binary file for writing
    if (output == NULL) { // check if file was created successfully
        fprintf(stderr, "Error: Failed to create compressed file.\n");
        return;
    }
    char c, prev = '\0'; // initialize variables to hold characters
    unsigned int count = 1; // initialize counter
    while ((c = fgetc(input)) != EOF) { // read input file until end
        if (c == prev) { // character matches previous character
            count++; // increment counter
        } else { // character does not match previous character
            if (prev != '\0') { // write previous character and counter to binary output file
                fwrite(&prev, sizeof(char), 1, output);
                fwrite(&count, sizeof(unsigned int), 1, output);
            }
            prev = c; // update previous character
            count = 1; // reset counter
        }
    }
    // write last character and counter to binary output file
    fwrite(&prev, sizeof(char), 1, output);
    fwrite(&count, sizeof(unsigned int), 1, output);
    fclose(input); // close input file
    fclose(output); // close binary output file
}

void decompress(char *filename) {
    FILE *input = fopen("compressed.bin", "rb"); // open binary file for reading
    if (input == NULL) { // check if file exists
        fprintf(stderr, "Error: Compressed file does not exist.\n");
        return;
    }
    FILE *output = fopen(filename, "w"); // open file for writing
    if (output == NULL) { // check if file was created successfully
        fprintf(stderr, "Error: Failed to create decompressed file.\n");
        return;
    }
    char c; // initialize variable to hold characters
    unsigned int count; // initialize variable to hold counter
    while (fread(&c, sizeof(char), 1, input)) { // read binary input file
        fread(&count, sizeof(unsigned int), 1, input);
        for (int i = 0; i < count; i++) { // repeat character for counter value
            fputc(c, output); // write character to output file
        }
    }
    fclose(input); // close binary input file
    fclose(output); // close output file
}

int main() {
    char filename[256];
    printf("Enter name of file to compress: ");
    scanf("%s", filename);
    compress(filename); // compress file and write to binary file
    printf("File compression complete.\n");
    printf("Enter name of file to decompress: ");
    scanf("%s", filename);
    decompress(filename); // read compressed binary file and write decompressed file
    printf("File decompression complete.\n");
    return 0;
}