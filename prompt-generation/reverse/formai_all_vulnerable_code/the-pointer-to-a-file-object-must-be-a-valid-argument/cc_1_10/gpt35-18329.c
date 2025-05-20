//FormAI DATASET v1.0 Category: Image Steganography ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BYTESIZE 8
#define MAXCHAR 1000

char* readMessageFromFile(char* filename) {
    FILE* fp = fopen(filename, "r");
    char* message = malloc(MAXCHAR * sizeof(char));
    fgets(message, MAXCHAR, fp);
    fclose(fp);
    return message;
}

void writeMessageToFile(char* message, char* filename) {
    FILE* fp = fopen(filename, "w");
    fprintf(fp, "%s", message);
    fclose(fp);
}

int* decimalToBinary(int decimal) {
    int* binary = malloc(BYTESIZE * sizeof(int));
    int copy = decimal;
    for (int i = BYTESIZE - 1; i >= 0; i--) {
        binary[i] = copy % 2;
        copy = copy / 2;
    }
    return binary;
}

int binaryToDecimal(int* binary) {
    int decimal = 0;
    for (int i = 0; i < BYTESIZE; i++) {
        decimal += binary[i] * (1 << (BYTESIZE - 1 - i));
    }
    return decimal;
}

void encodeMessage(char* message, char* imageFilename, char* outputFilename) {
    FILE* fp_image = fopen(imageFilename, "r");
    FILE* fp_output = fopen(outputFilename, "w");
    int messageLength = strlen(message);
    fprintf(fp_output, "%d\n", messageLength); // The first line in the output will be the message length in binary
    for (int i = 0; i < messageLength; i++) {
        char c = message[i];
        int* binary = decimalToBinary(c);
        for (int j = 0; j < BYTESIZE; j++) {
            int bit;
            fread(&bit, 1, 1, fp_image); // Read a single bit from the image
            int newbit = ((bit & 0xFE) | binary[j]); // Change the least significant bit to the j-th bit of the binary representation of c
            fwrite(&newbit, 1, 1, fp_output); // Write the new bit to the output file
        }
        free(binary);
    }
    int bit;
    while (fread(&bit, 1, 1, fp_image) == 1) { // Copy the remaining bits of the image to the output file
        fwrite(&bit, 1, 1, fp_output);
    }
    fclose(fp_image);
    fclose(fp_output);
}

char* decodeMessage(char* outputFilename) {
    FILE* fp_output = fopen(outputFilename, "r");
    int messageLength;
    fscanf(fp_output, "%d", &messageLength); // Read the message length from the output file
    char* message = malloc((messageLength + 1) * sizeof(char));
    message[messageLength] = '\0';
    int i = 0;
    while (i < messageLength) {
        int* binary = malloc(BYTESIZE * sizeof(int));
        for (int j = 0; j < BYTESIZE; j++) {
            int bit;
            fread(&bit, 1, 1, fp_output); // Read a single bit from the output file
            binary[j] = bit & 0x01; // The least significant bit is the j-th bit of the binary representation of the message character
        }
        message[i++] = binaryToDecimal(binary);
        free(binary);
    }
    fclose(fp_output);
    return message;
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        printf("Usage: %s <message_filename> <image_filename> <output_filename>\n", argv[0]);
        exit(1);
    }
    char* message = readMessageFromFile(argv[1]);
    encodeMessage(message, argv[2], argv[3]);
    printf("Message encoded successfully in %s\n", argv[3]);
    char* decodedMessage = decodeMessage(argv[3]);
    writeMessageToFile(decodedMessage, "decoded_message.txt");
    printf("Message decoded successfully in decoded_message.txt\n");
    free(message);
    free(decodedMessage);
    return 0;
}