//Falcon2-11B DATASET v1.0 Category: Image Steganography ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <stdint.h>
#include <math.h>

#define SQUARE_IMAGE_SIZE (100)

// Function to convert a character to ASCII value
unsigned char char_to_ascii(char ch)
{
    return (unsigned char)ch;
}

// Function to get the ASCII value of a character
char ascii_to_char(unsigned char ch)
{
    return (char)ch;
}

// Function to convert a byte to ASCII value
unsigned char byte_to_ascii(unsigned char *bytes, int length)
{
    unsigned char ascii_value;
    for (int i = 0; i < length; i++)
    {
        ascii_value += char_to_ascii(bytes[i]);
    }
    return ascii_value;
}

// Function to convert a byte array to a string
char *byte_array_to_string(unsigned char *bytes, int length)
{
    char *str = (char*)malloc(length * sizeof(char));
    int index = 0;
    for (int i = 0; i < length; i++)
    {
        str[index++] = ascii_to_char(bytes[i]);
    }
    return str;
}

// Function to convert an image to grayscale
void convert_to_grayscale(unsigned char *image, int width, int height)
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int red = image[i * width + j * 3];
            int green = image[i * width + j * 3 + 1];
            int blue = image[i * width + j * 3 + 2];
            int gray = round((0.299 * red) + (0.587 * green) + (0.114 * blue));
            image[i * width + j * 3] = gray;
        }
    }
}

// Function to embed a message in an image
void embed_message(unsigned char *image, int width, int height, char *message, int length)
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int gray = image[i * width + j * 3];
            int index = gray % 255;
            int message_index = (length * index) % length;
            unsigned char *message_bytes = (unsigned char*)malloc(length * sizeof(unsigned char));
            for (int k = 0; k < length; k++)
            {
                message_bytes[k] = message[message_index + k];
            }
            unsigned char ascii_value = byte_to_ascii(message_bytes, length);
            image[i * width + j * 3] = ascii_value;
        }
    }
}

// Function to display an image
void display_image(unsigned char *image, int width, int height)
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int gray = image[i * width + j * 3];
            printf("%d ", gray);
        }
        printf("\n");
    }
}

// Function to display a string
void display_string(char *string)
{
    printf("%s", string);
}

// Function to generate a random string
char *generate_random_string(int length)
{
    srand(time(NULL));
    char *str = (char*)malloc(length * sizeof(char));
    for (int i = 0; i < length; i++)
    {
        str[i] = 'a' + (rand() % 26);
    }
    return str;
}

// Main function
int main()
{
    // Generate a random string
    char *message = generate_random_string(10);

    // Create an array of grayscale pixels for the cover image
    unsigned char cover_image[SQUARE_IMAGE_SIZE * SQUARE_IMAGE_SIZE];

    // Convert the cover image to grayscale
    convert_to_grayscale(cover_image, SQUARE_IMAGE_SIZE, SQUARE_IMAGE_SIZE);

    // Display the original cover image
    display_image(cover_image, SQUARE_IMAGE_SIZE, SQUARE_IMAGE_SIZE);

    // Embed the message in the cover image
    embed_message(cover_image, SQUARE_IMAGE_SIZE, SQUARE_IMAGE_SIZE, message, strlen(message));

    // Display the stego image
    display_image(cover_image, SQUARE_IMAGE_SIZE, SQUARE_IMAGE_SIZE);

    // Display the embedded message
    display_string(message);

    return 0;
}