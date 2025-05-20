//GPT-4o-mini DATASET v1.0 Category: Image to ASCII art converter ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define IMG_WIDTH  80    // Number of ASCII characters across
#define IMG_HEIGHT 40    // Number of ASCII lines down
#define MAX_CHARS  70    // The number of ASCII characters for brightness mapping

const char *grayScaleMap = " .:-=+*%@#"; // The brighter it gets, the denser the character!

void printHelp() {
    printf("Welcome to the ASCII Art Converter!\n");
    printf("This program will take your beautiful bytes\n");
    printf("and jazz them up into ASCII! It's like a\n");
    printf("makeover, but for images! \n\n");
    printf("Usage:\n");
    printf("  ./ascii_art_converter <input_image.ppm>\n");
    printf("Don’t forget to provide a party hat for your image!\n\n");
}

void convertImageToASCII(const char *inputFilename) {
    FILE *file = fopen(inputFilename, "rb");
    if (file == NULL) {
        fprintf(stderr, "Oops! Cannot find the fabulous image: %s\n", inputFilename);
        exit(1);
    }

    // Reading a simple PPM (P6) file header
    char header[3];
    fscanf(file, "%s", header);
    if (header[1] == '6') { // Check if it's P6 format
        int width, height, maxColorValue;
        fscanf(file, "%d %d %d", &width, &height, &maxColorValue);
        fgetc(file); // consume newline after maxColorValue

        // Now let's create our canvas. This is like our empty pizza base.
        printf("\nConverting your image to ASCII... Please wait...\n\n");
        for (int y = 0; y < IMG_HEIGHT; y++) {
            for (int x = 0; x < IMG_WIDTH; x++) {
                // We read pixels in RGB (3 bytes)
                uint8_t r, g, b;
                fread(&r, sizeof(uint8_t), 1, file);
                fread(&g, sizeof(uint8_t), 1, file);
                fread(&b, sizeof(uint8_t), 1, file);
                
                // Average the colors to determine brightness
                uint8_t avgBrightness = (r + g + b) / 3;
                
                // Map average brightness to ASCII character index
                int asciiIndex = (avgBrightness * (MAX_CHARS - 1)) / 255;
                
                // Print the corresponding ASCII character
                putchar(grayScaleMap[asciiIndex]);
            }
            putchar('\n'); // Move to the next line of our beautiful art
        }
    } else {
        fprintf(stderr, "Yikes! This program only supports P6 PPM images!\n");
        fclose(file);
        exit(1);
    }

    fclose(file);
    printf("\nYour masterpiece is ready! Hang it on the wall, or send it to grandma!\n");
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printHelp();
        return 1; // Return to sender if no input is provided
    }

    convertImageToASCII(argv[1]); // It’s showtime!

    return 0; // All good here, folks!
}