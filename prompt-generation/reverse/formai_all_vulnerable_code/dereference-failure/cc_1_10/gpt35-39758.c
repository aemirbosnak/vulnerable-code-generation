//FormAI DATASET v1.0 Category: Compression algorithms ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void compress(char*);
void decompress(char*);

int main() {
    char* input;

    printf("Enter the string to compress: ");
    scanf("%[^\n]s", input);

    // Call the compression algorithm
    compress(input);

    // Call the decompression algorithm
    decompress(input);

    return 0;
}

void compress(char* str) {
    int len = strlen(str);
    char* result = (char*) malloc(len * sizeof(char));

    int count = 1, j = 0;
    result[j] = str[0];
    for(int i = 1; i < len; i++) {
        if(str[i] == str[i-1]) {
            count++;
        } else {
            if(count > 1) {
                // Add the count of repeated characters
                char buffer[16];
                sprintf(buffer, "%d", count);
                strcat(result, buffer);
                j += strlen(buffer);
                count = 1;
            }
            j++;
            result[j] = str[i];
        }
    }

    if(count > 1) {
        // Add the count of repeated characters
        char buffer[16];
        sprintf(buffer, "%d", count);
        strcat(result, buffer);
        j += strlen(buffer);
    }

    printf("Compressed string: %s\n", result);
}

void decompress(char* str) {
    int len = strlen(str);
    char* result = (char*) malloc(len * sizeof(char));

    int j = 0;
    for(int i = 0; i < len; i++) {
        if(str[i] >= '0' && str[i] <= '9') {
            // Repeated character count
            int count = str[i] - '0';
            while(str[i+1] >= '0' && str[i+1] <= '9') {
                count = count * 10 + (str[i+1] - '0');
                i++;
            }
            for(int k = 0; k < count - 1; k++) {
                result[j++] = result[j-1];
            }
        } else {
            result[j++] = str[i];
        }
    }

    printf("Decompressed string: %s\n", result);
}