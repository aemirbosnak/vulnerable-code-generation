//Gemma-7B DATASET v1.0 Category: Image Steganography ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MSG_SIZE 1024

void embed_message(char **image, char *message)
{
    int image_size = (*image)[0] * (*image)[1] * 3;
    int message_size = strlen(message);

    if (message_size > image_size)
    {
        printf("Error: Message too large for image.\n");
        exit(1);
    }

    int i, j, k = 0;
    for (i = 0; i < image_size; i++)
    {
        for (j = 0; j < 3; j++)
        {
            (*image)[i] = (*image)[i] & 0xFC | (message[k] & 0x3) << 2;
            k++;
        }
    }
}

int extract_message(char **image)
{
    int image_size = (*image)[0] * (*image)[1] * 3;
    int i, j, k = 0;
    char message[MAX_MSG_SIZE] = "";

    for (i = 0; i < image_size; i++)
    {
        for (j = 0; j < 3; j++)
        {
            int bit = (*image)[i] & 0x3;
            message[k] = (message[k] << 2) | bit;
            k++;
        }
    }

    return strlen(message);
}

int main()
{
    char *image = malloc(1024);
    image[0] = 1024;
    image[1] = 1024;
    image[2] = 3;

    char *message = "Hello, world!";

    embed_message(&image, message);

    int message_length = extract_message(&image);

    printf("Message length: %d\n", message_length);

    printf("Extracted message: %s\n", image);

    free(image);

    return 0;
}