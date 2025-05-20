//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: energetic
#include <stdio.h>

#define MAX_WIDTH 80 // maximum width of ASCII art

int main() {
    int width, height; // dimensions of image
    scanf("%d %d", &width, &height);
    while (getchar() != '\n') {} // flush the input buffer

    // read in the image as a two-dimensional array of characters
    char image[height][width];
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            image[i][j] = getchar();
        }
        while (getchar() != '\n') {} // flush the input buffer
    }

    // display the ASCII art version of the image
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            char c = image[i][j];
            switch (c) {
                case ' ':
                    putchar(' ');
                    break;
                case '.':
                    putchar('.');
                    break;
                case ':':
                    putchar(':');
                    break;
                case '-':
                    putchar('-');
                    break;
                case '=':
                    putchar('=');
                    break;
                case '+':
                    putchar('+');
                    break;
                case '*':
                    putchar('*');
                    break;
                case '#':
                    putchar('#');
                    break;
                default:
                    putchar('#'); // replace unknown characters with #
            }
        }
        putchar('\n');
    }

    return 0;
}