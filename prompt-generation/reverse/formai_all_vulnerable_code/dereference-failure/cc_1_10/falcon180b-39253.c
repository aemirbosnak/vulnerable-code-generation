//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to reverse a string
void reverse(char* str, int length) {
    int start = 0;
    int end = length - 1;
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

// Function to recover deleted data
void recoverData(FILE* file, int blockSize) {
    char buffer[blockSize];
    int bytesRead = fread(buffer, 1, blockSize, file);
    if (bytesRead == 0) {
        printf("No data to recover.\n");
        return;
    }
    int i = 0;
    while (i < bytesRead) {
        if (buffer[i] == '\0') {
            reverse(buffer, i);
            printf("Recovered deleted data: %s\n", buffer);
            break;
        }
        i++;
    }
}

int main(int argc, char* argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <filename> <block_size>\n", argv[0]);
        return 1;
    }
    FILE* file = fopen(argv[1], "rb");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    int blockSize = atoi(argv[2]);
    recoverData(file, blockSize);
    fclose(file);
    return 0;
}