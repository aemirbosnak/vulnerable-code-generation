//FormAI DATASET v1.0 Category: Image Steganography ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// defining constants
#define MAX_IMAGE_SIZE 1024*1024 // 1MB
#define MAX_MARK_SIZE 100
#define BMP_HEADER_SIZE 54

// defining file pointers
FILE *image, *marked_image, *extracted_mark;

// defining variables
int image_size, mark_size;
unsigned char *image_data, *mark_data;

// function to read image file
void read_image(char *filename)
{
    // opening image file in binary mode
    image = fopen(filename, "rb");

    // checking for errors
    if (!image)
    {
        printf("Error: Unable to open file '%s'\n", filename);
        exit(1);
    }

    // getting image size
    fseek(image, 0, SEEK_END);
    image_size = ftell(image) - BMP_HEADER_SIZE;
    fseek(image, BMP_HEADER_SIZE, SEEK_SET);

    // checking for image size limit
    if (image_size >= MAX_IMAGE_SIZE)
    {
        printf("Error: Image file is too large.\n");
        fclose(image);
        exit(1);
    }

    // reading image data
    image_data = (unsigned char *)malloc(image_size * sizeof(unsigned char));
    fread(image_data, sizeof(unsigned char), image_size, image);

    // closing image file
    fclose(image);
}

// function to read mark file
void read_mark(char *filename)
{
    // opening mark file in binary mode
    marked_image = fopen(filename, "rb");

    // checking for errors
    if (!marked_image)
    {
        printf("Error: Unable to open file '%s'\n", filename);
        exit(1);
    }

    // getting mark size
    fseek(marked_image, 0, SEEK_END);
    mark_size = ftell(marked_image);
    fseek(marked_image, 0, SEEK_SET);

    // checking for mark size limit
    if (mark_size >= MAX_MARK_SIZE)
    {
        printf("Error: Mark file is too large.\n");
        fclose(marked_image);
        exit(1);
    }

    // reading mark data
    mark_data = (unsigned char *)malloc(mark_size * sizeof(unsigned char));
    fread(mark_data, sizeof(unsigned char), mark_size, marked_image);

    // closing mark file
    fclose(marked_image);
}

// function to write marked image file
void write_marked_image(char *filename)
{
    // opening marked image file in binary mode
    marked_image = fopen(filename, "wb");

    // checking for errors
    if (!marked_image)
    {
        printf("Error: Unable to create file '%s'\n", filename);
        exit(1);
    }

    // copying image header to marked image file
    fseek(image, 0, SEEK_SET);
    unsigned char *header_data = (unsigned char *)malloc(BMP_HEADER_SIZE * sizeof(unsigned char));
    fread(header_data, sizeof(unsigned char), BMP_HEADER_SIZE, image);
    fwrite(header_data, sizeof(unsigned char), BMP_HEADER_SIZE, marked_image);

    // writing marked image data
    int i, j, k = 0;
    for (i = 0; i < image_size && k < mark_size; i++)
    {
        if (i % 3 == 2) // modifying blue channel
        {
            image_data[i] &= 0xFC; // setting 2 LSBs to 0
            image_data[i] |= mark_data[k] >> 6; // setting first 2 LSBs to mark data bits
            k++;
        }
        else if (i % 3 == 1) // modifying green channel
        {
            image_data[i] &= 0xFC; // setting 2 LSBs to 0
            image_data[i] |= (mark_data[k] >> 4) & 0x03; // setting next 2 LSBs to mark data bits
        }
        else // modifying red channel
        {
            image_data[i] &= 0xFC; // setting 2 LSBs to 0
            image_data[i] |= (mark_data[k] >> 2) & 0x03; // setting next 2 LSBs to mark data bits
        }
    }

    // writing marked image data to file
    fwrite(image_data, sizeof(unsigned char), image_size, marked_image);

    // closing marked image file
    fclose(marked_image);
}

// function to extract mark from image file
void extract_mark(char *filename)
{
    // opening marked image file in binary mode
    marked_image = fopen(filename, "rb");

    // checking for errors
    if (!marked_image)
    {
        printf("Error: Unable to open file '%s'\n", filename);
        exit(1);
    }

    // getting image size
    fseek(marked_image, 0, SEEK_END);
    image_size = ftell(marked_image) - BMP_HEADER_SIZE;
    fseek(marked_image, BMP_HEADER_SIZE, SEEK_SET);

    // reading marked image data
    image_data = (unsigned char *)malloc(image_size * sizeof(unsigned char));
    fread(image_data, sizeof(unsigned char), image_size, marked_image);

    // closing marked image file
    fclose(marked_image);

    // extracting mark data
    int i, j, k = 0;
    extracted_mark = fopen("extracted_mark.txt", "wb");
    for (i = 0; i < image_size && k < MAX_MARK_SIZE; i++)
    {
        if (i % 3 == 2) // extracting blue channel
        {
            mark_data[k] = (image_data[i] & 0x03) << 6; // getting first 2 LSBs of blue channel
            k++;
        }
        else if (i % 3 == 1) // extracting green channel
        {
            mark_data[k - 1] |= (image_data[i] & 0x03) << 4; // getting next 2 LSBs of green channel
        }
        else // extracting red channel
        {
            mark_data[k - 1] |= (image_data[i] & 0x03) << 2; // getting next 2 LSBs of red channel
        }
    }

    // writing extracted mark data to file
    fwrite(mark_data, sizeof(unsigned char), MAX_MARK_SIZE, extracted_mark);

    // closing extracted mark file
    fclose(extracted_mark);
}

// main function
int main()
{
    // reading image file
    read_image("image.bmp");

    // reading mark file
    read_mark("mark.txt");

    // writing marked image file
    write_marked_image("marked_image.bmp");

    // extracting mark from marked image file
    extract_mark("marked_image.bmp");

    // freeing memory
    free(image_data);
    free(mark_data);

    return 0;
}