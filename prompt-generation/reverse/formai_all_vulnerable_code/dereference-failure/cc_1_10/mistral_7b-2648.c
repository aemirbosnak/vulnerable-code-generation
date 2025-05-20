//MISTRAL-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>
#include <sys/ioctl.h>

#define ART_WIDTH 50
#define ART_HEIGHT 10
#define MAX_CHARS 100
#define RANDOM_DELTA 15

typedef struct {
    unsigned char r, g, b;
} Color;

Color randomColor() {
    Color color;
    srand(time(NULL) ^ getpid());
    color.r = rand() % 151;
    color.g = rand() % 151;
    color.b = rand() % 151;
    return color;
}

void printArtChar(int x, int y, char symbol, Color color) {
    printf("\033[%d;%dH\033[38;5;%dm%c\033[38;5;0m", y, x, color.r, symbol);
}

void generateArt(const char *text) {
    int textLength = strlen(text);
    if (textLength > MAX_CHARS) {
        printf("Error: Text is too long.\n");
        return;
    }

    int x = 0, y = 0;
    for (int i = 0; i < textLength; ++i) {
        char symbol;
        switch (text[i]) {
            case ' ':
                symbol = ' ';
                break;
            case '.':
                symbol = 'o';
                ++x;
                break;
            case ',':
                symbol = 'v';
                ++x;
                ++y;
                break;
            case '!':
                symbol = '^';
                ++x;
                ++y;
                break;
            case '?':
                symbol = '?';
                ++x;
                ++y;
                break;
            default:
                symbol = text[i];
                if (x >= ART_WIDTH) {
                    x = 0;
                    ++y;
                }
                break;
        }
        printArtChar(x, y, symbol, randomColor());
        x++;
    }

    printf("\033[H\033[2J"); // Clear the screen
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <text>\n", argv[0]);
        return 1;
    }

    generateArt(argv[1]);

    return 0;
}