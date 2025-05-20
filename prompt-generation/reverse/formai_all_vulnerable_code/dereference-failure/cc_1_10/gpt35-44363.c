//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

#define HEIGHT 6
#define WIDTH 7

/* This function takes a character and returns its ASCII art representation as a string */
char* char_to_ascii(char c) {
    switch(c) {
        case 'A':
            return "  A  \n"
                   " A A \n"
                   "AAAAA\n"
                   "A   A\n"
                   "A   A\n";
        case 'B':
            return "BBBB \n"
                   "B   B\n"
                   "BBBB \n"
                   "B   B\n"
                   "BBBB \n";
        case 'C':
            return " CCCC\n"
                   "C    \n"
                   "C    \n"
                   "C    \n"
                   " CCCC\n";
        case 'D':
            return "DDD  \n"
                   "D  D \n"
                   "D   D\n"
                   "D  D \n"
                   "DDD  \n";
        case 'E':
            return "EEEEE\n"
                   "E    \n"
                   "EEE  \n"
                   "E    \n"
                   "EEEEE\n";
        case 'F':
            return "FFFFF\n"
                   "F    \n"
                   "FFF  \n"
                   "F    \n"
                   "F    \n";
        case 'G':
            return " GGGG\n"
                   "G    \n"
                   "G GGG\n"
                   "G   G\n"
                   " GGGG\n";
        case 'H':
            return "H   H\n"
                   "H   H\n"
                   "HHHHH\n"
                   "H   H\n"
                   "H   H\n";
        case 'I':
            return " III \n"
                   "  I  \n"
                   "  I  \n"
                   "  I  \n"
                   " III \n";
        case 'J':
            return "    J\n"
                   "    J\n"
                   "    J\n"
                   "J   J\n"
                   " JJJ\n";
        case 'K':
            return "K   K\n"
                   "K  K \n"
                   "KKK  \n"
                   "K  K \n"
                   "K   K\n";
        case 'L':
            return "L    \n"
                   "L    \n"
                   "L    \n"
                   "L    \n"
                   "LLLLL\n";
        case 'M':
            return "M   M\n"
                   "MM MM\n"
                   "M M M\n"
                   "M   M\n"
                   "M   M\n";
        case 'N':
            return "N   N\n"
                   "NN  N\n"
                   "N N N\n"
                   "N  NN\n"
                   "N   N\n";
        case 'O':
            return " OOO \n"
                   "O   O\n"
                   "O   O\n"
                   "O   O\n"
                   " OOO \n";
        case 'P':
            return "PPPP \n"
                   "P   P\n"
                   "PPPP \n"
                   "P    \n"
                   "P    \n";
        case 'Q':
            return " QQQ \n"
                   "Q   Q\n"
                   "Q Q Q\n"
                   "Q  QQ\n"
                   " QQQQ\n";
        case 'R':
            return "RRRR \n"
                   "R   R\n"
                   "RRRR \n"
                   "R  R \n"
                   "R   R\n";
        case 'S':
            return " SSSS\n"
                   "S    \n"
                   " SSS \n"
                   "    S\n"
                   "SSSS \n";
        case 'T':
            return "TTTTT\n"
                   "  T  \n"
                   "  T  \n"
                   "  T  \n"
                   "  T  \n";
        case 'U':
            return "U   U\n"
                   "U   U\n"
                   "U   U\n"
                   "U   U\n"
                   " UUU \n";
        case 'V':
            return "V   V\n"
                   "V   V\n"
                   "V   V\n"
                   " V V \n"
                   "  V  \n";
        case 'W':
            return "W   W\n"
                   "W   W\n"
                   "W   W\n"
                   "W W W\n"
                   " W W \n";
        case 'X':
            return "X   X\n"
                   " X X \n"
                   "  X  \n"
                   " X X \n"
                   "X   X\n";
        case 'Y':
            return "Y   Y\n"
                   " Y Y \n"
                   "  Y  \n"
                   "  Y  \n"
                   "  Y  \n";
        case 'Z':
            return "ZZZZZ\n"
                   "   Z \n"
                   "  Z  \n"
                   " Z   \n"
                   "ZZZZZ\n";
        case ' ':
            return "     \n"
                   "     \n"
                   "     \n"
                   "     \n"
                   "     \n";
        default:
            return "     \n"
                   "  ?  \n"
                   "     \n"
                   "  ?  \n"
                   "     \n";
    }
}

/* This function takes a string and returns its ASCII art representation as a multiline string */
char* text_to_ascii(char* str) {
    char* result = malloc(HEIGHT * sizeof(char) * (strlen(str) + 1));
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < strlen(str); j++) {
            char c = str[j];
            char* ascii_c = char_to_ascii(c);
            int k = 0;
            while (ascii_c[k] != '\0' && ascii_c[k] != '\n') {
                result[i * strlen(str) * HEIGHT + j * HEIGHT + k] = ascii_c[k];
                k++;
            }
            result[i * strlen(str) * HEIGHT + j * HEIGHT + k] = '\n';
        }
    }
    return result;
}

/* This function prints the ASCII art of a string */
void print_ascii(char* str) {
    char* ascii_text = text_to_ascii(str);
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH * strlen(str); j++) {
            printf("%c", ascii_text[i * WIDTH * strlen(str) + j]);
        }
        printf("\n");
    }
    free(ascii_text);
}

int main() {
    print_ascii("HELLO WORLD");
    return 0;
}