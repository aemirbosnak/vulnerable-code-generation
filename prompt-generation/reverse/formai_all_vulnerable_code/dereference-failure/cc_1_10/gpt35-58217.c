//FormAI DATASET v1.0 Category: Image Steganography ; Style: rigorous
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define BYTESIZE 8

void hideMessage(char* message, char* image_path, char* output_path);
void showMessage(char* image_path);

int main(int argc, char** argv)
{
    if(argc != 4)
    {
        printf("Usage: %s [hide/show] [message/image path] [output path]\n", argv[0]);
        return 1;
    }
    if(strcmp(argv[1], "hide") == 0)
    {
        char* message_path = argv[2];
        char* image_path = argv[3];
        hideMessage(message_path, image_path, "output.bmp");
        printf("Message hidden succesfully!\n");
    }
    else if(strcmp(argv[1], "show") == 0)
    {
        char* image_path = argv[2];
        showMessage(image_path);
    }
    else
    {
        printf("Invalid command!\n");
        return 1;
    }
    return 0;
}

/*
    Hides the message in the image specified by image_path and saves the output in the file specified by output_path.
*/
void hideMessage(char* message_path, char* image_path, char* output_path)
{
    // Read the message
    FILE* fp = fopen(message_path, "rb");
    if(fp == NULL)
    {
        printf("Error: Could not open file %s!", message_path);
        exit(1);
    }
    fseek(fp, 0L, SEEK_END);
    int message_size = ftell(fp);
    fseek(fp, 0L, SEEK_SET);
    char* message = (char*)malloc(message_size);
    fread(message, message_size, 1, fp);
    fclose(fp);

    // Open the image file
    fp = fopen(image_path, "rb");
    if(fp == NULL)
    {
        printf("Error: Could not open file %s!", image_path);
        exit(1);
    }

    // Read the header
    char header[54];
    fread(header, 54, 1, fp);

    // Get the image dimensions
    int width = *(int*)&header[18];
    int height = *(int*)&header[22];

    // Calculate the number of pixels
    int num_pixels = width * height;

    // Calculate the number of bytes needed to store the hidden message
    int message_bytes = message_size * BYTESIZE;

    // Check if the message can fit in the image
    if(num_pixels * 3 < message_bytes)
    {
        printf("Error: Message is too large to fit in the image!");
        exit(1);
    }

    // Read the image data
    unsigned char* data = (unsigned char*)malloc(num_pixels * 3);
    fread(data, num_pixels * 3, 1, fp);
    fclose(fp);

    // Encode the message into the data
    int data_index = 0;
    for(int i=0; i<message_bytes; i++)
    {
        int bit = (message[i/8] >> (BYTESIZE-1 - i%8)) & 0x01; // Get the i-th bit from the message
        if(data_index >= num_pixels * 3) break;
        if(bit)
        {
            // Set the least significant bit to 1
            data[data_index++] |= 0x01;
        }
        else
        {
            // Set the least significant bit to 0
            data[data_index++] &= 0xFE;
        }
    }

    // Write the output image
    fp = fopen(output_path, "wb");
    fwrite(header, 54, 1, fp);
    fwrite(data, num_pixels * 3, 1, fp);
    fclose(fp);

    free(data);
    free(message);
}

/*
    Extracts and displays the hidden message from the image specified by image_path.
*/
void showMessage(char* image_path)
{
    // Open the image file
    FILE* fp = fopen(image_path, "rb");
    if(fp == NULL)
    {
        printf("Error: Could not open file %s!", image_path);
        exit(1);
    }

    // Read the header
    char header[54];
    fread(header, 54, 1, fp);

    // Get the image dimensions
    int width = *(int*)&header[18];
    int height = *(int*)&header[22];

    // Calculate the number of pixels
    int num_pixels = width * height;

    // Read the image data
    unsigned char* data = (unsigned char*)malloc(num_pixels * 3);
    fread(data, num_pixels * 3, 1, fp);
    fclose(fp);

    // Extract the message from the data
    char* message = (char*)malloc(num_pixels * 3 / BYTESIZE);
    int message_index = 0;
    for(int i=0; i<num_pixels * 3; i++)
    {
        if(message_index >= num_pixels * 3 / BYTESIZE) break;
        int bit = data[i] & 0x01; // Get the least significant bit from the pixel
        message[message_index/8] |= bit << (BYTESIZE-1 - message_index%8);
        message_index++;
    }

    printf("Hidden message: %s\n", message);

    free(data);
    free(message);
}