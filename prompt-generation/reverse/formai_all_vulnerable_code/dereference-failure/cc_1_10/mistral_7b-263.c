//MISTRAL-7B DATASET v1.0 Category: Text to Morse code conversion ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define DOT "_ .-"
#define DASH "|--"
#define SPACE "   "
#define MORSE_LENGTH 26
#define WORD_GAP 7

char morse_code[MORSE_LENGTH][3] = {
    [0] = ".-", [1] = "--", [2] = "-.", [3] = "---", [4] = ".---",
    [5] = "-.-", [6] = ".-..", [7] = "--.", [8] = "-.--", [9] = "--..",
    [10] = ".----", [11] = "..---", [12] = "...--", [13] = "....-", [14] = ".....",
    [15] = "-....", [16] = "--...", [17] = "---..", [18] = "----.", [19] = "-----"
};

void convert_morse(char *input) {
    char *word = strtok(input, " ");
    int word_count = 1;

    while (word != NULL) {
        int i;
        for (i = 0; i < MORSE_LENGTH; i++) {
            if (strcmp(morse_code[i], word) == 0) {
                printf("%s ", morse_code[i]);
                break;
            }
        }

        if (i == MORSE_LENGTH) {
            printf("UNKNOWN SIGNAL: %s ", word);
        }

        if (word_count < strlen(input) / (WORD_GAP + strlen(word) + 1)) {
            printf("%s ", SPACE);
        }

        word = strtok(NULL, " ");
        word_count++;
    }

    printf("\n");
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <message>\n", argv[0]);
        return 1;
    }

    convert_morse(argv[1]);
    return 0;
}