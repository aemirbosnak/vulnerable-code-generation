//FormAI DATASET v1.0 Category: Compression algorithms ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

char* Compress(char* str);
char* Decompress(char* str);

int main() {
    char str[MAX_SIZE];
    printf("Enter string to compress: ");
    fgets(str, MAX_SIZE, stdin);

    printf("\nCompressed string: %s\n", Compress(str));
    printf("\nDecompressed string: %s\n", Decompress(Compress(str)));

    return 0;
}

char* Compress(char* str)
{
    char* compressed;
    compressed = (char*) malloc(MAX_SIZE * sizeof(char));

    int count = 1, index = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == str[i+1]) {
            count++;
        } else if (str[i] != str[i+1]) {
            compressed[index] = str[i];
            compressed[index+1] = (char) count + '0';
            count = 1;
            index += 2;
        }
    }
    compressed[index] = '\0';

    return compressed;
}

char* Decompress(char* str)
{
    char* decompressed;
    decompressed = (char*) malloc(MAX_SIZE * sizeof(char));

    int index = 0;
    for (int i = 0; str[i] != '\0'; i += 2) {
        int count = str[i+1] - '0';
        for (int j = 0; j < count; j++) {
            decompressed[index] = str[i];
            index++;
        }
    }
    decompressed[index] = '\0';

    return decompressed;
}