//FormAI DATASET v1.0 Category: Compression algorithms ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IN_LEN 128
#define MAX_OUT_LEN 64

/* Custom data structure to store a character count */
typedef struct CharCount {
    char c;
    int count;
} CharCount;

/* Custom function to compare two CharCounts by count */
int cmpCharCount(const void *a, const void *b) {
    return ((CharCount *)b)->count - ((CharCount *)a)->count;
}

/* Custom function to compress a string using a simple run-length encoding */
char *compress(char *input) {
    // Count how many of each character there are
    CharCount counts[MAX_IN_LEN];
    int numCounts = 0;
    for (int i = 0; i < strlen(input); i++) {
        // See if this character has already been counted
        int j;
        for (j = 0; j < numCounts; j++) {
            if (counts[j].c == input[i]) {
                counts[j].count++;
                break;
            }
        }
        // If it hasn't been counted yet, add a new CharCount to the array
        if (j == numCounts) {
            counts[j].c = input[i];
            counts[j].count = 1;
            numCounts++;
        }
    }
    // Sort the CharCounts by count (descending order)
    qsort(counts, numCounts, sizeof(CharCount), cmpCharCount);
    // Build the compressed output
    char *output = malloc(MAX_OUT_LEN);
    output[0] = '\0';   // Start with an empty string
    for (int i = 0; i < numCounts; i++) {
        // Check if this character count is zero (end of input)
        if (counts[i].count == 0) {
            break;
        }
        // Append this character count to the output in the format 'cN'
        char countStr[4];
        sprintf(countStr, "%d", counts[i].count);
        strcat(output, &(counts[i].c));
        strcat(output, countStr);
        // If the output string is too long, stop compressing and return the input
        if (strlen(output) >= MAX_OUT_LEN-1) {
            return input;
        }
    }
    return output;
}

int main() {
    char input[MAX_IN_LEN];
    printf("Enter a string to compress (up to %d characters):\n", MAX_IN_LEN-1);
    fgets(input, MAX_IN_LEN, stdin);
    input[strcspn(input, "\r\n")] = '\0';    // Strip newline from input (if any)
    char *output = compress(input);
    printf("Compressed: %s\n", output);
    free(output);
    return 0;
}