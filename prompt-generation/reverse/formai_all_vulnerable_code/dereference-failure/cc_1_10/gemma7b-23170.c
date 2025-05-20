//Gemma-7B DATASET v1.0 Category: Image Steganography ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void embed(char *image, char *message)
{
    int i = 0, j = 0, k = 0;
    int image_size = strlen(image);
    int message_size = strlen(message);

    for (i = 0; i < image_size && j < message_size; i++)
    {
        image[i] ^= message[j] & 0x0F;
        j++;
    }
}

char *extract(char *image)
{
    int i = 0, message_size = 0;
    char *message = malloc(MAX);

    for (i = 0; image[i] & 0x0F; i++)
    {
        message_size++;
    }

    message = realloc(message, message_size);

    for (i = 0; i < message_size; i++)
    {
        message[i] = image[i] ^ 0x0F;
    }

    return message;
}

int main()
{
    char image[] = "Romeo.jpg";
    char message[] = "Juliet, my love";

    embed(image, message);

    char *extracted_message = extract(image);

    printf("Extracted message: %s\n", extracted_message);

    return 0;
}