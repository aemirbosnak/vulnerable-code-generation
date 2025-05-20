//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: introspective
#include <stdio.h>
#include <string.h>

#define MAX_CHARS 256
#define MAX_HEIGHT 10

void draw_char(char c, int height);
char* get_input();

int main(void) {
    char* input = get_input();
    int len = strlen(input);

    for (int i = 0; i < len; i++) {
        char curr_char = input[i];
        draw_char(curr_char, MAX_HEIGHT);
    }

    return 0;
}

void draw_char(char c, int height) {
    if (c == ' ') {
        for (int i = 0; i < height; i++) {
            printf("\n");
        }
    }
    else {
        int ascii_val = (int) c;
        int binary[8];

        // Convert to binary representation
        for (int i = 0; i < 8; i++) {
            binary[7-i] = ascii_val % 2;
            ascii_val >>= 1;
        }

        // Draw the character
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < 8; j++) {
                if (binary[j] == 1) {
                    printf("|");
                }
                else {
                    printf(" ");
                }
            }
            printf("\n");
        }
    }
}

char* get_input() {
    char* input = malloc(MAX_CHARS * sizeof(char));
    printf("Enter a string to convert to ASCII art:\n");
    fgets(input, MAX_CHARS, stdin);
    input[strcspn(input, "\n")] = '\0';
    return input;
}