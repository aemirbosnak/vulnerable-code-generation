//FormAI DATASET v1.0 Category: Image Steganography ; Style: light-weight
#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
#include <math.h>  

#define BYTE_SIZE 8  

/* bit mask to get one bit */
const int MASK[] = {128, 64, 32, 16, 8, 4, 2, 1};

/*function to get the binary representation of an integer*/
char *int_to_bin(int num) {
    char *bits = malloc(sizeof(char) * BYTE_SIZE + 1);

    for (int i = 0; i < BYTE_SIZE; i++) {
        if (((num << i) & 0x80) == 0x80) {
            bits[i] = '1';
        } else {
            bits[i] = '0';
        }
    }

    bits[BYTE_SIZE] = '\0';

    return bits;
}

/*function to set the ith bit of a byte to a certain value*/
void set_bit(unsigned char *byte, int position, int value) {
    if (value == 1) {
        *byte |= MASK[position];
    } else {
        *byte &= ~MASK[position];
    }
}

/*function to get the ith bit of a byte*/
int get_bit(unsigned char byte, int position) {
    return (byte & MASK[position]) != 0;
}

/*function to get the size of the file*/
long get_file_size(FILE *file) {
    long size;

    fseek(file, 0L, SEEK_END);
    size = ftell(file);
    rewind(file);

    return size;
}

/*function to hide a message in an image*/
void hide_message(FILE *image_file, char *message) {
    char *message_bits, ch;
    unsigned char byte;
    int message_size, bit_index = 0, byte_index = 0;

    /*get the size of the message*/
    message_size = strlen(message);
    message_bits = malloc(sizeof(char) * BYTE_SIZE * message_size + 1);

    /*convert the characters of the message to their binary representation*/
    for (int i = 0; i < message_size; i++) {
        char *char_bits = int_to_bin(message[i]);
        strcpy(message_bits + BYTE_SIZE * i, char_bits);
        free(char_bits);
    }

    /*calculate the total number of bits to hide*/
    int bits_to_hide = BYTE_SIZE * message_size;

    /*get the size of the image*/
    long image_size = get_file_size(image_file);

    /*check if there is enough space in the image to hide the message*/
    if (bits_to_hide > image_size * BYTE_SIZE) {
        printf("Error: message is too large for the given image.\n");
        exit(1);
    }

    /*hide the message in the image*/
    while ((ch = fgetc(image_file)) != EOF && bit_index < bits_to_hide) {
        byte = (unsigned char) ch;
        for (int i = 0; i < BYTE_SIZE && bit_index < bits_to_hide; i++) {
            set_bit(&byte, i, message_bits[bit_index] - '0');
            bit_index++;
        }
        fputc(byte, image_file);
    }

    /*if there are any bits left to hide, add an extra byte to the end of the image*/
    if (bit_index < bits_to_hide) {
        byte = 0;
        for (int i = 0; i < BYTE_SIZE && bit_index < bits_to_hide; i++) {
            set_bit(&byte, i, message_bits[bit_index] - '0');
            bit_index++;
        }
        fputc(byte, image_file);
    }

    /*add a null byte to the end of the message to mark the end of the message*/
    fputc('\0', image_file);

    free(message_bits);
}

/*function to retrieve a message from an image*/
void retrieve_message(FILE *image_file) {
    char *message_bits, *message;
    unsigned char byte;
    int bit_index = 0, message_length = 0;

    /*allocate memory for the array of bits*/
    message_bits = malloc(sizeof(char) * BYTE_SIZE);

    /*read each byte of the image*/
    while ((byte = fgetc(image_file)) != '\0') {
        /*extract the least significant bit of each byte*/
        for (int i = 0; i < BYTE_SIZE; i++) {
            message_bits[bit_index] = get_bit(byte, i) + '0';
            bit_index++;

            /*if we have read 8 bits, convert them to a character*/
            if (bit_index == BYTE_SIZE) {
                message_length++;
                message = realloc(message, sizeof(char) * message_length + 1);
                message[message_length - 1] = strtol(message_bits, NULL, 2);
                message[message_length] = '\0';

                free(message_bits);
                message_bits = malloc(sizeof(char) * BYTE_SIZE);
                bit_index = 0;
            }
        }
    }

    printf("Message hidden in the given image:\n%s\n", message);

    free(message_bits);
    free(message);
}

int main(int argc, char **argv) {
    FILE *image_file;
    char *message;

    if (argc != 4) {
        printf("Usage: %s [h/r] <image file> <message>\n", argv[0]);
        return 0;
    }

    image_file = fopen(argv[2], "r+");
    message = argv[3];

    if (image_file == NULL) {
        printf("Error: could not open file %s\n", argv[2]);
        return 1;
    }

    if (strcmp(argv[1], "h") == 0) {
        hide_message(image_file, message);
    } else if (strcmp(argv[1], "r") == 0) {
        retrieve_message(image_file);
    } else {
        printf("Error: invalid operation specified.\n");
        return 1;
    }

    fclose(image_file);

    return 0;
}