//FormAI DATASET v1.0 Category: Image Steganography ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 10000000
#define HEADER_SIZE 54

typedef struct{
    unsigned char r, g, b;
} PIXEL;

typedef struct {
    unsigned int size;
    unsigned short int reserved1, reserved2;
    unsigned int offset;
} BMP_HEADER;

typedef struct {
    unsigned int size, width, height;
    unsigned short int planes, bitsPerPixel;
    unsigned int compression, imageSize;
    int xResolution, yResolution;
    unsigned int numOfColors, importantColors;
} BMP_INFO_HEADER;

int embedMessage(char *fileName, char *message)
{
    FILE *f, *f_message;
    BMP_HEADER header;
    BMP_INFO_HEADER info_header;
    PIXEL *pixels;
    char c, *binary_message;
    unsigned int i, j, message_length;

    // Read the BMP file
    f = fopen(fileName, "rb");

    if (f == NULL){
        printf("Error: Unable to open file.\n");
        return -1;
    }

    fread(&header, sizeof(BMP_HEADER), 1, f);
    fread(&info_header, sizeof(BMP_INFO_HEADER), 1, f);

    // Validate that the BMP file has 24 bits per pixel
    if (info_header.bitsPerPixel != 24){
        printf("Error: Only bitmaps with 24 bits per pixel can be used.\n");
        return -1;
    }

    // Allocate memory for pixel data
    pixels = malloc(sizeof(PIXEL) * info_header.width * info_header.height);
    fread(pixels, sizeof(PIXEL), info_header.width * info_header.height, f);

    fclose(f);

    // Read the message to embed
    f_message = fopen(message, "rb");

    if (f_message == NULL){
        printf("Error: Unable to open message file.\n");
        return -1;
    }

    fseek(f_message, 0L, SEEK_END);
    message_length = ftell(f_message);
    fseek(f_message, 0L, SEEK_SET);

    binary_message = malloc(message_length * 8 + 1);

    // Convert message to binary string
    i = 0;
    while ((c = fgetc(f_message)) != EOF){
        for (j = 0; j < 8; j++) {
            char bit = (c >> j) & 1;
            binary_message[i++] = bit ? '1' : '0';
        }
    }

    binary_message[i] = '\0';
    fclose(f_message);

    // Add message length to the header of the BMP file
    if (info_header.height * info_header.width <= strlen(binary_message)){
        printf("Error: Message too large to embed in BMP image.\n");
        return -1;
    }

    char length_string[32];
    sprintf(length_string, "%d", message_length);
    char *header_bytes = malloc(sizeof(char) * HEADER_SIZE);
    memcpy(header_bytes, &header, sizeof(BMP_HEADER));
    memcpy(header_bytes + sizeof(BMP_HEADER), &info_header, sizeof(BMP_INFO_HEADER));
    memcpy(header_bytes + HEADER_SIZE - sizeof(char) * strlen(length_string), length_string, strlen(length_string));
    memcpy(&header, header_bytes, sizeof(BMP_HEADER));

    // Embed the message in the pixel data
    PIXEL *curr_pixel = pixels;
    for (i = 0; i < strlen(binary_message); i++) {
        if ((binary_message[i] - '0') == curr_pixel->r % 2)
            curr_pixel->r++;
        if ((binary_message[i] - '0') == curr_pixel->g % 2)
            curr_pixel->g++;
        if ((binary_message[i] - '0') == curr_pixel->b % 2)
            curr_pixel->b++;

        curr_pixel++;
    }

    // Write the modified pixel data to a new BMP file
    char *new_file_name = malloc(sizeof(char) * (strlen(fileName) + 11));
    sprintf(new_file_name, "steg_%s", fileName);
    f = fopen(new_file_name, "wb");

    if (f == NULL){
        printf("Error: Unable to open file to write steganogram.\n");
        return -1;
    }

    fwrite(&header, sizeof(BMP_HEADER), 1, f);
    fwrite(&info_header, sizeof(BMP_INFO_HEADER), 1, f);
    fwrite(pixels, sizeof(PIXEL), info_header.width * info_header.height, f);

    // Cleanup
    fclose(f);
    free(pixels);
    free(binary_message);
    free(header_bytes);
    free(new_file_name);

    return 0;
}

int extractMessage(char *fileName, char *messageFileName)
{
    FILE *f, *f_message;
    BMP_HEADER header;
    BMP_INFO_HEADER info_header;
    PIXEL *pixels;
    char *binary_message;
    unsigned int i;

    // Read the BMP file
    f = fopen(fileName, "rb");

    if (f == NULL){
        printf("Error: Unable to open file.\n");
        return -1;
    }

    fread(&header, sizeof(BMP_HEADER), 1, f);
    fread(&info_header, sizeof(BMP_INFO_HEADER), 1, f);

    // Validate that the BMP file has 24 bits per pixel
    if (info_header.bitsPerPixel != 24){
        printf("Error: Only bitmaps with 24 bits per pixel can be used.\n");
        return -1;
    }

    // Allocate memory for pixel data
    pixels = malloc(sizeof(PIXEL) * info_header.width * info_header.height);
    fread(pixels, sizeof(PIXEL), info_header.width * info_header.height, f);

    // Extract the message from the pixel data
    char length_string[32];
    memcpy(length_string, &header + sizeof(BMP_HEADER) + sizeof(BMP_INFO_HEADER), HEADER_SIZE - sizeof(BMP_HEADER) - sizeof(BMP_INFO_HEADER));
    unsigned int message_length = atoi(length_string);

    binary_message = malloc((message_length * 8) + 1);

    PIXEL *curr_pixel = pixels;
    for (i = 0; i < message_length * 8; i++) {
        binary_message[i] = (char)(curr_pixel->r % 2) + '0';
        curr_pixel++;
    }

    binary_message[i] = '\0';

    // Write the message to a new file
    f_message = fopen(messageFileName, "wb");

    if (f_message == NULL){
        printf("Error: Unable to open file to write message.\n");
        return -1;
    }

    for (i = 0; i < message_length / 8; i++) {
        char c = 0;
        int j;

        for (j = 0; j < 8; j++){
            c = c | ((binary_message[i * 8 + j] - '0') << j);
        }

        fputc(c, f_message);
    }

    // Cleanup
    fclose(f);
    fclose(f_message);
    free(pixels);
    free(binary_message);

    return 0;
}

int main()
{
    int choice;
    char fileName[256], messageFileName[256];

    printf("1. Embed message in BMP image.\n");
    printf("2. Extract message from BMP image.\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);

    printf("Enter the name of the BMP file: ");
    scanf("%s", fileName);

    if (choice == 1){
        printf("Enter the name of the text file containing the message: ");
        scanf("%s", messageFileName);
        embedMessage(fileName, messageFileName);
    }
    else if (choice == 2){
        printf("Enter the name of the file to write the extracted message to: ");
        scanf("%s", messageFileName);
        extractMessage(fileName, messageFileName);
    }
    else{
        printf("Invalid choice.\n");
    }

    return 0;
}