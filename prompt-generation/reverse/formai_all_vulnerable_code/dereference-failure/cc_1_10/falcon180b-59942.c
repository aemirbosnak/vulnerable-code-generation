//Falcon-180B DATASET v1.0 Category: Text to ASCII art generator ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 25

typedef struct {
    char *data;
    int width;
    int height;
} AsciiArt;

AsciiArt *generate_ascii_art(const char *text) {
    int text_width = strlen(text);
    int text_height = 1;
    AsciiArt *art = malloc(sizeof(AsciiArt));

    art->data = malloc(text_width * text_height + 1);
    art->width = text_width;
    art->height = text_height;

    int i, j;
    for (i = 0; i < text_height; i++) {
        for (j = 0; j < text_width; j++) {
            char c = text[j];
            art->data[i * text_width + j] = c;
        }
    }

    art->data[text_width * text_height] = '\0';

    return art;
}

void print_ascii_art(const AsciiArt *art) {
    int i, j;
    for (i = 0; i < art->height; i++) {
        for (j = 0; j < art->width; j++) {
            char c = art->data[i * art->width + j];
            printf("%c", c);
        }
        printf("\n");
    }
}

int main() {
    char input[MAX_WIDTH];
    printf("Enter some text: ");
    fgets(input, MAX_WIDTH, stdin);

    AsciiArt *art = generate_ascii_art(input);
    print_ascii_art(art);

    free(art->data);
    free(art);

    return 0;
}