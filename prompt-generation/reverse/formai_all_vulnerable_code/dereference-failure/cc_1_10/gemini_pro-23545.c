//GEMINI-pro DATASET v1.0 Category: Text to ASCII art generator ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

// Function to convert a character to ASCII art
char* char_to_art(char c) {
    switch (c) {
        case 'A':
            return "  *   *  \n * *   * *\n*****   *****\n*   *   *   *\n*   *   *   *";
        case 'B':
            return "*****   *****\n*   *   *   *\n*****   *****\n*   *   *   *\n*****   *****";
        case 'C':
            return " *****   *****\n*       *       *\n*       *       *\n*       *       *\n *****   *****";
        case 'D':
            return "*****   *****\n*   *   *   *\n*   *   *   *\n*   *   *   *\n*****   *****";
        case 'E':
            return "*****   *****\n*       *       *\n*****   *****\n*       *       *\n*****   *****";
        case 'F':
            return "*****   *****\n*       *       *\n*****   *****\n*       *       *\n*       *       *";
        case 'G':
            return " *****   *****\n*       *       *\n*  *    *  *    *\n*   *   *   *    *\n *****   *****";
        case 'H':
            return "*   *   *   *\n*   *   *   *\n*****   *****\n*   *   *   *\n*   *   *   *";
        case 'I':
            return "*****\n   *\n   *\n   *\n*****";
        case 'J':
            return "*****\n   *\n   *\n*   *\n *****";
        case 'K':
            return "*   *   *   *\n*  *  *  *  *\n*   * *   * *\n*  *  *  *  *\n*   *   *   *";
        case 'L':
            return "*       *\n*       *\n*       *\n*       *\n*****   *****";
        case 'M':
            return "*   *   *   *\n**  *  *  *  **\n* * * * * * * *\n*   *   *   *\n*   *   *   *";
        case 'N':
            return "*   *   *   *\n**  *  *  * **\n* * * * * * * *\n*  *  *  *  *\n*   *   *   *";
        case 'O':
            return " *****   *****\n*       *       *\n*       *       *\n*       *       *\n *****   *****";
        case 'P':
            return "*****   *****\n*       *       *\n*****   *****\n*       *       *\n*       *       *";
        case 'Q':
            return " *****   *****\n*       *       *\n*       *  *    *\n*   *   *   *    *\n *****   *****";
        case 'R':
            return "*****   *****\n*       *       *\n*****   *****\n*   *   *   *\n*   *   *   *";
        case 'S':
            return " *****   *****\n*       *       *\n *****   *****\n      *       *\n*****   *****";
        case 'T':
            return "*****\n   *\n   *\n   *\n   *";
        case 'U':
            return "*   *   *   *\n*   *   *   *\n*   *   *   *\n*   *   *   *\n *****   *****";
        case 'V':
            return "*   *   *   *\n*   *   *   *\n*   *   *   *\n * *   * * \n  *     *  ";
        case 'W':
            return "*   *   *   *\n*   *   *   *\n*   *   *   *\n* * * * * * * *\n*   *   *   *";
        case 'X':
            return "*   *   *   *\n * *   * * \n  *     *  \n * *   * * \n*   *   *   *";
        case 'Y':
            return "*   *   *   *\n * *   * * \n  *     *  \n  *     *  \n  *     *  ";
        case 'Z':
            return "*****   *****\n      *       *\n     *       *\n    *       *\n*****   *****";
        default:
            return " ";
    }
}

// Function to convert a string to ASCII art
char** string_to_art(char* str) {
    char** art = malloc(sizeof(char*) * strlen(str));
    for (int i = 0; i < strlen(str); i++) {
        art[i] = char_to_art(str[i]);
    }
    return art;
}

// Function to print ASCII art
void print_art(char** art) {
    for (int i = 0; i < strlen(art); i++) {
        printf("%s\n", art[i]);
    }
}

int main() {
    char* str = "PEACE";
    char** art = string_to_art(str);
    print_art(art);
    return 0;
}