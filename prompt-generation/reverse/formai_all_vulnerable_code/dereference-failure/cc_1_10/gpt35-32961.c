//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define maximum number of bits in a watermark
#define MAX_WATERMARK_BITS 256

// Define maximum size of input image file
#define MAX_FILE_SIZE 1024 * 1024

/*
Function to convert a decimal number to binary

@param decimal - the decimal number to convert
@param binary - pointer to the resulting binary string
*/
void decimal_to_binary(int decimal, char *binary)
{
    int i, j, temp;
    for (i = 0; decimal > 0; i++)
    {
        binary[i] = decimal % 2 + '0';
        decimal /= 2;
    }
    binary[i] = '\0';
    for (i = 0, j = strlen(binary) - 1; i < j; i++, j--)
    {
        temp = binary[i];
        binary[i] = binary[j];
        binary[j] = temp;
    }
}

/*
Function to convert a binary string to a decimal number

@param binary - the binary string to convert
@return the decimal equivalent of the binary string
*/
int binary_to_decimal(char *binary)
{
    int decimal = 0;
    int power = 1;
    int i;
    for (i = strlen(binary) - 1; i >= 0; i--)
    {
        decimal += (binary[i] - '0') * power;
        power *= 2;
    }
    return decimal;
}

/*
Function to read an image file and return its contents in a buffer

@param filename - the name of the image file to read
@param file_size - pointer to a variable to store the size of the file read
@return pointer to a buffer containing the contents of the file
*/
char *read_image_file(char *filename, long *file_size)
{
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL)
    {
        fprintf(stderr, "Error: Cannot open file %s\n", filename);
        exit(1);
    }

    fseek(fp, 0L, SEEK_END);
    *file_size = ftell(fp);
    rewind(fp);

    char *buffer = (char*) malloc(*file_size);
    if (buffer == NULL)
    {
        fprintf(stderr, "Error: Unable to allocate memory\n");
        fclose(fp);
        exit(1);
    }

    fread(buffer, sizeof(char), *file_size, fp);
    fclose(fp);

    return buffer;
}

/*
Function to write an image file from a buffer

@param filename - the name of the output image file to write
@param buffer - pointer to the buffer containing the contents of the file
@param file_size - the size of the file to write
*/
void write_image_file(char *filename, char *buffer, long file_size)
{
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL)
    {
        fprintf(stderr, "Error: Cannot open file %s for writing\n", filename);
        exit(1);
    }

    fwrite(buffer, sizeof(char), file_size, fp);
    fclose(fp);
}

int main(int argc, char *argv[])
{
    // Check for correct usage
    if (argc != 4)
    {
        printf("Usage: %s <input_image> <watermark_string> <output_image>\n", argv[0]);
        return 1;
    }

    char *input_filename = argv[1];
    char *watermark_string = argv[2];
    char *output_filename = argv[3];

    // Read input image file into a buffer
    long file_size;
    char *input_buffer = read_image_file(input_filename, &file_size);

    // Ensure that the file is not too large
    if (file_size > MAX_FILE_SIZE)
    {
        fprintf(stderr, "Error: Input file is too large\n");
        free(input_buffer);
        exit(1);
    }

    // Generate random key to be used for hiding watermark
    srand(time(NULL));
    int key = rand();

    // Convert key to binary
    char key_binary[33];
    decimal_to_binary(key, key_binary);

    // Convert watermark string to binary
    char watermark_binary[MAX_WATERMARK_BITS + 1];
    memset(watermark_binary, '\0', MAX_WATERMARK_BITS + 1);
    int i;
    for (i = 0; i < strlen(watermark_string); i++)
    {
        char temp[9];
        memset(temp, '\0', 9);
        decimal_to_binary((int) watermark_string[i], temp);
        strcat(watermark_binary, temp);
    }

    // Ensure that watermark is not too large
    if (strlen(watermark_binary) > MAX_WATERMARK_BITS)
    {
        fprintf(stderr, "Error: Watermark string is too large\n");
        free(input_buffer);
        exit(1);
    }

    // Embed the watermark in the input image file
    char *output_buffer = (char*) malloc(file_size);
    memcpy(output_buffer, input_buffer, file_size);
    for (i = 0; i < strlen(watermark_binary); i++)
    {
        if (watermark_binary[i] == '1')
        {
            if (output_buffer[i] % 2 == 0)
            {
                output_buffer[i]++;
            }
            else
            {
                output_buffer[i]--;
            }
        }
        else
        {
            if (output_buffer[i] % 2 == 0)
            {
                output_buffer[i]--;
            }
            else
            {
                output_buffer[i]++;
            }
        }
    }

    // Write output image file with embedded watermark
    write_image_file(output_filename, output_buffer, file_size);

    // Extract the watermark from the output image file
    char *extracted_watermark_binary = (char*) malloc(strlen(watermark_binary) + 1);
    memset(extracted_watermark_binary, '\0', strlen(watermark_binary) + 1);
    for (i = 0; i < strlen(watermark_binary); i++)
    {
        if (output_buffer[i] % 2 == 0)
        {
            extracted_watermark_binary[i] = '0';
        }
        else
        {
            extracted_watermark_binary[i] = '1';
        }
    }

    // Convert extracted watermark to characters
    char extracted_watermark[MAX_WATERMARK_BITS / 8 + 1];
    memset(extracted_watermark, '\0', MAX_WATERMARK_BITS / 8 + 1);
    for (i = 0; i < strlen(extracted_watermark_binary); i += 8)
    {
        char temp[9];
        memset(temp, '\0', 9);
        strncpy(temp, extracted_watermark_binary + i, 8);
        extracted_watermark[i / 8] = (char) binary_to_decimal(temp);
    }

    // Check if extracted watermark matches original watermark
    if (strcmp(watermark_string, extracted_watermark) == 0)
    {
        printf("Watermark successfully embedded and extracted\n");
    }
    else
    {
        printf("Error: Extracted watermark does not match original watermark\n");
    }

    // Free memory
    free(input_buffer);
    free(output_buffer);
    free(extracted_watermark_binary);

    return 0;
}