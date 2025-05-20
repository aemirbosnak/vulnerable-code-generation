//Falcon-180B DATASET v1.0 Category: Text to ASCII art generator ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WIDTH 120

typedef struct {
    char *text;
    int width;
    int height;
} AsciiArt;

void generate_ascii_art(AsciiArt *art) {
    char *text = art->text;
    int width = art->width;
    int height = art->height;

    int len = strlen(text);
    int lines = (len + width - 1) / width;

    for (int i = 0; i < lines; i++) {
        int start = i * width;
        int end = (i == lines - 1)? len : start + width - 1;

        char line[MAX_WIDTH];
        strncpy(line, &text[start], end - start + 1);
        line[end - start] = '\0';

        for (int j = 0; j < strlen(line); j++) {
            char c = tolower(line[j]);

            if (c >= 'a' && c <= 'z') {
                printf("%c", c - 'a' + 1);
            } else if (c >= '0' && c <= '9') {
                printf("%c", c - '0' + 1);
            } else if (c >= '!' && c <= '/') {
                printf("%c", c - '!' + 1);
            } else if (c >= ':' && c <= '@') {
                printf("%c", c - ':' + 1);
            } else if (c >= '[' && c <= '`') {
                printf("%c", c - '[' + 1);
            } else if (c >= '{' && c <= '~') {
                printf("%c", c - '{' + 1);
            } else {
                printf(" ");
            }
        }

        printf("\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        printf("Usage: %s <text> <width> <height>\n", argv[0]);
        return 1;
    }

    AsciiArt art;
    art.text = argv[1];
    art.width = atoi(argv[2]);
    art.height = atoi(argv[3]);

    generate_ascii_art(&art);

    return 0;
}