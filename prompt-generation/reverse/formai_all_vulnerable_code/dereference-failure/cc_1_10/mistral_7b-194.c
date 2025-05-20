//MISTRAL-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 30
#define HEIGHT 10

typedef struct {
    char c;
    int ascii[WIDTH];
} character;

character chars[26];

void init_chars() {
    int i, j;
    for (i = 0; i < 26; i++) {
        chars[i].c = 'A' + i;
        for (j = 0; j < WIDTH; j++) {
            if (j >= 5 && j <= 25) {
                chars[i].ascii[j] = chars[i].c;
            } else {
                chars[i].ascii[j] = ' ';
            }
        }
    }

    for (i = 0; i < 26; i++) {
        for (j = 0; j < WIDTH; j++) {
            if (j == 5 || j == 25) {
                if (i % 2 == 0) {
                    chars[i].ascii[j] = '*';
                } else {
                    chars[i].ascii[j] = 'o';
                }
            }
        }
    }
}

void print_ascii_art(const char *text) {
    int i, j, len;
    len = strlen(text);

    for (i = 0; i < len; i++) {
        for (j = 0; j < 26; j++) {
            if (text[i] == chars[j].c) {
                int k;
                for (k = 0; k < WIDTH; k++) {
                    putchar(chars[j].ascii[k]);
                }
                break;
            }
        }
    }
    putchar('\n');
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <text>\n", argv[0]);
        return 1;
    }

    if (WIDTH * HEIGHT > strlen(argv[1])) {
        printf("Error: Text too short to generate ASCII art\n");
        return 1;
    }

    init_chars();

    print_ascii_art(argv[1]);

    return 0;
}