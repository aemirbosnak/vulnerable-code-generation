//MISTRAL-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define HEIGHT 10
#define WIDTH 40

typedef struct { char str[WIDTH]; int len; } line_t;

line_t *screen;

void clear_screen() {
    int i;
    for (i = 0; i < HEIGHT; i++) {
        screen[i].len = 0;
    }
}

void print_line(int y, char *s) {
    int x;
    for (x = 0; x < WIDTH && s[x] != '\0'; x++) {
        screen[y].str[x] = s[x];
    }
    screen[y].len = x;
}

void print_char(int y, int x, char c) {
    if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT) return;
    screen[y].str[x] = c;
    screen[y].len++;
}

void shift_left() {
    int y, x, len;
    char c;
    for (y = 0; y < HEIGHT; y++) {
        len = screen[y].len;
        if (len > 0) {
            for (x = 0; x < len - 1; x++) {
                c = screen[y].str[x];
                screen[y].str[x] = screen[y].str[x + 1];
                screen[y].str[x + 1] = c;
            }
            screen[y].str[len - 1] = ' ';
            screen[y].len--;
        }
    }
}

void print_hex(unsigned int hex) {
    char hex_digits[3] = { '0', '0' };
    int i;

    for (i = 2; i >= 0; i--) {
        hex_digits[i] = "0123456789ABCDEF"[hex & 0xF];
        hex >>= 4;
        print_char(HEIGHT - 2, WIDTH - 2 - (i * 3), hex_digits[i]);
    }
}

int main(int argc, char *argv[]) {
    unsigned int number;
    int i;

    if (argc != 2) {
        printf("Usage: %s <hexadecimal number>\n", argv[0]);
        return 1;
    }

    number = strtoul(argv[1], NULL, 16);

    clear_screen();

    print_line(0, "HEX:");
    print_hex(number);
    shift_left();

    print_line(0, "DEC:");
    for (i = 0; ; i++) {
        if (!(number & 1)) {
            print_char(HEIGHT - 2, WIDTH - 2 - i, '0');
            if (!(number >> 1)) {
                print_char(HEIGHT - 2, WIDTH - 2 - i - 1, '1');
                number >>= 4;
                i--;
                continue;
            }
        } else {
            print_char(HEIGHT - 2, WIDTH - 2 - i, '1');
        }
        number >>= 1;

        if (number == 0) break;
    }

    print_line(HEIGHT - 1, "CONVERTED:");

    while (getchar() != '\n');

    return 0;
}