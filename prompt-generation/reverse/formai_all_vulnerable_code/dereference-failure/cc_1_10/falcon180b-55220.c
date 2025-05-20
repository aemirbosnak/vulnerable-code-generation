//Falcon-180B DATASET v1.0 Category: Text to ASCII art generator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 24
#define MAX_CODE_LENGTH 1000

typedef struct {
    char *code;
    int width;
    int height;
    int x;
    int y;
} TextArt;

void generate_art(TextArt *art, char *text) {
    int len = strlen(text);
    int i, j, k;
    for (i = 0; i < len; i++) {
        if (isspace(text[i])) {
            art->x = 0;
            art->y++;
        } else {
            for (j = 0; j < art->width; j++) {
                for (k = 0; k < art->height; k++) {
                    if (art->code[j * art->height + k] == text[i]) {
                        art->x = j;
                        art->y = k;
                        break;
                    }
                }
            }
        }
    }
}

void print_art(TextArt *art) {
    int i, j;
    for (i = 0; i < art->height; i++) {
        for (j = 0; j < art->width; j++) {
            printf("%c", art->code[i * art->width + j]);
        }
        printf("\n");
    }
}

int main() {
    char input_text[MAX_CODE_LENGTH];
    TextArt art;

    printf("Enter text to convert to ASCII art: ");
    fgets(input_text, MAX_CODE_LENGTH, stdin);

    art.code = (char *)malloc(MAX_CODE_LENGTH);
    strcpy(art.code, input_text);

    art.width = MAX_WIDTH;
    art.height = MAX_HEIGHT;
    art.x = 0;
    art.y = 0;

    generate_art(&art, input_text);
    print_art(&art);

    return 0;
}