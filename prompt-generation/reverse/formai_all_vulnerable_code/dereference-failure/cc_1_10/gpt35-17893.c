//FormAI DATASET v1.0 Category: Image Steganography ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

// function declaration
void encode(char *msg, char *inputFile, char *outputFile);
void decode(char *outputFile);

// main function
int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <encode/decode> <input_file> <output_file>\n", argv[0]);
        exit(1);
    }

    if (strcmp(argv[1], "encode") == 0) {
        if (argc < 4) {
            printf("Usage: %s encode <input_file> <output_file>\n", argv[0]);
            exit(1);
        }

        // get message from user
        char msg[100];
        printf("Enter the message to be encoded: ");
        scanf("%[^\n]", msg);
        getchar();

        // call encode function
        encode(msg, argv[2], argv[3]);
        printf("Message encoded successfully!\n");
    } else if (strcmp(argv[1], "decode") == 0) {
        // call decode function
        decode(argv[2]);
    } else {
        printf("Usage: %s <encode/decode> <input_file> <output_file>\n", argv[0]);
        exit(1);
    }

    return 0;
}

// function to encode message in image
void encode(char *msg, char *inputFile, char *outputFile) {
    FILE *fp1, *fp2;
    fp1 = fopen(inputFile, "rb");
    fp2 = fopen(outputFile, "wb");
    if (fp1 == NULL || fp2 == NULL) {
        printf("Error opening files!\n");
        exit(1);
    }

    // copy header
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, fp1);
    fwrite(header, sizeof(unsigned char), 54, fp2);

    // convert message to binary
    int i, j, k = 0;
    int msgLen = strlen(msg);
    char *binaryMsg = (char *) malloc(sizeof(char) * msgLen * 8 + 1);
    for (i = 0; i < msgLen; i++) {
        for (j = 7; j >= 0; j--) {
            int bit = (msg[i] >> j) & 1;
            binaryMsg[k++] = bit + '0';
        }
    }
    binaryMsg[k] = '\0';

    // calculate number of bytes in message
    int numBytes = strlen(binaryMsg) / 8;

    // encode message in image
    unsigned char buffer;
    int c = 0;
    while (fread(&buffer, sizeof(unsigned char), 1, fp1) > 0) {
        if (c < numBytes * 8) {
            int bit = binaryMsg[c++] - '0';
            buffer = (buffer & 0xFE) | bit;
        }
        fwrite(&buffer, sizeof(unsigned char), 1, fp2);
    }

    fclose(fp1);
    fclose(fp2);
}

// function to decode message from image
void decode(char *outputFile) {
    FILE *fp;
    fp = fopen(outputFile, "rb");
    if (fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    // read header
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, fp);

    // decode message
    char binaryMsg[500];
    int i, j, k = 0;
    unsigned char buffer;
    while (fread(&buffer, sizeof(unsigned char), 1, fp) > 0) {
        int bit = buffer & 1;
        binaryMsg[k++] = bit + '0';
        if (k == 8*500) {
            printf("Image contains more than 500 bits of data!\n");
            break;
        }
    }
    binaryMsg[k] = '\0';

    // convert binary message to string
    int msgLen = strlen(binaryMsg) / 8;
    char message[100];
    k = 0;
    for (i = 0; i < msgLen; i++) {
        unsigned char ch = 0;
        for (j = 7; j >= 0; j--) {
            ch |= (binaryMsg[k++] - '0') << j;
        }
        message[i] = ch;
    }
    message[i] = '\0';

    printf("Decoded message: %s\n", message);

    fclose(fp);
}