//GPT-4o-mini DATASET v1.0 Category: Text to ASCII art generator ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void render_char(char ch, int scale_factor) {
    // Define a simple mapping of ASCII characters to their ASCII art representation
    const char *ascii_art[] = {
        "  ##  \n #  # \n #  # \n #  # \n  ##  ",  // 0
        "  #   \n ##   \n  #   \n  #   \n #### ",  // 1
        " ###  \n#   # \n   ## \n  #   \n##### ",  // 2
        " ###  \n#   # \n ###  \n#   # \n ###  ",  // 3
        "#  #  \n#  #  \n #####\n   #  \n   #  ",  // 4
        "##### \n#     \n####  \n#   # \n ###  ",  // 5
        " ###  \n#     \n####  \n#  #  \n ###  ",  // 6
        "##### \n    # \n   #  \n  #   \n #    ",  // 7
        " ###  \n#  #  \n ###  \n#  #  \n ###  ",  // 8
        " ###  \n#  #  \n #### \n    # \n ###  "   // 9
    };

    // Convert character to corresponding index (0-9 for digits)
    int index = ch - '0';
    if (index < 0 || index > 9) { // Unsupported character
        fprintf(stderr, "Error: Unsupported character '%c'\n", ch);
        return;
    }

    // Print ASCII art representation scaled by scale_factor
    for (int i = 0; i < 5; i++) {
        for (int s = 0; s < scale_factor; s++) {
            for (const char *p = ascii_art[index] + (i * 6); *p && *p != '\n'; p++) {
                if (*p == '#') {
                    printf("#");
                } else {
                    printf(" ");
                }
            }
            printf(" ");
        }
        printf("\n");
    }
}

void ascii_art_from_string(const char *input, int scale_factor) {
    for (size_t i = 0; i < strlen(input); i++) {
        if (input[i] >= '0' && input[i] <= '9') {
            render_char(input[i], scale_factor);
        } else {
            printf("Unsupported character: %c\n", input[i]);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <text> <scale_factor>\n", argv[0]);
        return 1;
    }

    const char *text = argv[1];
    int scale_factor = atoi(argv[2]);

    if (scale_factor < 1) {
        fprintf(stderr, "Error: scale_factor must be greater than 0\n");
        return 1;
    }

    printf("Rendering ASCII art for: %s\n", text);
    ascii_art_from_string(text, scale_factor);
    
    return 0;
}