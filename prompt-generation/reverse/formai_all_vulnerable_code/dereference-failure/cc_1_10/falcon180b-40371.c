//Falcon-180B DATASET v1.0 Category: Compression algorithms ; Style: minimalist
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_CODE_LENGTH 1000

void generateCodeTable(char *codeTable[], int *tableIndex, int freq[], int n) {
    int i = 0;
    for (i = 0; i < n; i++) {
        freq[i] = 0;
    }
    for (i = 0; i < n; i++) {
        freq[i] = freq[i] + 1;
    }
    for (i = 0; i < n; i++) {
        codeTable[i] = (char)i;
    }
    for (i = 1; i < n; i++) {
        int j = 0;
        while (freq[j] < freq[i]) {
            j++;
        }
        int temp = freq[i];
        freq[i] = freq[j];
        freq[j] = temp;
        char tempChar = codeTable[j];
        codeTable[j] = codeTable[i];
        codeTable[i] = tempChar;
    }
}

void encode(char inputString[], int codeTable[], int *tableIndex, char outputString[]) {
    int i = 0;
    while (inputString[i]!= '\0') {
        outputString[i] = codeTable[inputString[i]];
        i++;
    }
    outputString[i] = '\0';
}

void decode(char inputString[], int codeTable[], int *tableIndex, char outputString[]) {
    int i = 0;
    while (inputString[i]!= '\0') {
        outputString[i] = (char)tableIndex[inputString[i]];
        i++;
    }
    outputString[i] = '\0';
}

int main() {
    int freq[26] = { 0 };
    char inputString[100] = "Compression algorithms are used to reduce the size of files. ";
    char outputString[200] = { 0 };
    char codeTable[26] = { 0 };
    int tableIndex[26] = { 0 };
    generateCodeTable(codeTable, tableIndex, freq, 26);
    encode(inputString, codeTable, tableIndex, outputString);
    printf("Encoded string: %s\n", outputString);
    int i = 0;
    while (outputString[i]!= '\0') {
        printf("%c", outputString[i]);
        i++;
    }
    return 0;
}