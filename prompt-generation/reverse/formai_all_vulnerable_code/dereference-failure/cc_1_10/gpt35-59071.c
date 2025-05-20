//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/* Assume we have a watermark image and an input image, both with the same size of 256x256 pixels */

/* Function to convert a decimal number to binary */
void dec2bin(long int decimal, int *binary)
{
    int i;

    for (i = 0; decimal > 0; i++) {
        binary[i] = decimal % 2;
        decimal /= 2;
    }
}

/* Function to convert a binary number to decimal */
long int bin2dec(int *binary, int n)
{
    long int decimal = 0;
    int i;

    for (i = 0; i < n; i++) {
        decimal += binary[i] * pow(2, i);
    }

    return decimal;
}

/* Function to read an image from a file */
void read_image(char *filename, int **image)
{
    FILE *fp;
    int i, j;

    fp = fopen(filename, "r");

    for (i = 0; i < 256; i++) {
        for (j = 0; j < 256; j++) {
            fscanf(fp, "%d", &image[i][j]);
        }
    }

    fclose(fp);
}

/* Function to write an image to a file */
void write_image(char *filename, int **image)
{
    FILE *fp;
    int i, j;

    fp = fopen(filename, "w");

    for (i = 0; i < 256; i++) {
        for (j = 0; j < 256; j++) {
            fprintf(fp, "%d ", image[i][j]);
        }
        fprintf(fp, "\n");
    }

    fclose(fp);
}

/* Function to apply watermarking to an image */
void apply_watermark(int **image, int **watermark)
{
    int i, j;
    int watermark_binary[8], pixel_binary[8];

    /* Convert each pixel of the watermark to binary */
    for (i = 0; i < 256; i++) {
        for (j = 0; j < 256; j++) {
            dec2bin(watermark[i][j], watermark_binary);

            /* Replace the least significant bit of each pixel of the image with the corresponding bit of the watermark */
            dec2bin(image[i][j], pixel_binary);
            pixel_binary[7] = watermark_binary[7];

            image[i][j] = bin2dec(pixel_binary, 8);
        }
    }
}

int main()
{
    int **image, **watermark;
    int i, j;

    /* Allocate memory for the image and the watermark */
    image = (int **) malloc(256 * sizeof(int *));
    for (i = 0; i < 256; i++) {
        image[i] = (int *) malloc(256 * sizeof(int));
    }

    watermark = (int **) malloc(256 * sizeof(int *));
    for (i = 0; i < 256; i++) {
        watermark[i] = (int *) malloc(256 * sizeof(int));
    }

    /* Read the image from a file */
    read_image("input.txt", image);

    /* Read the watermark from a file */
    read_image("watermark.txt", watermark);

    /* Apply watermarking to the image */
    apply_watermark(image, watermark);

    /* Write the watermarked image to a file */
    write_image("output.txt", image);

    /* Free memory */
    for (i = 0; i < 256; i++) {
        free(image[i]);
        free(watermark[i]);
    }
    free(image);
    free(watermark);

    return 0;
}