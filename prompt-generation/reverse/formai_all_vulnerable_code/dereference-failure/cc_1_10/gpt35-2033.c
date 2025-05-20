//FormAI DATASET v1.0 Category: Compression algorithms ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 65536
#define MAX_OUTPUT_SIZE 131072

char input[MAX_INPUT_SIZE];
char output[MAX_OUTPUT_SIZE];

int main(int argc, char **argv) {
    int length = 0;

    printf("Enter a string to compress:\n");
    fgets(input, MAX_INPUT_SIZE, stdin);

    length = strlen(input);
    if (length > 0 && input[length - 1] == '\n') {
        input[--length] = '\0';
    }

    int i, j, count;
    char c;
    char *compressed = malloc(length * sizeof(char));

    i = 0;
    j = 0;

    while (i < length) {
        c = input[i];
        count = 1;
        while (input[i + 1] == c && count < 127 && i < length - 1) {
            count++;
            i++;
        }
        compressed[j] = count;
        compressed[j + 1] = c;
        j += 2;
        i++;
    }

    int compressed_size = j;

    printf("\nInput: %s\n", input);
    printf("\nCompressed: ");
    for (i = 0; i < compressed_size; i++) {
        printf("%d%c", compressed[i], i == compressed_size - 1 ? '\n' : '-');
    }

    free(compressed);
    return 0;
}