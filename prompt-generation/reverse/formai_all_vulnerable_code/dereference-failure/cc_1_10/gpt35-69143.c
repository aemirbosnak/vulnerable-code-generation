//FormAI DATASET v1.0 Category: Image Steganography ; Style: accurate
#include<stdio.h>
#include<stdlib.h>

int main()
{
    FILE *img, *stego_img;
    char img_name[30], stego_name[30], secret_msg[100];
    int i, j, bit, byte, bit_count = 0, secret_size, img_size;

    printf("Enter the name/path of the image file: ");
    scanf("%s", img_name);
    img = fopen(img_name, "rb");
    if(img == NULL)
    {
        printf("Error! Failed to open image file.\n");
        exit(1);
    }

    printf("Enter the secret message to hide: ");
    getchar();
    fgets(secret_msg, 100, stdin);
    secret_size = strlen(secret_msg);

    printf("Enter the name/path of the steganographed image file: ");
    scanf("%s", stego_name);
    stego_img = fopen(stego_name, "wb");
    if(stego_img == NULL)
    {
        printf("Error! Failed to create steganographed image file.\n");
        exit(1);
    }

    // Get image size
    fseek(img, 0, SEEK_END);
    img_size = ftell(img);
    fseek(img, 0, SEEK_SET);

    // Write image header to stego image file
    for(i=0; i<54; i++)
    {
        byte = getc(img);
        putc(byte, stego_img);
    }

    // Write secret message size to stego image file
    for(i=0; i<4; i++)
    {
        byte = (secret_size >> i*8) & 0xff;
        putc(byte, stego_img);
    }

    // Write secret message to stego image file
    for(i=0; i<secret_size; i++)
    {
        byte = secret_msg[i];
        for(j=0; j<8; j++)
        {
            bit = (byte >> j) & 0x01;
            putc((getc(img) & 0xfe) | bit, stego_img);
            bit_count++;
            if(bit_count >= img_size-54)
                goto end;
        }
    }

    // Write remaining image bytes to stego image file
    while((byte = getc(img)) != EOF)
    {
        putc(byte, stego_img);
        bit_count++;
        if(bit_count >= img_size-54)
            break;
    }

    // Close files
    end:
    printf("Secret message hidden successfully in the image file.\n");
    fclose(img);
    fclose(stego_img);

    return 0;
}