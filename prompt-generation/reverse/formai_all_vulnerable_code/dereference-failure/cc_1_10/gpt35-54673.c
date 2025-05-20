//FormAI DATASET v1.0 Category: File handling ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    // Check for correct usage
    if (argc != 3) {
        printf("Usage: %s input_file output_file\n", argv[0]);
        exit(1);
    }
    
    // Open input and output files
    FILE *input_file = fopen(argv[1], "r");
    FILE *output_file = fopen(argv[2], "w");
    
    // Check if files exist
    if (input_file == NULL || output_file == NULL) {
        printf("Error opening files\n");
        exit(1);
    }
    
    // Initialize variables
    int word_count = 0;
    int char_count = 0;
    int in_word = 0;
    char c;
    
    // Iterate through input file character by character
    while((c=fgetc(input_file)) != EOF) {
        // Increment character count
        char_count++;
        
        // Check if current character is part of a word
        if(isalpha(c)) {
            // Set flag if not already set
            if(!in_word) {
                in_word = 1;
                word_count++;
            }
        } else {
            // Reset flag if previously set
            if(in_word) {
                in_word = 0;
            }
        }
    }
    
    // Write total word count and character count to output file
    fprintf(output_file, "Word Count: %d\n", word_count);
    fprintf(output_file, "Character Count: %d\n", char_count);
    
    // Close files
    fclose(input_file);
    fclose(output_file);
    
    return 0;
}