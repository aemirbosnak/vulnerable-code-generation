//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to add digital watermark to image
void add_watermark(char *input_image_path, char *output_image_path, char *watermark) {
    FILE *fp_input, *fp_output;
    int watermark_length = strlen(watermark);
    char ch;

    // Open input image file
    fp_input = fopen(input_image_path, "rb");
    if (fp_input == NULL) {
        printf("Error: Cannot open input image file.\n");
        exit(1);
    }

    // Open output image file
    fp_output = fopen(output_image_path, "wb");
    if (fp_output == NULL) {
        printf("Error: Cannot open output image file.\n");
        exit(1);
    }

    // Write digital watermark to output file
    fprintf(fp_output, "%s", watermark);

    // Copy the remaining content of input image file to output image file
    while((ch = fgetc(fp_input)) != EOF) {
        fputc(ch, fp_output);
    }

    // Close input and output image file
    fclose(fp_input);
    fclose(fp_output);

    printf("Digital watermark added successfully!\n");
}

// Function to extract digital watermark from image
void extract_watermark(char *input_image_path) {
    FILE *fp_input;
    int watermark_length = 20; // Assume the length of digital watermark
    char watermark[watermark_length + 1]; // Allocate memory for digital watermark (+1 for null character)
    char ch;
    int i = 0;

    // Open input image file
    fp_input = fopen(input_image_path, "rb");
    if (fp_input == NULL) {
        printf("Error: Cannot open input image file.\n");
        exit(1);
    }

    // Read digital watermark from input file
    while((ch = fgetc(fp_input)) != EOF && i < watermark_length) {
        watermark[i++] = ch;
    }
    watermark[i] = '\0';

    // Close input image file
    fclose(fp_input);

    printf("Digital watermark extracted successfully! Watermark: %s\n", watermark);
}

int main() {
    char input_image_path[] = "input_image.png";
    char output_image_path[] = "output_image.png";
    char watermark[] = "This is a digital watermark.";
  
    // Add digital watermark to input image and save as output image
    add_watermark(input_image_path, output_image_path, watermark);

    // Extract digital watermark from output image
    extract_watermark(output_image_path);

    return 0;
}