//Falcon-180B DATASET v1.0 Category: Text to ASCII art generator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000

void generate_ascii_art(char *text) {
    int length = strlen(text);
    int max_width = MAX_LENGTH - 2;
    int width = 0;
    int height = 1;
    char *ascii_art = malloc(MAX_LENGTH * sizeof(char));
    ascii_art[0] = '\0';

    for (int i = 0; i < length; i++) {
        if (text[i] == '\n') {
            height++;
            width = 0;
        } else {
            width++;
            if (width >= max_width) {
                height++;
                width = 0;
            }
        }
    }

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < max_width; j++) {
            if (i < height - 1 && width >= j) {
                strcat(ascii_art, " ");
            } else {
                strcat(ascii_art, "*");
            }
        }
        strcat(ascii_art, "\n");
    }

    printf("%s", ascii_art);
    free(ascii_art);
}

int main() {
    char text[MAX_LENGTH];

    printf("Enter some text to generate ASCII art: ");
    fgets(text, MAX_LENGTH, stdin);

    generate_ascii_art(text);

    return 0;
}