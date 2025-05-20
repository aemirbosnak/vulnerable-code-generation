//FormAI DATASET v1.0 Category: Compression algorithms ; Style: energetic
/* Let's energize our C Compression algorithm with this dynamic program! */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* This function will compress the input string using a dynamic programming approach. */
int compress(char* str) {
    /* Initialize variables. */
    int i = 0, j = 0, k = 0, l = 0;
    int n = strlen(str), count = 0;
    char c;
    char** arr = (char**) malloc(n * sizeof(char*));

    /* Iterate through the input string. */
    while (i < n) {
        /* If the current character is the same as the previous one, increase count. */
        c = str[i++];
        count++;

        /* If the current character is different from the previous one, insert it with its count. */
        if (i == n || str[i] != c) {
            /* Allocate memory for the new string and copy it to arr. */
            arr[j] = (char*) malloc(count * sizeof(char));
            for (k = 0; k < count; k++) {
                arr[j][k] = c;
            }
            arr[j][k] = '\0';
            j++;
            count = 0;
        }
    }

    /* Concatenate the compressed string. */
    char* result = (char*) malloc(n * sizeof(char));
    for (l = 0; l < j; l++) {
        strcat(result, arr[l]);
    }

    /* Print the compressed string. */
    printf("The compressed string is: %s\n", result);

    /* Return the length of the compressed string. */
    int length = strlen(result);
    free(result);
    free(arr);
    return length;
}

/* Main function. */
int main() {
    /* Define the input string. */
    char* str = "ABBCCCDDDDEEEEE";

    /* Call the compress function. */
    int length = compress(str);

    /* Print the length of the compressed string. */
    printf("The length of the compressed string is: %d\n", length);

    /* Return success. */
    return 0;
}