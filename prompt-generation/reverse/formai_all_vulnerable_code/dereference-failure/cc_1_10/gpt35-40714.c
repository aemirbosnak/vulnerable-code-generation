//FormAI DATASET v1.0 Category: Compression algorithms ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 512

/* Define a function that compresses a string */
char* compress(char* in) {
    int len = strlen(in);
    int i = 0, j = 0, count = 0;
    char c = in[0]; /* Initialize c with first character in input */
    char* out = (char*) malloc(MAX_BUFFER_SIZE);

    while (i < len) {
        if (in[i] == c) {
            count++; /* Increment count if same character found */
        } else {
            out[j] = c; /* Append character c to output */
            j++;
            if (count > 1) {
                char* n = (char*) malloc(MAX_BUFFER_SIZE);
                snprintf(n, MAX_BUFFER_SIZE, "%d", count); /* Convert count to string */
                strcat(out, n); /* Append count string to output */
                free(n);
                j += strlen(n);
            }
            count = 1; /* Reset count to 1 since we found a new character */
            c = in[i]; /* Update c to current character */
        }
        i++; /* Move to next character in input */
    }

    /* Append last character and count to output */
    out[j] = c;
    j++;
    if (count > 1) {
        char* n = (char*) malloc(MAX_BUFFER_SIZE);
        snprintf(n, MAX_BUFFER_SIZE, "%d", count);
        strcat(out, n);
        free(n);
        j += strlen(n);
    }

    out[j] = '\0'; /* Null terminate output */

    return out;
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("usage: %s <string>\n", argv[0]);
        return 1;
    }

    char* in = argv[1];

    printf("Input: %s\n", in);

    char* out = compress(in);

    printf("Output: %s\n", out);

    free(out);

    return 0;
}