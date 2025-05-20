//GPT-4o-mini DATASET v1.0 Category: Text to ASCII art generator ; Style: immersive
#include <stdio.h>
#include <string.h>

#define MAX_INPUT_SIZE 100

void print_ascii_art(char *input) {
    char *ascii_art[] = {
        "  **     **   *****     **         **     **  **        ",  
        " **      **  **   **    **         **      **  **        ",  
        "**        ** **     **   **         **     **   **       ",  
        "**        ** ********   **         **     **    **       ",  
        "**        ** **         **          **   **     **       ",  
        "**        ** **         **           ** **      **       ",  
        " **      **  **         **            ***       **       ",  
        "  **     **   **         **            **        **       "
    };

    int len = strlen(input);
    for (int i = 0; i < len; i++) {
        // If input is a lowercase letter
        if (input[i] >= 'a' && input[i] <= 'z') {
            int index = input[i] - 'a';
            for (int j = 0; j < 8; j++) {
                putchar(ascii_art[j][index * 8 + j]);
            }
            putchar('\n');
        }
        // If input is a space
        else if (input[i] == ' ') {
            printf("\n");
        }
        // For any character not in 'a' to 'z', display a question mark
        else {
            printf("??\n");
        }
    }
}

int main() {
    char input[MAX_INPUT_SIZE];

    printf("Welcome to the C ASCII Art Generator!\n");
    printf("Enter some text (up to %d characters, lowercase letters only): \n", MAX_INPUT_SIZE - 1);
    fgets(input, MAX_INPUT_SIZE, stdin);
    input[strcspn(input, "\n")] = 0; // Remove newline from input

    printf("\nHere is your ASCII art:\n\n");
    print_ascii_art(input);

    return 0;
}