//FormAI DATASET v1.0 Category: Compression algorithms ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

// function to perform compression using run-length encoding
char *compress(char *str) {

    int len = strlen(str);
    char *res = (char*)malloc(sizeof(char) * (2 * len + 1)); // allocate memory for result array
    int count = 1, i, j;
    char curr;

    // iterate through string
    for(i = 0, j = 0; i < len; i++) {
        curr = str[i];

        // if current character is same as previous one
        if(curr == str[i + 1]) {
            count++; // increase count
        } else {
            // add count and current character to result array
            res[j++] = count + '0';
            res[j++] = curr;
            count = 1; // reset count
        }
    }
    res[j] = '\0'; // add null terminator to result array
    return res;
}

int main() {

    char str[MAX_LEN], *res;

    printf("Enter a string to compress: ");
    fgets(str, MAX_LEN, stdin); // read string from user

    // remove newline character from fgets() output
    if ((strlen(str) > 0) && (str[strlen(str) - 1] == '\n')) {
        str[strlen(str) - 1] = '\0';
    }

    res = compress(str); // perform compression using RLE
    printf("Compressed string: %s\n", res);

    free(res); // free dynamically allocated memory
    return 0;
}