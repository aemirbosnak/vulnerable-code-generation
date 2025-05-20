//FormAI DATASET v1.0 Category: Image Steganography ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

#define MAX_FILE_SIZE 1000000

/* Function to read the contents of a file */
int read_file(char *filename, char *data)
{
    FILE *fp;
    int index = 0;
    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("Error opening file.");
        return -1;
    }

    char ch = fgetc(fp);
    while (ch != EOF && index < MAX_FILE_SIZE)
    {
        data[index++] = ch;
        ch = fgetc(fp);
    }
    fclose(fp);

    printf("The contents of the file are:\n%s\n\n", data);
    return index;
}

/* Function to write data to a file */
void write_file(char *filename, char *data, int size)
{
    FILE *fp;
    fp = fopen(filename, "w");
    if (fp == NULL)
    {
        printf("Error opening file.");
        return;
    }

    fprintf(fp, "%s", data);
    fclose(fp);
}

/* Function to hide data inside an image */
void hide_data_in_image(char *image_path, char *data, int data_size)
{
    FILE *fp = fopen(image_path, "rb+");
    if(fp == NULL)
    {
        printf("Error opening image file.");
        return;
    }

    fseek(fp, 0, SEEK_END);
    int image_size = ftell(fp);
    rewind(fp);

    /* Read the header length of the image */
    char header[54];
    fread(header, sizeof(char), 54, fp);

    /* Write the data size to the 4 bytes after the header of the image */
    fseek(fp, 54, SEEK_SET);
    fwrite(&data_size, sizeof(int), 1, fp);

    /* Hide the data after the header and the size */
    char image_data;
    int i = 0, j = 0;
    while(fread(&image_data, sizeof(char), 1, fp) == 1)
    {
        if(i++ < 54 + sizeof(int)) /* Skip the header and the size */
            continue;

        if(j < data_size)
        {
            /* Write the least significant bit of the data to the least significant bit of the image byte */
            /* This is done using bitwise operators */
            image_data = ((image_data & 0xFE) | ((data[j] >> (i % 8)) & 0x01));
            j++;
        }
        fwrite(&image_data, sizeof(char), 1, fp);
    }

    fclose(fp);
}

/* Function to retrieve data from an image */
char *get_data_from_image(char *image_path, int *data_size)
{
    FILE *fp = fopen(image_path, "rb");
    if(fp == NULL)
    {
        printf("Error opening image file.");
        return NULL;
    }

    /* Read the header length of the image */
    char header[54];
    fread(header, sizeof(char), 54, fp);

    /* Read the data size from the 4 bytes after the header of the image */
    fseek(fp, 54, SEEK_SET);
    fread(data_size, sizeof(int), 1, fp);

    /* Retrieve the data */
    char *data = (char *)malloc(*data_size);
    char image_data;
    int i = 0, j = 0;
    while(fread(&image_data, sizeof(char), 1, fp) == 1 && j < *data_size)
    {
        if(i++ < 54 + sizeof(int)) /* Skip the header and the size */
            continue;

        /* Retrieve the least significant bit of the image byte */
        /* This is done using bitwise operators */
        data[j++] = (image_data & 0x01) << (i % 8);
    }

    fclose(fp);
    return data;
}

int main()
{
    char filename[] = "data.txt";
    char image_path[] = "image.bmp";

    /* Read the data from the file */
    char data[MAX_FILE_SIZE];
    int data_size = read_file(filename, data);
    if (data_size == -1)
    {
        return -1;
    }

    /* Hide the data in the image */
    hide_data_in_image(image_path, data, data_size);

    /* Retrieve the data from the image */
    char *retrieved_data = get_data_from_image(image_path, &data_size);
    if (retrieved_data == NULL)
    {
        return -1;
    }

    /* Write the retrieved data to a file */
    write_file("retrieved_data.txt", retrieved_data, data_size);

    printf("Data hidden in image and retrieved successfully!\n\n");

    return 0;
}