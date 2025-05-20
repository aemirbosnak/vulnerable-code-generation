//GPT-4o-mini DATASET v1.0 Category: Text to ASCII art generator ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_ascii_art(const char *str) {
    const char *ascii_art[] = {
        "   ###      ###   ##     ##   #####   ###     ###      ###   ###    #######  ",
        " ######    #####  ##     ##  ##   ##  ####   #####    #####  ## ##   ##     ## ",
        "##    ##   ## ##  ##     ##  ##       ## ##  ## ##   ## ##  ##   ##   ##      ",
        "##         ##  ## ##     ##  ######   ##  ## ##  ##  ##  ##  ##         ##     ",
        "##   ####  ## ### ##     ##  ##       ##   ## ## ##  ##   ## ###       ##      ",
        " ##    ##   ####  ##     ##  ##   ##  ##    ## ##  ## ##    ###       ##       ",
        " ###  ###    ###    #######   #####   ##     ##         ##   ###     ##        "
    };

    int length = strlen(str);
    for (int i = 0; i < length; i++) {
        int c = str[i];
        if (c < 32 || c > 126) {
            c = 0; // Non-printable characters will just be ignored
        }
        c -= 32; // Offset to align with ASCII art array
        for (int j = 0; j < 7; j++) {
            if (c < 0 || c >= 95) {
                continue;
            }
            if ((ascii_art[c][j] == '#') || (ascii_art[c][j] == ' ')) {
                putchar(ascii_art[c][j]);
            }
            else {
                putchar(' '); // Default space
            }
        }
        putchar('\n');
    }
}

void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

int main() {
    char input[256];

    printf("Welcome to the ASCII Art Generator!\n");
    printf("Enter a string to convert it into ASCII art (max 255 characters): ");
    
    if (fgets(input, sizeof(input), stdin) == NULL) {
        fprintf(stderr, "Failed to read input\n");
        return EXIT_FAILURE;
    }

    // Strip newline character if present
    input[strcspn(input, "\n")] = 0;

    printf("\nGenerated ASCII Art:\n");
    print_ascii_art(input);

    return 0;
}