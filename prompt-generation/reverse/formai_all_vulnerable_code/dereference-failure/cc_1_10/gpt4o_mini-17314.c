//GPT-4o-mini DATASET v1.0 Category: Text to ASCII art generator ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_usage() {
    printf("Welcome to the ASCII Art Generator!\n");
    printf("Please enter a string to generate ASCII art:\n");
    printf("Usage: ./ascii_art_generator [string]\n");
}

void convert_to_ascii_art(const char *input) {
    int len = strlen(input);
    char ascii_art[100][100]; // Initialize a 2D array for ASCII art

    // Fill ASCII representation for A-Z and a-z
    const char *art[] = {
        "  A  ", // 0
        "  B  ", // 1
        "  C  ", // 2
        "  D  ", // 3
        "  E  ", // 4
        "  F  ", // 5
        "  G  ", // 6
        "  H  ", // 7
        "  I  ", // 8
        "  J  ", // 9
        "  K  ", // 10
        "  L  ", // 11
        "  M  ", // 12
        "  N  ", // 13
        "  O  ", // 14
        "  P  ", // 15
        "  Q  ", // 16
        "  R  ", // 17
        "  S  ", // 18
        "  T  ", // 19
        "  U  ", // 20
        "  V  ", // 21
        "  W  ", // 22
        "  X  ", // 23
        "  Y  ", // 24
        "  Z  ", // 25
        "  a  ", // 26
        "  b  ", // 27
        "  c  ", // 28
        "  d  ", // 29
        "  e  ", // 30
        "  f  ", // 31
        "  g  ", // 32
        "  h  ", // 33
        "  i  ", // 34
        "  j  ", // 35
        "  k  ", // 36
        "  l  ", // 37
        "  m  ", // 38
        "  n  ", // 39
        "  o  ", // 40
        "  p  ", // 41
        "  q  ", // 42
        "  r  ", // 43
        "  s  ", // 44
        "  t  ", // 45
        "  u  ", // 46
        "  v  ", // 47
        "  w  ", // 48
        "  x  ", // 49
        "  y  ", // 50
        "  z  ", // 51
    };

    for (int i = 0; i < len; i++) {
        char ch = input[i];
        int index = -1;

        if (ch >= 'A' && ch <= 'Z') {
            index = ch - 'A';
        } else if (ch >= 'a' && ch <= 'z') {
            index = ch - 'a' + 26;
        } else {
            printf("Unsupported character: %c\n", ch);
            continue;
        }
        strcpy(ascii_art[i], art[index]);
    }

    printf("\nGenerated ASCII Art:\n");
    for (int i = 0; i < len; i++) {
        printf("%s\n", ascii_art[i]);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        print_usage();
        return 1;
    }
    
    convert_to_ascii_art(argv[1]);
    
    return 0;
}