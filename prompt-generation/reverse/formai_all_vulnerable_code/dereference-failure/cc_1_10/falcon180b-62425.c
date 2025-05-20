//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define WIDTH 80 // ASCII art width
#define HEIGHT 60 // ASCII art height

// Function to convert image to ASCII art
void image_to_ascii(char *filename, char *output_filename) {
    FILE *fp;
    char ch;
    int i, j, k, l, count = 0, bright = 0, dark = 0;

    // Open input file
    fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: Cannot open input file\n");
        exit(1);
    }

    // Open output file
    FILE *out = fopen(output_filename, "w");
    if (out == NULL) {
        printf("Error: Cannot open output file\n");
        exit(1);
    }

    // Read image data
    while ((ch = fgetc(fp))!= EOF) {
        if (ch >= 0 && ch <= 127) { // Convert printable characters to ASCII art
            if (isupper(ch)) {
                fprintf(out, "@");
            } else if (islower(ch)) {
                fprintf(out, ".");
            } else {
                fprintf(out, "*");
            }
        } else { // Convert non-printable characters to spaces
            fprintf(out, " ");
        }
        count++;
        if (count == WIDTH) { // End of line
            fprintf(out, "\n");
            count = 0;
        }
    }

    // Close files
    fclose(fp);
    fclose(out);
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        exit(1);
    }

    // Convert image to ASCII art
    image_to_ascii(argv[1], argv[2]);

    printf("ASCII art generated successfully!\n");
    return 0;
}