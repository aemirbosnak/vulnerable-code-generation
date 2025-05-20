//MISTRAL-7B DATASET v1.0 Category: Text to Morse code conversion ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define LENGTH 26
#define DOTS 3
#define DASHES 7

char morse_code[LENGTH][3] = {
    {'.', '.'}, {'-', '.'}, {'-', '-'}, {'-', '.'}, {'.', '.'}, {'-', '.'},
    {'--', '.'}, {'-.', '.'}, {'-', '-', '.'}, {'--', '.'}, {'-', '.'}, {'-', '-'},
    {'-', '--', '.'}, {'-', '..'}
};

void morse_encode_char(char morse[DOTS + DASHES], char ch) {
    int index;

    if (isalpha(ch)) {
        index = ch - 'A';
        strncpy(morse, morse_code[index], sizeof(morse_code[0][0]) * (sizeof(morse_code[index]) / sizeof(morse_code[0][0])));
        if (isupper(ch))
            morse[0] = toupper(morse[0]);
    } else if (ch == ' ') {
        strcpy(morse, "/");
    } else {
        strcpy(morse, "");
    }
}

void morse_encode(char morse[100], char str[100]) {
    char temp_morse[DOTS + DASHES];

    for (int i = 0; str[i] != '\0'; i++) {
        morse_encode_char(temp_morse, str[i]);
        strcat(morse, temp_morse);
        if (str[i] != ' ') {
            strcat(morse, " ");
        }
        strcpy(temp_morse, "");
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <text>\n", argv[0]);
        return 1;
    }

    char morse[100];
    strcpy(morse, "");

    morse_encode(morse, argv[1]);
    puts(morse);

    return 0;
}