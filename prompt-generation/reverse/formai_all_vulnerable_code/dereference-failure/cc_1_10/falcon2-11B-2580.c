//Falcon2-11B DATASET v1.0 Category: Compression algorithms ; Style: medieval
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 1000

char* compress(char* str) {
    char* compressed = (char*) malloc(MAX_LEN);
    char* current = compressed;
    char* prev = compressed;
    char c;
    int count = 1;
    
    for (int i = 0; i < strlen(str); i++) {
        c = str[i];
        if (prev!= compressed && c == prev[0]) {
            strcpy(current, prev);
            current += strlen(prev);
            prev = compressed;
        } else {
            strcpy(prev, str + i);
            prev[strlen(prev) - 1] = '\0';
            current = compressed;
        }
        prev = compressed;
    }
    
    strcpy(current, prev);
    current += strlen(prev);
    prev = compressed;
    
    for (int i = 0; i < strlen(prev); i++) {
        if (i == 0 || prev[i]!= prev[i - 1]) {
            strcpy(current, prev + i);
            current += strlen(prev + i);
            prev = compressed;
        } else {
            prev++;
        }
    }
    
    if (prev!= compressed) {
        strcpy(current, prev);
        current += strlen(prev);
        prev = compressed;
    }
    
    free(str);
    return compressed;
}

int main() {
    char str[MAX_LEN];
    printf("Enter a string to compress: ");
    fgets(str, MAX_LEN, stdin);
    
    char* compressed_str = compress(str);
    printf("Compressed string: %s\n", compressed_str);
    
    free(compressed_str);
    return 0;
}