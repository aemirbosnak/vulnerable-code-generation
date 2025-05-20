//FormAI DATASET v1.0 Category: Compression algorithms ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1000 // Maximum length of input string

// Returns compressed string using my unique algorithm
char* compress(char* str) {
    int len = strlen(str);
    char* compressed = (char*)malloc(sizeof(char) * MAX_LEN);
    int count = 1;
    char prev = str[0];
    int j = 0;

    for (int i = 1; i < len; i++) {
        if (str[i] == prev) {
            count++;
        } else {
            if (count > 1) {
                compressed[j++] = count + '0';
            }
            compressed[j++] = prev;
            prev = str[i];
            count = 1;
        }
    }

    // Handling the last character(s)
    if (count > 1) {
        compressed[j++] = count + '0';
    }
    compressed[j++] = prev;
    compressed[j] = '\0';

    return compressed;
}

int main() {
    printf("\nWelcome to my unique compression algorithm!\n");
    printf("Enter a string to compress (Maximum length: %d): ", MAX_LEN);
    char* str = (char*)malloc(sizeof(char) * MAX_LEN);
    fgets(str, MAX_LEN, stdin);
    str[strcspn(str, "\n")] = '\0'; // removing newline at the end of input string

    char* compressed = compress(str);
    printf("\nOriginal String: %s\n", str);
    printf("Compressed String: %s\n", compressed);

    return 0;
}