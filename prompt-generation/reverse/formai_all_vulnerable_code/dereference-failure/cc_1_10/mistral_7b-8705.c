//MISTRAL-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define WIDTH 32
#define HEIGHT 3

void print_ascii_char(char symbol) {
    switch (symbol) {
        case 'A': printf(" ____\n/     \\");
                 printf("|     |\n|     |_\n|_____|");
                 break;
        case 'B': printf(" ____\n/   _  \\");
                 printf("|  (o)  |\n|  |\\_| |\n|_____|");
                 break;
        case 'C': printf(" ____\n/   _  \\");
                 printf("|  (__) |\n|  |\\_| |\n|_____|");
                 break;
        case 'D': printf(" ____\n/   _  \\");
                 printf("|  (__) |\n|  |\\_| |\n|  |  |_|\n|_____|");
                 break;
        default: printf("Invalid character");
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <text>\n", argv[0]);
        return 1;
    }

    char *text = argv[1];
    int text_len = strlen(text);

    if (text_len > WIDTH * HEIGHT) {
        printf("Error: Text is too long\n");
        return 1;
    }

    int x = 0, y = 0;
    for (int i = 0; i < text_len; i++) {
        char symbol = text[i];
        if (x >= WIDTH) {
            x = 0;
            y++;
            if (y >= HEIGHT) {
                break;
            }
        }
        print_ascii_char(symbol);
        x++;
    }

    return 0;
}