//FormAI DATASET v1.0 Category: Image Steganography ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024

// Function to hide the message in the image
void encode(char *image_path, char *message_path, char *output_path, char *key)
{
    FILE *image_file = fopen(image_path, "rb");
    FILE *message_file = fopen(message_path, "r");
    FILE *output_file = fopen(output_path, "wb");

    if (!image_file || !message_file || !output_file)
    {
        printf("Error opening files!");
        return;
    }

    int image_size;
    fread(&image_size, sizeof(int), 1, image_file);

    // Check if the size of the message is greater than the size of the image
    fseek(message_file, 0, SEEK_END);
    int message_size = ftell(message_file);
    if (message_size > image_size)
    {
        printf("Error: Message is too large to encode in the image!");
        return;
    }
    fseek(message_file, 0, SEEK_SET);

    // Write the size of the message to the output file
    fwrite(&message_size, sizeof(int), 1, output_file);

    // Write the key to the output file
    int key_length = strlen(key);
    fwrite(&key_length, sizeof(int), 1, output_file);
    fwrite(key, sizeof(char), key_length, output_file);

    // Hide the message in the image
    unsigned char image_buffer[MAX_SIZE];
    int bytes_read;
    int message_index = 0;
    while ((bytes_read = fread(image_buffer, sizeof(unsigned char), MAX_SIZE, image_file)) > 0)
    {
        for (int i = 0; i < bytes_read; i++)
        {
            if (message_index < message_size)
            {
                image_buffer[i] = (image_buffer[i] & 0xFE) | ((message_path[message_index] >> 7) & 0x01);
                message_path[message_index] <<= 1;
                message_index++;
            }
        }
        fwrite(image_buffer, sizeof(unsigned char), bytes_read, output_file);
    }

    printf("Steganography successful!\n");

    fclose(image_file);
    fclose(message_file);
    fclose(output_file);
}

// Function to decode the message from the image
void decode(char *output_path, char *key)
{
    FILE *output_file = fopen(output_path, "rb");

    if (!output_file)
    {
        printf("Error opening output file!");
        return;
    }

    int message_size;
    fread(&message_size, sizeof(int), 1, output_file);

    // Read the key from the output file
    int key_length;
    fread(&key_length, sizeof(int), 1, output_file);
    char *read_key = (char *)malloc(key_length * sizeof(char));
    fread(read_key, sizeof(char), key_length, output_file);

    if (strcmp(key, read_key) != 0)
    {
        printf("Error: Incorrect key!");
        free(read_key);
        return;
    }
    free(read_key);

    printf("Message size: %d\n", message_size);

    // Decode the message from the image
    unsigned char image_buffer[MAX_SIZE];
    int bytes_read;
    int message_index = 0;
    while ((bytes_read = fread(image_buffer, sizeof(unsigned char), MAX_SIZE, output_file)) > 0)
    {
        for (int i = 0; i < bytes_read; i++)
        {
            if (message_index < message_size)
            {
                printf("%c", ((image_buffer[i] & 0x01) << 7) | ((image_buffer[i + 1] & 0x01) << 6) | ((image_buffer[i + 2] & 0x01) << 5) | ((image_buffer[i + 3] & 0x01) << 4) | ((image_buffer[i + 4] & 0x01) << 3) | ((image_buffer[i + 5] & 0x01) << 2) | ((image_buffer[i + 6] & 0x01) << 1) | (image_buffer[i + 7] & 0x01));
                message_index++;
            }
        }
    }

    fclose(output_file);
}

int main()
{
    char image_path[] = "image.bmp";
    char message_path[] = "message.txt";
    char output_path[] = "output.bmp";
    char key[] = "my_key";

    // Encode the message in the image
    encode(image_path, message_path, output_path, key);

    // Decode the message from the image
    decode(output_path, key);

    return 0;
}