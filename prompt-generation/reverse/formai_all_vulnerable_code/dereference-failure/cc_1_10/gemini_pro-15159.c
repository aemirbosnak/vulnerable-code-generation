//GEMINI-pro DATASET v1.0 Category: Text to ASCII art generator ; Style: medieval
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 80
#define HEIGHT 25

char *art[] = {
    "  ____  _____   __    __  __  _____ ",
    " | __ )/ ____| |  |  |  ||  |/ ____|",
    " |  _|| |  __  |  |__|  || | | (___  ",
    " | |_ | | |_ | |  __  __|| |  \\___ \\ ",
    " |____||_|___| |_|  |_|  |_|  |_____|",
    "                                   ",
    "  ____  __  __   ____ ___  __   __  ",
    " | __ )|  \/  | | __ )_ _||  | |  \/  |",
    " |  _ \| |\/| | |  _ \| |  | | |\/| |",
    " | |_) | |  | | | |_) | |  | | |  | |",
    " |____/|_|  |_| |____/___||_|  |_|  |_|",
    "                                   ",
    "  ____  _____   ____ ___  __   __  ",
    " | __ )| ____| |  _ \_ _||  | |  \/  |",
    " |  _ \|  _|   | |_) || |  | | |\/| |",
    " | |_) | |___  |  __/ | |  | | |  | |",
    " |____/|_____| |_|   ___||_|  |_|  |_|",
    "                                   ",
    "  ____  _   _   ____  __      __  ",
    " | __ )| | | | | __ )\ \ /\ / /|  \/  |",
    " |  _ \| | | | |  _ \\ V  V / | |\/| |",
    " | |_) | |_| | | |_) || |\/| | |  | |",
    " |____/ \___/  |____/ |_|  |_| |_|  |_|"
};

void draw_text(char *text) {
    int x, y;
    int len = strlen(text);

    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            if (x < len && y < art[text[x] - 'A'][y * WIDTH + x]) {
                putchar('*');
            } else {
                putchar(' ');
            }
        }
        putchar('\n');
    }
}

int main() {
    char text[100];

    printf("Enter text to convert to ASCII art (max 100 characters): ");
    fgets(text, sizeof(text), stdin);

    for (int i = 0; i < strlen(text); i++) {
        text[i] = toupper(text[i]);
    }

    draw_text(text);

    return 0;
}