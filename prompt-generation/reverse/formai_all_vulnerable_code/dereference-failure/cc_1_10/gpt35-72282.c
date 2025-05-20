//FormAI DATASET v1.0 Category: Compression algorithms ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    printf("Wow, I can't believe I just created a unique C Compression algorithm!\n");

    char* original = "The quick brown fox jumps over the lazy dog.";
    printf("Original text: %s\n", original);

    int size = strlen(original);
    char* compressed = malloc(size * sizeof(char));

    int i, j;
    int index = 0;
    int count = 1;

    for(i = 0; i < size; i++) {
        compressed[index] = original[i];
        for(j = i + 1; j < size; j++) {
            if(original[i] != original[j]) {
                i = j - 1;
                break;
            }
            count++;
        }
        if(count > 1) {
            char* countstr = malloc(10 * sizeof(char));
            sprintf(countstr, "%d", count);

            int k;
            for(k = 0; k < strlen(countstr); k++) {
                index++;
                compressed[index] = countstr[k];
            }

            free(countstr);
            count = 1;
        }
        index++;
    }
    compressed[index] = '\0';

    printf("Compressed text: %s\n", compressed);

    free(compressed);

    printf("I hope you're as surprised as I am by this program.\n");

    return 0;
}