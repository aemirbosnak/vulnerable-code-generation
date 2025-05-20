//MISTRAL-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ART_WIDTH 40
#define ART_HEIGHT 10

char art[ART_HEIGHT][ART_WIDTH];

void init_art() {
    int i, j;

    for (i = 0; i < ART_HEIGHT; i++) {
        for (j = 0; j < ART_WIDTH; j++) {
            art[i][j] = '*';
        }
    }

    for (i = 0; i < ART_HEIGHT; i++) {
        art[i][ART_WIDTH / 2] = 'O';
    }

    art[ART_HEIGHT / 2][ART_WIDTH / 2] = 'X';
}

void encrypt_text(char *text, char key) {
    int i;

    for (i = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])) {
            text[i] = (((text[i] - 'A' + key) % 26) + 'A');
        }
    }
}

void print_ascii_art(char *text) {
    int i, j;
    int text_length = strlen(text);

    for (i = 0; i < text_length; i++) {
        j = text[i] - 'A';

        if (i % 2 == 0) {
            art[i / 2][j] = ' ';
        } else {
            art[i / 2][j] = ' ';
            art[i / 2][j] = art[i / 2][j] ^ 0x01;
        }
    }

    for (i = 0; i < ART_HEIGHT; i++) {
        for (j = 0; j < ART_WIDTH; j++) {
            putchar(art[i][j]);
        }
        putchar('\n');
    }
}

int main(int argc, char *argv[]) {
    char text[100];
    char key;

    if (argc < 3) {
        printf("Usage: %s <text> <key>\n", argv[0]);
        return 1;
    }

    strcpy(text, argv[1]);
    key = atoi(argv[2]);

    init_art();
    encrypt_text(text, key);
    print_ascii_art(text);

    return 0;
}