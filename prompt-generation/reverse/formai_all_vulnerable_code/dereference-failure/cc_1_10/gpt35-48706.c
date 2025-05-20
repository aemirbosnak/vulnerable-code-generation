//FormAI DATASET v1.0 Category: Compression algorithms ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define our compression algorithm
void compress(char *input, char *output) {
    // initialize counters and pointers
    int count = 0;
    char *curr = input;
    char *prev = input;
    char *out = output;
    
    // loop through the input string
    while (*curr != '\0') {
        // if the current character matches the previous character, increment the counter
        if (*curr == *prev) {
            count++;
        }
        // otherwise, write the previous character and its count to the output string
        else {
            *out = *prev;
            out++;
            char count_str[10];
            sprintf(count_str, "%d", count);
            strcat(out, count_str);
            out += strlen(count_str);
            // reset the counter and pointer
            count = 1;
            prev = curr;
        }
        curr++;
    }
    // write the final character and count to the output string
    *out = *prev;
    out++;
    char count_str[10];
    sprintf(count_str, "%d", count);
    strcat(out, count_str);
    out += strlen(count_str);
    // add null terminator to the output string
    *out = '\0';
}

int main() {
    char input[] = "aabcccccaaa";
    char output[50];
    compress(input, output);
    printf("Input string: %s\n", input);
    printf("Compressed string: %s\n", output);
    return 0;
}