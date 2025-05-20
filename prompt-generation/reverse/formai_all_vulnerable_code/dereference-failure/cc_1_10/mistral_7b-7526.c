//MISTRAL-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: retro
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define ART_SIZE 25
#define ART_CHARS " .:+*%@"

void create_ascii_art(char text[100], char ascii_art[ART_SIZE][ART_SIZE]);
void print_ascii_art(char ascii_art[ART_SIZE][ART_SIZE]);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <text>\n", argv[0]);
        return 1;
    }

    char text[100];
    strcpy(text, argv[1]);

    char ascii_art[ART_SIZE][ART_SIZE];
    create_ascii_art(text, ascii_art);
    print_ascii_art(ascii_art);

    return 0;
}

void create_ascii_art(char text[100], char ascii_art[ART_SIZE][ART_SIZE]) {
    int text_len = strlen(text);
    int row = 0;

    for (int i = 0; i < text_len; i++) {
        char c = toupper(text[i]);

        int col = 0;
        for (int j = 0; j < 8; j++) {
            int char_index = (int)c - 65;
            if (char_index < 0 || char_index > 25)
                char_index = (char_index % 26) + 65;

            ascii_art[row][col++] = ART_CHARS[ART_CHARS[7 - (text[i] & (1 << j))]];
        }
        row++;
    }
}

void print_ascii_art(char ascii_art[ART_SIZE][ART_SIZE]) {
    for (int i = 0; i < ART_SIZE; i++) {
        for (int j = 0; j < ART_SIZE; j++) {
            printf("%c", ascii_art[i][j]);
        }
        printf("\n");
    }
}