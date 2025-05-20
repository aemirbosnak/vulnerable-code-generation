//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 80
#define HEIGHT 40

// A decentralized ASCII image converter that reads from standard input
// and writes the result to standard output.

char *pixels;

// Convert a RGB pixel to a grayscale character
char to_gray(int r, int g, int b) {
    return (r + g + b) / 3 / 32;
}

// Convert an ASCII character to a 4-bit grayscale pixel
char to_pixel(char c) {
    switch(c) {
        case ' ':
        case '_':
        case '.':
        case ',':
        case '\'':
        	return 0;
        case '`':
        case ':':
        case '-':
        case '~':
        	return 1;
        case '*':
        case '/':
        case '=':
        case '?':
        case '!':
        	return 2;
        case '+':
        case '%':
        case '$':
        case '#':
        	return 3;
        default:
        	return 0;
    }
}

int main() {
    char line[WIDTH + 1];
    int i, j, k, x, y;
    int r, g, b;
    char gray;

    pixels = (char *)malloc(WIDTH * HEIGHT / 2);

    while(fgets(line, WIDTH + 1, stdin) != NULL && y < HEIGHT) {
        for(i = x = 0; i < WIDTH && line[i] != '\0'; i++, x += 2) {
            if(x >= WIDTH) // ignore lines that exceed the image width
                break;
            // read a RGB pixel from the input
            if(sscanf(line + i, "#%02x%02x%02x", &r, &g, &b) != 3)
                break;

            // convert the pixel to grayscale
            gray = to_gray(r, g, b);

            // store the 4-bit grayscale pixel in the buffer
            pixels[y * WIDTH / 2 + x / 8] |= (to_pixel("`-'_|/=\\()1{}[]?<>i!l+t=%#@*+~:;,^\"."[gray]) << (x % 8));
        }
        y++;
    }

    // print the ASCII art to standard output
    for(i = 0; i < HEIGHT; i++) {
        for(j = 0; j < WIDTH; j += 2) {
            k = pixels[i * WIDTH / 2 + j / 8] >> (j % 8);
            putchar("`-'_|/=\\()1{}[]?<>i!l+t=%#@*+~:;,^\"."[k & 0xf]);
        }
        putchar('\n');
    }

    free(pixels);

    return 0;
}