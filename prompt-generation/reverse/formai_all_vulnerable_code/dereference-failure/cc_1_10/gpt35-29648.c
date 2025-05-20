//FormAI DATASET v1.0 Category: Compression algorithms ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_LENGTH 1000

/**
 * Compresses a given string using the Run Length Encoding algorithm.
 * This algorithm replaces sequences of repeated characters with the character
 * followed by a count of its occurrences.
 * For example, "AAAABBBBCCCCCCCC" is compressed to "A4B4C8".
 *
 * @param str The string to compress
 * @return A pointer to the compressed string
 */
char *compress(const char *str) {
    int len = strlen(str);
    char *compressed = (char*)malloc(sizeof(char) * (len * 2 + 1)); // allocate memory for compressed string
    
    int i, j = 0, count = 1;
    for (i = 0; i < len; i++) {
        if (str[i] == str[i + 1]) { // if the current char is the same as the next
            count++; // increment the count
        } else { // if current char is not the same as the next
            compressed[j++] = str[i]; // add current char to compressed string
            if (count > 1) { // if count is greater than 1
                char num[MAX_LENGTH];
                sprintf(num, "%d", count); // convert count to string
                strcat(compressed, num); // append count to compressed string
                j += strlen(num); // update index to point to end of compressed string
                count = 1; // reset count
            }
        }
    }
    compressed[j] = '\0'; // add null terminator to end of compressed string
    return compressed; // return the compressed string
}

/**
 * Decompresses a given string compressed using the Run Length Encoding algorithm.
 * This algorithm recreates the original string by reading each character and its count.
 * For example, "A4B4C8" is decompressed to "AAAABBBBCCCCCCCC".
 *
 * @param str The compressed string to decompress
 * @return A pointer to the decompressed string
 */
char *decompress(const char *str) {
    int len = strlen(str);
    char *decompressed = (char*)malloc(sizeof(char) * (len + 1)); // allocate memory for decompressed string
    
    int i, j = 0, count = 0;
    for (i = 0; i < len; i++) {
        if (isdigit(str[i])) { // if the current char is a digit
            count = count * 10 + str[i] - '0'; // update count
        } else { // if the current char is not a digit
            for (int k = 0; k < count; k++) { // repeat the character count number of times
                decompressed[j++] = str[i];
            }
            count = 0; // reset count
        }
    }
    decompressed[j] = '\0'; // add null terminator to end of decompressed string
    return decompressed; // return the decompressed string
}

/**
 * Main function to demonstrate the compression and decompression algorithms.
 */
int main() {
    char original[MAX_LENGTH];
    printf("Enter a string to compress: ");
    fgets(original, MAX_LENGTH, stdin); // read input from user
    original[strcspn(original, "\n")] = '\0'; // remove newline character
    
    char *compressed = compress(original);
    printf("The compressed string is: %s\n", compressed);
    
    char *decompressed = decompress(compressed);
    printf("The decompressed string is: %s\n", decompressed);
    
    free(compressed); // free memory used by compressed string
    free(decompressed); // free memory used by decompressed string
    
    return 0;
}