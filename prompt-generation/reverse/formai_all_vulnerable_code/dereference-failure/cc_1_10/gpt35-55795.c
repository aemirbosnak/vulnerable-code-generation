//FormAI DATASET v1.0 Category: Compression algorithms ; Style: shocked
#include <stdio.h>

int main() {
    printf("What in the world is this?! A C compression algorithm!\n");
    printf("I've never seen such a thing before...I'm shocked!\n");
    printf("Ok, let me try to understand this.\n");
    printf("So this program takes in a file and compresses it, right?\n");
    
    // Let's start by opening the input file
    FILE *input_file = fopen("input.txt", "r");
    
    if (input_file == NULL) {
        printf("Oh no, something went wrong with opening the input file. I'm shocked!\n");
        return 1;
    }
    
    printf("File opened successfully. Let's get started with the compression...\n");
    
    // Let's create the output file
    FILE *output_file = fopen("output.txt", "w");
    
    if (output_file == NULL) {
        printf("Can't believe it...failure to create the output file. This is shocking!\n");
        return 1;
    }
    
    int current_char, last_char = EOF, count = 0;
    
    while ((current_char = fgetc(input_file)) != EOF) {
        if (current_char == last_char) {
            count++;
        } else {
            if (last_char != EOF) {
                fprintf(output_file, "%d%c", count, last_char);
            }
            count = 1;
            last_char = current_char;
        }
    }
    
    // Don't forget to write out the last character block
    fprintf(output_file, "%d%c", count, last_char);
    
    printf("Done compressing. It worked! This is still so shocking to me.\n");
    
    // Close the files
    fclose(input_file);
    fclose(output_file);
    
    return 0;
}