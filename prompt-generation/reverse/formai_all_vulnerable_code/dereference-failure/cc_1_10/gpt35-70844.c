//FormAI DATASET v1.0 Category: Compression algorithms ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int compress(char str[], int index, int count);

int main() {
    char str[MAX_SIZE];
    int result;

    printf("Enter the string to compress: ");
    fgets(str, MAX_SIZE, stdin);

    result = compress(str, 0, 1);
    printf("The compressed string is: ");

    // Check if the string is compressible
    if (result == strlen(str)) {
        printf("%s", str);
    } else {
        for (int i = 0; i < result; i++) {
            printf("%c", str[i]);
        }
    }

    return 0;
}

int compress(char str[], int index, int count) {
    static char compressed[MAX_SIZE] = {'\0'};
    static int compressed_index = 0;

    // Base case
    if (str[index] == '\0') {
        // Copy the compressed string to the input string
        for (int i = 0; i < compressed_index; i++) {
            str[i] = compressed[i];
        }
        return compressed_index;
    }

    // If the current character is the same as the previous one
    if (str[index] == str[index - 1]) {
        count++;
    } else {
        // Add the compressed count to the compressed string
        if (count > 1) {
            char temp[MAX_SIZE];
            int temp_index = 0;

            sprintf(temp, "%d", count);
            while (temp[temp_index] != '\0') {
                compressed[compressed_index++] = temp[temp_index++];
            }
        }

        // Add the current character to the compressed string
        compressed[compressed_index++] = str[index - 1];

        // Reset the count
        count = 1;
    }

    // Recursive call
    return compress(str, index + 1, count);
}