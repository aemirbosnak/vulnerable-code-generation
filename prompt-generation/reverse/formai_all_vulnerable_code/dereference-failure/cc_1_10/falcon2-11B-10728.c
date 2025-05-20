//Falcon2-11B DATASET v1.0 Category: Compression algorithms ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to compress a string using a simple run-length encoding algorithm
void compressString(char *str, int *length) {
    int count = 1;
    int i = 0;
    int j = 0;
    int k = 0;

    // Iterate through the string and count the number of consecutive characters
    while (str[i]!= '\0') {
        if (str[i] == str[i + 1]) {
            count++;
            i++;
        } else {
            count = 1;
            i++;
        }
    }

    // Allocate memory for the compressed string
    char *compressedStr = (char*)malloc(sizeof(char) * (count + 1));
    compressedStr[k++] = '\0';

    // Copy the compressed string into the allocated memory
    j = k;
    while (str[i]!= '\0') {
        if (str[i] == str[i + 1]) {
            count++;
            i++;
        } else {
            compressedStr[j++] = str[i];
            compressedStr[j++] = '1';
            i++;
        }
    }
    compressedStr[j++] = str[i];
    compressedStr[j++] = '1';

    // Copy the length of the compressed string into the allocated memory
    *length = k;
}

// Function to decompress a string using a simple run-length encoding algorithm
void decompressString(char *str, int length) {
    int i = 0;
    int j = 0;

    // Iterate through the compressed string and copy the characters into the decompressed string
    while (str[i]!= '\0') {
        if (str[i] == '1') {
            str[j++] = str[i + 1];
            i++;
        } else {
            str[j++] = str[i + 1];
            i++;
            str[j++] = str[i + 1];
            i++;
        }
    }
    str[j++] = '\0';
}

int main() {
    char str[100];
    int length;

    printf("Enter a string to compress: ");
    fgets(str, sizeof(str), stdin);
    str[strlen(str) - 1] = '\0';

    compressString(str, &length);
    printf("Compressed string: %s\n", str);

    decompressString(str, length);
    printf("Decompressed string: %s\n", str);

    return 0;
}