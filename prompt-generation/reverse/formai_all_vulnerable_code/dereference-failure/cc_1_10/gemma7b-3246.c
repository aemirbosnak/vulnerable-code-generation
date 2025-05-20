//Gemma-7B DATASET v1.0 Category: Image Steganography ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1024

int main()
{
    char *cover, *secret;
    int cover_size, secret_size, i, key, flag = 0;

    cover = (char *)malloc(MAX);
    secret = (char *)malloc(MAX);

    printf("Enter the size of the cover image (in KB): ");
    scanf("%d", &cover_size);

    printf("Enter the size of the secret message (in KB): ");
    scanf("%d", &secret_size);

    printf("Enter the key (an integer): ");
    scanf("%d", &key);

    printf("Enter the secret message: ");
    scanf("%s", secret);

    // Calculate the actual size of the cover and secret messages
    cover_size *= 1024;
    secret_size *= 1024;

    // Embed the secret message into the cover image
    for (i = 0; i < secret_size; i++)
    {
        cover[i] = secret[i] ^ key;
    }

    // Create a header for the hidden message
    for (i = secret_size; i < cover_size; i++)
    {
        cover[i] = 0x5F;
    }

    // Save the modified cover image
    FILE *fp = fopen("stego.jpg", "wb");
    fwrite(cover, cover_size, 1, fp);
    fclose(fp);

    // Flag to indicate successful embedding
    flag = 1;

    // Display a success message
    if (flag)
    {
        printf("Secret message successfully embedded into the cover image.\n");
    }

    return 0;
}