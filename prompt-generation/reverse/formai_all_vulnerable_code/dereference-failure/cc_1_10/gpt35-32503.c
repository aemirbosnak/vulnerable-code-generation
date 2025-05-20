//FormAI DATASET v1.0 Category: Image Steganography ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

/* function to get the binary representation of an integer */
void intToBinary(int num, char* binary) {
    int i = 0;
    while (num > 0) {
        binary[i++] = (num % 2) + '0';
        num = num / 2;
    }
    binary[i] = '\0';
}

/* function to get the integer value of a binary string */
int binaryToInt(char* binary) {
    int num = 0;
    int i = 0;
    while (binary[i] != '\0') {
        num = num * 2 + (binary[i] - '0');
        i++;
    }
    return num;
}

/* function to hide a message in an image */
void hideMessage(char* imageFilePath, char* message, char* steganoImageFilePath) {
    FILE* fp1, * fp2;
    fp1 = fopen(imageFilePath, "rb");
    fp2 = fopen(steganoImageFilePath, "wb");

    if (fp1 == NULL || fp2 == NULL) {
        printf("Error: Failed to open files\n");
        exit(0);
    }

    int byte, i, j = 0;
    char binary[9];

    /* read each byte from the image file */
    while ((byte = fgetc(fp1)) != EOF) {
        /* get the binary representation of the byte */
        intToBinary(byte, binary);

        /* check if we have any more characters to hide in the message */
        if (message[j] == '\0') {
            /* no more characters to hide, write the remaining bytes of the image to stegano image */
            while ((byte = fgetc(fp1)) != EOF) {
                fputc(byte, fp2);
            }
            break;
        }

        /* loop through each bit of the binary representation */
        for (i = 0; i < 8; i++) {
            if (message[j] == '\0') {
                /* no more characters to hide, write the remaining bits of the byte to stegano image */
                for (; i < 8; i++) {
                    binary[i] = '\0';
                }
                fputc(binaryToInt(binary), fp2);
                break;
            }

            /* modify the last bit of the byte with the bit of the current character in the message */
            binary[7] = message[j] & 1 ? '1' : '0';
            message[j] = message[j] >> 1;

            j++;

            /* write the modified byte to the stegano image */
            fputc(binaryToInt(binary), fp2);
        }
    }

    fclose(fp1);
    fclose(fp2);

    printf("Message successfully hidden in the image!\nStegano image saved in %s\n", steganoImageFilePath);
}

/* function to retrieve a hidden message from an image */
void retrieveMessage(char* steganoImageFilePath) {
    FILE* fp;
    fp = fopen(steganoImageFilePath, "rb");

    if (fp == NULL) {
        printf("Error: Failed to open file\n");
        exit(0);
    }

    int byte, i, count = 0;
    char binary[9], message[100];

    /* read each byte from the stegano image */
    while ((byte = fgetc(fp)) != EOF) {
        /* get the binary representation of the byte */
        intToBinary(byte, binary);

        /* get the last bit of the byte */
        char lastBit = binary[7];

        /* add the last bit to the message */
        message[count] = lastBit;

        /* increment the count */
        count++;

        /* check if we have enough bits to construct a character */
        if (count % 8 == 0) {
            /* get the binary representation of the character */
            for (i = 0; i < 8; i++) {
                binary[i] = message[count - i - 1];
            }
            binary[8] = '\0';

            /* add the character to the message */
            printf("%c", binaryToInt(binary));
        }
    }

    printf("\nMessage successfully retrieved from the image!\n");

    fclose(fp);
}

/* main function */
int main() {
    char imageFilePath[100] = "image.bmp";
    char message[100] = "This is a hidden message!";
    char steganoImageFilePath[100] = "stegano_image.bmp";

    /* hide message in the image */
    hideMessage(imageFilePath, message, steganoImageFilePath);

    /* retrieve message from the stegano image */
    retrieveMessage(steganoImageFilePath);

    return 0;
}