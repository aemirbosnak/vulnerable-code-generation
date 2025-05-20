//MISTRAL-7B DATASET v1.0 Category: Alien Language Translator ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ZOTZ_NUM 26
#define ZODIAC_NAMES "xutxul zarquon plix ziv quux dhactar zib"
#define NUM_Vowels 5
#define NUM_Cons 21
#define NUM_Digits 10

char *zodiac_names = ZODIAC_NAMES;
char vowels[NUM_Vowels][2] = { "a", "e", "i", "o", "u" };
char consonants[NUM_Cons][2] = { "b", "c", "d", "f", "g", "h", "j", "k", "l", "m", "n", "p", "q", "r", "s", "t", "v", "w", "x", "y", "z" };
char digits[NUM_Digits][2] = { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9" };

char *zodiac(int day) {
    char *zodiac_sign;
    int index = day % ZOTZ_NUM;

    zodiac_sign = malloc(strlen(zodiac_names) + 2);
    strcpy(zodiac_sign, zodiac_names);
    zodiac_sign += index * (strlen(zodiac_names) / ZOTZ_NUM);

    return zodiac_sign;
}

int main(int argc, char **argv) {
    char *input, *output = NULL;
    int day;

    if (argc != 2) {
        printf("Usage: %s <day of the year>\n", argv[0]);
        return 1;
    }

    input = argv[1];

    day = atoi(input);
    if (day < 1 || day > 366) {
        printf("Invalid day of the year: %s\n", input);
        return 1;
    }

    output = malloc(strlen(zodiac(day)) + 1);
    strcpy(output, zodiac(day));

    // Alien Language Translation Logic
    for (int i = 0; i < strlen(output); i++) {
        if (isdigit(output[i])) {
            for (int j = 0; j < NUM_Digits; j++) {
                if (output[i] == digits[j][0]) {
                    output[i] = digits[j][1];
                    break;
                }
            }
        } else if (isalpha(output[i])) {
            for (int j = 0; j < NUM_Vowels; j++) {
                if (output[i] == vowels[j][0]) {
                    output[i] = vowels[j][1];
                    for (int k = i + 1; k < strlen(output); k++) {
                        if (isalpha(output[k])) {
                            output[k] = consonants[NUM_Cons + (int)(output[k] - 'a')][1];
                        }
                    }
                    break;
                }
            }
        }
    }

    printf("Alien Translation: %s\n", output);
    free(output);
    return 0;
}