//FormAI DATASET v1.0 Category: Image Steganography ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

void hide(unsigned char *input, unsigned char *output, char *message, int mess_len) {
    int i, j;

    for(i = 0; i < mess_len; i++) {
        char c = message[i];

        for(j = 0; j < 8; j++) {
            if(((c >> (7 - j)) & 1) == 0) {
                output[i] &= 0xFE;
            } else {
                output[i] |= 0x01;
            }

            input++;
        }
    }
}

void reveal(unsigned char *encoded_img, int size) {
    int i, j;
    char c = 0;

    for(i = 0; i < size; i++) {
        for(j = 0; j < 8; j++) {
            c <<= 1;
            c |= encoded_img[i] & 1;

            encoded_img++;
        }

        if(c == '\0') {
            break;
        }

        printf("%c",c);
    }

    printf("\n");
}

int main() {
    FILE *input_img = fopen("input.bmp", "rb");
    FILE *output_img = fopen("output.bmp", "wb");

    if(!input_img || !output_img) {
        printf("Error: could not find input.bmp or could not create output.bmp");
        exit(1);
    }

    fseek(input_img, 0, SEEK_END);
    int size = ftell(input_img);
    fseek(input_img, 0, SEEK_SET);

    unsigned char *input = (unsigned char*)malloc(size);
    unsigned char *output = (unsigned char*)malloc(size);

    fread(input, size, 1, input_img);

    int mess_len = 6;
    char *message = "Hello!";

    hide(input, output, message, mess_len);

    fwrite(output, size, 1, output_img);

    rewind(output_img);

    unsigned char *encoded_img = (unsigned char*)malloc(size);

    fread(encoded_img, size, 1, output_img);

    reveal(encoded_img, size);

    fclose(input_img);
    fclose(output_img);

    free(input);
    free(output);
    free(encoded_img);

    return 0;
}