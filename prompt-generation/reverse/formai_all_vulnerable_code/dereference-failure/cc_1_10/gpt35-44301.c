//FormAI DATASET v1.0 Category: Image Steganography ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SIZE 1000000

int offset = 0;

void hide(char *image_file, char *message_file, char *output_file);
void retrieve(char *image_file, char *output_file);

int main()
{
    char choice;
    char image_file[100], message_file[100], output_file[100];
    printf("\t\tSteganography\n\n");
    printf("1. Hide Message\n");
    printf("2. Retrieve Message\n");
    printf("Enter choice: ");
    scanf("%c", &choice);
    fflush(stdin);
    switch (choice)
    {
    case '1':
        printf("\nEnter the cover image file path: ");
        scanf("%[^\n]", image_file);
        fflush(stdin);
        printf("\nEnter the secret message file path: ");
        scanf("%[^\n]", message_file);
        fflush(stdin);
        printf("\nEnter the output image file path: ");
        scanf("%[^\n]", output_file);
        hide(image_file, message_file, output_file);
        break;
    case '2':
        printf("\nEnter the image file path: ");
        scanf("%[^\n]", image_file);
        fflush(stdin);
        printf("\nEnter the output message file path: ");
        scanf("%[^\n]", output_file);
        retrieve(image_file, output_file);
        break;
    default:
        printf("\nInvalid choice!\n");
        break;
    }
    return 0;
}

void encode(unsigned char *img_buffer, unsigned char bit, int position)
{
    if (position % 8 == 0 && position != 0)
    {
        offset++;
    }

    img_buffer[offset] = (img_buffer[offset] & ~(1 << (7 - (position % 8)))) | (bit << (7 - (position % 8)));
}

unsigned char decode(unsigned char *img_buffer, int position)
{
    return ((img_buffer[offset] & (1 << (7 - (position % 8)))) >> (7 - (position % 8)));
}

void hide(char *image_file, char *message_file, char *output_file)
{
    FILE *fp_image = fopen(image_file, "rb");
    FILE *fp_message = fopen(message_file, "r");
    FILE *fp_output = fopen(output_file, "wb");

    if (fp_image == NULL || fp_message == NULL || fp_output == NULL)
    {
        printf("\nError opening file!\n");
        exit(1);
    }

    unsigned char img_buffer[MAX_SIZE], i, bit;
    int img_size, msg_size, encoded_bits = 0, hidden_bits = 0;
    fseek(fp_image, 0, SEEK_END);
    img_size = ftell(fp_image);
    rewind(fp_image);
    fread(img_buffer, 1, img_size, fp_image);
    fclose(fp_image);

    char message[MAX_SIZE];
    fgets(message, MAX_SIZE, fp_message);
    msg_size = strlen(message);
    fclose(fp_message);

    if (msg_size * 8 > img_size - 54)
    {
        printf("\nImage size too small to hide data!\n");
        exit(1);
    }

    for (i = 0; i < 24; i++)
    {
        encode(img_buffer, decode(img_buffer, i), i * 8);
    }

    for (i = 0; i < msg_size; i++)
    {
        bit = 1 & (message[i] >> 7);
        encode(img_buffer, bit, (i * 8) + 24 + encoded_bits++);

        bit = 1 & (message[i] >> 6);
        encode(img_buffer, bit, (i * 8) + 24 + encoded_bits++);

        bit = 1 & (message[i] >> 5);
        encode(img_buffer, bit, (i * 8) + 24 + encoded_bits++);

        bit = 1 & (message[i] >> 4);
        encode(img_buffer, bit, (i * 8) + 24 + encoded_bits++);

        bit = 1 & (message[i] >> 3);
        encode(img_buffer, bit, (i * 8) + 24 + encoded_bits++);

        bit = 1 & (message[i] >> 2);
        encode(img_buffer, bit, (i * 8) + 24 + encoded_bits++);

        bit = 1 & (message[i] >> 1);
        encode(img_buffer, bit, (i * 8) + 24 + encoded_bits++);

        bit = 1 & (message[i] >> 0);
        encode(img_buffer, bit, (i * 8) + 24 + encoded_bits++);
    }

    fwrite(img_buffer, 1, img_size, fp_output);
    fclose(fp_output);
    printf("\nMessage successfully hidden in image.\n");
}

void retrieve(char *image_file, char *output_file)
{
    FILE *fp_image = fopen(image_file, "rb");
    FILE *fp_output = fopen(output_file, "w");
    if (fp_image == NULL || fp_output == NULL)
    {
        printf("\nError opening file!\n");
        exit(1);
    }

    unsigned char img_buffer[MAX_SIZE], i, bit, message_byte = 0;
    int img_size, decoded_bits = 0;
    fseek(fp_image, 0, SEEK_END);
    img_size = ftell(fp_image);
    rewind(fp_image);
    fread(img_buffer, 1, img_size, fp_image);
    fclose(fp_image);

    for (i = 0; i < 24; i++)
    {
        bit = decode(img_buffer, i * 8);
        message_byte = (message_byte << 1) | bit;
    }

    int msg_size = message_byte;
    char message[MAX_SIZE];

    for (i = 0; i < msg_size; i++)
    {
        message_byte = 0;
        message_byte = (message_byte << 1) | decode(img_buffer, (i * 8) + 24 + decoded_bits++);
        message_byte = (message_byte << 1) | decode(img_buffer, (i * 8) + 24 + decoded_bits++);
        message_byte = (message_byte << 1) | decode(img_buffer, (i * 8) + 24 + decoded_bits++);
        message_byte = (message_byte << 1) | decode(img_buffer, (i * 8) + 24 + decoded_bits++);
        message_byte = (message_byte << 1) | decode(img_buffer, (i * 8) + 24 + decoded_bits++);
        message_byte = (message_byte << 1) | decode(img_buffer, (i * 8) + 24 + decoded_bits++);
        message_byte = (message_byte << 1) | decode(img_buffer, (i * 8) + 24 + decoded_bits++);
        message_byte = (message_byte << 1) | decode(img_buffer, (i * 8) + 24 + decoded_bits++);
        message[i] = message_byte;
    }

    fprintf(fp_output, "%s", message);
    fclose(fp_output);
    printf("\nMessage successfully retrieved from image.\n");
}