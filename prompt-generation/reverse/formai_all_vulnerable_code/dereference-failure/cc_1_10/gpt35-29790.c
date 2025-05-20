//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* This program demonstrates a basic example of digital watermarking using C language. */
/* It takes an input image file and embeds a secret message as a watermark using LSB algorithm. */ 

/*-------------------------------- Functions --------------------------------*/

/* function to embed watermark message into image */
void embedMessage(FILE *image, FILE *watermark, FILE *output, char message[])
{
    int ch, bit;
    char *msg = message;
    while (*msg)
    {
        ch = *msg;
        for (int i = 0; i < 8; i++)
        {
            bit = (ch & (1 << i)) ? 1 : 0;
            if (fread(&ch, 1, 1, image) == 0) /* if image has ended, exit the loop */
                return;
            ch = (ch & 0xFE) | bit; /* set last bit to message bit */
            fwrite(&ch, 1, 1, output);
        }
        msg++;
    }

    /* copy remaining data from image to output file */
    while (fread(&ch, 1, 1, image))
    {
        fwrite(&ch, 1, 1, output);
    }

    printf("Watermark embedded successfully!");
}

/* function to extract and print watermark message from image */
void extractMessage(FILE *image)
{
    char message[256];
    int ch, bit, count = 0;
    while (1)
    {
        ch = 0;
        for (int i = 0; i < 8; i++)
        {
            if (fread(&bit, 1, 1, image) == 0) /* if image has ended, exit the loop */
                goto Exit;
            ch |= bit << i; /* extract message bit from image byte */
        }
        if (ch == '\0') /* if end of message, exit the loop */
            break;
        message[count++] = ch;
    }
    message[count] = '\0';
    printf("The extracted message is: %s", message);

Exit:
    printf("\nWatermark extracted successfully!");
}

/*-------------------------------- Main --------------------------------*/

int main()
{
    FILE *image, *watermark, *output;
    char filename[50], message[256];

    printf("\nEnter the name of the image file: ");
    scanf("%s", filename);
    image = fopen(filename, "rb");
    if (image == NULL)
    {
        printf("Unable to open image file!");
        exit(1);
    }

    printf("Enter the name of the file containing watermark message: ");
    scanf("%s", filename);
    watermark = fopen(filename, "r");
    if (watermark == NULL)
    {
        printf("Unable to open watermark file!");
        exit(1);
    }

    printf("Enter the message to be embedded: ");
    scanf(" %[^\n]", message);

    output = fopen("output.bmp", "wb");
    if (output == NULL)
    {
        printf("Unable to create output file!");
        exit(1);
    }

    /* skip the header of the image file */
    fseek(image, 0L, SEEK_END);
    long int fileSize = ftell(image);
    fseek(image, 0L, SEEK_SET);
    int headerSize = fileSize - (512 * 512 * 3); // assuming header size is 54 bytes
    for (int i = 0; i < headerSize; i++)
    {
        getc(image);
    }

    /* copy header to output file */
    for (int i = 0; i < headerSize; i++)
    {
        putc(getc(image), output);
    }

    /* embed message and copy remaining data to output file */
    embedMessage(image, watermark, output, message);

    /* close files */
    fclose(image);
    fclose(watermark);
    fclose(output);

    /* extract watermark from output file and print message */
    output = fopen("output.bmp", "rb");
    if (output == NULL)
    {
        printf("Unable to open output file!");
        exit(1);
    }

    /* skip the header of the output file */
    fseek(output, 0L, SEEK_END);
    fileSize = ftell(output);
    fseek(output, 0L, SEEK_SET);
    headerSize = fileSize - (512 * 512 * 3); // assuming header size is 54 bytes
    for (int i = 0; i < headerSize; i++)
    {
        getc(output);
    }

    extractMessage(output);

    /* close files */
    fclose(output);

    printf("\n");
    return 0;
}