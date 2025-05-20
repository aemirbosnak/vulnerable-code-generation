//FormAI DATASET v1.0 Category: Image Steganography ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BMP_HEADER_SIZE 54
#define MAX_MESSAGE_SIZE 100

int hide_message(char *bmp_filename, char *message)
{
    FILE *bmp_file = fopen(bmp_filename, "rb+");

    if (bmp_file == NULL) {
        printf("Error: Could not open BMP file\n");
        return 1;
    }

    fseek(bmp_file, 0, SEEK_END);
    long int bmp_size = ftell(bmp_file);
    rewind(bmp_file);

    char *bmp_data = malloc(bmp_size);

    fread(bmp_data, 1, bmp_size, bmp_file);

    int message_length = strlen(message);

    if (message_length > MAX_MESSAGE_SIZE) {
        printf("Error: Message too long\n");
        return 1;
    }

    unsigned char *message_data = (unsigned char *) message;

    int i, j;

    for (i = BMP_HEADER_SIZE, j = 0; j < message_length; i += 3, j++) {
        bmp_data[i] = (bmp_data[i] & 0xFC) | ((message_data[j] >> 6) & 0x03);
        bmp_data[i+1] = (bmp_data[i+1] & 0xFC) | ((message_data[j] >> 4) & 0x03);
        bmp_data[i+2] = (bmp_data[i+2] & 0xFC) | ((message_data[j] >> 2) & 0x03);
    }

    fseek(bmp_file, 0, SEEK_SET);
    fwrite(bmp_data, 1, bmp_size, bmp_file);

    fclose(bmp_file);

    free(bmp_data);

    return 0;
}

int read_message(char *bmp_filename)
{
    FILE *bmp_file = fopen(bmp_filename, "rb");

    if (bmp_file == NULL) {
        printf("Error: Could not open BMP file\n");
        return 1;
    }

    fseek(bmp_file, 0, SEEK_END);
    long int bmp_size = ftell(bmp_file);
    rewind(bmp_file);

    char *bmp_data = malloc(bmp_size);

    fread(bmp_data, 1, bmp_size, bmp_file);

    int i, j;

    for (i = BMP_HEADER_SIZE, j = 0; i < bmp_size && j < MAX_MESSAGE_SIZE; i += 3, j++) {
        unsigned char message_byte = 0;
        message_byte |= (bmp_data[i] & 0x03) << 6;
        message_byte |= (bmp_data[i+1] & 0x03) << 4;
        message_byte |= (bmp_data[i+2] & 0x03) << 2;
        printf("%c", (char) message_byte);
    }

    printf("\n");

    fclose(bmp_file);

    free(bmp_data);

    return 0;
}

int main()
{
    char *bmp_filename = "image.bmp";
    char *message = "This is a secret message!";

    hide_message(bmp_filename, message);

    read_message(bmp_filename);

    return 0;
}