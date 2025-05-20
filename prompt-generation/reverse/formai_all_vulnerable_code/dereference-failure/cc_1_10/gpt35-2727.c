//FormAI DATASET v1.0 Category: Compression algorithms ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

int main() {
    int i, j, freq, count, compressed_length;
    char *input_string, *compressed_string, current_char;

    // Get input string dynamically
    input_string = (char *) malloc (sizeof(char) * MAX_SIZE);
    printf("Enter a string: ");
    fgets(input_string, MAX_SIZE, stdin);
    input_string[strcspn(input_string, "\n")] = 0; // remove newline character

    // Initialize compressed string
    compressed_length = strlen(input_string);
    compressed_string = (char *) malloc (sizeof(char) * compressed_length);

    // Compress the input string
    current_char = input_string[0];
    count = 1;
    j = 0; // index of current compressed string character
    for (i = 1; i <= strlen(input_string); i++) {
        if (input_string[i] == current_char) {
            count++;
        }
        else {
            // append character and frequency to output string
            compressed_string[j++] = current_char;
            freq = count;
            if (freq > 1) {
                while (freq > 0) {
                    compressed_string[j++] = '0' + (freq % 10);
                    freq /= 10;
                }
            }
            current_char = input_string[i];
            count = 1; // reset counter for next character
        }
    }
    compressed_string[j] = '\0'; // add null character to end of output string

    // Print compressed string
    printf("Compressed string: %s\n", compressed_string);

    // Free dynamic memory
    free(input_string);
    free(compressed_string);

    return 0;
}