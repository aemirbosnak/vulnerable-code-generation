//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 30
#define MAX_INPUT 128

char *letters[26][MAX_HEIGHT] = {
    { /* A */
        "        /\\        ",
        "       /  \\       ",
        "      /    \\      ",
        "     /------\\     ",
        "    /        \\    ",
        "   /          \\   ",
        "  /            \\  "
    },
    { /* B */
        " ________      ",
        "|        \\     ",
        "|         \\    ",
        "|_________\\   ",
        "|          |   ",
        "|          |   ",
        "|_________/  "
    },
    /* ... etc ... */
};

int char_to_index(char c) {
    if (c >= 'a' && c <= 'z') {
        return c - 'a';
    } else if (c >= 'A' && c <= 'Z') {
        return c - 'A';
    } else {
        return -1;
    }
}

void print_text_as_ascii_art(char *text) {
    int length = strlen(text);
    int height = MAX_HEIGHT;
    int width = length * MAX_WIDTH;

    char **image = malloc(sizeof(char*) * height);
    for (int i = 0; i < height; i++) {
        image[i] = malloc(sizeof(char) * width);
        memset(image[i], ' ', width);
    }

    for (int i = 0; i < length; i++) {
        int index = char_to_index(text[i]);
        if (index < 0) continue;
        for (int y = 0; y < MAX_HEIGHT; y++) {
            for (int x = 0; x < MAX_WIDTH; x++) {
                image[y][i*MAX_WIDTH + x] = letters[index][y][x];
            }
        }
    }

    for (int i = 0; i < height; i++) {
        printf("%s\n", image[i]);
        free(image[i]);
    }
    free(image);
}

int main() {
    char input[MAX_INPUT];
    printf("Enter text: ");
    fgets(input, MAX_INPUT, stdin);
    input[strcspn(input, "\n")] = 0;
    print_text_as_ascii_art(input);
    return 0;
}