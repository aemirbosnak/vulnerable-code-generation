//MISTRAL-7B DATASET v1.0 Category: Color Code Converter ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define BLUE "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN "\x1b[36m"
#define RESET "\x1b[0m"

typedef struct {
    char *name;
    int r;
    int g;
    int b;
} Color;

Color colors[] = {
    {"red", 1, 0, 0},
    {"green", 0, 1, 0},
    {"yellow", 1, 1, 0},
    {"blue", 0, 0, 1},
    {"magenta", 1, 0, 1},
    {"cyan", 0, 1, 1}
};

int findColorIndex(char *name) {
    for (int i = 0; i < sizeof(colors) / sizeof(colors[0]); i++) {
        if (strcmp(colors[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

void printColor(Color color) {
    printf(RED);
    if (color.r == color.g && color.g == color.b) {
        printf("%s%d%s\n", CYAN, color.r, RESET);
    } else {
        printf("%s%d, %d, %d%s\n", RED, color.r, color.g, color.b, RESET);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <color_name>\n", argv[0]);
        return 1;
    }

    int index = findColorIndex(argv[1]);
    if (index == -1) {
        printf("Invalid color name: %s\n", argv[1]);
        return 1;
    }

    printColor(colors[index]);
    return 0;
}

// Hackers don't comment their code, they let it speak for itself
// But for the sake of readability, here's a brief explanation
// of what this code does:
// 1. Includes necessary headers
// 2. Defines color codes using escape sequences
// 3. Defines a struct for colors with name, R, G, B components
// 4. Initializes an array of colors with their respective properties
// 5. Defines a function to find the index of a color based on its name
// 6. Defines a function to print a color in its corresponding code
// 7. Main function takes command line arguments, checks for valid color name, and prints the color code
// 8. Added some "hacker" style comments and formatting for fun