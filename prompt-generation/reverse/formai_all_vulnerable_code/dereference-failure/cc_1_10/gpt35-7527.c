//FormAI DATASET v1.0 Category: Compression algorithms ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1000

/**
 * Function to compress a given string using a unique algorithm
 * Algorithm:
 * - Count the number of occurrences of each character in string
 * - Replace each occurrence of a character with the format 'nC', where n is the number of occurrences
 *   and C is the character itself
 * - Append the compressed string in the format 'nCmD' to the output string, where n is the number of
 *   occurrences of the first character, C is the first character itself, m is the number of occurrences
 *   of the second character and D is the second character itself
 * - Repeat until all characters in the string have been processed
 * - Return the compressed string
 */
char *compress_string(char *str)
{
    int i, count[MAX_LEN], compressed_len = 0;
    char *compressed_str = (char *) malloc(MAX_LEN*sizeof(char));

    // Initialize count array to 0
    memset(count, 0, sizeof(count));

    // Count the number of occurrences of each character
    for (i = 0; i < strlen(str); i++) {
        count[str[i]]++;
    }

    // Compress the string
    i = 0;
    while (i < strlen(str)) {
        // Get the character and its count
        int c = str[i];
        int n = count[c];

        // Append the compressed string to the output string
        sprintf(compressed_str+compressed_len, "%d%c", n, c);

        // Update the compressed string length
        compressed_len += 2;

        // Update the count array
        count[c] = 0;

        // Move to the next character
        i++;
    }

    // Null-terminate the compressed string
    compressed_str[compressed_len] = '\0';

    return compressed_str;
}

int main()
{
    char str[MAX_LEN];
    printf("Enter a string to compress: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0'; // remove newline character
    char *compressed_str = compress_string(str);
    printf("Compressed string: %s\n", compressed_str);
    free(compressed_str);
    return 0;
}