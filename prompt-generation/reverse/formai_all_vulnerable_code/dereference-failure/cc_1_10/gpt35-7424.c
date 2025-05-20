//FormAI DATASET v1.0 Category: Compression algorithms ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// This compression algorithm will replace consecutive repeated characters in a string with a shorthand notation
// For example, "yyy" will become "y3"

char* compressString(char* input) {
    char* output = (char*) malloc(sizeof(char) * (strlen(input) + 1));
    int count = 1;
    char current_char = input[0];
    int output_position = 0;
    int i;
    for (i = 1; i <= strlen(input); i++) {
        if (input[i] == current_char) {
            count++;
        } else {
            if (count == 1) {
                // No repeating characters, just copy the current character
                output[output_position] = current_char;
                output_position++;
            } else if (count == 2) {
                // Two repeating characters, use shorthand notation (i.e. double the character)
                output[output_position] = current_char;
                output_position++;
                output[output_position] = current_char;
                output_position++;
            } else {
                // More than two repeating characters, use shorthand notation (i.e. character followed by count)
                output[output_position] = current_char;
                output_position++;
                char count_char = count + '0';
                output[output_position] = count_char;
                output_position++;
            }
            current_char = input[i];
            count = 1;
        }
    }
    output[output_position] = '\0';
    return output;
}

int main() {
    char* input_string = "aaabbbccdddeefffggghhhiiijjjkkklll";
    char* compressed_string = compressString(input_string);
    printf("Compressed: %s\n", compressed_string);
    free(compressed_string);
    return 0;
}