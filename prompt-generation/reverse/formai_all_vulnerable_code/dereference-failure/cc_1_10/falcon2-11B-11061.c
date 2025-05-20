//Falcon2-11B DATASET v1.0 Category: Compression algorithms ; Style: curious
#include <stdio.h>
#include <string.h>

void compress(char* str, int* compressed_str) {
    int count = 0;
    int i = 0;
    int j = 0;
    
    while (str[i]!= '\0') {
        if (str[i]!= str[i + 1]) {
            compressed_str[j++] = str[i];
            count++;
            i++;
        } else {
            i++;
        }
    }
    
    compressed_str[j++] = '\0';
    compressed_str[j] = '\0';
    printf("Compressed string: %s\n", compressed_str);
}

void decompress(char* compressed_str, char* str) {
    int i = 0;
    int j = 0;
    
    while (compressed_str[i]!= '\0') {
        if (compressed_str[i] == compressed_str[i + 1]) {
            str[j++] = compressed_str[i];
            i++;
        } else {
            str[j++] = compressed_str[i];
            i += 2;
        }
    }
    
    str[j++] = '\0';
    printf("Decompressed string: %s\n", str);
}

int main() {
    char* str = "aaaaaabbbbccccdddddd";
    int compressed_str[100];
    
    compress(str, compressed_str);
    decompress(compressed_str, str);
    
    return 0;
}