//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WATERMARK "digitalwatermark"

typedef struct {
    unsigned char r, g, b;
} pixel;

// Function to extract watermark from given image file.
void extract_watermark(char *filename) {
    FILE *fp_in = fopen(filename, "rb"); // Open the image file in read mode.
    if (!fp_in) {
        printf("Error: Unable to open file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    char marker[sizeof(WATERMARK)] = {0}; // Initializing marker with zeros.
    int i = 0, flag = 0;

    pixel p; // A pixel variable to store RGB values.

    fseek(fp_in, 54, SEEK_SET); // Move the pointer to the starting position of pixel data.

    while (fread(&p, sizeof(p), 1, fp_in)) {
        if (i < sizeof(WATERMARK)) {
            marker[i] = p.r; // Store the red value of each pixel in marker character array.
            i++;
        } else {
            if (strcmp(marker, WATERMARK) == 0) { // If the marker matches our watermark then print it.
                printf("Digital Watermark Found!\n");
                flag = 1;
                break;
            } else { // Else slide the data by one byte to make space for next pixel data.
                for (int j = 1; j < sizeof(marker); j++) {
                    marker[j - 1] = marker[j];
                }
                marker[sizeof(marker) - 1] = p.r;
            }
        }
    }

    if (!flag) { // If watermark is not found then print this message.
        printf("Sorry, Watermark not found!\n");
    }

    fclose(fp_in); // Close the input file.
}

// Function to embed given watermark in given image file.
void embed_watermark(char *filename, char *watermark) {
    FILE *fp_in = fopen(filename, "rb"); // Open the image file in read mode.
    if (!fp_in) {
        printf("Error: Unable to open file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    char *ext = strrchr(filename, '.'); // Get the file extension from file name.
    if (!ext) {
        printf("Error: Invalid file name.\n");
        exit(EXIT_FAILURE);
    }

    char *new_filename = malloc(strlen(filename) + 5); // Allocate memory for new file name.
    if (!new_filename) {
        printf("Error: Not enough memory.\n");
        exit(EXIT_FAILURE);
    }

    strcpy(new_filename, filename); // Copy original file name to new file name.
    strcat(new_filename, "_wm"); // Append "_wm" to the new file name.

    FILE *fp_out = fopen(new_filename, "wb"); // Open new file in write mode.
    if (!fp_out) {
        printf("Error: Unable to create file %s\n", new_filename);
        exit(EXIT_FAILURE);
    }

    int i = 0;
    char c = watermark[i];

    fseek(fp_in, 0, SEEK_END); // Move the pointer to the end of input file.
    size_t size = ftell(fp_in); // Get the size of input file in bytes.
    fseek(fp_in, 0, SEEK_SET); // Move the pointer back to the starting position of input file.

    unsigned char header[54]; // An array to store image header.
    fread(header, sizeof(header), 1, fp_in); // Read image header from input file.
    fwrite(header, sizeof(header), 1, fp_out); // Write image header to output file.

    pixel p; // A pixel variable to store RGB values.

    int flag = 0;

    while (fread(&p, sizeof(p), 1, fp_in)) {
        if (i <= strlen(watermark)) {
            c = watermark[i]; // Get the next character of watermark.

            p.r &= ~1; // Manipulate red channel of pixel to embed the watermark.
            p.r |= (c & 0x01);

            i++;
        } else {
            flag = 1;
        }

        fwrite(&p, sizeof(p), 1, fp_out); // Write the pixel to output file.
    }

    if (!flag) { // If there is some space left in image, then add some padding to end the image.
        char pad[sizeof(WATERMARK)] = {0}; // Initializing padding with zeros.
        while (i < sizeof(WATERMARK)) {
            pad[i] = 0;
            i++;
        }

        i = 0;

        while (i < sizeof(pad)) {
            c = pad[i];

            p.r &= ~1; // Manipulate red channel of pixel to embed the padding.
            p.r |= (c & 0x01);

            i++;
            fwrite(&p, sizeof(p), 1, fp_out); // Write the pixel to output file.
        }
    }

    fclose(fp_in); // Close input file.
    fclose(fp_out); // Close output file.

    printf("Digital Watermark Embedded Successfully!\n");
    printf("New Image File: %s\n", new_filename);

    free(new_filename); // Free allocated memory for new file name.
}

int main() {
    char filename[100], choice, watermark[50];

    printf("Enter Image Filename: ");
    scanf("%s", filename);

    printf("Do You Want to Embed or Extract Watermark? (e/x): ");
    scanf("\n%c", &choice);

    if (choice == 'e') { // If user wants to embed a watermark then take input watermark and call embed_watermark function.
        printf("Enter Watermark: ");
        scanf("\n%s", watermark);

        embed_watermark(filename, watermark);
    } else if (choice == 'x') { // If user wants to extract watermark from an image then call extract_watermark function.
        extract_watermark(filename);
    } else { // If user enters an invalid choice then print this message.
        printf("Invalid Choice!\n");
    }

    return 0;
}