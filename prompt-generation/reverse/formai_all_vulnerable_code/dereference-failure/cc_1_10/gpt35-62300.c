//FormAI DATASET v1.0 Category: Image Steganography ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Welcome to the Image Steganography program!\n\n");

    // get image name from user
    char input_name[50];
    printf("Enter the name of the image you want to encrypt: ");
    scanf("%s", input_name);

    // open input file
    FILE *input_file = fopen(input_name, "rb");
    if (input_file == NULL)
    {
        printf("Error opening file. Please try again.\n");
        return 1;
    }

    // get message from user
    char message[100];
    printf("\nEnter the secret message you want to hide in the image: ");
    scanf("%s", message);

    // get output file name from user
    char output_name[50];
    printf("\nEnter the name of the output file (with .bmp extension): ");
    scanf("%s", output_name);

    // open output file
    FILE *output_file = fopen(output_name, "wb");
    if (output_file == NULL)
    {
        printf("Error opening file. Please try again.\n");
        return 1;
    }

    // read header from input file
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, input_file);

    // write header to output file
    fwrite(header, sizeof(unsigned char), 54, output_file);

    // calculate size of input and output files
    fseek(input_file, 0, SEEK_END);
    int input_size = ftell(input_file);
    int output_size = ftell(output_file);
    fseek(input_file, 0, SEEK_SET);

    // read image data from input file
    unsigned char *image_data = (unsigned char*)malloc(input_size - 54);
    fread(image_data, sizeof(unsigned char), input_size - 54, input_file);

    // hide message in image data
    int message_length = strlen(message);
    for (int i = 0; i < message_length; i++)
    {
        // convert character to binary string
        char binary[9];
        int num = (int)message[i];
        for (int j = 0; j < 8; j++)
        {
            binary[7-j] = num % 2 + '0';
            num /= 2;
        }
        binary[8] = '\0';

        // hide each bit of binary string in each byte of image data
        for (int k = 0; k < 8; k++)
        {
            if ((image_data[i*3 + k/3] & (0x01 << (k%3))) > 0)
            {
                if (binary[k] == '0')
                {
                    image_data[i*3 + k/3] &= ~(0x01 << (k%3));
                }
            }
            else
            {
                if (binary[k] == '1')
                {
                    image_data[i*3 + k/3] |= (0x01 << (k%3));
                }
            }
        }
    }

    // write modified image data to output file
    fwrite(image_data, sizeof(unsigned char), input_size - 54, output_file);

    printf("\nMessage hidden successfully!\n");

    // close files and free memory
    fclose(input_file);
    fclose(output_file);
    free(image_data);

    return 0;
}