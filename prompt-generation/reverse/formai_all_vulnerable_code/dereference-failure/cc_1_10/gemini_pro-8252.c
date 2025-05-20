//GEMINI-pro DATASET v1.0 Category: Text to ASCII art generator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 25

char *textToAscii(char *text, int *width, int *height) {
    int i, j, k, l, m, n;
    int len = strlen(text);
    char *ascii = malloc(MAX_WIDTH * MAX_HEIGHT * sizeof(char));
    memset(ascii, ' ', MAX_WIDTH * MAX_HEIGHT * sizeof(char));
    int charsPerLine = MAX_WIDTH / 8;
    int lines = len / charsPerLine;
    if (len % charsPerLine > 0) {
        lines++;
    }
    for (i = 0; i < lines; i++) {
        for (j = 0; j < charsPerLine; j++) {
            if (i * charsPerLine + j < len) {
                for (k = 0; k < 8; k++) {
                    for (l = 0; l < 8; l++) {
                        m = i * charsPerLine + j;
                        n = (text[m] >> (7 - k)) & 1;
                        ascii[i * MAX_WIDTH + j * 8 + k * MAX_WIDTH + l] = (n == 1) ? '*' : ' ';
                    }
                }
            }
        }
    }
    *width = MAX_WIDTH;
    *height = lines;
    return ascii;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <text>\n", argv[0]);
        return 1;
    }
    int width, height;
    char *ascii = textToAscii(argv[1], &width, &height);
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%c", ascii[i * width + j]);
        }
        printf("\n");
    }
    free(ascii);
    return 0;
}