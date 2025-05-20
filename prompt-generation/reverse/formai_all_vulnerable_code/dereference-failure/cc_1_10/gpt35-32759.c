//FormAI DATASET v1.0 Category: Compression algorithms ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 1000

// Function to compress the given string using the given compression algorithm
char* compress(char* str, int length) {
    // Allocate memory to store the compressed string
    char* compressed = (char*) malloc(sizeof(char) * MAX_LENGTH);
    int i, j, count;

    // Iterate through each character of the string
    for (i = 0, j = 0; i < length; i++) {
        // Count the number of consecutive occurrences of the current character
        count = 1;
        while (i + 1 < length && str[i] == str[i + 1]) {
            count++;
            i++;
        }

        // If the count is greater than 1, add the count to the compressed string
        if (count > 1) {
            compressed[j++] = count + '0';
        }

        // Add the current character to the compressed string
        compressed[j++] = str[i];
    }

    // NULL-terminate the compressed string
    compressed[j] = '\0';

    return compressed;
}

int main() {
    char str[MAX_LENGTH];
    printf("Enter a string: ");
    fgets(str, MAX_LENGTH, stdin);

    int length = 0;
    while (str[length] != '\n' && str[length] != '\0') {
        length++;
    }

    char* compressed = compress(str, length);

    printf("Compressed string: %s\n", compressed);

    free(compressed);
    return 0;
}