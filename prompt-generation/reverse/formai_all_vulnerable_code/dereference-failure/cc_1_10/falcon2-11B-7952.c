//Falcon2-11B DATASET v1.0 Category: Huffman Coding Implementation ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to find the frequency of a character in a string
int getFrequency(char *str, char c) {
    int freq = 0;
    while (*str!= '\0') {
        if (*str == c)
            freq++;
        str++;
    }
    return freq;
}

// Function to get the Huffman codes for a given string
char* getHuffmanCodes(char *str) {
    int size = strlen(str);
    int *freq = (int*)malloc(sizeof(int) * 256);
    for (int i = 0; i < size; i++) {
        freq[str[i]]++;
    }

    int n = 256;
    while (n-- > 0) {
        freq[n] = 0;
    }

    int i, j;
    for (i = 0; i < 256; i++) {
        for (j = 0; j < 256; j++) {
            if (freq[i] < freq[j]) {
                freq[i] += freq[j];
                freq[j] = i;
            }
        }
    }

    char *codes = (char*)malloc(sizeof(char) * 256);
    int leaf = 0;
    for (i = 0; i < 256; i++) {
        if (freq[i] == 1) {
            codes[i] = '0';
        } else {
            codes[i] = '1';
            leaf = i;
        }
    }

    char *left = (char*)malloc(sizeof(char) * 256);
    char *right = (char*)malloc(sizeof(char) * 256);
    for (i = 0; i < 256; i++) {
        if (freq[i] == 1) {
            left[i] = '0';
        } else {
            left[i] = '1';
        }
    }

    for (i = 0; i < 256; i++) {
        if (freq[i] == 1) {
            right[i] = '0';
        } else {
            right[i] = '1';
        }
    }

    char *result = (char*)malloc(sizeof(char) * 256);
    result[0] = '0';

    int cur = 0;
    while (1) {
        int code = codes[cur];
        if (code == '0') {
            result[cur + 1] = '0';
            cur += 1;
        } else {
            result[cur + 1] = '1';
            int left_code = left[leaf];
            result[cur + 1] += left_code;
            cur += 1;
            int right_code = right[leaf];
            result[cur + 1] += right_code;
            cur += 1;
            leaf = cur;
        }
        if (cur == 256) {
            break;
        }
    }

    char *huffman_codes = (char*)malloc(sizeof(char) * 256);
    for (i = 0; i < 256; i++) {
        huffman_codes[i] = result[i];
    }

    free(freq);
    free(codes);
    free(left);
    free(right);
    free(result);
    return huffman_codes;
}

int main() {
    char str[256];
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    char *huffman_codes = getHuffmanCodes(str);
    printf("Huffman codes: ");
    for (int i = 0; i < 256; i++) {
        printf("%c", huffman_codes[i]);
    }
    printf("\n");
    free(huffman_codes);
    return 0;
}