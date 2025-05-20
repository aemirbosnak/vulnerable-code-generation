//FormAI DATASET v1.0 Category: Image Steganography ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Steganography is the art of hiding information within other data

// Given an integer, convert it into a binary string
char* intToBinary(int num) {
    char* binary = malloc(sizeof(char) * 9);
    int index = 0;
    for (int i = 7; i >= 0; i--) {
        binary[index++] = (num & (1 << i)) ? '1' : '0';
    }
    binary[8] = '\0';
    return binary;
}

// Given a binary string, convert it into an integer
int binaryToInt(char* binary) {
    int power = 1;
    int num = 0;
    for (int i = strlen(binary) - 1; i >= 0; i--) {
        if (binary[i] == '1') {
            num += power;
        }
        power *= 2;
    }
    return num;
}

// Given two characters, hide a message within them
void hide(char* c1, char* c2, char* message) {
    char* binary = intToBinary(message[0]);
    c1[strlen(c1) - 1] = binary[6];
    c1[strlen(c1) - 2] = binary[7];
    free(binary);

    binary = intToBinary(message[1]);
    c2[strlen(c2) - 1] = binary[6];
    c2[strlen(c2) - 2] = binary[7];
    free(binary);
}

// Extract the hidden message from two characters
char* extract(char* c1, char* c2) {
    char* binary = malloc(sizeof(char) * 9);
    binary[0] = '0';
    binary[1] = '0';
    for (int i = 0; i < 2; i++) {
        binary[i * 2 + 2] = c1[strlen(c1) - 2 + i];
        binary[i * 2 + 3] = c2[strlen(c2) - 2 + i];
    }
    binary[8] = '\0';
    char* message = malloc(sizeof(char) * 2);
    message[0] = binaryToInt(binary);
    binary = malloc(sizeof(char) * 9);
    binary[0] = '0';
    binary[1] = '0';
    for (int i = 2; i < 8; i++) {
        binary[i] = c1[strlen(c1) - 8 + i];
    }
    binary[8] = '\0';
    message[1] = binaryToInt(binary);
    return message;
}

int main() {
    FILE* in = fopen("input.bmp", "rb");
    FILE* out = fopen("output.bmp", "wb");
    char header[54];
    char color[3];
    fread(header, sizeof(char), 54, in);
    fwrite(header, sizeof(char), 54, out);
    while (fread(color, sizeof(char), 3, in) == 3) {
        if (ftell(in) < 54) {
            fwrite(color, sizeof(char), 3, out);
            continue;
        }
        char c1[9];
        char c2[9];
        sprintf(c1, "%08d", color[0]);
        sprintf(c2, "%08d", color[1]);
        char message[2] = {'A', 'B'};
        hide(c1, c2, message);
        color[0] = binaryToInt(c1);
        color[1] = binaryToInt(c2);
        fwrite(color, sizeof(char), 3, out);
        char* extractedMessage = extract(c1, c2);
        printf("Extracted message: %c%c\n", extractedMessage[0], extractedMessage[1]);
        free(extractedMessage);
    }
    fclose(in);
    fclose(out);
    return 0;
}