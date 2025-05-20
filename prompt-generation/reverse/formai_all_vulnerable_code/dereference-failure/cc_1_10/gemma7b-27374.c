//Gemma-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void itoa(int n, char *s)
{
    int i = 0;
    char num[10];
    char *p = s;
    if (n < 0) {
        *p++ = '-';
        n = -n;
    }
    do {
        num[i++] = n % 10 + '0';
        n /= 10;
    } while (n);
    num[i] = '\0';
    strcpy(s, num);
}

int main()
{
    char image[] = "           /\n"
                     "\\/|__)\n"
                     "\ | \__)\n"
                     "\__) \___)\n";

    int w = 20;
    int h = 4;
    char **ascii_image = (char **)malloc(h * w * sizeof(char *));

    for (int r = 0; r < h; r++) {
        ascii_image[r] = (char *)malloc(w * sizeof(char));
    }

    for (int r = 0; r < h; r++) {
        for (int c = 0; c < w; c++) {
            ascii_image[r][c] = image[r * w + c];
        }
    }

    for (int r = 0; r < h; r++) {
        for (int c = 0; c < w; c++) {
            printf("%c ", ascii_image[r][c]);
        }
        printf("\n");
    }

    free(ascii_image);

    return 0;
}