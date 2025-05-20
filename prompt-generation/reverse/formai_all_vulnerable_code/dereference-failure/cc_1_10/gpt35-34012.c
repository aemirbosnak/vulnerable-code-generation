//FormAI DATASET v1.0 Category: Image Steganography ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define FILENAME "image.bmp"
#define MESSAGE_FILE "secret.txt"
#define MAX_MSG_SIZE 1000
#define MAX_BIT_SIZE 8

/* Function to get the binary value of a character */
char* getCharBinary(char c) {
    char* bin = malloc(MAX_BIT_SIZE + 1);
    for(int i = 0; i < MAX_BIT_SIZE; i++) {
        bin[i] = (c & (1 << i)) ? '1' : '0';
    }
    bin[MAX_BIT_SIZE] = '\0';
    return bin;
}

/* Function to get the decimal value of a binary string */
int getDecimalValue(char* bin, int size) {
    int decValue = 0;
    for(int i = 0; i < size; i++) {
        decValue += (bin[i] - '0') * (1 << (size - i - 1));
    }
    return decValue;
}

/* Function to embed the message into the image */
void embedMessage(char* msg, int size) {
    /* Open the file */
    FILE* file = fopen(FILENAME, "rb+");
    if(file == NULL) {
        printf("Unable to open file!\n");
        return;
    }
    /* Skip the BMP header */
    fseek(file, 54, SEEK_SET);
    char c = fgetc(file);
    int msgIndex = 0;
    bool done = false;
    while(!done) {
        /* Get the binary value of the character */
        char* bin = getCharBinary(msg[msgIndex++]);
        /* Embed the binary value into the least significant bit of each byte */
        for(int i = 0; i < MAX_BIT_SIZE; i++) {
            char byte = fgetc(file);
            byte = (byte & 0xFE) | (bin[i] - '0');
            fseek(file, -1, SEEK_CUR);
            fputc(byte, file);
            /* Check if the message has been fully embedded */
            if(msgIndex >= size) {
                done = true;
                break;
            }
        }
        free(bin);
    }
    fclose(file);
}

/* Function to extract the message from the image */
void extractMessage() {
    /* Open the file */
    FILE* file = fopen(FILENAME, "rb");
    if(file == NULL) {
        printf("Unable to open file!\n");
        return;
    }
    /* Skip the BMP header */
    fseek(file, 54, SEEK_SET);
    char c = fgetc(file);
    int msgSize = 0;
    char msg[MAX_MSG_SIZE + 1];
    while(msgSize < MAX_MSG_SIZE) {
        /* Extract the least significant bit of each byte and append to the message */
        char byte = 0;
        for(int i = 0; i < MAX_BIT_SIZE; i++) {
            byte = (byte << 1) | (fgetc(file) & 1);
        }
        msg[msgSize++] = byte;
    }
    msg[MAX_MSG_SIZE] = '\0';
    fclose(file);
    /* Write the message to a file */
    FILE* msgFile = fopen(MESSAGE_FILE, "w");
    if(msgFile == NULL) {
        printf("Unable to create message file!\n");
        return;
    }
    fprintf(msgFile, "%s", msg);
    fclose(msgFile);
}

int main() {
    char* msg = "This is a secret message!";
    int size = strlen(msg);
    embedMessage(msg, size);
    extractMessage();
    return 0;
}