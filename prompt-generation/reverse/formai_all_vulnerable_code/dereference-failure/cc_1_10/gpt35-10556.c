//FormAI DATASET v1.0 Category: Compression algorithms ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* This is a unique C compression algorithm that compresses a string by 
   converting repeating character sequences into numbers that indicate the 
   number of times the sequence is repeating. */

char* compress(char* input) {
    int len = strlen(input);
    char* compressed = (char*)malloc(sizeof(char) * len);

    int i = 0, j = 0;

    while (i < len) {
        char current = input[i];
        compressed[j++] = current;

        int count = 1;
        while (i + count < len && input[i + count] == current) {
            count++;
        }

        if (count > 1) {
            char count_str[10];
            sprintf(count_str, "%d", count);
            int count_len = strlen(count_str);

            for (int k = 0; k < count_len; k++) {
                compressed[j++] = count_str[k];
            }

            i += count;
        } else {
            i++;
        }
    }

    compressed[j] = '\0';
    return compressed;
}

int main() {
    char* input = "aaaabbbcccdddeeeefffggg";
    char* compressed = compress(input);

    printf("Before compression: %s\n", input);
    printf("After compression: %s\n", compressed);

    free(compressed);
    return 0;
}