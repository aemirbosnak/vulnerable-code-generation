//Falcon2-11B DATASET v1.0 Category: Compression algorithms ; Style: mind-bending
#include <stdio.h>
#include <string.h>

// Function to compress the string
char *compress(char *str, int size) {
    char *compr = (char *)malloc(size * 3);
    int i, j, k, count = 0;

    // Scan the string for repeating characters
    for (i = 0; i < size; i++) {
        for (j = i + 1; j < size; j++) {
            if (str[i] == str[j]) {
                count++;
                break;
            }
        }

        // If a repeating character is found, replace it with a single character and increment count
        if (count > 1) {
            compr[i] = str[j];
            compr[i + 1] = (count - 1) % 256;
            compr[i + 2] = (count - 1) / 256;
            count = 0;
        }
    }

    // Convert the compressed string back to a normal string
    for (i = 0; i < size; i++) {
        compr[i] = str[i];
    }

    return compr;
}

int main() {
    char str[100];
    int size = sizeof(str);

    printf("Enter a string: ");
    fgets(str, size, stdin);

    // Compress the string
    char *comp = compress(str, size);

    printf("Compressed string: %s\n", comp);

    // Free the allocated memory
    free(comp);

    return 0;
}